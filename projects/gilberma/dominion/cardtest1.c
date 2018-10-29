#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*Test Card: Smithy*/

int main(int argc, char** argv)
{
	printf("\n********TESTING CARD EFFECT SMITHY********\n");

	int i, handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, player = 0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState game, testCase;
	int k[10] = { adventurer, council_room, cutpurse, embargo, great_hall, mine, outpost, sea_hag, smithy, tribute };

	initializeGame(numPlayers, k, seed, &game);

	memcpy(&testCase, &game, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testCase, handPos, &bonus);

	player = whoseTurn(&testCase);

	printf("\nCHECKING HAND COUNT\n");
	if (testCase.handCount[player] - 1 == game.handCount[player])
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");
	
	printf("\nCHECKING FOR DISCARDED CARD\n");
	if (testCase.discardCount[player] == game.discardCount[player] + 1)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\n********END TESTING CARD EFFECT SMITHY********\n");
}
