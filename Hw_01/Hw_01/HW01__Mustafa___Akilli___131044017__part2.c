/*##############################################################################*/
/*HW01_part2.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on Februay 22, 2015              					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*Find x and y then calculate f(x,y)          				                	*/		
/*Inputs:																		*/
/*	-coefficient of x for 1 st eq.							                    */
/*	-coefficient of y for 1 st eq							                    */
/*  -result of 1 st equation                                 					*/		
/*	-coefficient of x for 2 st eq.							                    */
/*	-coefficient of x for 2 st eq.							                    */		
/*	-result of 2 st equation		                                            */
/*  -coefficient of x for function          					                */		
/*  -coefficient of y for function												*/
/*Outputs:																		*/
/*	-Resulting x, y, f(x,y) 	                								*/		
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/

double find_x(double a,double b,double c,double d,double e,double f);
double find_y(double a,double b,double c,double d,double e,double f);
double calculate_fxy(double g,double h,double x,double y);


int
main(){


	double a;
	double b;
	double c;
	double d;
	double e;
	double f;
	double g;
	double h;
	double x;
	double y;
	double fxy;


	FILE *inp, *inp2, *outp;

/*  katsayilarin alinacagi EqCoefficients.txt dosyasi acilir                    */

	inp = fopen("EqCoefficients.txt","r");

/* a = coefficient of x for 1 st eq.                                            */		
	fscanf (inp, "%lf", &a);

/* b = coefficient of y for 1 st eq.                                            */
	fscanf (inp, "%lf", &b);

/* c = result of 1 st equation                                                  */
	fscanf (inp, "%lf", &c);

/* d = coefficient of x for 2 st eq.                                            */
	fscanf (inp, "%lf", &d);

/* e = coefficient of y for 2 st eq.                                            */
	fscanf (inp, "%lf", &e);

/* f = result of 2 st equation                                                  */
	fscanf (inp, "%lf", &f);

/*  x degerini bulma                                                            */
	x = find_x(a,b,c,d,e,f);

/*  y degerini bulma                                                            */
	y = find_y(a,b,c,d,e,f);
	
	
	fclose(inp);
	
	inp2 = fopen("FuncCoefficients.txt","r");

/* g = coefficient of x for function                                            */
	fscanf (inp, "%lf", &g);

/* h = coefficient of y for function                                            */
	fscanf (inp, "%lf", &h);

/*  f(x,y) degerini bulma                                                       */
	fxy = calculate_fxy(g,h,x,y);

/*  x,y ve f(x,y) degerlerinin yazilacagi Results2.txt dosyasi acilir           */

	outp = fopen("Results2.txt","w");
	
/*  x,y ve f(x,y) degerleri Results2.txt dosyasina yazilir                      */

	fprintf (outp, "x = %f\n",x);
	fprintf (outp, "y = %f\n",y);
	fprintf (outp, "f(x,y) = %f\n",fxy);

	fclose(outp);

/*  x,y ve f(x,y) degerleri consol'a yazilir                                    */

	printf("x = %f\n",x);
	printf("y = %f\n",y);
	printf("f(x,y) = %f\n",fxy);

}

/*  x degerinin bulunmasi:                                                      */
/*  İlk denklem ikinci denklemdeki y'nin katsayisi olan                         */
/*  e sayinin negatif hali olan -e ile genisletilir                             */
/*  ikinci denklem ilk denklemdeki y'nin katsayisi olan                         */
/*  b sayisi ile genişletilir                                                   */
/*  iki denklem toplandiginda y'ler birbirini götürür                           */
/*  elimizde sadece bir bilinmeyen kalir yani x                                 */
/*  boylece x degeri bulunmus olur                                              */



double find_x(double a,double b,double c,double d,double e,double f)
{
	double x;
	x = ((b*f)-(e*c))/((b*d)-(a*e));
	return x;
}

/*  y degerinin bulunmasi:                                                      */
/*  İlk denklem ikinci denklemdeki x'in katsayisi olan                          */
/*  d sayinin negatif hali olan -d ile genisletilir                             */
/*  ikinci denklem ilk denklemdeki x'in katsayisi olan                          */
/*  a sayisi ile genişletilir                                                   */
/*  iki denklem toplandiginda x'ler birbirini götürür                           */
/*  elimizde sadece bir bilinmeyen kalir yani y                                 */
/*  boylece y degeri bulunmus olur                                              */

double find_y(double a,double b,double c,double d,double e,double f)
{
	double y;
	y = ((a*f)-(d*c))/((a*e)-(d*b));
	return y;
}

/*  f(x,y) degerinin bulunmasi:                                                 */
/*  x ve y degerleri bulunduktan sonra yerine yazilir                           */
/*  boylece f(x,y) degeri bulunmus olur                                         */


double calculate_fxy(double g,double h,double x,double y)
{
	double fxy;
	fxy = (g*x)+(h*y);
	return fxy;
}
/*##############################################################################*/
/*			                  End of HW01_part2.c 	    		         		*/
/*##############################################################################*/
