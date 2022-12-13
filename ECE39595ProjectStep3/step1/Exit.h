#include "Statements.h"
using namespace std;

class Exit : public Statements{
    public:
        Exit(std::string _op) : Statements(_op) {opcode = OP_EXIT_PROGRAM;};
        std::string print();
};