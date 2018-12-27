#include "queen.h"

namespace chess {

	void Queen::init()
	{
		_type = 'Q';
		_offsets = { { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 } };
	}

}