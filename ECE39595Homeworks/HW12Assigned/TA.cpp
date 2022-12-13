#include <iostream>
#include "Teacher.h"
#include "Student.h"
#include "TA.h"

TA::TA(long _SSN, long _phone, double _contactHours, int _coursesTaught, double credits, int coursesTaken) : Teacher(_SSN, _phone, _contactHours, _coursesTaught), Student(_SSN, _phone, credits, coursesTaken)/* need to add initializer and constructor calls here */ { 
   
   std::cout << "TA" << std::endl;
} 
                      
