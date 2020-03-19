/*
  Os salários dos funcionários da empresa ABC são calculados da seguinte forma:
  deve-se pedir o número de horas trabalhadas no mês e o valor da hora.
  Com esses valores calcula-se o salário bruto.
  Para calcular o salário líquido deve descontar: 8% de INSS,
  12% de imposto de renda e o total de adiantamentos feitos ao funcionário.
  Faça um programa que descreva o algoritmo para resolver este problema.
*/

#include <stdio.h>
#include <stdlib.h>

float calculateGrossSalary(int hours, float hourPrice) {
  return hours * hourPrice;
}

float calculateNetSalary(float gross, int hasForwardness, float forwardness) {
  float inss = 0.08, incomeTax = 0.12, netSalary;

  netSalary = gross - (gross * inss) - (gross * incomeTax);

  if (hasForwardness) {
    netSalary -= forwardness;
  }

  return netSalary;
}

void main() {
  int hours, hasForwardness;
  float forwardness = 0.00, hourPrice, grossSalary, netSalary;

  printf("\nInsert the number of hours worked by the employee this month: ");
  scanf("%d", &hours);

  printf("\nInsert the price of the hour of the employee: ");
  scanf("%f", &hourPrice);

  printf("\nWas there any forwardness this month? (0 - No, 1 - Yes): ");
  scanf("%d", &hasForwardness);

  if (hasForwardness) {
    printf("\nInsert the forwardness value: ");
    scanf("%f", &forwardness);
  }

  grossSalary = calculateGrossSalary(hours, hourPrice);

  netSalary = calculateNetSalary(grossSalary, hasForwardness, forwardness);

  printf("\nEmployee's gross: %.2f and net salary: %.2f!", grossSalary, netSalary);
  printf("\n");
}