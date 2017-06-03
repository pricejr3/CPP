#include <stdio.h>


void array_op(int *first, int *second, int N , int M)
{
	// If M, the source, is larger than or equal to N, the destination,
	// it sets the values of the source to the values of N.
	if ( M >= N){
		for(int i = 0; i < N; i++){

			*(first + i) = *(second + i);
		}
	}

	// If M, the source, is smaller N, the destination,
	// it sets the values of the destination to the values of N.
	if( N > M){
		for(int i = 0; i < M; i++){

			 *(first + i) = *(second + i);
		}
		for(int i = M; i < N; i++){

			 *(first + i) = *(first + i);
		}
	}
} // END array_op


int main() 
{
	printf("New Test below for N > M \n ");
	printf("EXPECTING: 6 7 7 4 \n ");
	// Test for when N is greater than M
	int arr_N[] = {1, 2, 7, 4};
	int arr_M[] = {6, 7};
	array_op(arr_N, arr_M, 4, 2);
	printf("RESULT: ");
	for (int i = 0; i < 4; i++)
    printf("%d ", arr_N[i]);
	printf("\n ");
	// EXPECTING: 6 7 7 4
	// RESULT:    6 7 7 4
	// PASS


	printf("New Test below for equality \n ");
	printf("EXPECTING: 6 7 8 \n ");
	
	int arr_N1[] = {1, 2, 7};
	int arr_M1[] = {6, 7, 8};
	array_op(arr_N1, arr_M1, 3, 3);
	printf("RESULT: ");
	for (int i = 0; i < 3; i++)
    printf("%d ", arr_N1[i]);
	printf("\n ");
	// EXPECTING: 6 7 8
	// RESULT:    6 7 8
	// PASS

	printf("New Test below for M > N \n ");
	printf("EXPECTING: 2 4 \n ");
	
	int arr_N2[] = {1, 5};
	int arr_M2[] = {2, 4, 8, 7};
	array_op(arr_N2, arr_M2, 2, 4);
	printf("RESULT: ");
	for (int i = 0; i < 2; i++) 
    printf("%d ", arr_N2[i]);
	printf("\n ");
	// EXPECTING: 2 4
	// RESULT:    2 4
	// PASS
	
	






	return 0;
}