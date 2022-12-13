#include <iostream>
#include <fstream>
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

vector<Statements*> instmem;
vector<std::string> strbuffer;

void ParseInst(string line){

    int idx = line.find_first_of(" ");
    string command1 = line.substr(0,idx);
 
    if(command1 == "Start")
    { 
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        Start* entry = new Start("Start", temp);
        instmem.push_back(entry);

    }

    else if(command1 == "End")
    
    {
        End* entry = new End(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Exit")
    
    {
        Exit* entry = new Exit(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Return")
    
    {
        Return* entry = new Return(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Add")
    
    {
        Add* entry = new Add(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Mul")
    
    {
        Mul* entry = new Mul(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Div")
    
    {
        Div* entry = new Div(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Negate")
    
    {
        Negate* entry = new Negate(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Pop")
    
    {
        Pop* entry = new Pop(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Dup")
    {
        Dup* entry = new Dup(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "Swap")
    {
        Swap* entry = new Swap(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "PrintTOS")
    {
        PrintTOS* entry = new PrintTOS(command1);
        instmem.push_back(entry);
    }

    else if(command1 == "PopScalar")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        PopScal* entry = new PopScal(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "PushScalar")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        PushScal* entry = new PushScal(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "PopArray")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        PopArr* entry = new PopArr(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "PushArray")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        PushArr* entry = new PushArr(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "PushI")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        PushI* entry = new PushI(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "Prints")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));
        Prints* entry = new Prints(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "Jump")
    {
       int idx = line.find_first_of(" ");
       int temp = std::stoi(line.substr(idx+1));
       Jump* entry = new Jump(command1, temp);
       instmem.push_back(entry);
    }

    else if(command1 == "GoSub")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));;
        GoSub* entry = new GoSub(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "GoSubLabel")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+2));;
        GoSubLabel* entry = new GoSubLabel(command1, temp);
        instmem.push_back(entry);
    }
   
    else if(command1 == "JumpZero")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));;
        JumpZero* entry = new JumpZero(command1, temp);
        instmem.push_back(entry);
    }

    else if(command1 == "JumpNZero")
    {
        int idx = line.find_first_of(" ");
        int temp = std::stoi(line.substr(idx+1));;
        JumpNZero* entry = new JumpNZero(command1, temp);
        instmem.push_back(entry);
    }

    else
    strbuffer.push_back(line);
    
}

int counter = 0;
vector<int> mem_stack;
vector<int> add_stack;
vector<int*> data_mem;

void compute_inst(Statements* inst){
    string command1 = (*inst).operator_;

    if(command1 == "Start")
    {
        Start* temp_Start = static_cast<Start*>(inst);
        int* temp = new int((*temp_Start).count);
        data_mem.push_back(temp);
        counter += 1;
    }

    else if(command1 == "Exit")
    {
        counter += 1;
    }

    else if(command1 == "Add")
    {
        int temp1 = mem_stack.back();
        mem_stack.pop_back();
        int temp2 = mem_stack.back();
        mem_stack.pop_back();
        int result = temp1 + temp2;
        mem_stack.push_back(result);
        counter += 1;
    }

    else if(command1 == "Div")
    {
        int temp1 = mem_stack.back();
        mem_stack.pop_back();
        int temp2 = mem_stack.back();
        mem_stack.pop_back();
        int result = temp2 / temp1;
        mem_stack.push_back(result);
        counter += 1;
    }

    else if(command1 == "Dup")
    {
        int temp = mem_stack.back();
        mem_stack.push_back(temp);
        counter += 1;
    }

    else if(command1 == "Mul")
    {
        int temp1 = mem_stack.back();
        mem_stack.pop_back();
        int temp2 = mem_stack.back();
        mem_stack.pop_back();
        int result = temp1 * temp2;
        mem_stack.push_back(result);
        counter += 1;
    }

    else if(command1 == "Negate")
    {
        int temp = mem_stack.back();
        mem_stack.pop_back();
        int result = temp *-1;
        mem_stack.push_back(result);
        counter += 1;
    }

    else if(command1 == "Pop")
    {
        mem_stack.pop_back();
        counter += 1;
    }

    else if(command1 == "Swap")
    {
        int temp1 = mem_stack.back();
        mem_stack.pop_back();
        int temp2 = mem_stack.back();
        mem_stack.pop_back();
        mem_stack.push_back(temp1);
        mem_stack.push_back(temp2);
        counter += 1;
    }

    else if(command1 == "Jump")
    {
        Jump* temp_Jump = static_cast<Jump*>(inst);
        counter = (*temp_Jump).loc;
    }

    else if(command1 == "GoSub")
    {
        add_stack.push_back(counter + 1);
        GoSub* temp_GoSub = static_cast<GoSub*>(inst);
        counter = (*temp_GoSub).loc;
    }

    else if(command1 == "GoSubLabel")
    {
        GoSubLabel* temp_GoSubLabel = static_cast<GoSubLabel*>(inst);
        int* temp = new int((*temp_GoSubLabel).size);
        data_mem.push_back(temp);
        counter += 1;
    }

    else if(command1 == "Return")
    {
        Return* temp_Return = static_cast<Return*>(inst);
        counter = add_stack.back();
        add_stack.pop_back(); 
        data_mem.pop_back();
    }

    else if(command1 == "PushI")
    {
        PushI* temp_PushI= static_cast<PushI*>(inst);
        mem_stack.push_back((*temp_PushI).temp);
        counter += 1;
    }

    else if(command1 == "Prints")
    {
        Prints* temp_Prints = static_cast<Prints*>(inst);
        cout << strbuffer[(*temp_Prints).strocr] << std::endl;
        counter += 1;
    }

    else if(command1 == "PrintTOS")
    {
        int temp = mem_stack.back();
        mem_stack.pop_back();
        cout << temp << std::endl;
        counter += 1;
    }

    else if(command1 == "PopScalar")
    {
        PopScal* temp_PopScal = static_cast<PopScal*>(inst);
        int temp = mem_stack.back();
        mem_stack.pop_back();
        data_mem.back()[(*temp_PopScal).loc] = temp;
        counter += 1;
    }

    else if(command1 == "PushScalar")
    {
        PushScal* temp_PushScal = static_cast<PushScal*>(inst);
        int temp = data_mem.back()[(*temp_PushScal).loc];
        mem_stack.push_back(temp);
        counter += 1;
    }
    
    else if(command1 == "PopArray")
    {
        PopArr* temp_PopArr = static_cast<PopArr*>(inst);
        int idx = mem_stack.back();
        mem_stack.pop_back();
        int t_idx = idx + (*temp_PopArr).loc;
        int temp = mem_stack.back();
        mem_stack.pop_back();
        data_mem.back()[t_idx] = temp;
        counter += 1;
    }

    else if(command1 == "PushArray")
    {
        PushArr* temp_PushArr = static_cast<PushArr*>(inst);
        int temp = (*temp_PushArr).loc + mem_stack.back();
        mem_stack.pop_back();
        mem_stack.push_back(data_mem.back()[temp]);
        counter += 1;
    }

    else if(command1 == "JumpZero")
    {
        JumpZero* temp_JumpZero = static_cast<JumpZero*>(inst);
        int temp = mem_stack.back();
        mem_stack.pop_back();
        if(temp == 0)
        counter = (*temp_JumpZero).loc;
        else
        counter += 1;
    
    }

    else if(command1 == "JumpNZero")
    {
        JumpNZero* temp_JumpNZero = static_cast<JumpNZero*>(inst);
        int temp = mem_stack.back();
        mem_stack.pop_back();
        if(temp != 0)
        counter = (*temp_JumpNZero).loc;
        else 
        counter += 1;
    }
}

int main(int argc, char **argv){
    if(argc != 2){
        cerr << "Incorrect number of arguments\n";
        return 0;
    }
    fstream inputfile;
    string line;
    inputfile.open(argv[1]);

    if(inputfile.is_open()){
        int instuctionBufferCount = 0;
        int endHit = 0;
        while(getline(inputfile, line)){
        ParseInst(line);
        }
        int size = instmem.size();
        for(int i=0; i<size;i=counter){
            // cout<<counter<<endl;
         compute_inst(instmem[i]); 
        }
        inputfile.close();
    }
    else cout << "Not able to open the file\n";
    return -1;
    

}