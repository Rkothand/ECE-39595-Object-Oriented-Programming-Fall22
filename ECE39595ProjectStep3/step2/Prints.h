#include "Statements.h"
using namespace std;

class Prints: public Statements{
    public:
        int strocr;
        Prints(std::string _op, int _strocr) : Statements(_op) {opcode = OP_PUSHI; strocr = _strocr;};
        std::string print();
};