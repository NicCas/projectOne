/*
	Write a program that can be used by a small theater to sell tickets for performances.
	The theater’s auditorium has 15 rows of seats, with 30 seats in each row. The program should display a screen
	that shows which seats are available and which are taken. For example, the following screen shows a chart depicting
	each seat in the theater. Seats that are taken are represented by an * symbol, and seats that are available are represented by a # symbol:

								   Seats
						123456789012345678901234567890
		Row 1			***###***###*########*****####
		Row 2			####*************####*******##
		Row 3			**###**********########****###
		Row 4			**######**************##******
		Row 5			********#####*********########
		Row 6			##############************####
		Row 7			#######************###########
		Row 8			************##****############
		Row 9			#########*****############****
		Row 10			#####*************############
		Row 11			#**********#################**
		Row 12			#############********########*
		Row 13			###***********########**######
		Row 14			##############################
		Row 15			##############################

	Here is a list of tasks this program must perform:

		• When the program begins, it should ask the user to enter the seat prices for each row.
			The prices can be stored in a separate array. (Alternatively, the prices may be read from a file.)

		• Once the prices are entered, the program should display a seating chart similar to the one shown above.
			The user may enter the row and seat numbers for tickets being sold. Every time a ticket or group of tickets is purchased,
			the program should display the total ticket prices and update the seating chart.

		• The program should keep a total of all ticket sales. The user should be given an option of viewing this amount.

		• The program should also give the user an option to see a list of how many seats have been sold, how many seats are
			available in each row, and how many seats are available in the entire auditorium.

	Input Validation: When tickets are being sold, do not accept row or seat numbers that do not exist. When someone requests a particular seat,
	the program should make sure that seat is available before it is sold.
 */



/*
 * To do:
 *
 * Get File to work for preprogrammed prices
 * Organize all variables
 * Organize variable names (especially for-loops)
 * Fool proof everything
 * Add comments
 * Test
 *
 * Optional: Practice creating files and use one for prices or pre-made test conditions
 */

#include <stdio.h>
#include <stdlib.h>

char seats [15] [30];
float totalTicketSales, prices [15];
int totalSeatsSold, totalSeatsLeft = 450;

void printSeatingChart ()
{

	printf("			    Seats\n\n");
	printf("		123456789012345678901234567890\n");
	for (int a = 0; a < 15; a++)
	{

		printf ("Row %d		", a + 1);
		for (int b = 0; b < 30; b++)
		{

			printf("%c", seats [a][b]);
		}

		printf("\n");
	}
}

int checkSeatingChart (int row, int seat)
{

	row--;
	seat--;
	if (seats [row][seat] == '~')
	{

		printf("This seat is already taken, please select another\n");
		return 0;
	} else {

		seats [row][seat] = '~';
		return 1;
	}
}

void printRowPrices ()
{

	for (int c = 0; c < 15; c++)
	{

		printf("Row %d	costs	$ %.2f", c + 1, prices[c]);
		printf("\n");
	}

	printf("\n");
}


