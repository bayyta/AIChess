#include "bishop.h"

namespace chess {

	void Bishop::init()
	{
		type = 'B';
		directions = { { 1, -1 }, { 1, 1 }, { -1, 1 }, { -1, -1 } };
	}

}