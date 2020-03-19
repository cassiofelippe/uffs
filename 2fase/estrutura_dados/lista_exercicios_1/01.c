/*
  Uma usina possui 3 máquinas que produzem postes.
  A máquina 1 produz 1 poste por dia, a máquina 2 produz 3 e a máquina 3 produz 2,5.
  Faça um programa que calcule o número de postes produzidos por esta usina para uma quantidade de dias informada.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  float mc1 = 1, mc2 = 3, mc3 = 2.5, total = 0;
  int days;

  printf("Insert the number of working days: ");
  scanf("%d", &days);

  total += mc1 * days;
  total += mc2 * days;
  total += mc3 * days;

  printf("In %d days the factory has made %.2f light poles!", days, total);
  printf("\n");
}