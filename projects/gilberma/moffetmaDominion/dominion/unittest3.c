#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*Test function whoseTurn*/
int main(int argc, char** argv)
{
	printf("\n********TESTING FUNCTION WHOSETURN********\n");

	struct gameState game;
	game.whoseTurn = 1;

	printf("\nCHECKING PLAYER 1\n");
	if (whoseTurn(&game) == 1)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	game.whoseTurn = 2;
	printf("\nCHECKING PLAYER 2\n");
	if (whoseTurn(&game) == 2)
		printf("\tTEST PASSED");
	else
		printf("\tTEST FAILED");

	printf("\n********END TEST FUNCTION WHOSETURN********\n");
}
