/*##############################################################################*/
/*HW01_part1.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on Februay 22, 2015              					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*Calculate f(x), g(x), fog(x) and gof(x) Functions          					*/		
/*Inputs:																		*/
/*	-Value of x							                                     	*/
/*Outputs:																		*/
/*	-Resulting f(x), g(x), fog(x) and gof(x) 									*/		
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
#include <math.h>
/*------------------------------------------------------------------------------*/
																				
#define Y 8.0

double Calculate_gx(double x);
double Calculate_fx(double x);

int
main(){

	int x;
	double gx;
	double fx;
	double gofx;
	double fogx;

	FILE *inp, *outp;

/*  x degerinin alinacagi Variables.txt dosyasi acilir     					 	*/

	inp  = fopen("Variables.txt","r");
	fscanf (inp, "%d", &x);

/*  g(x) fonksiyonun hesaplanmasi										     	*/
	gx = Calculate_gx(x);

/*  f(x) fonksiyonun hesaplanmasi										     	*/
	fx = Calculate_fx(x);

/*  g(x) fonksiyonda x yerine f(x) yazarsak gof(x)'i hesaplamis oluruz		 	*/
	gofx = Calculate_gx(fx);
	
/*  f(x) fonksiyonda x yerine g(x) yazarsak gof(x)'i hesaplamis oluruz		 	*/
    fogx = Calculate_fx(gx);

/*  g(x),f(x),gof(x) ve fog(x) degerlerinin yazilacagi    					 	*/
/*	Results1.txt dosyasi acilir                                                 */

	outp = fopen("Results1.txt","w");
	
	fprintf (outp, "g(x) = %f\n",gx);
	fprintf (outp, "f(x) = %f\n",fx);
	fprintf (outp, "gof(x) = %f\n",gofx);
	fprintf (outp, "fog(x) = %f\n",fogx);

	fclose(inp);
	fclose(outp);

/*  g(x),f(x),gof(x) ve fog(x) degerleri consol'a yazdirilir    				*/

	printf("g(x) = %f\n",gx);
	printf("f(x) = %f\n",fx);
	printf("gof(x) = %f\n",gofx);
	printf("fog(x) = %f\n",fogx);

}

/*  g(x) fonksiyonun hesaplanmasi:										     	*/

double Calculate_gx(double x)
{
	double gx;
	gx = x+(1/(x+(Y/(2*x))));
	return gx;
}

/*  f(x) fonksiyonun hesaplanmasi:										     	*/

double Calculate_fx(double x)
{
	double fx;
	fx   = sin(pow((((x+Y)/x)+(pow(log(pow(3,x)/((2*x)+1)),0.5))),2.5));
	return fx;
}


/*##############################################################################*/
/*			                  End of HW01_part1.c 	    		         		*/
/*##############################################################################*/
