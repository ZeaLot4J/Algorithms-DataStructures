#ifndef _FURITMACHINE_H
#define _FURITMACHINE_H


# include <stdio.h>
# include <conio.h>
# include <time.h>
# include <stdlib.h>

void Rule();
int GetBet();
int GetAmount();
void Throw();
int Judge(int a, int b, int c);
void Moneycal();
int check(int pm, int dm);

extern int a, b, c, Playermoney , Dealermoney , Betmoney, bet, get;




#endif // _FURITMACHINE_H
