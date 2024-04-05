#pragma once

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

constexpr float MAX_DEGREE = 180.0f;
constexpr float PHI = 3.14159265358979323846264338327950288419716939937510f;

class Vector2f
{
public:
	Vector2f()
		: m_X(0.0f), m_Y(0.0f) {}
	Vector2f(float x, float y)
		: m_X(x), m_Y(y) {}
	Vector2f(float num)
		: m_X(num), m_Y(num) {}

	Vector2f(const Vector2f& other);
	Vector2f& operator=(const Vector2f& other);

	inline float norm() const { return static_cast<float>(sqrt(pow(m_X, 2.0f) + pow(m_Y, 2.0f))); }
	inline static float dotProduct(const Vector2f& v1, const Vector2f& v2) { return v1.norm() * v2.norm() * cos(angleDegree(v1, v2)); }
	static Vector2f crossProduct();

	inline static float dotProductComp(const Vector2f& v1, const Vector2f& v2) { return (isEqual(v1, v2) ? static_cast<float>(pow(v1.norm(), 2.0f)) : (v1.getX() * v2.getX()) + (v1.getY() * v2.getY())); }
	inline static float angleDegree(const Vector2f& v1, const Vector2f& v2) { return (isEqual(v1, v2) ? 0.0f : acos(dotProductComp(v1, v2) / (v1.norm() * v2.norm())) * (MAX_DEGREE / PHI)); }
	static Vector2f projection(const Vector2f& vec, const Vector2f& line);

	inline float getX() const { return m_X; }
	inline float getY() const { return m_Y; }

	static const bool isEqual(const Vector2f& v1, const Vector2f& v2) { return (v1.m_X == v2.m_X && v1.m_Y == v2.m_Y); }

	inline Vector2f operator+(const Vector2f& rhs) const { return Vector2f(this->getX() + rhs.getX(), this->getY() + rhs.getY()); }
	inline Vector2f operator-(const Vector2f& rhs) const{ return Vector2f(this->getX() - rhs.getX(), this->getY() - rhs.getY()); }
	inline Vector2f operator*(const float scalar) const { return Vector2f(this->getX() * scalar, this->getY() * scalar); }
	inline Vector2f operator/(const float scalar) const { return Vector2f(this->getX() / scalar, this->getY() / scalar); }

	friend const ostream& operator<<(ostream& out, const Vector2f& vec);

private:
	float m_X, m_Y;
};

const ostream& operator<<(ostream& out, const Vector2f& vec);
