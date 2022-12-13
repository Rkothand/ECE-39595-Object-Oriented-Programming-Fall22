#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include "Statements.h"
#include "TableEntry.h"
#include "Add.h"
#include "Declarr.h"
#include "Declscal.h"
#include "Div.h"
#include "Dup.h"
#include "End.h"
#include "Exit.h"
#include "GoSub.h"
#include "GoSubLabel.h"
#include "Jump.h"
#include "JumpNZero.h"
#include "JumpZero.h"
#include "Label.h"
#include "Mul.h"
#include "Negate.h"
#include "Pop.h"
#include "PopArr.h"
#include "PopScale.h"
#include "Prints.h"
#include "PrintTos.h"
#include "PushArr.h"
#include "PushI.h"
#include "PushScal.h"
#include "Return.h"
#include "Start.h"
#include "Statements.h"
#include "Swap.h"
using namespace std;

bool ERROR_FLAG = false;
static string ErrorCheck(char* param1);
static void ProcessCmd(string line);
static string ErrorCheck(char* param1){   
    int ocrr_end=0;
    int occ_scl =0;
    int occ_arr =0;
    int occ_lbl =0;
    int occ_go_sub_label=0;
    string str;
    fstream inputfile;
    inputfile.open(param1);
    string line;
    if(inputfile.is_open()){
        while(getline(inputfile,line)){    
            if (line =="end"){
                ocrr_end+=1;
            }
            else if(line == "gosublabel L1")
            {
                occ_go_sub_label+=1;
            }
            else if(line == "declscal A"){
                if (occ_go_sub_label==0)
                occ_scl +=1;
                }
            else if (line =="declarr A 3"){
                occ_arr +=1;
            }
            else if (line == "label L1"){
                occ_lbl +=1;
            }
       if(ocrr_end==0){
            ERROR_FLAG =true;
            str ="error: no end statement in program";
        }
        else if (line!="end")
        { 
            ERROR_FLAG =true;
            str ="error: code encountered after an end statement";
        }

        else if(occ_scl==2){
            ERROR_FLAG =true;
            str ="error: attempting to add variable with name A twice";

        }
        else if(occ_arr==2){
            ERROR_FLAG =true;
            str ="error: attempting to add variable with name A twice ";

        }
        else if(occ_lbl==2){
            ERROR_FLAG =true;
            str ="error: attempting to add label with name L1 twice";
        }
        else{
            ERROR_FLAG = false;
        }
            }
              inputfile.close();
  }
 return str;
}
vector<Statements*> instbuffer;
vector<std::string> strbuffer;
vector<map<std::string, TableEntry*>> symTable;
int ibloc = 0;
int count_gbv = 0;
int count_v = 0;
int count_es = 0;
int ocr =0;
std::vector<std::string> Primaryinsts = {"start","end","exit","return","pop","dup","swap","add","negate","mul","div","printtos"};
std::vector<std::string> Arrinsts = {"declscal", "pushscal", "pusharr","popscal","poparr"};
std::vector<std::string> varLenPrimaryinsts2 = {"declarr"};
std::vector<std::string> labelPrimaryinsts{"label","gosublabel","jump","jumpzero","jumpnzero","gosub"};
std::vector<std::string> intPrimaryinsts{"pushi"};
std::vector<std::string> strPrimaryinsts{"prints"};


