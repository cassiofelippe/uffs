#include <stdio.h>
#include <stdlib.h>

int main() {
  int x, y;
  float media;

  printf("\nInsert the first value: ");
  scanf("%d", &x);

  printf("\nInsert the second value: ");
  scanf("%d", &y);

  media = (float) (x + y) / 2;

  printf("%.2f", media);


  printf("\n");

  return 0;
}