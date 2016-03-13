/*##############################################################################*/
/*HW03_part3.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on March 8, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	Draw a vertical diagram of a bouncing ball                   				*/		
/*Inputs:																		*/
/*	-First Height							                                    */
/*	-Feet Height							                                    */
/*	-The Peak Point							                                    */
/*	-The Path Point							                                    */
/*Outputs:																		*/
/*	-Diagram					                                                */
/*	-Total Number of The Character Used											*/
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/

#define ONE 1
#define TWO 2

int draw_ver_diag_of_bb(int first_height,int feet_height,char the_peak_point
,char the_path_point);
int draw_diag_step(int first_height,int feet_height,char the_peak_point
,char the_path_point);
int finish_diag(int length);

int 
main(void){


	int first_height,feet_height;
	char the_peak_point,the_path_point;
	int first_test,second_test,third_test;

	first_test = draw_ver_diag_of_bb(4,3,'O','*');
	second_test = draw_ver_diag_of_bb(3,2,'D','+');
	third_test = draw_ver_diag_of_bb(5,3,'B','/');

	printf("First diagram return :%d\n",first_test);	
	printf("Second diagram return :%d\n",second_test);
	printf("Third diagram return :%d\n",third_test);
	
	return 0;

}

	/*Guessing An Integer Number*/
int draw_ver_diag_of_bb(int first_height,int feet_height,char the_peak_point
,char the_path_point){

	int number_of_character=0;	
	
	printf("^\n");
			
	while(first_height>=ONE){
	
	draw_diag_step(first_height,feet_height,the_peak_point,the_path_point);
	number_of_character += TWO*first_height*feet_height+ONE;
	--first_height;
	}

	finish_diag(25);

	return number_of_character;

}

	/*returns the number of the character used as peak points and path points*/
	/*print the diagram*/
int draw_diag_step(int first_height,int feet_height,char the_peak_point
,char the_path_point){


	int control_variable=ONE;
	int control_variable_2=ONE;
	int fixed_first_height ,fixed_feet_height,temp_fixed_feet_height;
	int space_control=0;	

	fixed_feet_height = feet_height;
	fixed_first_height = first_height;

	printf("l");

	/*First Part of Bouncing Ball*/
	while(control_variable<=fixed_first_height){
	
	control_variable_2=ONE;

	while( control_variable_2<=fixed_feet_height){
	printf("%c",the_path_point);
	++ control_variable_2;
	}
	printf("\n");
	printf("l");
	space_control=ONE;
	while(space_control<=feet_height){
		printf(" ");
		++space_control;
	}
	feet_height+=fixed_feet_height;
	++control_variable;
	}
	
	feet_height-=fixed_feet_height;
	while(space_control<=feet_height){
		printf(" ");
		++space_control;
	}

	printf("%c\n",the_peak_point);


	/*Second Part of Bouncing Ball*/
	
	control_variable=ONE;
		
	while(control_variable<=fixed_first_height){
	
	control_variable_2=ONE;

	printf("l");
	feet_height-=fixed_feet_height;
	space_control=ONE;
	while(space_control<=feet_height){
		printf(" ");
		++space_control;
	}
		
	temp_fixed_feet_height = fixed_feet_height;	
	while(temp_fixed_feet_height>=ONE){

	printf("%c",the_path_point);
	--temp_fixed_feet_height;
	}
	
	printf("\n");
	++control_variable;
	}

	return (TWO*first_height*feet_height)+ONE;
} 

	/*print the end of the diagram by drawing the bottom axes.*/
int finish_diag(int length){

	printf("L");

	while(length>=ONE){
		printf("-");
		--length;
	}
	printf(">\n");
	return 1;
}
/*##############################################################################*/
/*			                  End of HW03_part3.c 	    		         		*/
/*##############################################################################*/
