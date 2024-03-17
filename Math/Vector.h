#pragma once

#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

constexpr float MAX_DEGREE = 180.0f;
constexpr float PHI = 3.14159265358979323846264338327950288419716939937510f;

class Vector3f
{
public:
	Vector3f()
		: m_X(0.0f), m_Y(0.0f), m_Z(0.0f) {}
	Vector3f(float x, float y, float z)
		: m_X(x), m_Y(y), m_Z(z) {}

	Vector3f(const Vector3f& other);
	Vector3f& operator=(const Vector3f& other);
	inline static Vector3f ones() { return Vector3f(1.0f, 1.0f, 1.0f); }
	inline static Vector3f uniform(const float pos) { return Vector3f(pos, pos, pos); }

	inline float norm() const { return (float)sqrt(pow(m_X, 2.0f) + pow(m_Y, 2.0f) + pow(m_Z, 2.0f)); }
	inline static float dotProduct(const Vector3f& v1, const Vector3f& v2) { return v1.norm() * v2.norm() * cos(angleDegree(v1, v2)); }
	static Vector3f crossProduct();

	inline static float dotProductComp(const Vector3f& v1, const Vector3f& v2) { return (isEqual(v1, v2) ? pow(v1.norm(), 2.0f) : (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ())); }
	inline static float angleDegree(const Vector3f& v1, const Vector3f& v2) { return (isEqual(v1, v2) ? 0.0f : acos(dotProductComp(v1, v2) / (v1.norm() * v2.norm())) * (MAX_DEGREE / PHI)); }
	static Vector3f projection(const Vector3f& vec, const Vector3f& line);

	inline float getX() const { return m_X; }
	inline float getY() const { return m_Y; }
	inline float getZ() const { return m_Z; }

	static const bool isEqual(const Vector3f& v1, const Vector3f& v2) { return (v1.m_X == v2.m_X && v1.m_Y == v2.m_Y && v1.m_Z == v2.m_Z); }

	inline Vector3f operator+(const Vector3f& rhs) const { return Vector3f(this->getX() + rhs.getX(), this->getY() + rhs.getY(), this->getZ() + rhs.getZ()); }
	inline Vector3f operator-(const Vector3f& rhs) const{ return Vector3f(this->getX() - rhs.getX(), this->getY() - rhs.getY(), this->getZ() - rhs.getZ()); }
	inline Vector3f operator*(const float scalar) const { return Vector3f(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar); }
	inline Vector3f operator/(const float scalar) const { return Vector3f(this->getX() / scalar, this->getY() / scalar, this->getZ() / scalar); }

	friend const ostream& operator<<(ostream& out, const Vector3f& vec);

private:
	float m_X, m_Y, m_Z;
};

const ostream& operator<<(ostream& out, const Vector3f& vec);