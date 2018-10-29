#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*Test function updateCoins*/

int main(int argc, char** argv)
{
	printf("\n********TESTING FUNCTION UPDATECOINS********\n");
	struct gameState game;
	int i;

	game.handCount[0] = 5;

	printf("\nTESTING COPPER HAND\n");
	for (i = 0; i < 5; i++)
		game.hand[0][i] = copper;	

	updateCoins(0, &game, 0);
	
	if (game.coins == 5)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING SILVER HAND\n");
	for (i = 0; i < 5; i++)
		game.hand[0][i] = silver;

	updateCoins(0, &game, 0);
	
	if (game.coins == 10)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING GOLD HAND\n");
	for (i = 0; i < 5; i++)
		game.hand[0][i] = gold;

	updateCoins(0, &game, 0);
	
	if (game.coins == 15)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING MIXED HAND\n");
	game.hand[0][0] = copper;
	game.hand[0][1] = copper;
	game.hand[0][2] = silver;
	game.hand[0][3] = silver;
	game.hand[0][4] = gold;

	updateCoins(0, &game, 0);
	
	if (game.coins == 9)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING COPPER HAND WITH BONUS\n");
	for (i = 0; i < 5; i++)
		game.hand[0][i] = copper;

	updateCoins(0, &game, 1);
	
	if (game.coins == 6)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\n********END TEST FUNCTION UPDATECOINS********\n");
}
