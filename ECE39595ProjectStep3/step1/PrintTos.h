#include "Statements.h"
using namespace std;

class PrintTOS : public Statements{
    public:
        PrintTOS(std::string _op) : Statements(_op) {opcode = OP_PRINTTOS;};
        std::string print();
};