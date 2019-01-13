#include "rook.h"

namespace chess {

	Rook::Rook(const Vec2<int>& position, const bool& white)
		: Runner(position, white)
	{
		_type = 'R';
		_offsets = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
	}

	void Rook::getCopy(std::shared_ptr<Piece>& copyTo) const
	{
		copyTo = std::make_shared<Rook>(*this);
	}

}