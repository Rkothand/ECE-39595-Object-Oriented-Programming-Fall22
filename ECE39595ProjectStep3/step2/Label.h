#include "Statements.h"
using namespace std;


class Label: public Statements{
    public:
        Label(std::string _op) : Statements(_op) {opcode = 0;};
        std::string print();
};