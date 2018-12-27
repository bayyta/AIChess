#pragma once

namespace chess {

	template<typename T>
	struct Vec2
	{
		T x, y;

		Vec2()
		{
			x = 0;
			y = 0;
		}

		Vec2(const T& x, const T& y)
		{
			this->x = x;
			this->y = y;
		}

		Vec2(const Vec2& vec2)
		{
			x = vec2.x;
			y = vec2.y;
		}

		Vec2<T>& operator+=(const Vec2& vec2)
		{
			this->x += vec2.x;
			this->y += vec2.y;

			return *this;
		}

		Vec2<T>& operator+(const Vec2& vec2)
		{
			this->x + vec2.x;
			this->y + vec2.y;

			return *this;
		}

		Vec2<T>& operator*(const int& mul)
		{
			this->x *= mul;
			this->y *= mul;

			return *this;
		}

		void add(const T& x, const T& y)
		{
			this->x += x;
			this->y += y;
		}

		void add(const Vec2& vec2)
		{
			this->x += vec2.x;
			this->y += vec2.y;
		}

		bool operator==(const Vec2& vec2)
		{
			return x == vec2.x && y == vec2.y;
		}
	};

}