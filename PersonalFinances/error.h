#pragma once
enum class errorID : int {
	arraySizeMismatch = 1,
	outOfMem,
	fontLoadError,
};

void error(const errorID error);
