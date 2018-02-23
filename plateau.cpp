#include <stdio.h>

int maxlen(int *array, int elements);

int main(int argc, char const *argv[]) {
  int array[15] = {1,1,1,1,2,2,2,3,3,4,4,4,4,4};
  printf("Max length: %d\n", maxlen(array, sizeof(array)/sizeof(int)));
  return 0;
}

int maxlen(int *array, int elements) {
  int count = 0;
  int maxCount = 0;
  int times = 0;

  int max = array[0];
  int temp = array[0];
  for (int i = 0; i < elements; i++) {

    if (temp == array[i])
      count++;
    else {
      if (count > maxCount) {
        maxCount = count;
        max = array[i-1];
      }
      count = 1;
      temp = array[i];
    }

    //see if we can skip some numbers
    if ((i + maxCount/2) <= elements) {
      if (temp == array[i + maxCount/2]) {
        i += maxCount/2;
        count += maxCount/2;
      }
    }
    times++;
  }
  printf("Max number: %d\nTimes through loop: %d\n", max, times);
  return maxCount;
}
