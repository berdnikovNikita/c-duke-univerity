#include <stdlib.h>                  
#include <assert.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  int x = 5; //used as a standart length of an array
  int incr[] = {-1, 0, 1, 2, 3}; //5
  int decr[] = {3, 2, 1, 0, -1}; //1
  int oneByOne[] = {2, 0, 3, 1, 4}; //2
  int repeat[] = {1, 1, 1, 2, 2, 1}; //2
  int zeroes[] = {0, 0, 0, 0, 0}; //1
  int twoSeqs[] = {0, 1, 5, 2, 9}; //3

  assert(maxSeq(incr, x) == 5);
  assert(maxSeq(decr, x) == 1);
  assert(maxSeq(oneByOne, x) == 2);
  assert(maxSeq(repeat, x) == 2);
  assert(maxSeq(zeroes, x) == 1);
  assert(maxSeq(twoSeqs, x) == 3);
  assert(maxSeq(incr, 0) == 0);

  return EXIT_SUCCESS;
}
