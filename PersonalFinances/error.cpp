#include "error.h"
#include <cstdlib>
#include <stdio.h>

void error(const errorID error) {

	// display the error here later!
	switch (error)
	{
	case errorID::arraySizeMismatch:
		puts("\nError in progam! arraySizeMismatch!");
		break;
	case errorID::outOfMem:
		puts("\nProgamm ran out of memory!");
		break;
	case errorID::fontLoadError:
		puts("\nComicMono.ttf was not found!");
		break;
	default:
		break;
	}

	puts("press return to continue...");
	getchar();

	std::exit((int)error);
}