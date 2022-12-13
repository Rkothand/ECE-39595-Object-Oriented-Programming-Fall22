#include "Statements.h"
using namespace std;

class JumpZero : public Statements{
    public:
        std::string label;
        int loc;
        JumpZero(std::string _op, int _loc) : Statements(_op) {opcode = OP_JUMPZERO; loc = _loc;};
        std::string print();
};