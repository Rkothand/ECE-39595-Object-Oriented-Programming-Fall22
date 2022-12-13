#include "Statements.h"
using namespace std;

class Start : public Statements{
    public:
        int count = 0; 
        Start(std::string _op, int _count) : Statements(_op) {opcode = OP_START_PROGRAM;};
        std::string print(); 

};