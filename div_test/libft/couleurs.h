#ifndef _COULEURS_H
#define _COULEURS_H

#include <stdio.h>

#define clrscr() printf("\033[H\033[2J") 1
#define couleur(param) printf("\033[%sm", param)

#endif