#pragma once
enum class errorID : int {
	arraySizeMismatch = 1,
	outOfMem,
};

void error(const errorID error);
