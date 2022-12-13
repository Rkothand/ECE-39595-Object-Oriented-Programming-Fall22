#include "Statements.h"
using namespace std;

class Start : public Statements{
    public:
        int numVars = -1; 
        Start(std::string _op) : Statements(_op) {opcode = OP_START_PROGRAM;};
        std::string print();

};