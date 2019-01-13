#pragma once
#include "../vec2.h"
#include <memory>
#include <vector>

namespace chess {

	class Piece
	{
	protected:
		int _moveCount;
		char _type;
		std::vector<Vec2<int>> _offsets;
	public:
		Vec2<int> pos;
		const bool isWhite;
	protected:
		virtual void getPositions(std::vector<Vec2<int>>& outPositions,
			const std::shared_ptr<Piece> const (&board)[8][8]) const;
		virtual bool isChecked(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8]) const;
		virtual bool getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
			const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8]) const;
		virtual void getCopy(std::shared_ptr<Piece>& copyTo) const = 0;
	public:
		Piece(const Vec2<int>& position, const bool& white);
		~Piece();
		virtual int getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
			std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const = 0;
		void movePiece(const int& newX, const int& newY, std::shared_ptr<Piece>(&cachedBoard)[8][8]) const;
		void duplicateBoard(const std::shared_ptr<Piece> const (&copyFrom)[8][8],
			std::shared_ptr<Piece>(&copyTo)[8][8]) const;
		const int& getMoveCount() const;
		const char& getType() const;
	};

}