#include "Statements.h"
using namespace std;

class PushI: public Statements{
    public:
        int temp;
        PushI(std::string _op, int _temp) : Statements(_op) {opcode = OP_PUSHI; temp = _temp;};
        std::string print();
};