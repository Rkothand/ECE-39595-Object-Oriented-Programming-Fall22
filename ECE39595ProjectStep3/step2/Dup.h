#include "Statements.h"
using namespace std;

class Dup : public Statements{
    public:
        Dup(std::string _op) : Statements(_op) {opcode = OP_DUP;};
        std::string print();
};
