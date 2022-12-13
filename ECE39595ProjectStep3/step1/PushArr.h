#include "Statements.h"
using namespace std;

class PushArr: public Statements{
    public:
        int loc = -1; 
        std::string var;
        PushArr(std::string _op, std::string _var) : Statements(_op) {opcode = OP_PUSHARRAY; var = _var; loc = -1;};
        std::string print();

};