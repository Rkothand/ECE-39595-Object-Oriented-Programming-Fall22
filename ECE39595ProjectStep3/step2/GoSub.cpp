#include "GoSub.h"
using namespace std;

std::string GoSub::print(){
    return "GoSub " + label + "(" + to_string(loc) + ")";
}