/*##############################################################################*/
/*HW09_part1.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on April 26, 2015                					*/			
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
/*							 Structure											*/
typedef struct{

	char name[30];
	char surname[30];
	char department[30];
	char first_class[30];
	char second_class[30];
	double salary;

}type_I;

typedef struct{

	char name[30];
	char surname[30];
	double salary;
	char degree;

}type_E;

typedef union{

	type_I Instructor;
	type_E Employee;
	
}type_union;

typedef struct{

	char mission_type[30];
	type_union mission;

}combine_type;
/*------------------------------------------------------------------------------*/
/*							 Functions											*/
combine_type salary_rise(combine_type person_info);
void update_and_binary(const char *input_file, const char *output_file);
/*------------------------------------------------------------------------------*/

int
main (void)
{
	
	/*	Call the update_and_binary function */
	update_and_binary("input_file.txt","output.bin");

	return 0;
}


/*	Function that Calculate annual salary increase of a person in the university*/
combine_type salary_rise(combine_type person_info)
{
	/*	İf person is Instructor */
	if(person_info.mission_type[0]=='I')
	{

		person_info.mission.Instructor.salary+=
			(person_info.mission.Instructor.salary*5.0)/100.0;
		
		person_info.mission.Instructor.salary+=
			(person_info.mission.Instructor.salary*5.3)/100.0;

	}

	/*	İf person is Employee */
	else
	{
		/*	İf degree of Employee is a */
		if(person_info.mission.Employee.degree=='a')
		{
			person_info.mission.Employee.salary+=
				(person_info.mission.Employee.salary*17.5)/100.0;

		}

		/*	İf degree of Employee is b */
		else if(person_info.mission.Employee.degree=='b')
		{
			person_info.mission.Employee.salary+=
				(person_info.mission.Employee.salary*12.0)/100.0;

		}
 
		/*	İf degree of Employee is c */
		else if(person_info.mission.Employee.degree=='c')
		{
			person_info.mission.Employee.salary+=
				(person_info.mission.Employee.salary*9.0)/100.0;

		}

		/*	İf degree of Employee is false */
		else
		{
			printf("Degree of Employee is not true.\n");
		}

	}

	
	return person_info;
}

/*	Function that takes person information from an input file update the salary
information (calculate annual salary increase) and write into a binary file.	*/
void update_and_binary(const char *input_file, const char *output_file)
{
	FILE *inp,*outp;
	char char_comma[1000];
	char space;
	char status;
	combine_type person[1000];
	int i=0,k=0,j=0;

	inp=fopen(input_file,"r");
	outp=fopen(output_file,"wb");
	
	do
	{
		status=fscanf(inp,"%c",&person[i].mission_type[j]);	
	
		if(status!=EOF)
		{

			/*	İf person is Instructor */
			if(person[i].mission_type[j]=='I')
			{

				/*	Take mission_type */
				while(k!=-1)
				{
					++j;
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
						person[i].mission_type[j]=char_comma[j];	
					}
					
					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;
				fscanf(inp,"%c",&space);
				
				/*	Take name */
				while(k!=-1)
				{
					
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=' ')
					{
						person[i].mission.Instructor.name[j]=char_comma[j];
						++j;
					}

					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;

				/*	Take surname */
				while(k!=-1)
				{
					
					fscanf(inp," %c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
						person[i].mission.Instructor.surname[j]=char_comma[j];
						++j;
					}
					
					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;
				fscanf(inp,"%c",&space);

				/*	Take department */
				while(k!=-1)
				{
					
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
					   person[i].mission.Instructor.department[j]=char_comma[j];
					   ++j;
					}

					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;
				fscanf(inp,"%c",&space);				

				/*	Take First Class */
				while(k!=-1)
				{
					
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
					  person[i].mission.Instructor.first_class[j]=char_comma[j];
					  ++j;
						
					}
					
					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;
				fscanf(inp,"%c",&space);

				/*	Take Second Class */
				while(k!=-1)
				{
					
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
					 person[i].mission.Instructor.second_class[j]=char_comma[j];
					 ++j;
					}

					else
					{
						k=-1;
						j=0;
					}
				}
				
				/*	Take Sallary */
				fscanf(inp,"%lf",&person[i].mission.Instructor.salary);
				fscanf(inp,"%c",&space);
				k=0;
				
				/*	Call the salary_rise function */
				person[i]=salary_rise(person[i]);

				/*	Write into a binary file */
				fwrite(&person[i],sizeof(combine_type),1,outp);
	
			}

			/*	İf person is Employee */
			else
			{

				/*	Take mission_type */
				while(k!=-1)
				{
					++j;
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
						person[i].mission_type[j]=char_comma[j];	
					}
					
					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;
				fscanf(inp,"%c",&space);
				
				/*	Take name */
				while(k!=-1)
				{
					
					fscanf(inp,"%c",&char_comma[j]);
					if(char_comma[j]!=' ')
					{
						person[i].mission.Employee.name[j]=char_comma[j];
						++j;
					}

					else
					{
						k=-1;
						j=0;
					}
				}

				k=0;

				/*	Take surname */
				while(k!=-1)
				{
					
					fscanf(inp," %c",&char_comma[j]);
					if(char_comma[j]!=',')
					{
						person[i].mission.Employee.surname[j]=char_comma[j];
						++j;
					}
					
					else
					{
						k=-1;
						j=0;
					}
				}

				/*	Take salary */
				fscanf(inp,"%lf",&person[i].mission.Employee.salary);

				fscanf(inp,"%c",&space);
				fscanf(inp,"%c",&space);
				k=0;

				/*	Take degree */
				fscanf(inp,"%c",&person[i].mission.Employee.degree);

				fscanf(inp,"%c",&space);

				/*	Call the salary_rise function */
				person[i]=salary_rise(person[i]);

				/*	Write into a binary file */
				fwrite(&person[i],sizeof(combine_type),1,outp);		
			}

		}
		++i;

	}while(status!=EOF);

	
	fclose(inp);
	fclose(outp);
}
/*##############################################################################*/
/*			                  End of HW09_part1.c 	    		         		*/
/*##############################################################################*/
