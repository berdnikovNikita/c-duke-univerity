#include "cards.h"

int main(void) {
  card_t aceSpades;
  //  card_t wrongCard;
  card_t forNum;
  unsigned rightNum = 37;
  
  aceSpades = card_from_letters('A', 's');
  // wrongCard = card_from_letters('f', 'f');
  
  print_card(aceSpades);

  forNum = card_from_num(rightNum);
  // forNum = card_from_num(wrongNum);

  print_card(forNum);

  return 0;
}
