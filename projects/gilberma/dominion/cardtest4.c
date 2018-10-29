#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv)
{
	printf("\n********TESTING CARD EFFECT OUTPOST********\n");

	int i, handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState game, testCase;
	int k[10] = { adventurer, council_room, cutpurse, embargo, great_hall, mine, outpost, sea_hag, smithy, tribute };

	initializeGame(numPlayers, k, seed, &game);

	memcpy(&testCase, &game, sizeof(struct gameState));
	cardEffect(outpost, choice1, choice2, choice3, &testCase, handPos, &bonus);

	player = whoseTurn(&testCase);

	printf("\nTESTING OUTPOST PLAYED COUNT\n");
	if (testCase.outpostPlayed - 1 == game.outpostPlayed)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING DISCARDED CARDS\n");
	if (testCase.discardCount[player] - 1 == game.discardCount[player])
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\n********END TESTING CARD EFFECT OUTPOST********\n");
}
