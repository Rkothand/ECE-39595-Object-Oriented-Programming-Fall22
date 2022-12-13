#include "Statements.h"


class End: public Statements{
    public:
        End(std::string _op) : Statements(_op) {opcode = -1;};
        std::string print();
};