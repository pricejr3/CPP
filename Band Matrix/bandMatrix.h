#include <stdexcept>

class bandMatrix
{
private:
	int m_size;
	double *array;
	int numberOfElements;
	int numberOfRows;
 
public:

	

	~bandMatrix(void) {
   	
	

	}

	bandMatrix(int size) { 

	if( size <= 0){
	throw std::invalid_argument( "ERROR! Can't create a matrix with a negative size!" );
 	 }


	 numberOfRows = size;

  	numberOfElements = ((size - 2) * 3) + 4;

  	// Array for representing the band matrix:
 	 array = new double[numberOfElements];

	m_size = size; 
	
	}

 
	friend bandMatrix operator+(const bandMatrix &c1, const bandMatrix &c2);
 
	double get(int, int);
	void set(int, int, double);
 
	int size() const { return m_size; }
};
