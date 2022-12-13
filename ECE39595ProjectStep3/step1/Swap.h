#include "Statements.h"
using namespace std;

class Swap : public Statements{
    public:
        Swap(std::string _op) : Statements(_op) {opcode = OP_SWAP;};
        std::string print();
};