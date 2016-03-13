/*##############################################################################*/
/*HW02_part2.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on March 1, 2015              					    */			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	Calculate point, grade and contribution for 5 students                      */		
/*Inputs:																		*/
/*	-Student Name   						                                    */
/*	-Student Surname 						                                    */
/*	-Midterm1 Point 					                                        */
/*	-Midterm2 Point  						                                    */
/*	-Final Point							                                    */
/*Outputs:																		*/
/*	-Point	                                                                    */
/*	-Grade                                                                      */
/*	-Contribution                                                               */		
/*##############################################################################*/
/*				     															*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------*/
/*                                #defines                                      */
#define DENOMINATOR 100
#define SHARE_THIRTY 40
#define SHARE_FORTY 30
#define ALL_CREDITS 20
#define COURSE_CREDIT 3
#define GRADE_A 4.0
#define GRADE_B 3.0
#define GRADE_C 2.0
#define GRADE_D 1.0
#define GRADE_F 0
/*------------------------------------------------------------------------------*/

/*	Calculate the point of student function                                     */	
int calculate_point(int mid1,int mid2,int final);

/*	Calculate the grade of student function                                     */
int calculate_grade(int point);

/*	Calculate the contribution of student function                              */
void calculate_contribution(int grade);

int 
main(void){

	/*variables*/
	char student_name_1, student_surname_1;
	int midterm1_point_1, midterm2_point_1, final_point_1;
	char student_name_2, student_surname_2;
	int midterm1_point_2, midterm2_point_2, final_point_2;
	char student_name_3, student_surname_3;
	int midterm1_point_3, midterm2_point_3, final_point_3;
	char student_name_4, student_surname_4;
	int midterm1_point_4, midterm2_point_4, final_point_4;
	char student_name_5, student_surname_5;
	int midterm1_point_5, midterm2_point_5, final_point_5;
	int point1, point2, point3, point4, point5;
	char grade1, grade2, grade3, grade4, grade5;
	int mid1, mid2, mid3, mid4, mid5, final, point;
	int contribution1, contribution2, contribution3;
	int contribution4, contribution5;

	FILE *inp, *outp;
	
	/*get input from txt*/
	inp = fopen("Students.txt","r");
	fscanf(inp,"%c",&student_name_1);
	fscanf(inp,"%c",&student_surname_1);
	fscanf(inp,"%d",&midterm1_point_1);
	fscanf(inp,"%d",&midterm2_point_1);
	fscanf(inp,"%d",&final_point_1);
	fscanf(inp,"\n%c",&student_name_2);
	fscanf(inp,"%c",&student_surname_2);
	fscanf(inp,"%d",&midterm1_point_2);
	fscanf(inp,"%d",&midterm2_point_2);
	fscanf(inp,"%d",&final_point_2);
	fscanf(inp,"\n%c",&student_name_3);
	fscanf(inp,"%c",&student_surname_3);
	fscanf(inp,"%d",&midterm1_point_3);
	fscanf(inp,"%d",&midterm2_point_3);
	fscanf(inp,"%d",&final_point_3);
	fscanf(inp,"\n%c",&student_name_4);
	fscanf(inp,"%c",&student_surname_4);
	fscanf(inp,"%d",&midterm1_point_4);
	fscanf(inp,"%d",&midterm2_point_4);
	fscanf(inp,"%d",&final_point_4);
	fscanf(inp,"\n%c",&student_name_5);
	fscanf(inp,"%c",&student_surname_5);
	fscanf(inp,"%d",&midterm1_point_5);
	fscanf(inp,"%d",&midterm2_point_5);
	fscanf(inp,"%d",&final_point_5);

	fclose(inp);


	point1 = calculate_point(midterm1_point_1,midterm2_point_1,final_point_1);
	point2 = calculate_point(midterm1_point_2,midterm2_point_2,final_point_2);
	point3 = calculate_point(midterm1_point_3,midterm2_point_3,final_point_3);
	point4 = calculate_point(midterm1_point_4,midterm2_point_4,final_point_4);
	point5 = calculate_point(midterm1_point_5,midterm2_point_5,final_point_5);
	grade1 = calculate_grade(point1);
	grade2 = calculate_grade(point2);
	grade3 = calculate_grade(point3);
	grade4 = calculate_grade(point4);
	grade5 = calculate_grade(point5);

	/*output the result to screen*/
	printf("Student 1:%c%c ",student_name_1,student_surname_1);
	printf("point:%d ",point1);
	printf("grade:%c ",grade1);
	calculate_contribution(grade1);
	printf("Student 2:%c%c ",student_name_2,student_surname_2);
	printf("point:%d ",point2);
	printf("grade:%c ",grade2);
	calculate_contribution(grade2);
	printf("Student 3:%c%c ",student_name_3,student_surname_3);
	printf("point:%d ",point3);
	printf("grade:%c ",grade3);
	calculate_contribution(grade3);
	printf("Student 4:%c%c ",student_name_4,student_surname_4);
	printf("point:%d ",point4);
	printf("grade:%c ",grade4);
	calculate_contribution(grade4);
	printf("Student 5:%c%c ",student_name_5,student_surname_5);
	printf("point:%d ",point5);
	printf("grade:%c ",grade5);
	calculate_contribution(grade5);

	/*output the result to txt*/
	outp = fopen("Grades.txt","w");
	fprintf(outp,"%c%c %d\n",student_name_1,student_surname_1,point1);
	fprintf(outp,"%c%c %d\n",student_name_2,student_surname_2,point2);
	fprintf(outp,"%c%c %d\n",student_name_3,student_surname_3,point3);
	fprintf(outp,"%c%c %d\n",student_name_4,student_surname_4,point4);
	fprintf(outp,"%c%c %d",student_name_5,student_surname_5,point5);
	
	fclose(outp);

	return 0;

}

