#include "Statements.h"
using namespace std;

class Div : public Statements{
    public:
        Div(std::string _op) : Statements(_op) {opcode = OP_DIV;};
        std::string print();
};