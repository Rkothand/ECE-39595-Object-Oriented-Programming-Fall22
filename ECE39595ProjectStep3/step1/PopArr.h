#include "Statements.h"
using namespace std;

class PopArr: public Statements{
    public:
        int loc = -1;
        std::string var;
        PopArr(std::string _op, std::string _var) : Statements(_op) {opcode = OP_POPARRAY; var = _var; loc = -1;};
        std::string print();

};