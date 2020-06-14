#pragma once

namespace SSGE
{

class Vec3
{
public:
	float x, y, z;

	Vec3::Vec3() {}
	Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

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
};

} // namespace SSGE