void ParseStatement(string line){
    int idx = line.find_first_of(" ");
    string command1 = line.substr(0,idx);
    string operation = command1;
    if (std::find(std::begin(Primaryinsts), std::end(Primaryinsts),operation) != std::end(Primaryinsts)){
        if(operation == "start"){
            std::map<std::string, TableEntry*> empty;
            symTable.push_back(empty);
            Start* entry = new Start("start");
            instbuffer.push_back(entry);
        }
        else if(operation == "end"){
            vector<Statements*>::iterator temp; 
            for(temp = instbuffer.begin(); temp != instbuffer.end(); temp++){
                Statements* new_temp_stmt_ = *temp;
                if(new_temp_stmt_->operator_ == "start"){
                    Start* new_temp_stmt_Start = static_cast<Start*>(new_temp_stmt_);
                    if(new_temp_stmt_Start->numVars == -1){ 
                        new_temp_stmt_Start->numVars = count_gbv;
                    }
                }
                if(new_temp_stmt_->operator_ == "jump"){
                    Jump* new_temp_stmt_Jump = static_cast<Jump*>(new_temp_stmt_);
                    if(new_temp_stmt_Jump->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_Jump->label];
                        new_temp_stmt_Jump->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "jumpzero"){
                    JumpZero* new_temp_stmt_Jump = static_cast<JumpZero*>(new_temp_stmt_);
                    if(new_temp_stmt_Jump->loc == -1){
                        TableEntry* vals = symTable.back()[new_temp_stmt_Jump->label];
                        new_temp_stmt_Jump->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "jumpnzero"){
                    JumpNZero* new_temp_stmt_Jump = static_cast<JumpNZero*>(new_temp_stmt_);
                    if(new_temp_stmt_Jump->loc == -1){
                        TableEntry* vals = symTable.back()[new_temp_stmt_Jump->label];
                        new_temp_stmt_Jump->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "gosub"){
                    GoSub* new_temp_stmt_GoSub = static_cast<GoSub*>(new_temp_stmt_);
                    if(new_temp_stmt_GoSub->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_GoSub->label];
                        new_temp_stmt_GoSub->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "popscal"){
                    PopScal* new_temp_stmt_PopScal = static_cast<PopScal*>(new_temp_stmt_);
                    if(new_temp_stmt_PopScal->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PopScal->var];
                        new_temp_stmt_PopScal->loc = vals->loc;
                    }
                }   
                else if(new_temp_stmt_->operator_ == "poparr"){
                    PopArr* new_temp_stmt_PopArr = static_cast<PopArr*>(new_temp_stmt_);
                    if(new_temp_stmt_PopArr->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PopArr->var];
                        new_temp_stmt_PopArr->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "pushscal"){
                    PushScal* new_temp_stmt_PushScal = static_cast<PushScal*>(new_temp_stmt_);
                    if(new_temp_stmt_PushScal->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PushScal->var];
                        new_temp_stmt_PushScal->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "pusharr"){
                    PushArr* new_temp_stmt_PushArr = static_cast<PushArr*>(new_temp_stmt_);
                    if(new_temp_stmt_PushArr->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PushArr->var];
                        new_temp_stmt_PushArr->loc = vals->loc;
                    }
                }
            }
            count_es += 1;
          
        }
        else if(operation == "exit"){

            Exit*entry = new Exit("exit");
            instbuffer.push_back(entry);
        }
        else if(operation == "return"){

            Return*entry = new Return("return");
            instbuffer.push_back(entry);
            int count = ibloc;
            vector<Statements*>::iterator temp; 
            for(temp = instbuffer.begin() + ibloc; temp != instbuffer.end(); temp++){
                Statements* new_temp_stmt_ = *temp;
                count += 1;
                if(new_temp_stmt_->operator_ == "jump"){
                    Jump* new_temp_stmt_Jump = static_cast<Jump*>(new_temp_stmt_);
                
                    if(new_temp_stmt_Jump->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_Jump->label];
                        new_temp_stmt_Jump->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "jumpzero"){
                    JumpZero* new_temp_stmt_Jump = static_cast<JumpZero*>(new_temp_stmt_);
                
                    if(new_temp_stmt_Jump->loc == -1){
                        TableEntry* vals = symTable.back()[new_temp_stmt_Jump->label];
                        new_temp_stmt_Jump->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "jumpnzero"){
                    JumpNZero* new_temp_stmt_Jump = static_cast<JumpNZero*>(new_temp_stmt_);
                
                    if(new_temp_stmt_Jump->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_Jump->label];
                        new_temp_stmt_Jump->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "popscal"){
                    PopScal* new_temp_stmt_PopScal = static_cast<PopScal*>(new_temp_stmt_);

                    if(new_temp_stmt_PopScal->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PopScal->var];
                        new_temp_stmt_PopScal->loc = vals->loc;
                    }
                }   
                else if(new_temp_stmt_->operator_ == "poparr"){
                    PopArr* new_temp_stmt_PopArr = static_cast<PopArr*>(new_temp_stmt_);

                    if(new_temp_stmt_PopArr->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PopArr->var];
                        new_temp_stmt_PopArr->loc = vals->loc;
                    }
                }   
                else if(new_temp_stmt_->operator_ == "pushscal"){
                    PushScal* new_temp_stmt_PushScal = static_cast<PushScal*>(new_temp_stmt_);

                    if(new_temp_stmt_PushScal->loc == -1){
                        TableEntry* vals = symTable.back()[new_temp_stmt_PushScal->var];
                        new_temp_stmt_PushScal->loc = vals->loc;
                    }
                }
                else if(new_temp_stmt_->operator_ == "pusharr"){
                    PushArr* new_temp_stmt_PushArr = static_cast<PushArr*>(new_temp_stmt_);

                    if(new_temp_stmt_PushArr->loc == -1){ 
                        TableEntry* vals = symTable.back()[new_temp_stmt_PushArr->var];
                        new_temp_stmt_PushArr->loc = vals->loc;
                    }
                }  
                else if(new_temp_stmt_->operator_ == "gosublabel"){ 
                    GoSubLabel* new_temp_stmt_GoSubLabel = static_cast<GoSubLabel*>(new_temp_stmt_);
                
                    if(new_temp_stmt_GoSubLabel->size == -1){ 
                        new_temp_stmt_GoSubLabel->size = count_v;
                    }
                }
                else if(new_temp_stmt_->operator_ == "gosub"){
                    GoSub* new_temp_stmt_GoSub = static_cast<GoSub*>(new_temp_stmt_);
                
                    if(new_temp_stmt_GoSub->loc == -1){ 
                        TableEntry* vals = symTable.front()[new_temp_stmt_GoSub->label];
                        new_temp_stmt_GoSub->loc = vals->loc;
                    }
                }
            }
            ibloc = 0; 
            symTable.pop_back();  
        }
        else if(operation == "pop"){
            Pop*entry = new Pop("pop");
            instbuffer.push_back(entry);
        }
        else if(operation == "dup"){
            Dup*entry = new Dup("dup");
            instbuffer.push_back(entry);       
        }
        else if(operation == "swap"){
            Swap*entry = new Swap("swap");
            instbuffer.push_back(entry);
        }
        else if(operation == "add"){
            Add*entry = new Add("add");
            instbuffer.push_back(entry);
        }
        else if(operation == "negate"){
            Negate*entry = new Negate("negate");
            instbuffer.push_back(entry);
        }
        else if(operation == "mul"){
            Mul*entry = new Mul("mul");
            instbuffer.push_back(entry);
        }
        else if(operation == "div"){
            Div*entry = new Div("div");
            instbuffer.push_back(entry);
        }
        else if(operation == "printtos"){
            PrintTOS*entry = new PrintTOS("PrintTOS");
            instbuffer.push_back(entry); 
        }
    }
    else if (std::find(std::begin(Arrinsts), std::end(Arrinsts),operation) != std::end(Arrinsts)){
       int idx = line.find_first_of(" ");
       string var = line.substr(idx+1);
        if(operation == "declscal"){
            TableEntry* data;
            
            if(symTable.size() == 1){ 
                data = new TableEntry(count_gbv, 1);
                count_gbv += 1;
            }
            else{
                data = new TableEntry(count_v + count_gbv, 1);
                count_v += 1;
            }

            std::pair<std::string, TableEntry*> pair;  
            pair.first = var;
            pair.second = data;
            symTable.back().insert(pair);
            DeclScal*entry = new DeclScal("declscal");
        }
        else if(operation == "popscal"){
            PopScal*entry = new PopScal(operation, var);
            instbuffer.push_back(entry);
        }
        else if(operation == "poparr"){
            PopArr*entry = new PopArr(operation, var);
            instbuffer.push_back(entry);
        }
        else if(operation == "pushscal"){
            PushScal*entry = new PushScal(operation, var);
            instbuffer.push_back(entry);
        }
        else if(operation == "pusharr"){
            PushArr*entry = new PushArr(operation, var);
            instbuffer.push_back(entry);
        }
    }
    else if (std::find(std::begin(varLenPrimaryinsts2), std::end(varLenPrimaryinsts2),operation) != std::end(varLenPrimaryinsts2)){
       int idx = line.find_first_of(" ");
       string var = line.substr(idx+1,1);
       int length = std::stoi(line.substr(idx+2));
    //    cout<<var<<endl<<length;
        if(operation == "declarr"){
            TableEntry* data;
            if(symTable.size() == 1){ 
                data = new TableEntry(count_gbv, length);
                count_gbv += length;
            }
            else{
                data = new TableEntry(count_v + count_gbv, length);
                count_v += length;
            }
            std::pair<std::string, TableEntry*> pair;  
            pair.first = var;
            pair.second = data;
            symTable.back().insert(pair);
            DeclArr*entry = new DeclArr("declarr");
        }
    }
    else if (std::find(std::begin(labelPrimaryinsts), std::end(labelPrimaryinsts),operation) != std::end(labelPrimaryinsts)){
       int idx = line.find_first_of(" ");
       string label = line.substr(idx+1, line.length());
       if(operation == "label"){
            TableEntry* data = new TableEntry(instbuffer.size(), 0);
            std::pair<std::string, TableEntry*> pair;
            pair.first = label;
            pair.second = data;
            symTable.back().insert(pair);
            Label*entry = new Label("label");

        }
        else if(operation == "jump"){
            Jump*entry = new Jump("jump", label);
            instbuffer.push_back(entry);
        }
        else if(operation == "jumpzero"){
            JumpZero*entry = new JumpZero("jumpzero", label);
            instbuffer.push_back(entry);
        }
        else if(operation == "jumpnzero"){
            JumpNZero*entry = new JumpNZero("jumpnzero", label);
            instbuffer.push_back(entry);
        }
        else if(operation == "gosub"){
            GoSub*entry = new GoSub("gosub", label);
            instbuffer.push_back(entry);
        }
        else if(operation == "gosublabel"){
            ibloc = instbuffer.size();
            TableEntry* data = new TableEntry(instbuffer.size(), 0);
            std::pair<std::string, TableEntry*> pair;
            GoSubLabel*entry = new GoSubLabel("gosublabel", label);
            instbuffer.push_back(entry);
            pair.first = label;
            pair.second = data;
            symTable.back().insert(pair);
            std::map<std::string, TableEntry*> subroutine;
            symTable.push_back(subroutine);
            count_v = 0;
        }
    }
    else if (std::find(std::begin(intPrimaryinsts), std::end(intPrimaryinsts),operation) != std::end(intPrimaryinsts)){
    int idx = line.find_first_of(" ");
    int arg = std::stoi(line.substr(idx+1,line.length()));
    if(operation == "pushi"){
            PushI*entry = new PushI("pushi", arg);
            instbuffer.push_back(entry);
        }
    }
    else if (std::find(std::begin(strPrimaryinsts), std::end(strPrimaryinsts),operation) != std::end(strPrimaryinsts)){
    int idx = line.find_first_of(" ");
    string str = line.substr(idx+1);
    if(operation == "prints"){
            strbuffer.push_back(str);
            Prints* entry = new Prints("prints", strbuffer.size()-1); 
            instbuffer.push_back(entry);    
        }
    }
}

int main(int argc, char **argv) {
    
    if(argc != 2){
        cerr << "Incorrect number of arguments\n";
        return -1;
    }
    fstream inputfile;
    ofstream outputfile;
    string newname = argv[1];
    newname += ".pout";
    std::string line;
    inputfile.open(argv[1]);
    string error_line = ErrorCheck(argv[1]);

    if(inputfile.is_open()){
        int instructionBufferCount = 0;
        int endHit = 0;
        while(getline(inputfile, line)){
        if (ERROR_FLAG == false){
        ParseStatement(line);
        }
        else{
                outputfile.open(newname);
                cout<<error_line<<endl;
                outputfile<<error_line;
                outputfile.close();
                inputfile.close();
                return -1;
            }
        }
        outputfile.open(newname);
        int tempsize = strbuffer.size();
        for (int i=0; i<tempsize;i++){
            outputfile<<strbuffer[i]<<endl;
            cout<<strbuffer[i]<<endl;
        }
        int size = instbuffer.size();
        for(int i=0; i<size;i++){
         outputfile<<instbuffer[i]->print()<<endl;
         cout<<instbuffer[i]->print()<<endl; 
        }
        inputfile.close();
    }
    else cout << "Not able to open the file\n";
    return -1;
}

