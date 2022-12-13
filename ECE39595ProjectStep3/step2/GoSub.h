#include "Statements.h"
using namespace std;

class GoSub : public Statements{
    public:
        std::string label;
        int loc;
        GoSub(std::string _op, int _loc) : Statements(_op) {opcode = OP_GOSUB; loc = _loc;};
        std::string print();
};
