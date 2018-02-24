/*
Keawa Rozet
CSc 600-01 - Programming Languages
Homework #2
Plateau Program (max sequence length)
*/

#include <stdio.h>

int maxlen(int *array, int elements);

int main(int argc, char const *argv[]) {
  int array[] = {1,1,1,1,2,2,2,3,3,4,4,4,4,4,5,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,8,8,9,9,9,9,10,10,10,10,10,10};

  printf("Max length: %d\n", maxlen(array, sizeof(array)/sizeof(int)));
  return 0;
}

int maxlen(int *array, int elements) {
  int count = 0; //keeps track how many times each number occurs
  int maxCount = 0;
  int times = 0;
  int numUnique= 1;
  int avgLength = 1;

  int max = array[0];
  int temp = array[0];
  for (int i = 0; i < elements; i++) {

    if (temp == array[i])
      count++;
      
    //the next unique number is found
    else {
      //set new max number
      if (count > maxCount) {
        maxCount = count;
        max = array[i-1];
      }

      count = 1;
      temp = array[i];
      numUnique++;

      //increased performance for large arrays with plenty reoccuring numbers
      //takes the average length a number occurs
      //check if the current number's occurance is equal to the average length or half
      //if so, move to that location in the array to save time
      avgLength = i/numUnique; //total num of elements so far divided by unique numbers
      if ((i + avgLength) <= elements) {
        if (temp == array[i + avgLength]) {
          i += avgLength;
          count += avgLength;
        }
        else if (temp == array[i + avgLength/2]) {
          i += avgLength/2;
          count += avgLength/2;
        }
      }
      else if ((i + avgLength/2) <= elements) {
        if (temp == array[i + avgLength/2]) {
          i += avgLength/2;
          count += avgLength/2;
        }
      }
    }
    times++;
  }

  //performance evaluation
  printf("Max number: %d\tO(n) = %d\tActual complexity = %d\n", max, elements, times);

  return maxCount;
}
