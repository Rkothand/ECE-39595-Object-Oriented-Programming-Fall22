#include "Statements.h"
using namespace std;

class PopScal: public Statements{
    public:
        std::string var;
        int loc = 0; 
        PopScal(std::string _op, int _loc) : Statements(_op) {opcode = OP_POPSCALAR; loc = _loc;};
        std::string print();

};