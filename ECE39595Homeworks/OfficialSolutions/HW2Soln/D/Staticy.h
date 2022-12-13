#ifndef STATICY_H_
#define STATICY_H_
class Staticy {
public:
   static Staticy* makeStaticy(int arg);
   static int getEvenCount( );
private:
   Staticy(int arg);
   static int count;
};
#endif /* STATICY_H_ */
