/*##############################################################################*/
/*HW01_part3.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on Februay 22, 2015              					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*Find x and y then calculate f(x,y)          				                	*/		
/*Inputs:																		*/
/*	-car1 amount (lt) of fuel consumed per km				                    */
/*	-car2 amount (lt) of fuel consumed per km				                    */
/*  -car3 amount (lt) of fuel consumed per km                  					*/		
/*	-car1 price of fuel (1lt)					    		                    */
/*	-car2 price of fuel (1lt)		    					                    */		
/*	-car3 price of fuel (1lt)		                                            */
/*  -total km taken by car1             				    	                */
/*  -total km taken by car2                 					                */		
/*  -total km taken by car3     												*/
/*Outputs:																		*/
/*	-Resulting car1 Total Fuel Cost 	           								*/
/*	-Resulting car2 Total Fuel Cost 	           								*/	
/*	-Resulting car3 Total Fuel Cost 	           								*/			
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/

double Car1Cost(double Car1LtPerKm,double Car1PriceOfFuel,double Car1TotalKm);
double Car2Cost(double Car2LtPerKm,double Car2PriceOfFuel,double Car2TotalKm);
double Car3Cost(double Car3LtPerKm,double Car3PriceOfFuel,double Car3TotalKm);

int
main(){

	double Car1LtPerKm;
	double Car2LtPerKm;
	double Car3LtPerKm;
	double Car1PriceOfFuel;
	double Car2PriceOfFuel;
	double Car3PriceOfFuel;
	double Car1TotalKm;
	double Car2TotalKm;
	double Car3TotalKm;
	double Car1TotalFuelCost;
	double Car2TotalFuelCost;
	double Car3TotalFuelCost;
	int car1TLPartOfCost;
	int car2TLPartOfCost;
	int car3TLPartOfCost;
	int car1KurusPartOfCost;
	int car2KurusPartOfCost;
	int car3KurusPartOfCost;	
	

	FILE *inp, *outp;

/*  Degerlerin alinacagi cars.txt dosyasi acilir                                */

	inp = fopen("Cars.txt","r");

/*  -car1 amount (lt) of fuel consumed per km                                   */
	fscanf (inp, "%lf", &Car1LtPerKm);

/*  -car1 price of fuel (1lt)                                                   */
	fscanf (inp, "%lf", &Car1PriceOfFuel);

/*  -total km taken by car1                                                     */
	fscanf (inp, "%lf", &Car1TotalKm);

/*  -car2 amount (lt) of fuel consumed per km                                   */
	fscanf (inp, "%lf", &Car2LtPerKm);

/*  -car2 price of fuel (1lt)                                                   */
	fscanf (inp, "%lf", &Car2PriceOfFuel);

/*  -total km taken by car2                                                     */
	fscanf (inp, "%lf", &Car2TotalKm);

/*  -car3 amount (lt) of fuel consumed per km                                   */
	fscanf (inp, "%lf", &Car3LtPerKm);

/*  -car3 price of fuel (1lt)                                                   */
	fscanf (inp, "%lf", &Car3PriceOfFuel);

/*  -total km taken by car3                                                     */
	fscanf (inp, "%lf", &Car3TotalKm);

	Car1TotalFuelCost = Car1Cost(Car1LtPerKm,Car1PriceOfFuel,Car1TotalKm);
	Car2TotalFuelCost = Car2Cost(Car2LtPerKm,Car2PriceOfFuel,Car2TotalKm);
	Car3TotalFuelCost = Car3Cost(Car3LtPerKm,Car3PriceOfFuel,Car3TotalKm);

/*  Degerlerin yazilacagi TotalFuelCosts.txt dosyasi acilir                     */

	outp = fopen("TotalFuelCosts.txt","w");

/*  Car1,Car2 ve Car3 icin bulunan toplam benzin fiyatlari(Total Fuel Cost)     */
/*  TotalFuelCosts.txt dosyasi icine yazilir                                 	*/

	fprintf (outp, "Car1 Total Fuel Cost = %.2f\n",Car1TotalFuelCost);
	fprintf (outp, "Car2 Total Fuel Cost = %.2f\n",Car2TotalFuelCost);
	fprintf (outp, "Car3 Total Fuel Cost = %.2f\n",Car3TotalFuelCost);

	fclose(inp);
	fclose(outp);
	
/*  Car1,Car2 ve Car3 icin bulunan toplam benzin fiyatlarinin(Total Fuel Cost)  */
/*  TL kismini ayirmak icin double olan degiskeni                        		*/	
/*  int olan baska bir degiskene esitleriz              						*/
/*  Boylece virgulden sonraki kisimdan kurtulmus oluruz              			*/

	car1TLPartOfCost = Car1TotalFuelCost;
	car2TLPartOfCost = Car2TotalFuelCost;
	car3TLPartOfCost = Car3TotalFuelCost;

/*  Car1,Car2 ve Car3 icin bulunan toplam benzin fiyatlarinin(Total Fuel Cost)  */
/*  Kurus kismini bulmak icin                         							*/	
/*  Double olan degiskenimizden int olan degiskeni cikaririz      				*/
/*  Boylece elimizde 0.700000 gibi bir sayi olur           			            */
/*  Bu sayiyi yuz ile carparsak elimizde 70.00000 gibi bir sayi olur            */
/*  Bu sayiyi int olarak aldiğimiz bir degiskene esitlersek                     */
/*  Elimizde 70 gibi bir sayi kalir           			                        */
/*  Buda toplam benzin fiyatinin kurus kismi olur           		            */

	car1KurusPartOfCost = (Car1TotalFuelCost-car1TLPartOfCost)*100;
	car2KurusPartOfCost = (Car2TotalFuelCost-car2TLPartOfCost)*100;
	car3KurusPartOfCost = (Car3TotalFuelCost-car3TLPartOfCost)*100;

	
/*  Car1,Car2 ve Car3 icin bulunan toplam benzin fiyatlari(Total Fuel Cost)     */
/*  Consol'a yazilirken TL ve kurus kismi ayrilir                            	*/

	printf("The total fuel cost of the car 1 is ");
	printf("%d TL and %d Kurus.\n",car1TLPartOfCost,car1KurusPartOfCost);
	printf("The total fuel cost of the car 2 is ");
	printf("%d TL and %d Kurus.\n",car2TLPartOfCost,car2KurusPartOfCost);
	printf("The total fuel cost of the car 3 is ");
	printf("%d TL and %d Kurus.\n",car3TLPartOfCost,car3KurusPartOfCost);

}

