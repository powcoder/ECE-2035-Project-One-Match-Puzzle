https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**

Match Puzzle

This program finds the reference pattern in the candidates which might be
rotated or flipped.

*/

#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1 // RESET THIS TO 0 BEFORE SUBMITTING YOUR CODE

int main(int argc, char *argv[]) {
  int  Reference;
  int  Candidates[8];
  int  NumCandidates;
  int  Position = -9; //temporary initial value (you can change it)
  int  Load_Reference(char *);
  int  Load_Mem(char *, int *);

  if (argc != 2) {
    printf("usage: ./P1-1 testfile\n");
    exit(1);
  }
  Reference = Load_Reference(argv[1]);
  if (Reference == 0) {
    printf("Invalid Reference pattern.\n");
    exit(1);
   }
  NumCandidates = Load_Mem(argv[1], Candidates);
   if (NumCandidates != 8) {
      printf("testfiles must contain 8 candidates\n");
      exit(1);
   }

   /* Your program goes here */
  

   /* Use a statement like this to print information helpful to
      debugging (e.g., the current value of some variable).
      Set DEBUG to 1 using the #define above when debugging, but
      reset it back to 0 before submitting your code so that your
      program doesn't confuse the autograder with superfluous prints. */
   if (DEBUG){
     printf("Reference: %d == 0x%08x\n", Reference, Reference);
   }

   // your program should use this print statement to report the answer
   printf("The matching pattern is at position [0-7]: %d\n", Position);
   exit(0);
}

/* This routine reads in one integer value from the first line of a named file in the local directory (each line of the file is in the form Addr: integer). The integer is returned. */

int Load_Reference(char *InputFileName) {
  int	Reference, NumVals, Addr, Value;
  FILE	*FP;

  FP = fopen(InputFileName, "r");
  if (FP == NULL) {
    printf("%s could not be opened; check the filename\n", InputFileName);
    return 0;
  } else {
    NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
    if (NumVals == 2)
      Reference = Value;
    else {
      printf("test file must contain Addr: Value pairs on each line.\n");
      Reference = 0;
    }
    fclose(FP);
    return Reference;
   }
}

/* This routine loads in up to 8 newline delimited integers from
a named file in the local directory. The values are placed in the
passed integer array. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int IntArray[]) {
   int	N, Addr, Value, NumVals;
   FILE	*FP;

   FP = fopen(InputFileName, "r");
   if (FP == NULL) {
     printf("%s could not be opened; check the filename\n", InputFileName);
     return 0;
   } else {
     fscanf(FP, "%d: %d", &Addr, &Value); // ignore first line
     for (N=0; N < 8; N++) {
       NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
       if (NumVals == 2)
	 IntArray[N] = Value;
       else
	 break;
     }
     fclose(FP);
     return N;
   }
}
