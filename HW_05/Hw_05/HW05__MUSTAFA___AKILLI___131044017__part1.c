/*##############################################################################*/
/*HW05_part1.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on March 22, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	 A car crash simulator program.    		    								*/
/*Inputs:																		*/
/*	-Name of Car 1  								                            */
/*	-Name of Car 2  								                            */
/*	-Speed of Car 1  								                            */	
/*	-Speed of Car 2 								                            */
/*	-Weight of Car 1  								                            */
/*	-Weight of Car 2 								                            */			
/*Outputs:																		*/
/*	-Crash Simulator			                                       		    */
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*								Includes										*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/

/*								Defines											*/
#define WAY_END 50.0
#define WAY_START 1.0
#define WAY_NUMBER 10.0
/*------------------------------------------------------------------------------*/

typedef enum{PLAY,CRASH,END}object_state;

void make_move(char *object1, double *position1, double *speed1, int weight1,
char *object2, double *position2, double *speed2, int weight2, object_state
*game_state);

double car_crash_time(double position1, double position2, double speed1, double
speed2);

void print_game_state(char object1, double position1, char object2,
double position2, object_state game_state);

int
main(void)
{
	char object1,object2;
	double speed1,speed2,position1,position2;
	int weight1,weight2;
	object_state game_state,game_state2,game_state3;

	printf("Name of Car 1:");
	scanf("%c",&object1);
	printf("Name of Car 2:");
	scanf(" %c",&object2);
	printf("Speed of Car 1:");
	scanf("%lf",&speed1);
	printf("Speed of Car 2:");
	scanf("%lf",&speed2);	
	printf("Weight of Car 1:");
	scanf("%d",&weight1);
	printf("Weight of Car 2:");
	scanf("%d",&weight2);

	position1=WAY_START;
	position2=WAY_END;

/*								PLAY											*/	
	game_state=PLAY;

	make_move(&object1, &position1, &speed1, weight1, &object2, 
	&position2, &speed2, weight2, &game_state);
/*------------------------------------------------------------------------------*/

/*								CRASH											*/	
	game_state2=CRASH;

	make_move(&object1, &position1, &speed1, weight1, &object2, 
	&position2, &speed2, weight2, &game_state2);
/*------------------------------------------------------------------------------*/
}

/******************************************************************************
 * call car_crash_time fonk.                                		  		  *
 * -1 add to crash_time.							  		  				  *
 * until crash_time be 0,                      					  			  *
 * call print_game_state fonk.       				  			  			  *
 * calculate new speed,						 								  *
 * calculate new position,									  				  *
 * calculate end_time.						 								  *
 * new speed add to end_time 						 						  *
 * until end_time be 0,									  					  *
 * call print_game_state fonk.						 						  *
 ******************************************************************************/
void make_move(char *object1, double *position1, double *speed1, int weight1,
char *object2, double *position2, double *speed2, int weight2, object_state
*game_state)
{
	int crash_time,temp_crash_time;
	double new_speed,new_position,end_time;

	crash_time = car_crash_time(*position1, *position2, *speed1, *speed2);

	switch(*game_state){
		
		case PLAY :   temp_crash_time = crash_time;
					  while(crash_time>0)
					  {
					  	 print_game_state(*object1, *position1, *object2, 
					 	 *position2, *game_state);
					  if(*speed1>0)
					  {
						*position1 += *speed1;
					  }
					  if(*speed2<0)
					  {
					  	*position2 += *speed2;
					  }
					  	--crash_time;
					  }
					  break;	

		case CRASH : new_speed=((weight1**speed1)+(weight2**speed2))/
								(weight1+weight2);
				 
		

					 new_position = (*position1+(((*position2-*position1-1)/
									(*speed1-*speed2))**speed1));

					if(*speed2>=0)
					{
						*position1 -= *speed1;
					new_position = (*position1+(((*position2-*position1-1)/
									(*speed1-*speed2))**speed1))+1;
					}

					if(*speed1<=0)
					{
			
						new_position = *position1+0.5;
					}

				

					 if(new_speed<0)
					 {
					 	end_time = new_position;
					 	while(end_time>0)
					 	{
					 		print_game_state(*object1, new_position, *object2, 
					 		*position2, *game_state);
							new_position += new_speed;
					 		end_time += new_speed;
					 	}
					 }
					
					 else if(new_speed>0)
					 {
					 	end_time = WAY_END-new_position;
					 	while(end_time>0)
					 	{
					 		print_game_state(*object1, new_position, *object2, 
					 		*position2, *game_state);
					 		new_position += new_speed;
					 		end_time -= new_speed;	 
					 	}
					 }

					else
					{
						print_game_state(*object1, new_position, *object2, 
					 	*position2, *game_state);
					}
					 break;

		case END : break;
	}
}

