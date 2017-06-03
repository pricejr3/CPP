#include <stdio.h>

// Define Swap Here

 void swap(int *aaa, int *bbb){

  int tempVal;
  tempVal = *aaa;
  *aaa = *bbb;
  *bbb = tempVal;
  


}
int main() 
{
       

	int aaa = 6; 
	int bbb = 11;

    int *ptr;      // The int pointer.
	ptr = &aaa;

     *ptr = 20;

	 ptr = &bbb;
	 *ptr = -15;
         



	// print out the value of pointer and value pointed by pointer
    printf("%X\n", ((unsigned int)ptr)); // value of pointer
	printf("%d\n", *ptr); // value pointed by pointer


	swap(&aaa, &bbb);

    printf("aaa is now: ");
	printf("%d\n", aaa);
	printf("bbb is now: ");
    printf("%d\n", bbb);

	return 0;
}