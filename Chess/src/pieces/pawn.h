#pragma once
#include "piece.h"

namespace chess {

	class Pawn : public Piece
	{
	public:
		void getPossibleMoves(const s_ptr<Piece> const (&board)[8][8], s_ptr<Piece> (&cachedBoards)[26][8][8]) override;
	};

}