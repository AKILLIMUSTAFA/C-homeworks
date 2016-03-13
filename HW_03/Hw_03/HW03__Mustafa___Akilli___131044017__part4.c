/*##############################################################################*/
/*HW03_part4.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on March 8, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	        	                        				*/		
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

int draw_hor_diag_of_bb(int first_height,int feet_height,char the_peak_point
,char the_path_point);


int 
main(void){

	int diagram;
	diagram = draw_hor_diag_of_bb(4,3,'o','*');
	printf("\nl");

}

int draw_hor_diag_of_bb(int first_height,int feet_height,char the_peak_point
,char the_path_point){

	int control_variable=1;
	int control_variable_2=1;
	int fixed_first_height ,fixed_feet_height,temp_fixed_feet_height;
	int space_control=0;
	int temp_inside,inside=1,inside2=1,outside,temp_outside;
	int temp_feet_height,temp2_feet_height;
	int temp3_feet_height;
	int next_peak=2*first_height-2;
	int temp_next_peak;
	int counter_next_peak=1;
	int control_next_height=1,control_inside2=1;

	fixed_feet_height = feet_height;
	fixed_first_height = first_height;
	temp3_feet_height = fixed_feet_height+fixed_feet_height;

	printf("^\n");
	printf("l");
	outside = first_height;
	while(outside>=1){

		printf(" ");
		--outside;
	}

	printf("%c",the_peak_point);

	temp2_feet_height = first_height;
	outside = --first_height;
	first_height = fixed_first_height;


	while(temp2_feet_height>=1){

	temp_feet_height = --feet_height;
	feet_height = fixed_feet_height;
	
	
	while(temp_feet_height>=0){
		
		printf("\nl");
	
			

			temp_outside=outside;
			while(temp_outside>=1){

				printf(" ");
				--temp_outside;
			}
		
			printf("%c",the_path_point);
			temp_inside=inside;
			while(temp_inside>=1){
		
				printf(" ");
				--temp_inside;
			}
			
			printf("%c",the_path_point);
			

			if(control_next_height>fixed_feet_height){

			

			temp_outside=outside*2;
			while(temp_outside>=1){

				printf(" ");
				--temp_outside;
			}
		
			printf("%c",the_path_point);
			temp_inside=inside2;
			while(temp_inside>=1){
		
				printf(" ");
				--temp_inside;
			}
			
			printf("%c",the_path_point);
			
			--temp3_feet_height;
	
			
			}
			++control_next_height;
			--temp_feet_height;
		}

	if(control_inside2>1){		
	++inside2;
	++inside2;		
	}
	++control_inside2;
	--next_peak;
	--next_peak;
	++inside;
	++inside;
	--outside;
	--temp2_feet_height;
	++counter_next_peak;
	 --first_height;

	
	}
}
/*##############################################################################*/
/*			                  End of HW03_part4.c 	    		         		*/
/*##############################################################################*/
