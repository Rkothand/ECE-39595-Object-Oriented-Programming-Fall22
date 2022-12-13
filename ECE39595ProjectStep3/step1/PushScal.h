#include "Statements.h"
using namespace std;

class PushScal: public Statements{
    public:
        int loc = -1; 
        std::string var;
        PushScal(std::string _op, std::string _var) : Statements(_op) {opcode = OP_PUSHSCALAR; var = _var; loc = -1;};
        std::string print();

};