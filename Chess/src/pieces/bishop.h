#pragma once
#include "runner.h"

namespace chess {

	class Bishop : public Runner
	{
	private:
		void getCopy(std::shared_ptr<Piece>& copyTo) const override;
	public:
		Bishop(const Vec2<int>& position, const bool& white);
	};

}