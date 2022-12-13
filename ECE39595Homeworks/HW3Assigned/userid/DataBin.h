#ifndef DATABIN_H_
#define DATABIN_H_
class DataBin {
public:
   DataBin(int _datum); 
   virtual int getDatum( );
   ~DataBin(){
      std::cout << "deleting DataBin " << *datum << std::endl;
      free(datum);
   }
private:
   int* datum;
   
};
#endif /* DATABIN_H_ */
