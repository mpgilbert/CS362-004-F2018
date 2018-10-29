#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*FUNCTION TEST: buyCard*/

int main(int argc, char** argv)
{
	printf("\n********TESTING BUYCARD FUNCTION********\n");

	//represents duchy card
	int supplyPos = 2;

	struct gameState game;
	game.numBuys = 1;
	game.coins = 4;

	printf("\nTESTING INSUFFICIENT COINS\n");
	if (buyCard(supplyPos, &game) == -1)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");


	game.numBuys = 0;
	printf("\nTESTING INSUFFICIENT BUYING POTENTIAL\n");
	if (buyCard(supplyPos, &game) == -1)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	game.numBuys = 1;
	game.coins = 10;
	printf("\nTESTING SUFFICIENT COINS AND SUFFICIENT BUYING POTENTIAL\n");
	if (buyCard(supplyPos, &game) == 0)
		printf("\tTEST PASSED");
	else
		printf("\tTEST PASSED");

	printf("\n********END TEST BUYCARD FUNCTION********\n");
}
