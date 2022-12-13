#ifndef DATABIN_H_
#define DATABIN_H_
class DataBin {
public:
   DataBin(int _datum); 
   virtual ~DataBin( ); 
   virtual int getDatum( );
private:
   int* datum;
};
#endif /* DATABIN_H_ */
