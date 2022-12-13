#ifndef PERSON_H_
#define PERSON_H_
class Person {
private:
   long SSN;
   long phone;
public:
   Person(long _SSN, long _phone);
   virtual long getSSN( );
   virtual void setSSN(long _SSN);
   virtual long getPhone( );
   virtual void setPhone(long _phone);
};
#endif /* PERSON_H_ */
