/*********** Declaration*******
 I hereby certify that no part of this assignment has been copied from
 any other student�s work or from any other source. No part of the code
 has been written/produced for me by another person or copied from any
 other source.
 I hold a copy of this assignment that I can produce if the original is
 lost or damaged.
 **************************/

#include <time.h>
#include "Game.h"

int main() {

	long int t = static_cast<long int>(time(NULL));
	srand(t);


	char ans;
	do {

		Game game;

		game.play();

			cout << "\nDo you want to play again (y/n): ";
			cin >> ans;
			cout << "";

	} while (ans == 'y' || ans == 'Y');
	return 0;
}
