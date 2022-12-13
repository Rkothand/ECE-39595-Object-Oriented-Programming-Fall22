#include "Address.h"
#include "Person.h"
#include "Employee.h"

Employee::Employee(std::string _name, int _birthMonth, int _birthDay, int _birthYear, Address& _address, double _salary)
: Person(_name, _birthMonth, _birthDay, _birthYear, _address), 
   salary(_salary) {}

std::string Employee::getRole( ) { 
   return "Employee";
}

double Employee::getSalary( ) { 
   return salary;
}
