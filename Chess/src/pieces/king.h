#pragma once
#include "piece.h"

namespace chess {

	class King : public Piece
	{
	private:
		void init();
	public:
		int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) override;
	};

}