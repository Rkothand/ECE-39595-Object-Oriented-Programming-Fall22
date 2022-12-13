#include "Statements.h"
using namespace std;

class GoSub : public Statements{
    public:
        std::string label;
        int loc;
        GoSub(std::string _op, std::string _label) : Statements(_op) {opcode = OP_GOSUB; label = _label; loc = -1;};
        std::string print();
};
