#include "Statements.h"
using namespace std;

class PushArr: public Statements{
    public:
        std::string var;
        int loc= 0; 
        PushArr(std::string _op, int _loc) : Statements(_op) {opcode = OP_PUSHARRAY; loc = _loc;};
        std::string print();

};