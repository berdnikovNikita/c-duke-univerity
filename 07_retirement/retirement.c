#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
} retire_info;

double retBalance(double current, retire_info source) {
  current *= source.rate_of_return;
  return current + source.contribution;
}

double computeRetirement(retire_info source, int age, double money) {
  for (int i = 0; i < source.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", (age+i) / 12, (age+i) %  12, money);
    money += retBalance(money, source);
  }

  return money;
}

//startAge in months
//initial - init. savings in $
//working, retirement - info about working and  retirement
void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  initial = computeRetirement(working, startAge, initial);
  initial = computeRetirement(retired, startAge + working.months, initial);
}
  
int main(void) {
  retire_info working, retired;
  int age = 327;
  double savings = 21345;
  
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(age, savings, working, retired);
  return 0;
}
