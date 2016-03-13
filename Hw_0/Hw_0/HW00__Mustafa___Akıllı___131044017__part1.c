#include <stdio.h>

int
main(){
	double ia0, ia1;
	double ra1, ra2;

	/*Get the 1st degree input polynomial*/
	printf("Enter the coefficient of the polynomial");
	printf("(from higher to lower order)>");
	scanf("%lf%lf", &ia1, &ia0);

	/*Calculate the resulting poly*/
	ra2 = ia1/2;
	ra1 = ia0;

	/*Output the resulting poly*/
	printf("The resulting polynomial is %.1f x^2 + %.1f x + c.\n", ra2,ra1);

	return 0;
}
