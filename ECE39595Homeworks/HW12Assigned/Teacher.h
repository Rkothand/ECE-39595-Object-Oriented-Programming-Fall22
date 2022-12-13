#ifndef TEACHER_H_
#define TEACHER_H_
#include "Person.h"

class Teacher : public Person {
private:
   double contactHours;
   int coursesTaught;
public:
   Teacher(long _SSN, long _phone, double _contactHours, int _coursesTaught);
   virtual double getContactHours( );
   virtual void setContactHours(double _contactHours);
   virtual int getCoursesTaught( );
   virtual void setCoursesTaught(int _coursesTaught);
};
#endif /* TEACHER_H_ */