int main(void)
{

	float rowPrice;
	int  w, menu, s = 0, run = 1;


	printf("Would you like to use preprogrammed prices? If yes, type 1, If you would like to enter your own prices type 0:\n");
	scanf("%d", &w);

	while (s == 0){
		if (w == 1){

				/*
					FILE *fp;

					fp = fopen("projectOneTextFile.txt", "r");
					int q = 0;

					for (int i = 0; i < 15; i++){
						fscanf(fp, "%d", q);
						prices [i] = q;
					}

					printSeatingChart();

					fclose(fp);
					*/

				prices [0] = 300.9;
				prices [1] = 250.85;
				prices [2] = 200;
				prices [3] = 100.7;
				prices [4] = 95.6;
				prices [5] = 90.54;
				prices [6] = 85;
				prices [7] = 75.4;
				prices [8] = 70;
				prices [9] = 60;
				prices [10] = 55.32;
				prices [11] = 50;
				prices [12] = 45.2;
				prices [13] = 30.19;
				prices [14] = 15;

				s = 1;

			} else if (w == 0){

				//Set up row prices
				printf("\nPlease enter the seat prices for each row when prompted, beginning in the front with Row 1 and ending with row 15\n\n");

				for (int g = 0; g < 15; g++)
				{

					printf("Please enter the seat price for Row %d:\n", g + 1);
					scanf("%f", &rowPrice);
					prices [g] = rowPrice;

					printf("\n");
				}

				s = 1;
			} else {

				printf("Please enter either 0 or 1:\n");
				scanf("%d", &w);
			}
	}


	//Set up an empty seating chart array
	for (int e = 0; e < 15; e++)
	{
		for (int f = 0; f < 30; f++)
		{
			seats [e][f] = 'O';
		}
	}

	printf("\n");

	printRowPrices();

	printf("\n\n");

	printSeatingChart();

	printf("\n\n");

	while (run == 1)
	{

		printf("Select an action: \n1) Purchase a seat \n2) View total ticket sales \n3) Seat Availability \n4) Close the program [WARNING: This is a final action. All previous data will be lost]\n");
		scanf("%d", &menu);

		//Safety net
		while (!(menu > 0 && menu < 5))
		{
			printf("Please chose an option from the menu\n");
			scanf("%d", &menu);
		}

		printf("\n");

		if(menu == 1)
		{
			//Purchasing seats

			//Booleans
			int purchaseInProgress = 1;
			int seatAvailable = 0;

			//Other Variables
			int row, seat, transactionSeats = 0;
			float transactionTotal = 0;

			printf("Thank you for shopping with Monetized Experiences TM, please write the row and seat number you wish to purchase when indicated.\n\n");

			while (purchaseInProgress == 1)
			{

				while (seatAvailable == 0)
				{

					printf("What row is your desired seat?\n");
					scanf("%d", &row);

					while (!(row > 0 && row < 16))
					{
						printf("Please select a row\n");
						scanf("%d", &row);
					}

					printf("What is the desired seat number?\n");
					scanf("%d", &seat);

					while (!(seat > 0 && seat < 31))
					{
						printf("Please select a seat\n");
						scanf("%d", &seat);
					}


					seatAvailable = checkSeatingChart (row, seat);
				}

				transactionSeats++;
				totalSeatsSold++;
				totalSeatsLeft--;

				transactionTotal = transactionTotal + prices [row - 1];

				printSeatingChart();

				printf("\nYour ticket costs:	$ %.2f\n\n", prices[row - 1]);
				printf("Your total is:		$ %.2f\n\n", transactionTotal);
				printf("Select an action: \n1) Add another seat \n2) Go to checkout\n");
				scanf("%d", &menu);

				while (!(menu > 0 && menu < 3))
				{
					printf("Please chose an option from the menu:\n");
					scanf("%d", &menu);
				}

				if (menu == 1)
				{
					purchaseInProgress = 1;
					seatAvailable = 0;
				} else if (menu == 2) {

					purchaseInProgress = 0;
				}
			}

			totalTicketSales = totalTicketSales + transactionTotal;

			printf("\nYour total is:	$ %.2f for %d seats\nThank you for shopping with Monetized Experiences TM\n\n\n", transactionTotal, transactionSeats);

		} else if (menu == 2){

			//Total ticket sale
			printf("\nTotal Tickets Sales: $ %.2f\n\n\n", totalTicketSales);

		} else if (menu == 3){

			//Seat Availability
			printf("\nNumber of seats sold:	%d\n", totalSeatsSold);
			printf("Number of seats left:	%d\n\n", totalSeatsLeft);

			int count;

			for (int g = 0; g < 15; g++)
			{
				count = 0;
				for (int h = 0; h < 30; h++)
				{
					if (seats [g][h] == '~')
					{
						count++;
					}
				}

				printf("Row %d	has  %d seats left at $ %.2f	per seat\n", g + 1, 30 - count, prices[g]);
			}

			printf("\n\n");

		} else if (menu == 4){

			//Close program
			run = 0;
		}
	}

	return EXIT_SUCCESS;
}
