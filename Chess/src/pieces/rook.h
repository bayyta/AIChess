#pragma once
#include "runner.h"

namespace chess {

	class Rook : public Runner
	{
	private:
		void getCopy(std::shared_ptr<Piece>& copyTo) const override;
	public:
		Rook(const Vec2<int>& position, const bool& white);
	};

}