/*  Car1 icin toplam benzin fiyatini hesaplama                                  */

double Car1Cost(double Car1LtPerKm,double Car1PriceOfFuel,double Car1TotalKm)

{
	double Car1_Total_Fuel_Cost;
	Car1_Total_Fuel_Cost = Car1LtPerKm*Car1PriceOfFuel*Car1TotalKm;
	return Car1_Total_Fuel_Cost;
}

/*  Car2 icin toplam benzin fiyatini hesaplama                                  */

double Car2Cost(double Car2LtPerKm,double Car2PriceOfFuel,double Car2TotalKm)

{
	double Car2_Total_Fuel_Cost;
	Car2_Total_Fuel_Cost = Car2LtPerKm*Car2PriceOfFuel*Car2TotalKm;
	return Car2_Total_Fuel_Cost;
}

/*  Car3 icin toplam benzin fiyatini hesaplama                                  */

double Car3Cost(double Car3LtPerKm,double Car3PriceOfFuel,double Car3TotalKm)

{
	double Car3_Total_Fuel_Cost;
	Car3_Total_Fuel_Cost = Car3LtPerKm*Car3PriceOfFuel*Car3TotalKm;
	return Car3_Total_Fuel_Cost;
}

/*##############################################################################*/
/*			                  End of HW01_part3.c 	    		         		*/
/*##############################################################################*/
