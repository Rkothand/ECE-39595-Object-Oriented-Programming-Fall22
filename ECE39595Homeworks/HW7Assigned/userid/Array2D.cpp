#include <iostream>
#include <cstdlib>
#include "Array2D.h"

// This constructor is delegated to by other constructors and does all of the 
// allocation, showing an example of a delegating constructor..  
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {

   ary = new int*[numRows];
   for (int i = 0; i < numRows; i++) {
      ary[i] = new int[numCols];
      for (int j = 0; j < numCols; j++) {
            ary[i][j] = -1;
      }
   }
}

Array2D::Array2D(int numR, int numC) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }
}

Array2D::Array2D(int numR, int numC, int val) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = val;
      }
   }
}

int& Array2D::operator( )(int row, int col) {
   return ary[row][col];
}
      
int Array2D::operator( )(int row, int col) const {
   return ary[row][col];
}

bool Array2D::sameSize(const Array2D& other) const  {
   return (numRows == other.getNumRows( ) && numCols == other.getNumCols( ));
}

void Array2D::deleteAry(int** ary) {
   for (int k = 0; k < numRows; k++) {
      delete [ ] ary[k];
   }
   delete [ ] ary;
}

Array2D::~Array2D()
{
   this->deleteAry(this->ary);
}

int Array2D::getNumRows() const
{
   return numRows;
}

int Array2D::getNumCols() const
{
   return numCols;
}

Array2D::Array2D(const Array2D& array): Array2D(array.getNumRows(), array.getNumCols(), 'c'){
   for(int l = 0; l < numRows; l++){
      for(int m = 0; m < numCols; m++){
         ary[l][m] = array(l,m);
      }
   }
}

Array2D& Array2D::operator=(const Array2D& array){
   numCols = array.numCols;
   numRows = array.numRows;

   this->deleteAry(ary);
   ary = new int*[array.numRows];

   for(int n = 0; n< numRows; n++){
      ary[n] = new int[array.numCols];
      for(int o = 0; o<numCols; o++){
         ary[n][o] =array(n,o);
      }
   }
   return *this;
}

bool Array2D::operator==(const Array2D& other){
   if(this->sameSize(other) != true){
   return false;
   }
   for(int p = 0; p< this->getNumRows();p++){
      for(int q = 0;q<this->getNumCols();q++){
         if(ary[p][q] != other(p,q)){
            return false;
         }
      }
   }
   return true;
}

Array2D Array2D::operator*(const Array2D& array)
{
   if(numCols != array.getNumRows()){
      Array2D num(this->getNumRows(),this->getNumCols(),-1);
      return num;
   }
   Array2D num(this->getNumRows(),array.getNumCols(),0);
   for(int r = 0; r < this->getNumRows();r++){
      for(int s = 0; s < array.getNumCols();s++){
         for(int t = 0; t<array.getNumRows();t++){
            num(r,s) += ary[s][t]*array(t,s);
         }
      }
   }
   return num;
}

std::ostream& operator<<(std::ostream& ostream, const Array2D& array)
{
   for(int u = 0;u<array.getNumRows();u++){
      for(int v = 0;v<array.getNumCols();v++){
         ostream << (array(u,v)) << " ";
      }
      ostream << std::endl;
   }
   return ostream;
}