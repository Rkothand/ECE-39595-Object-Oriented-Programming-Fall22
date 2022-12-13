#include "Statements.h"
using namespace std;

class GoSubLabel : public Statements{
    public:
        std::string label;
        int size;
        GoSubLabel(std::string _op, std::string _label) : Statements(_op) {opcode = OP_ENTER_SUBROUTINE; label = _label; size = -1;};
        std::string print();
};