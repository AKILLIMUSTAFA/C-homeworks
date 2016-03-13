/*##############################################################################*/
/*HW07_part2.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on April 12, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	How many distinct ways you can climb to the top.		         	        */		
/*Inputs:																		*/
/*	-Number of stairs						                               		*/
/*Outputs:																		*/
/*	-How many distinct ways you can climb to the top.							*/		
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/

int combination (int n , int k);
int ways_rec(int n,int k);
int ways(int n);


int 
main(void){

	int t;

	t=ways(5);

	return 0;
}

/* A recursive function to calculate combination							 	*/
int combination (int n , int k)
{

	int result;

	if(n==k || k==0)
	{
		result=1;
	}

	else
	{
		result=combination(n-1,k-1)+combination(n-1,k);
	}

	return result;
}

/* A recursive function to calculate and return total number of ways.			*/
int ways_rec(int n, int k)
{
	int total_number_of_ways=0;

	total_number_of_ways=combination(n,k);

	if(n-1>=k+1)
	{
		total_number_of_ways+=ways_rec(n-1,k+1);
	}

	return total_number_of_ways;
}

/* A function to call ways_rec(int n, int k) function							*/
int ways(int n)
{
	int number_ways;

	number_ways=ways_rec(n,0);

	printf("%d\n",number_ways);

	return number_ways;
}

/*##############################################################################*/
/*			                  End of HW07_part2.c 	    		         		*/
/*##############################################################################*/
