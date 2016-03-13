/*##############################################################################*/
/*HW02_part2.c                                        		                	*/
/*_____________________________													*/
/*Written by Mustafa Akilli on March 1, 2015                					*/			
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
#include <stdlib.h>
/*------------------------------------------------------------------------------*/


/*	To generate the random number                                               */
double RNG();
/*	To calculate the difference between guess and the number                    */
double CalculateTheDifference(int random_number, int guess_number);
/*	To print a warning in order to guide the player                             */
double WarnThePlayer(int difference);

int 
main(void){

	/*variables*/
	int random_number, guess_number, difference, warn;

	/*To generate the random number*/
	random_number = RNG();
	
	/*get input from user*/
	printf("You have 2 chances to guess\n");
	printf("Please Guess the number to between 1-10:");
	scanf("%d",&guess_number);
	
	/*To calculate the difference between guess and the number*/
	difference = CalculateTheDifference(random_number, guess_number);
	/*To print a warning in order to guide the player*/
	warn = WarnThePlayer(difference);

	/*Congratulation to user if user win*/
	if(random_number==guess_number){
	
		printf("congratulation you find the number...\n");
		return 0;
}

	/*Give to second chance to user*/
	else{
		
		printf("This is the last chance. Please try again:");
		scanf("%d",&guess_number);		
		difference = CalculateTheDifference(random_number, guess_number);
		
}
		
	/*Congratulation to user if user win*/
	if(random_number == guess_number){
	
		printf("congratulation you find the number...\n");
		return 0;
}
	
	/*Game over*/
	else{
		printf("You are lose all chances\n");
}

	/*write to number if user did not win*/
	printf("Number is %d\n",random_number);
	
	return 0;

}

/*	To generate the random number                                               */
double RNG(){

	int x;
	srand(time(NULL));
	x = rand ()%10+1;
	return x;
}

/*	To calculate the difference between guess and the number                    */
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

/*	To print a warning in order to guide the player                             */
double WarnThePlayer(int difference){


	if(difference>=5){
	
		printf("You are too far from the number\n");
}

	else if(difference>=3){
	
		printf("You are far from the number\n");
}

	else if(difference>=1){
		
		printf("You are close to the number\n");
}


}

/*##############################################################################*/
/*			                  End of HW02_part2.c 	    		         		*/
/*##############################################################################*/

