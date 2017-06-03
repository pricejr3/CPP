#include <iostream>
#include "bandMatrix.h"
#include <stdexcept>

#include <iostream>


using namespace std;
 
 


bandMatrix operator+(const bandMatrix &c1, const bandMatrix &c2)
{

	int mat1Size =  c1.numberOfElements;
   	int mat2Size =  c2.numberOfElements;

  	
  
   	if(mat1Size != mat2Size){
	
		throw std::invalid_argument( "The sizes are not the same, so we cannot add them!" );
	
 	 }


	// We can now create the bandMatrix
	bandMatrix newMatrix(mat1Size);

	for(int i = 0; i < mat1Size; i++){

		double val1 = c1.array[i];
		double val2 = c2.array[i];

	newMatrix.array[i] = val1 + val2;


  }
	
	return newMatrix;
}


void bandMatrix::set(int idx1, int idx2, double value){
	

	bool inBounds = false;

	
	if(idx1 < 0 || idx2 < 0){

		throw std::invalid_argument( "ERROR! Attempting to set an negative position on board!" );

	}

	if((idx1 == 0 && idx2 == 0) || (idx1 == 0 && idx2 == 1 ) ){

		inBounds = true;
		
	}

	int one = 0;
	int two = 1;
	int three = 2;

	for(int i = 1; i < numberOfRows - 1; i++){
		
		if((idx1 == i && idx2 == one) || (idx1 == i && idx2 == two) || (idx1 == i && idx2 == three) ){
			inBounds = true;
			break;
		}
		one++;
		two++;
		three++;


	}

	if((idx1 == numberOfRows - 1  && idx2 == numberOfRows - 2) || (idx1 == numberOfRows - 1 && idx2 == numberOfRows - 1 ) ){
		
		
		inBounds = true;
		
	}


	if(inBounds == false){

		throw std::invalid_argument( "ERROR! Attempting to set an INVALID POSITION" );

	}

	
	if(inBounds == true){

		array[((2 * idx1) + idx2)] = value;

	}


}

double bandMatrix::get(int idx1, int idx2){

	bool inBounds = false;

	
	if(idx1 < 0 || idx2 < 0){

		throw std::invalid_argument( "ERROR! Attempting to set an negative position on board!" );

	}

	if((idx1 == 0 && idx2 == 0) || (idx1 == 0 && idx2 == 1 ) ){

		inBounds = true;
		
	}

	int one = 0;
	int two = 1;
	int three = 2;
	double theValue;

	for(int i = 1; i < numberOfRows - 1; i++){
		
		if((idx1 == i && idx2 == one) || (idx1 == i && idx2 == two) || (idx1 == i && idx2 == three) ){
			inBounds = true;
			break;
		}
		one++;
		two++;
		three++;


	}

	if((idx1 == numberOfRows - 1  && idx2 == numberOfRows - 2) || (idx1 == numberOfRows - 1 && idx2 == numberOfRows - 1 ) ){
		
		
		inBounds = true;
		
	}


	if(inBounds == false){

		throw std::invalid_argument( "ERROR! Attempting to set an INVALID POSITION" );

	}

	
	if(inBounds == true){

		theValue = array[((2 * idx1) + idx2)];
	
}

	return theValue;
}



 
