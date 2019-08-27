#include <stdio.h>

void batalha(
		int p1_a, p1_b, p1_c,
		int p2_a, p2_b, p2_c,
		int *s1, *s2;
	)
	{
		
		// CRIPTOGRAFANDO AS ENTRDAS
		int e_a = p1_b;
		int e_b = p1_c;
		int e_c = p1_a;

		// "COMPARANDO AS ENTRADAS" (?)
		if
		(	
			(e_a == e_b && e_b == e_c && e_a == 0) ||
			(e_a == e_b && e_b == e_c && e_a == 1) ||
			(p2_a == p2_b && p2_b == p2_c && p2_a == 0) ||
			(p2_a == p2_b && p2_b == p2_c && p2_a == 0)
		)
		{
			*s1 = 1;
			*s2 = 0;
		}
		else if(e_a == p2_a)

}

int main(){

	int s1, s2;



	return 0;
}