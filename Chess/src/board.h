#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "pieces/piece.h"

namespace chess {

	template<class T>
	using s_ptr = std::shared_ptr<T>;

	class Board
	{
	private:
		s_ptr<Piece> _board[8][8];
		s_ptr<Piece> _cachedBoards[26][8][8];
	public:
		Board();
		~Board();
	};


}