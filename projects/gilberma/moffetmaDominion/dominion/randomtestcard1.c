#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define CARD_COUNT treasure_map

int main()
{

	int k[10] = { adventurer, council_room, cutpurse, embargo, great_hall, mine, outpost, sea_hag, smithy, tribute };
	int i, j, players, turn, seed, decksize, handsize, prevhandcount, prevdiscardcount, handpos;
	int testSuccess = 0;
	int testFail = 0;
	struct gameState G;
	srand(time(NULL));

	printf("\n********Random Test: Smithy********\n");
	for (i = 0; i < 10000; i++)
	{
		players = rand() % 3 + 2;
		seed = rand() % 1000 + 1;
	
		initializeGame(players, k, seed, &G);
	
		turn = rand() % players;
		G.whoseTurn = turn;
		G.numActions = 1;
		decksize = rand() % MAX_DECK + 1;
		handsize = rand() % decksize + 1;
		G.deckCount[turn] = decksize - handsize;
		G.handCount[turn] = handsize;
		G.discardCount[turn] = 0;
		handpos = rand() % handsize;
		
		for (j = 0; j < G.deckCount[turn]; j++)
			G.deck[turn][j] = rand() % CARD_COUNT;

		for (j = 0; j < G.handCount[turn]; j++)
			G.hand[turn][j] = rand() % CARD_COUNT;

		prevhandcount = G.handCount[turn];
		prevdiscardcount = G.discardCount[turn];
		//smithyEffect(&G, turn, handpos);
		smithyFunction(&G, handpos, turn);
		
		if (G.handCount[turn] != prevhandcount)
		{
			testFail++;
			continue;
		}

		if (G.discardCount[0] - 1 != prevdiscardcount)
		{
			testFail++;
			continue;
		}

		testSuccess++;
	}

	printf("\n\nTest successes: %d\n", testSuccess);
	printf("\nTest failures: %d\n", testFail);
}
