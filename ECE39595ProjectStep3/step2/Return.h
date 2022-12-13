#include "Statements.h"


class Return : public Statements{
    public:
        Return(std::string _op) : Statements(_op) {opcode = OP_RETURN;};
        std::string print();
};
