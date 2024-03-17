#include "Vector2f.h"

Vector2f::Vector2f(const Vector2f& other)
{
	m_X = other.getX();
	m_Y = other.getY();
}

Vector2f& Vector2f::operator=(const Vector2f& other)
{
	if (this != &other)
	{
		this->m_X = other.getX();
		this->m_Y = other.getY();
	}
	return *this;
}

Vector2f Vector2f::projection(const Vector2f& vec, const Vector2f& line)
{
	float angle = angleDegree(vec, line);

	return (vec * (line.norm() / (line.norm() * line.norm())));
}

// Non-member function definition

const ostream& operator<<(ostream& out, const Vector2f& vec)
{
	out << "(" << vec.m_X << ", " << vec.m_Y << ")";
	return out;
}
