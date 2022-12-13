#include "Statements.h"
using namespace std;

class PopArr: public Statements{
    public:
        std::string var;
        int loc = 0;
        PopArr(std::string _op, int _loc) : Statements(_op) {opcode = OP_POPARRAY; loc = _loc;};
        std::string print();

};