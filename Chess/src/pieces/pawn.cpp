#include "pawn.h"

namespace chess {

	void Pawn::init()
	{
		type = 'P';
		lastTwoSteps = false;
	}

	int Pawn::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8],
		std::shared_ptr<Piece>(&cachedBoards)[27][8][8])
	{
		int count = 0;

		int dir = 1;
		if (isWhite)
			dir = -1;

		// can move forward?
		if (board[pos.x][pos.y + dir] == nullptr)
		{
			if (getMove(pos.x, pos.y + dir, kingPos, board, cachedBoards[count]))
				count++;
		}

		// can move two forward?
		if ((pos.y == 1 && !isWhite) || (pos.y == 6 && isWhite))
		{
			if (board[pos.x][pos.y + dir * 2] == nullptr)
			{
				if (getMove(pos.x, pos.y + dir * 2, kingPos, board, cachedBoards[count]))
				{
					std::dynamic_pointer_cast<Pawn>(cachedBoards[count][pos.x][pos.y + dir * 2])->lastTwoSteps = true;
					count++;
				}
			}
		}

		// can capture piece to the left?
		if (pos.x - 1 >= 0)
		{
			// normal capture
			if (board[pos.x - 1][pos.y + dir] != nullptr)
			{
				if (board[pos.x - 1][pos.y + dir]->isWhite != isWhite)
				{
					if (getMove(pos.x - 1, pos.y + dir, kingPos, board, cachedBoards[count]))
						count++;
				}
			}
			// en passant 
			if (board[pos.x - 1][pos.y] != nullptr)
			{
				if (board[pos.x - 1][pos.y]->type == 'P' && board[pos.x - 1][pos.y]->isWhite != isWhite)
				{
					if (std::dynamic_pointer_cast<Pawn>(board[pos.x - 1][pos.y])->lastTwoSteps)
					{
						duplicateBoard(board, cachedBoards[count]);
						movePiece(pos.x - 1, pos.y + dir, cachedBoards[count]);
						// remove pawn to the left
						cachedBoards[count][pos.x - 1][pos.y] == nullptr;
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
			if (board[pos.x + 1][pos.y + dir] != nullptr)
			{
				if (board[pos.x + 1][pos.y + dir]->isWhite != isWhite)
				{
					if (getMove(pos.x + 1, pos.y + dir, kingPos, board, cachedBoards[count]))
						count++;
				}
			}
			// en passant
			if (board[pos.x + 1][pos.y] != nullptr)
			{
				if (board[pos.x + 1][pos.y]->type == 'P' && board[pos.x + 1][pos.y]->isWhite != isWhite)
				{
					if (std::dynamic_pointer_cast<Pawn>(board[pos.x + 1][pos.y])->lastTwoSteps)
					{
						duplicateBoard(board, cachedBoards[count]);
						movePiece(pos.x + 1, pos.y + dir, cachedBoards[count]);
						// remove pawn to the left
						cachedBoards[count][pos.x + 1][pos.y] == nullptr;
						if (!isChecked(kingPos, cachedBoards[count]))
							count++;
					}
				}
			}
		}


		return count;
	}

	bool Pawn::getMove(const int& newX, const int& newY, const Vec2<int>& kingPos,
		const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoard)[8][8])
	{
		duplicateBoard(board, cachedBoard);
		movePiece(newX, newY, cachedBoard);
		if (newY == 0 || newY == 7)
		{
			// make queen
			cachedBoard[newX][newY] = std::make_shared<Queen>(Vec2<int>{ newX, newY }, isWhite);
		}
		if (!isChecked(kingPos, cachedBoard))
			return true;
		return false;
	}

}