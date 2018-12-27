#pragma once
#include "../vec2.h"
#include <memory>
#include <vector>

namespace chess {

	class Piece
	{
	public:
		Vec2<int> pos;
		char type;
		const bool isWhite;
	protected:
		virtual void init() = 0;
		virtual void getPositions(std::vector<Vec2<int>>& outPositions, 
			const std::shared_ptr<Piece> const (&board)[8][8]);
		virtual bool isChecked(const Vec2<int>& kingPos, std::shared_ptr<Piece> (&board)[8][8]);
		void duplicateBoard(const std::shared_ptr<Piece> const (&copyFrom)[8][8],
			std::shared_ptr<Piece>(&copyTo)[8][8]);
		void movePiece(const int& newX, const int& newY, std::shared_ptr<Piece>(&cachedBoard)[8][8]);
		virtual bool getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
			const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8]);
	public:
		Piece(const Vec2<int>& position, const bool& white);
		~Piece();
		virtual int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) = 0;
	};


}