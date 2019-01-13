#include "bishop.h"

namespace chess {

	Bishop::Bishop(const Vec2<int>& position, const bool& white)
		: Runner(position, white)
	{
		_type = 'B';
		_offsets = { { 1, -1 }, { 1, 1 }, { -1, 1 }, { -1, -1 } };
	}

	void Bishop::getCopy(std::shared_ptr<Piece>& copyTo) const
	{
		copyTo = std::make_shared<Bishop>(*this);
	}

}