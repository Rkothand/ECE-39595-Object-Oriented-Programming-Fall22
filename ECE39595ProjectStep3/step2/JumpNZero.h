#include "Statements.h"
using namespace std;

class JumpNZero : public Statements{
    public:
        std::string label;
        int loc;
        JumpNZero(std::string _op, int _loc) : Statements(_op) {opcode = OP_JUMPNZERO;  loc = _loc;};
        std::string print();
};