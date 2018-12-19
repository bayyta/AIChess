#include "piece.h"

namespace chess {


	Piece::Piece(const int& xp, const int& yp, const bool& white)
		: x(xp), y(yp), isWhite(white)
	{ }

	Piece::~Piece()
	{ }

}