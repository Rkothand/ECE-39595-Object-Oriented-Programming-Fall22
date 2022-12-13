#include "Statements.h"
using namespace std;

class PushScal: public Statements{
    public:
        std::string var;
        int loc = 0; 
        PushScal(std::string _op, int _loc) : Statements(_op) {opcode = OP_PUSHSCALAR; loc = _loc;};
        std::string print();

};