#include <iostream> 
#include "Person.h"
#include "Student.h"

Student::Student(long _SSN, long _phone, double _credits, int _coursesTaken) : Person(_SSN, _phone), credits(_credits), coursesTaken(_coursesTaken)/* need to add initializer and constructor calls here */ {                                
   
   std::cout << "Student" << std::endl;
}

double Student::getCredits( ) {
   return credits;
}

void Student::setCredits(double _credits) {
   credits = _credits;
}

int Student::getCoursesTaken( ) {
   return coursesTaken;
}

void Student::setCoursesTaken(int _coursesTaken) {
   coursesTaken = _coursesTaken;
}
