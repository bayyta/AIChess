#include "bishop.h"

namespace chess {

	void Bishop::init()
	{
		_type = 'B';
		_offsets = { { 1, -1 }, { 1, 1 }, { -1, 1 }, { -1, -1 } };
	}

}