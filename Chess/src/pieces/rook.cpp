#include "rook.h"

namespace chess {

	void Rook::init()
	{
		_type = 'R';
		_offsets = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
	}

}