/*------------------------------------------------------------------------------*/
/*                         Function Prototypes                                  */
/*------------------------------------------------------------------------------*/

/*	Calculate the point of student function                                     */	
int calculate_point(int mid1,int mid2,int final){

	int point;
	point = (mid1*SHARE_FORTY/DENOMINATOR)
			+(mid2*SHARE_FORTY/DENOMINATOR)
			+(final*SHARE_THIRTY/DENOMINATOR);
	return point;
}

/*	Calculate the grade of student function                                     */
int calculate_grade(int point){	

	char grade;
	
	if(point<=39){
		grade = 'F';
}

	else if(point<=64){
		grade = 'D';
}			
	
	else if(point<=69){
		grade = 'C';
}	
	
	else if(point<=84){
		grade = 'B';
}
	
	else {
		grade = 'A';
}

	return grade;
}


/*	Calculate the contribution of student function                              */
void calculate_contribution(int grade){



	double contribution;


	switch(grade){

		case 'A' : contribution = GRADE_A*COURSE_CREDIT/ALL_CREDITS;
				   printf("Contribution: %.2f\n",contribution);
				   break;

		case 'B' : contribution = GRADE_B*COURSE_CREDIT/ALL_CREDITS;
				   printf("Contribution: %.2f\n",contribution);
				   break;

		case 'C' : contribution = GRADE_C*COURSE_CREDIT/ALL_CREDITS;
				   printf("Contribution: %.2f\n",contribution);
				   break;

		case 'D' : contribution = GRADE_D*COURSE_CREDIT/ALL_CREDITS;
				   printf("Contribution: %.2f\n",contribution);
				   break;

		default  : contribution = GRADE_F*COURSE_CREDIT/ALL_CREDITS;
				   printf("Contribution: %.2f\n",contribution);
	

	}

}

/*##############################################################################*/
/*			                  End of HW02_part1.c 	    		         		*/
/*##############################################################################*/
