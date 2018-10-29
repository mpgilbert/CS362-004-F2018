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
	printf("\n********TESTING CARD EFFECT ADVENTURER********\n");

	int i, handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0;
	int secondLastIsTreasure = 0, lastIsTreasure = 0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState game, testCase;
	int k[10] = { adventurer, council_room, cutpurse, embargo, great_hall, mine, outpost, sea_hag, smithy, tribute };

	initializeGame(numPlayers, k, seed, &game);

	memcpy(&testCase, &game, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testCase, handPos, &bonus);

	player = whoseTurn(&testCase);

	printf("\nTESTING HAND SIZED\n");
	if (testCase.handCount[player] - 2 == testCase.handCount[player])
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\nTESTING FOR NEW TREASURE CARDS\n");
	if (testCase.hand[player][testCase.handCount[player] - 2] == copper ||
		testCase.hand[player][testCase.handCount[player] - 2] == silver ||
		testCase.hand[player][testCase.handCount[player] - 2] == gold)
		secondLastIsTreasure = 1;

	if (testCase.hand[player][testCase.handCount[player] - 1] == copper ||
		testCase.hand[player][testCase.handCount[player] - 1] == silver ||
		testCase.hand[player][testCase.handCount[player] - 1] == gold)
		lastIsTreasure = 1;

	if (secondLastIsTreasure == 1 && lastIsTreasure == 1)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\n********END TESTING CARD EFFECT ADVENTURER********\n");
}
