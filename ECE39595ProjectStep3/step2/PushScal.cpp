#include "PushScal.h"
using namespace std;

std::string PushScal::print(){
    return "PushScalar " + var + ", (" + to_string(loc) + ")";
}