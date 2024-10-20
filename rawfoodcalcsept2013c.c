/* Coded by Robert Brown, October 2013, for K9 Instinct!
v. 1.2
*/

#include <stdio.h>
#include <conio.h>

//VARIABLE DECLARATIONS
int selection;

//FUNCTION DECLARATIONS
void foodCalculator();
float lbsToOz(int, float );
void rawAmountsNeeded(float);

int main()
{
	start:
	printf("K9 Instinct Food Calculator, v. 1.2\n\n"); //Selection Menu
	printf("1. Raw Food Calculator\n");
	printf("2. Homemade Diet Calculator\n");
	printf("3. Exit\n\n");
	printf("Please make a selection: ");
	scanf("%d", &selection);
	printf("\n");
	
	if(selection == 1 || selection == 2)
	{
		foodCalculator();
	}
	else if ( selection == 3)
	{
		printf("Press any key to exit.");
	    getch();
	    goto end;
	}	
	else
	{
		system("cls");
		goto start;
	}			          						       		          						          	
	end:							   
	return 0;
}

//=================================
void foodCalculator() //Calculates oz and lbs of food to feed from dog's est adult weight and the percentage of food needed
{
	int adultWeight;
	float weightPercentage;
	printf("Please enter estimated adult weight as a whole number in lbs: ");
	scanf("%d", &adultWeight);
	printf("\n");
	
	printf("Please enter percentage of weight to feed as a whole number or decimal: ");
	scanf("%f", &weightPercentage);
	printf("\n");
	
	float ozToFeed;
	ozToFeed = lbsToOz(adultWeight, weightPercentage);

	printf("Amount of food needed per day: %.2f oz (%.2f lbs)\n\n", ozToFeed, (ozToFeed/16));
	printf("Amount of food needed per meal: %.2f oz (%.2f lbs)\n\n", (ozToFeed/2), (ozToFeed/16));

	if(selection == 1)  // if/else if statement decides whether to print details needed for raw food calculations as opposed to homemade diet
	{
		rawAmountsNeeded(ozToFeed);
	}
	else if (selection == 2)
	{
		printf("Press any key to continue...\n\n");
        getch();
        system("cls");
        main();
	}
}
//==================================
float lbsToOz(int x, float y) //converts the percentage of food from dog's est adult weight from lbs to oz of food needed
{
	float z;
	z = (y/100) * x;
	z = z * 16;
	return z;
}
//==================================
void rawAmountsNeeded(float x) //All the details of raw food plan needed here.
{	
	float mm = (x * .45);
	float rmb = (x * .5);
	float om = (x * .05);
	printf("Raw meaty bones needed per day: %.2f oz\n", rmb);
	printf("Muscle meat needed per day: %.2f oz\n", mm);
	printf("Organ meat needed per day: %.2f oz\n\n", om);
	
	printf("Raw meaty bones needed per meal: %.2f oz\n", (rmb/2));
	printf("Muscle meat needed per meal: %.2f oz\n", (mm/2));
	printf("Organ meat needed per meal: %.2f oz\n\n", (om/2));

	if(selection == 1)
	{
		printf("Press any key to continue...\n");
		getch();
		system("cls");
		main();
	}
}