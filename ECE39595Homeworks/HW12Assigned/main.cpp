#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "TA.h"

int main(int argc, char** args) {
  std::cout << "Creating a new Student" << std::endl;
  Student* student = new Student(999999999, 7655551212, 12.0, 4); 
  
  std::cout << "\nCreating a new Teacher" << std::endl;
  Teacher* teacher = new Teacher(888888888, 7655551212, 729, 2); 

  std::cout << "\nCreating a new TA" << std::endl;
  TA* ta = new TA(777777777, 7655551212, 729, 2, 12.0, 4); 
}
