#include "rook.h"

namespace chess {

	void Rook::init()
	{
		type = 'R';
		directions = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
	}

}