/*##############################################################################*/
/*HW09_part3.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on April 28, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	Guessing An Integer Number         	                        				*/		
/*Inputs:																		*/
/*	-Guess number							                                    */
/*Outputs:																		*/
/*										                                        */		
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/
/*							  Struct											*/
typedef struct{

	int first_five;
	int second_five;
	int third_five;

}triplet_t;

typedef struct{

	triplet_t Combination_of_Positives;
	int Most_probable_number;
	int Lower;
	int Upper;
	
}Row;
/*------------------------------------------------------------------------------*/
/*							Function											*/
void Into_Binary(FILE *text_input, FILE *binary_output);
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[], int maxsize);
void Printf_function(Row mpn_table[],int actual_size);
void search( Row mpn_table[], int actual_size, const triplet_t triplet_to_search);
/*------------------------------------------------------------------------------*/

int
main(void)
{
	Row mpn_table[50];
	int actual_size=0, temp_actual_size=10,i,line=0;

	FILE *text_input,*binary_output,*binary_input_file;

	text_input=fopen("input.txt","r");

	/*Check the text_input*/
	if(text_input == NULL){

		printf("ERROR!! Text input file could not be opened to read.\n");
		return 0;
	}

	binary_output=fopen("converted.bin","wb");

	/*Check the binary_output*/
	if(binary_output == NULL){

		printf("ERROR!! Binary Output file could not be opened to write.\n");
		return 0;
	}

	/*Call the Into_Binary*/
	Into_Binary(text_input,binary_output);

	/*Close the Files*/
	fclose(text_input);
	fclose(binary_output);

	binary_input_file=fopen("converted.bin","rb");

	/*Check the binary_input_file*/
	if(binary_input_file == NULL){

		printf("ERROR!! Binary input file could not be opened to read.\n");
		return 0;
	}
		
	/*Call the Load_Mpn_table*/
	/*Find the actual_size*/
	while(temp_actual_size==10)
	{
		temp_actual_size=Load_Mpn_table(binary_input_file,&mpn_table[line],10);
		actual_size+=temp_actual_size;
		line=+10;
	}	
	
	/*Close the File*/
	fclose(binary_input_file);

	/*Call the Printf_function*/
	Printf_function(mpn_table,actual_size);	

	return 0;
}

/*Reads the data from text file and writes into binary file*/
void Into_Binary(FILE *text_input, FILE *binary_output)
{
	Row string[1000];
	int i=0,status,k;
	char character[100];
	char char_char;
	
	/*------İmportant-----------*/
	/* İnput File be like this:
			4 – 2 - 0

	first hyphen is long
	second hyphen is short
	
	**************************
	not like this==> 4 - 2 - 0
	not like this==> 4-2-0
	**************************

	if you use short hyphen,
	
	like this:4 - 2 - 0

	you must delete 151. line 
	in the program.

	**************************
	if you dont use the space
	and you use short hyphen
	
	like this:4-2-0

	you must delete 151. 153.
	155. 161. 163. lines in
	the program.
		
								*/
	/*------İmportant-----------*/
	do
	{	
		status=
		fscanf(text_input,"%d",&string[i].Combination_of_Positives.first_five);
	

		fscanf(text_input,"%c",&char_char);

		fscanf(text_input,"%c",&character[i]);
		
		fscanf(text_input,"%c",&character[i]);
		
		fscanf(text_input,"%c",&character[i]);
		
		fscanf(text_input,"%d",&string[i].Combination_of_Positives.second_five);

		fscanf(text_input,"%c",&char_char);

		fscanf(text_input,"%c",&character[i]);
		
		fscanf(text_input,"%c",&character[i]);
		
		fscanf(text_input,"%d",&string[i].Combination_of_Positives.third_five);
		
		fscanf(text_input,"%d",&string[i].Most_probable_number);
		
		fscanf(text_input,"%d",&string[i].Lower);

		fscanf(text_input,"%d",&string[i].Upper);
		

		if(status!=EOF)
		{
			fwrite(&string[i],sizeof(Row),1,binary_output);
		}

		++i;
	}while(status!=EOF);


}

/*Read data from the binary file, 
  assign to called Row array
  returns the actual size of array*/
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[], int maxsize)
{
	int actual_size;
	
	actual_size=fread(mpn_table,sizeof(Row),maxsize,binary_input_file);

	return actual_size;
}

/*Take from the user combination of positives and call the search function*/
void Printf_function(Row mpn_table[],int actual_size)
{
	triplet_t triplet_to_search;
	char character;	

	printf("combination-of-positives triplet(For example:5-2-1):");
	scanf("%d",&triplet_to_search.first_five);
	scanf("%c",&character);
	scanf("%d",&triplet_to_search.second_five);
	scanf("%c",&character);
	scanf("%d",&triplet_to_search.third_five);

	search(mpn_table,actual_size,triplet_to_search);
}

/*Chech the combination of positives
  if find then print the data,
  if not find then print the error message*/
void search( Row mpn_table[], int actual_size, const triplet_t triplet_to_search)
{
	int i=0,k,found=0;
	
	triplet_to_search.first_five;
	triplet_to_search.second_five;
	triplet_to_search.third_five;

	for(k=0;k<=actual_size;++k)	
	{
		if(mpn_table[i].Combination_of_Positives.first_five==
			triplet_to_search.first_five &&
			
			mpn_table[i].Combination_of_Positives.second_five==
			triplet_to_search.second_five &&
			
			mpn_table[i].Combination_of_Positives.third_five==
			triplet_to_search.third_five)
		{
			printf("MPN=%d; ",mpn_table[i].Most_probable_number);
			printf("95%% of samples contain between ");
			printf("%d and ",mpn_table[i].Lower);
			printf("%d bacteria/ml.\n",mpn_table[i].Upper);
			found=1;
		}
		++i;
	}

	if(found==0)
	{
		printf("This combination of positives not found.\n");
	}
}
/*##############################################################################*/
/*			                  End of HW09_part3.c 	    		         		*/
/*##############################################################################*/
