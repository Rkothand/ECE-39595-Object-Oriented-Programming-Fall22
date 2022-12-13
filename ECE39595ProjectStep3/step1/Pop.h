#include "Statements.h"
using namespace std;

class Pop : public Statements{
    public:
        Pop(std::string _op) : Statements(_op) {opcode = OP_POP;};
        std::string print();
};