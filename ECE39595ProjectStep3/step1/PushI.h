#include "Statements.h"
using namespace std;

class PushI: public Statements{
    public:
        int arg;
        PushI(std::string _op, int _arg) : Statements(_op) {opcode = OP_PUSHI; arg = _arg;};
        std::string print();
};