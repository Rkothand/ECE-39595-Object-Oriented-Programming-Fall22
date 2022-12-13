#ifndef STUDENT_H_
#define STUDENT_H_
#include "Person.h"

class Student : public Person {
private:
   double credits;
   int coursesTaken;
public:
   Student(long _SSN, long _phone, double _credits, int _coursesTaken);
   virtual double getCredits( );
   virtual void setCredits(double _credits);
   virtual int getCoursesTaken( );
   virtual void setCoursesTaken(int _coursesTaken);
};
#endif /* STUDENT_H_ */
