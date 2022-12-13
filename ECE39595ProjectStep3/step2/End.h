#include "Statements.h"


class End: public Statements{
    public:
        End(std::string _op) : Statements(_op) {opcode = 0;};
        std::string print();
};