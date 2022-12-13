#include "Statements.h"
using namespace std;

class JumpNZero : public Statements{
    public:
        std::string label;
        int loc;
        JumpNZero(std::string _op, std::string _label) : Statements(_op) {opcode = OP_JUMPNZERO; label = _label; loc = -1;};
        std::string print();
};