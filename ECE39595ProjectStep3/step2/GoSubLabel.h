#include "Statements.h"
using namespace std;

class GoSubLabel : public Statements{
    public:
        std::string label;
        int size;
        GoSubLabel(std::string _op, int _size) : Statements(_op) {opcode = OP_ENTER_SUBROUTINE; size = _size;};
        std::string print();
};