#include "queen.h"

namespace chess {

	Queen::Queen(const Vec2<int>& position, const bool& white)
		: Runner(position, white)
	{
		_type = 'Q';
		_offsets = { { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 } };
	}

	void Queen::getCopy(std::shared_ptr<Piece>& copyTo) const
	{
		copyTo = std::make_shared<Queen>(*this);
	}

}