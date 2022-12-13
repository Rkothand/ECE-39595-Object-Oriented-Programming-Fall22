#include "Statements.h"
using namespace std;

class Jump : public Statements{
    public:
        std::string label;
        int loc;
        Jump(std::string _op, int _loc) : Statements(_op) {opcode = OP_JUMP; loc = _loc;};
        std::string print();
};