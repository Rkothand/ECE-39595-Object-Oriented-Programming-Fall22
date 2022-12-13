#include "Statements.h"
using namespace std;


class Negate : public Statements{
    public:
        Negate(std::string _op) : Statements(_op) {opcode = OP_NEGATE;};
        std::string print();
};