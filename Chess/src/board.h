#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "pieces/piece.h"

namespace chess {

	class Board
	{
	private:
		std::shared_ptr<Piece> _board[8][8];
		std::shared_ptr<Piece> _cachedBoards[26][8][8];
	public:
		Board();
		~Board();
	};


}