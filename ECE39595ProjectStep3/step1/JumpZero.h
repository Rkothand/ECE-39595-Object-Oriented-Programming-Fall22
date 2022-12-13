#include "Statements.h"
using namespace std;

class JumpZero : public Statements{
    public:
        std::string label;
        int loc;
        JumpZero(std::string _op, std::string _label) : Statements(_op) {opcode = OP_JUMPZERO; label = _label; loc = -1;};
        std::string print();
};