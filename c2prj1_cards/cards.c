#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2) && (c.value <= VALUE_ACE));
  assert((c.suit >= SPADES) && (c.suit <= CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default: return "";
    }
}

char value_letter(card_t c) {
  switch(c.value){
  case VALUE_JACK: return 'J';
  case VALUE_QUEEN: return 'Q';
  case VALUE_KING: return 'K';
  case VALUE_ACE: return 'A';
  case 10: return '0';
  default: return c.value+48;
  }
  
  return 'x';
}


char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return 'X';
  }
  
  return 'x';  
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;

  //assign a suit
  for (int i = 0; i <= NUM_SUITS; i++) {
    temp.suit = i;
    if (suit_letter(temp) == suit_let)
      break;
  }

  //assign a value
  for (int i = 2; i <= 52; i++) {
      temp.value = i;
      if (value_letter(temp) == value_let)
	break;
  }

  //asserting the value
  assert_card_valid(temp);
  
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  
  temp.suit = c/13;
  temp.value = c%13+2;

  assert_card_valid(temp);
  
  return temp;
}
