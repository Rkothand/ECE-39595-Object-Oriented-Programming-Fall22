#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
class Array2D {

public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 
   Array2D(const Array2D& other); 

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;

   virtual int getNumRows() const;
   virtual int getNumCols() const;
   virtual Array2D operator* (const Array2D& other);
   virtual Array2D& operator = (const Array2D& other);
   virtual bool operator==(const Array2D& other);
   ~Array2D();

private:
   int numRows;
   int numCols;
   int** ary;
   
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other) const;
};

std::ostream& operator<<(std::ostream& stream, const Array2D& other);

#endif /* ARRAY2D_H_ */
