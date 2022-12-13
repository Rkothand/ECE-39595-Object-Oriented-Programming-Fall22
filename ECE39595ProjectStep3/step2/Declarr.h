#include "Statements.h"
using namespace std;

class DeclArr : public Statements{
    public:
        DeclArr(std::string _op) : Statements(_op) {opcode = 0;};
        std::string print();
};