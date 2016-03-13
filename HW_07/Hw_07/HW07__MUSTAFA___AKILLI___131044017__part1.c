/*##############################################################################*/
/*HW07_part1.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on April 12, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	How many times a given string is used in a given string.         	        */		
/*Inputs:																		*/
/*	-First Given String							                                */
/*	-Second Given String							                            */
/*Outputs:																		*/
/*	How many times second given string is used in first given string.			*/		
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/

int find_size(const char *string);
int char_number(const char *string, const char *wish_to_find);


int 
main(void){

	int size;	
	
	size=char_number("asasas sasas","sasas");

	printf("size:%d\n",size);

	return 0;
}

/*	A recursive function that finds and returns size of a string. 				*/
int find_size(const char *string)
{
	int size;

	if(string[0]=='\0')
	{
		size = 1;
	}

	else
	{
		size=find_size(&string[1]);
		++size;		
	}

	return size;
}

/*	Finds how many times second given string is used in first given string.		*/
int char_number(const char *string, const char *wish_to_find)
{
	int size_string;
	int size_wish_to_find;
	int how_many_times=0,i;

	size_string=find_size(string);
	size_wish_to_find=find_size(wish_to_find);
	
	if(size_string>=size_wish_to_find)
	{
		
		for(i=0;string[i]==wish_to_find[i];++i)
		{
			if(i==size_wish_to_find-2)
			{
				how_many_times=1;

				if(size_string>=size_wish_to_find)
				{
					how_many_times+=char_number(&string[1],wish_to_find);
				}	
			}
		}
	}

	if(size_string>=size_wish_to_find)
	{
		if(how_many_times==0)
		{
			how_many_times+=char_number(&string[1],wish_to_find);
		}
	}

	return how_many_times;
	
}
/*##############################################################################*/
/*			                  End of HW07_part1.c 	    		         		*/
/*##############################################################################*/
