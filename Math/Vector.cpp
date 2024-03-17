#include "Vector.h"

Vector3f::Vector3f(const Vector3f& other)
{
	m_X = other.getX();
	m_Y = other.getY();
	m_Z = other.getZ();
}

Vector3f& Vector3f::operator=(const Vector3f& other)
{
	if (this != &other)
	{
		this->m_X = other.getX();
		this->m_Y = other.getY();
		this->m_Z = other.getZ();
	}
	return *this;
}

Vector3f Vector3f::projection(const Vector3f& vec, const Vector3f& line)
{
	float angle = angleDegree(vec, line);

	return (vec * (line.norm() / (line.norm() * line.norm())));
}

// Non-member function definition

const ostream& operator<<(ostream& out, const Vector3f& vec)
{
	out << "(" << vec.m_X << ", " << vec.m_Y << ", " << vec.m_Z << ")";
	return out;
}
