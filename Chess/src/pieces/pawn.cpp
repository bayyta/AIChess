#include "pawn.h"

namespace chess {

	void Pawn::init()
	{
		type = 'P';
		lastTwoSteps = false;
	}

	int Pawn::getPossibleMoves(const Vec2<int>& kingPos, const std::shared_ptr<Piece> const (&board)[8][8], std::shared_ptr<Piece>(&cachedBoards)[26][8][8])
	{
		int count = 0;

		int dir = 1;
		if (isWhite)
			dir = -1;

		// can move forward?
		if (board[pos.x][pos.y + dir] == nullptr)
		{
			duplicateBoard(board, cachedBoards[count]);
			movePiece(pos.x, pos.y + dir, cachedBoards[count]);
			if (!isChecked(kingPos, cachedBoards[count]))
				count++;
		}

		// can move two forward?
		if ((pos.y == 1 && !isWhite) || (pos.y == 6 && isWhite))
		{
			if (board[pos.x][pos.y + dir * 2] == nullptr)
			{
				duplicateBoard(board, cachedBoards[count]);
				movePiece(pos.x, pos.y + dir * 2, cachedBoards[count]);
				std::dynamic_pointer_cast<Pawn>(cachedBoards[count][pos.x][pos.y + dir * 2])->lastTwoSteps = true;
				if (!isChecked(kingPos, cachedBoards[count]))
					count++;
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
					duplicateBoard(board, cachedBoards[count]);
					movePiece(pos.x - 1, pos.y + dir, cachedBoards[count]);
					if (!isChecked(kingPos, cachedBoards[count]))
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
					duplicateBoard(board, cachedBoards[count]);
					movePiece(pos.x + 1, pos.y + dir, cachedBoards[count]);
					if (!isChecked(kingPos, cachedBoards[count]))
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

}