#pragma once

#include <LinearMath/btVector3.h>

namespace SSGE
{

class Vec3
{
public:
	float x, y, z;

	Vec3::Vec3() {}
	Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3::Vec3(const btVector3& v) : x(v.x()), y(v.y()), z(v.z()) {}

	Vec3 Vec3::operator+(Vec3 other)
	{
		Vec3 result;
		result.x = x + other.x;
		result.y = y + other.y;
		result.z = z + other.z;

		return result;
	}

	void Vec3::operator+=(Vec3 other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	// Physics (BULLET)
	operator btVector3()
	{
		return btVector3(x, y, z);
	}

	Vec3& operator=(const btVector3& other)
	{
		x = other.x();
		y = other.y();
		z = other.z();

		return *this;
	}
};

} // namespace SSGE
