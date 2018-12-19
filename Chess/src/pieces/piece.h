#pragma once
#include <vector>

namespace chess {

	template<class T>
	using s_ptr = std::shared_ptr<T>;

	class Piece
	{
	public:
		int x;
		int y;
		bool isWhite;
	public:
		Piece(const int& xp, const int& yp, const bool& white);
		~Piece();
		virtual void getPossibleMoves(const s_ptr<Piece> const (&board)[8][8], s_ptr<Piece> (&cachedBoards)[26][8][8]) = 0;
	};


}