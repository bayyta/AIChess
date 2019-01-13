#pragma once
#include "runner.h"

namespace chess {

	class Queen : public Runner
	{
	private:
		void getCopy(std::shared_ptr<Piece>& copyTo) const override;
	public:
		Queen(const Vec2<int>& position, const bool& white);
	};

}