#include <stdio.h>



void interleaving(int *destination, int *source, int M , int N)
{


	int j = 0;
	int remainDest = M - N;
	int remainDest2 = N - M;

	// Initialize the copy array.
	int *copyArray = new int[M];
	int *copyArray2 = new int[N];

	// Copy values from the destination1 into COPY ARRAY. 
	for(int i = 0; i < M; i++){
		*(copyArray + i) = *(destination + i);
	}

	
	for(int i = 0; i < N; i++){
		*(copyArray2 + i) = *(source + i);
	}

	//////////////////////////////////////////////////////// END COPY VALUES

	// If M and N have the same values
	if( M == N){

		
	
		for(int i = 0; i < ((M + N)/2); i++){

			*(destination + j ) = *(copyArray + i);
			*(destination + j + 1) = *(source + i);

			j+=2; // Increment for destination count
		}
	}

	/////////////////////////////////////////////////////////

	// if source < destination
	if( N < M){

		
	
		for(int i = 0; i < ((M + N-1)/2); i++){

			*(destination + j ) = *(copyArray + i);
			*(destination + j + 1) = *(source + i);

			j+=2; // Increment for destination count
		}

		for(int i = 0; i < remainDest; i++){

			*(destination + j ) = *(copyArray + (N + i));
			j++;

		}
	}// END SOURCE < DEST


	/////////////////////////////////////////////////////////

	// if DEST < SOURCE
	if( M < N){

		
	
		for(int i = 0; i < ((M + N-1)/2); i++){

			*(destination + j ) = *(copyArray + i);
			*(destination + j + 1) = *(source + i);

			j+=2; // Increment for destination count
		}

		for(int i = 0; i < remainDest2; i++){

			*(destination + j ) = *(copyArray2 + (M + i));
			j++;

		}

		
	}// END DEST < SOURCE

} // END FUNCTION
		
		










int main() 
{
	int destination[] = {8, 9, 7};
	int source[] = {1, 2, 6};
	// FOR REFERENCE:
	// M is source (FIRST), N is destination(second)
	// void array_op(int *first, int *second, int M , int N){
	printf("Testing equally sized destination and source arrays");
	printf("\n ");
	printf("Expecting: 8 1 9 2 7 6");
	printf("\n ");
	interleaving(destination, source, 3, 3);
	printf("THE RESULT: ");
	printf("\n ");
	for (int i = 0; i < 6; i++) 
    printf("%d ", destination[i]);
	printf("\n ");

	///////////////////////// SOURCE < DEST

	printf("Testing source < dest");
	int destination1[] = {4, 3, 6, 8};
	int source1[] = {1, 2, 99};
	printf("\n ");
	printf("Expecting: 4 1 3 2 6 99 8");
	printf("\n ");
	interleaving(destination1, source1, 4, 3);
	printf("THE RESULT:  ");
	printf("\n ");
	for (int i = 0; i < 7; i++) 
    printf("%d ", destination1[i]);
	printf("\n ");





	///////////////////////// DEST < SOURCE

	printf("Testing dest < source");
	int destination2[] = {2, 4, 5};
	int source2[] = {1, 2, 99, 44, 2};
	printf("\n ");
	printf("Expecting: 2 1 4 2 5 99 44 2");
	printf("\n ");
	interleaving(destination2, source2, 3, 5);
	printf("THE RESULT: 2 1 4 2 5 99 44 2  ");
	printf("\n ");
	for (int i = 0; i < 8; i++) 
    printf("%d ", destination2[i]);
	printf("\n ");


	return 0;
}