#include "Statements.h"
using namespace std;


class Label: public Statements{
    public:
        Label(std::string _op) : Statements(_op) {opcode = -1;};
        std::string print();
};