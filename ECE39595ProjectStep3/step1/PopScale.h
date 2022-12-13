#include "Statements.h"
using namespace std;

class PopScal: public Statements{
    public:
        int loc = -1; 
        std::string var;
        PopScal(std::string _op, std::string _var) : Statements(_op) {opcode = OP_POPSCALAR; var = _var; loc = -1;};
        std::string print();

};