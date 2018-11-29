#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*FUNCTION TEST: handCard*/

int main(int argc, char** argv)
{
	struct gameState game;
	game.hand[0][0] = copper;
	game.hand[0][1] = silver;
	game.hand[0][2] = gold;
	game.hand[0][3] = village;

	printf("\n********TESTING FUNCTION HANDCARD********\n");

	printf("\nTESTING FIRST CARD IN HAND\n");
	if (handCard(0, &game) == copper)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING SECOND CARD IN HAND\n");
	if (handCard(1, &game) == silver)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING THIRD CARD IN HAND\n");
	if (handCard(2, &game) == gold)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING FOURTH CARD IN HAND\n");
	if (handCard(3, &game) == village)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\n********END TEST HANDCARD FUNCTION********");

}
