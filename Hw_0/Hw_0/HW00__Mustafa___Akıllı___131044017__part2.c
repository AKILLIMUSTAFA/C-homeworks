#include <stdio.h>

int
main(){
	double ia0, ia1, ia2;
	double ib0, ib1, ib2;
	double ra0, ra1, ra2, ra3, ra4;

	/*Get the 1st degree input polynomial*/
	printf("Enter the first coefficients of the polynomial");
	printf("(from higher to lower order)");
	scanf("%lf%lf%lf", &ia2, &ia1, &ia0);
	printf("\nEnter the second coefficients of the polynomial");
	printf("(from higher to lower order)");
	scanf("%lf%lf%lf", &ib2, &ib1, &ib0);
	
	/*Calculate the resulting poly*/
	ra4 = ia2*ib2;
	ra3 = (ia2*ib1)+(ia1*ib2);
	ra2 = (ia1*ib1)+(ia2*ib0)+(ia0*ib2);
	ra1 = (ia1*ib0)+(ia0*ib1);
	ra0 = (ia0*ib0);

	/*Output the resulting poly*/
	printf("\nThe resulting polynomial is %.1f x^4 + %.1f x^3 ", ra4, ra3);
	printf("%.1f x^2 + %.1f x + %.1f\n", ra2, ra1, ra0);

	return 0;
}
