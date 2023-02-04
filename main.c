// Dynamically allocating a struct from a function that has a dynamically allocated array in it
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct BigInteger{
  int* digits;
  int size;
};

struct BigInteger * createRandomBigInt(int numdigits){
  // creating a struct pointer and allocating memory of 1 single block
  struct BigInteger *bi = (struct BigInteger *)malloc(sizeof(struct BigInteger));
  // accessing the pointer structure member "digits" and allocating an array of int digits, with the size depending on user input 
  bi->digits = (int *)malloc(numdigits*sizeof(int));
  bi->size = numdigits; // accessing struct member size and setting it to user input we passed in

  // 
  bi->digits[numdigits-1] = 1+rand()%9; // accessing last element of our array of digits and making sure it isnt a 0 (1-9)
  // for loop to fill the rest of the digits up in the BigInteger array
  for(int i = 0; i<numdigits-1; i++)
    bi->digits[i] = rand()%10;

  return bi;
}

//function to print digits
void displayDigits(struct BigInteger *b);

// function that releases the memory of our DMA
void releaseMemory(struct BigInteger *m){
  free(m->digits);
  free(m);
}

// driver function
int main(void) {
  int n;

  printf("How many digits? ");
  scanf("%d", &n);

  // create a structure that can hold array of int with the size depending on user input
  struct BigInteger *mybi = createRandomBigInt(n);

  displayDigits(mybi);

  releaseMemory(mybi);
  
  return 0;
}


void displayDigits(struct BigInteger *b){
  printf("The digits of the big integer: \n");

  // traverse through our array of int and print each element in the array
  for(int i = 0; i<b->size; i++)
    printf("%d", b->digits[i]);
}