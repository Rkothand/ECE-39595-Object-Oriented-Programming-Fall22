#include "Statements.h"
using namespace std;


class Mul : public Statements{
    public:
        Mul(std::string _op) : Statements(_op) {opcode = OP_MUL;};
        std::string print();
};

