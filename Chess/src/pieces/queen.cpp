#include "queen.h"

namespace chess {

	void Queen::init()
	{
		type = 'Q';
		directions = { { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 } };
	}

}