#include "Statements.h"
using namespace std;

class Add: public Statements{
    public:
        Add(std::string _op) : Statements(_op) {opcode = OP_ADD;};
        std::string print();
};