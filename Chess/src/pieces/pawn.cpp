#include "pawn.h"

namespace chess {

	Pawn::Pawn(const Vec2<int>& position, const bool& white)
		: Piece(position, white)
	{
		_type = 'P';
		lastTwoSteps = false;
	}

	int Pawn::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8]) const
	{
		int count = 0;

		int dir = 1;
		if (isWhite)
			dir = -1;

		// can move forward?
		if (board[pos.y + dir][pos.x] == nullptr)
		{
			if (getMove(pos.x, pos.y + dir, kingPos, board, cachedBoards[count]))
				count++;
		}

		// can move two forward?
		if (_moveCount == 0)
		{
			if (board[pos.y + dir * 2][pos.x] == nullptr)
			{
				if (getMove(pos.x, pos.y + dir * 2, kingPos, board, cachedBoards[count]))
				{
					std::static_pointer_cast<Pawn>(cachedBoards[count][pos.y + dir * 2][pos.x])->lastTwoSteps = true;
					count++;
				}
			}
		}

		// can capture piece to the left?
		if (pos.x - 1 >= 0)
		{
			// normal capture
			if (board[pos.y + dir][pos.x - 1] != nullptr)
			{
				if (board[pos.y + dir][pos.x - 1]->isWhite != isWhite)
				{
					if (getMove(pos.x - 1, pos.y + dir, kingPos, board, cachedBoards[count]))
						count++;
				}
			}
			// en passant 
			if (board[pos.y][pos.x - 1] != nullptr)
			{
				if (board[pos.y][pos.x - 1]->getType() == 'P' && board[pos.y][pos.x - 1]->isWhite != isWhite)
				{
					if (std::static_pointer_cast<Pawn>(board[pos.y][pos.x - 1])->lastTwoSteps)
					{
						duplicateBoard(board, cachedBoards[count]);
						movePiece(pos.x - 1, pos.y + dir, cachedBoards[count]);
						// remove pawn to the left
						cachedBoards[count][pos.y][pos.x - 1] == nullptr;
						if (!isChecked(kingPos, cachedBoards[count]))
							count++;
					}
				}
			}
		}

		// can capture piece to the right?
		if (pos.x + 1 < 8)
		{
			// normal capture
			if (board[pos.y + dir][pos.x + 1] != nullptr)
			{
				if (board[pos.y + dir][pos.x + 1]->isWhite != isWhite)
				{
					if (getMove(pos.x + 1, pos.y + dir, kingPos, board, cachedBoards[count]))
						count++;
				}
			}
			// en passant
			if (board[pos.y][pos.x + 1] != nullptr)
			{
				if (board[pos.y][pos.x + 1]->getType() == 'P' && board[pos.y][pos.x + 1]->isWhite != isWhite)
				{
					if (std::static_pointer_cast<Pawn>(board[pos.y][pos.x + 1])->lastTwoSteps)
					{
						duplicateBoard(board, cachedBoards[count]);
						movePiece(pos.x + 1, pos.y + dir, cachedBoards[count]);
						// remove pawn to the left
						cachedBoards[count][pos.y][pos.x + 1] == nullptr;
						if (!isChecked(kingPos, cachedBoards[count]))
							count++;
					}
				}
			}
		}

		return count;
	}

	bool Pawn::getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
		const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8]) const
	{
		duplicateBoard(board, cachedBoard);
		movePiece(newX, newY, cachedBoard);
		if (newY == 0 || newY == 7)
		{
			// make queen
			cachedBoard[newY][newX] = std::make_shared<Queen>(Vec2<int>{ newX, newY }, isWhite);
		}
		if (!isChecked(kingPos, cachedBoard))
			return true;
		return false;
	}

	void Pawn::getCopy(std::shared_ptr<Piece>& copyTo) const
	{
		copyTo = std::make_shared<Pawn>(*this);
	}

}