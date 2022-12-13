#include "Statements.h"
using namespace std;

class DeclScal : public Statements{
    public:
        DeclScal(std::string _op) : Statements(_op) {opcode = -1;};
        std::string print();
};
