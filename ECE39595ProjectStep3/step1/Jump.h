#include "Statements.h"
using namespace std;

class Jump : public Statements{
    public:
        std::string label;
        int loc;
        Jump(std::string _op, std::string _label) : Statements(_op) {opcode = OP_JUMP; label = _label; loc = -1;};
        std::string print();
};