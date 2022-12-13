#include <iostream>
#include "Person.h"
#include "Teacher.h"

Teacher::Teacher(long _SSN, long _phone, double _contactHours, int _coursesTaught) : Person(_SSN, _phone), contactHours(_contactHours), coursesTaught(_coursesTaught)/* need to add initializer and constructor calls here */ {                                
   
   std::cout << "Teacher" << std::endl;
}

double Teacher::getContactHours( ) {
   return contactHours;
}

void Teacher::setContactHours(double _contactHours) {
   contactHours = _contactHours;
}

int Teacher::getCoursesTaught( ) {
   return coursesTaught;
}

void Teacher::setCoursesTaught(int _coursesTaught) {
   coursesTaught = _coursesTaught;
}
