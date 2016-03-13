/*##############################################################################*/
/*HW03_part1.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on March 8, 2015                					*/			
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*	Guessing An Integer Number         	                        				*/		
/*Inputs:																		*/
/*	-Guess number							                                    */
/*Outputs:																		*/
/*	-Number of guesses					                                        */		
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------------------------------------------------*/

#define MOD 10
#define ONE 1
#define BIGGER_THAN_FIVE 5
#define BIGGER_THAN_THREE 3
#define BIGGER_THAN_ONE 1

	/*To generate the random number */
	double RNG();
	/*To calculate the difference between guess and the number */
	double CalculateTheDifference(int random_number, int guess_number);
	/*To print a warning in order to guide the player */
	double warn_the_player(int difference);

int 
main(void){

	/*variables*/
	int random_number, guess_number, difference, warn,number_of_guesses;
	char play_or_exit;
	int infinite=1;
	
	

	/*ask to player whether she wants to play or exit*/
	printf("What do you want? Play(P or p) or Exit(E or e)\n");
	scanf(" %c",&play_or_exit);
	
	/*İf player want exit*/
	if(play_or_exit == 'E' || play_or_exit == 'e'){

		printf("Bye Bye\n");
		return 0;
	}
	
	/*if player give invalid value*/
	while(play_or_exit != 'P' && play_or_exit != 'p'){
	
		
		printf("invalid value.\n");
		printf("What do you want? Play(P or p) or Exit(E or e)\n");
		scanf(" %c",&play_or_exit);

		if(play_or_exit == 'E' || play_or_exit == 'e'){

			printf("Bye Bye\n");
			return 0;
		}
	}
	
	while(infinite = ONE){
			
		number_of_guesses=1;	/*Number of guesses to reset*/	
	
		/*To generate the random number*/
		random_number = RNG();

		/*get input from user*/
		printf("Please Guess the number to between 1-10:");
		scanf("%d",&guess_number);
	
		/*To calculate the difference between guess and the number*/
		difference = CalculateTheDifference(random_number, guess_number);
		
		/*To print a warning in order to guide the player*/
		warn = warn_the_player(difference);

		/*Give to another chance to player until player win*/
		while(random_number != guess_number){
		
			scanf("%d",&guess_number);		
			difference = CalculateTheDifference(random_number, guess_number);
			warn = warn_the_player(difference);
			++number_of_guesses;
					
		}
		
		/*Congratulation to player if player win*/
		printf("Congratulation you find the number...\n");
		printf("Number of Guesses : %d\n", number_of_guesses);

		/*again ask to player whether she wants to play or exit*/
		printf("What do you want? Play(P or p) or Exit(E or e)\n");
		scanf(" %c",&play_or_exit);
	
		/*İf player want exit*/
		if(play_or_exit == 'E' || play_or_exit == 'e'){

		printf("Bye Bye\n");
		return 0;
		}
	
		/*if player give invalid value*/
		while(play_or_exit != 'P' && play_or_exit != 'p'){
	
		
			printf("invalid value.\n");
			printf("What do you want? Play(P or p) or Exit(E or e)\n");
			scanf(" %c",&play_or_exit);

		if(play_or_exit == 'E' || play_or_exit == 'e'){

			printf("Bye Bye\n");
			return 0;
		}
		}
	}	
}


	/*To generate the random number*/
double RNG(){

	int number_random;
	srand(time(NULL));
	number_random = rand ()%MOD+ONE;
	return number_random;
	}


	/*To calculate the difference between guess and the number*/
double CalculateTheDifference(int random_number, int guess_number){

	int difference;

	if(guess_number>random_number){
		
		difference = guess_number-random_number;
	}

	else{
		
		difference = random_number-guess_number;
	}

	return difference;
	}

	/*To print a warning in order to guide the player*/
double warn_the_player(int difference){


	if(difference>= BIGGER_THAN_FIVE){
	
		printf("You are too far from the number\n");
		printf("please try again:");
	}

	else if(difference>= BIGGER_THAN_THREE){
	
		printf("You are far from the number\n");
		printf("please try again:");
	}

	else if(difference>= BIGGER_THAN_ONE){
		
		printf("You are close to the number\n");
		printf("please try again:");
	}

}

/*##############################################################################*/
/*			                  End of HW03_part1.c 	    		         		*/
/*##############################################################################*/