/******************************************************************************
 * calculate all way									  					  *
 * sump up to pozitif speed1 and pozitif speed2                               *
 * way assign to temp_way                                		  			  *
 * calculate (temp_way-sum up to speeds)        				  			  *
 * 1 add to car_crash_time													  *
 * if sum up to speeds bigger than temp_way-sum								  *
 * return car_crash_time													  *
 ******************************************************************************/
double car_crash_time(double position1, double position2, double speed1,
double speed2)
{
	double way,temp_way,car_crash_time=0,control_way;

	way = position2-position1-1;
	temp_way = way;

	if(speed1<0)
	{
		speed1=0;
	}
	

	if(speed2>0)
	{
		speed2=0;
	}

	while(temp_way>=-1)
	{
		++car_crash_time;
		control_way=way;
		temp_way = control_way-(speed1-speed2);
		if(temp_way == way)
		{
			++car_crash_time;
			return car_crash_time;
		}
		way = temp_way;
	}
	
	return car_crash_time;

}

/******************************************************************************
 * until crash time:                                		  			  	  *
 * printf first_out_line,object1,in_line 							  		  *
 * printf object1,second_out_line.                         					  *
 * after crash time:        				  			  					  *
 * until end time							 								  *
 * printf first_out_line,X,second_out_line									  *
 ******************************************************************************/
void print_game_state(char object1, double position1, char object2,
double position2, object_state game_state)
{
	double in_line,first_out_line,second_out_line;
	double temp_in_line,temp_first_out_line,temp_second_out_line;
	int ruler;

	switch(game_state){
		
		case PLAY : first_out_line = position1-1.9;
				 	temp_first_out_line = first_out_line;
					while(temp_first_out_line>0)
					{
					  printf("_");
					  --temp_first_out_line;
					}

					printf("%c",object1);

					in_line = position1-position2-0.9;
					temp_in_line = in_line;
					while(temp_in_line<-2)
					{
					  printf("_");
					  ++temp_in_line;
					}

					printf("%c",object2);

					second_out_line = WAY_END-position2-0.9;
				 	temp_second_out_line = second_out_line;
					while(temp_second_out_line>0)
					{
					  printf("_");
					  --temp_second_out_line;
					}

					printf("\n");
					for(ruler=1;ruler<(WAY_END/WAY_NUMBER+0.9);++ruler)
					{
						printf("1234567890");
					}
		
					printf("\n");
					break;

		case CRASH : 
					 first_out_line=position1-1;
					 temp_first_out_line = first_out_line;
					 while(temp_first_out_line>0)
					{
					  printf("_");
					  --temp_first_out_line;
					}
					
					printf("X");

					second_out_line = WAY_END-position1+1;

				 	temp_second_out_line = second_out_line;

					while(temp_second_out_line>2)
					{
					  printf("_");
					  --temp_second_out_line;
					}	

						printf("\n");
					for(ruler=1;ruler<(WAY_END/WAY_NUMBER+0.9);++ruler)
					{
						printf("1234567890");
					}
				
					printf("\n");
					break;

		case END : break;
	}
}
/*##############################################################################*/
/*			                  End of HW05_part1.c 	    		         		*/
/*##############################################################################*/
