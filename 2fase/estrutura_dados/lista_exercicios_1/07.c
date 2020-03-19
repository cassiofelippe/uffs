/*
  Faça um algoritmo que dados o valor calórico gasto por hora em uma determinada atividade física
  e a quantidade de calorias que uma pessoa pretende queimar,
  informe quantas horas da atividade física devem ser realizadas.
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  float caloriesPerHour, desiredCalories, hours;

  printf("\nInsert the calories you want to burn in an hour: ");
  scanf("%f", &caloriesPerHour);

  printf("\nAnd how many calories do you want to burn: ");
  scanf("%f", &desiredCalories);

  hours = desiredCalories / caloriesPerHour;

  printf("\nIt will take %.2f hour%s to burn the desired calories!", hours, hours > 1 ? "s" : "");
  printf("\n");
}