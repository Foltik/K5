#include "vec3f.h"

vec3f::vec3f() {}

vec3f::vec3f(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
}

vec3f::vec3f(float XYZ) {
	x = y = z = XYZ;
}

void vec3f::Init(float X, float Y, float Z) {
	x = X;
	y = Y;
	z = Z;
}

void vec3f::Zero() {
	x = y = z = 0.0f;
}

bool vec3f::isValid() const {
	return x == x && y == y && z == z;
}

inline float vec3f::length() { return std::sqrt((x * x) + (y * y) + (z * z)); }

inline float vec3f::dot(vec3f v) { return (x * v.x) + (y * v.y) + (z * v.z); }

vec3f vec3f::normalized() {
	return *this / length();
}

vec3f vec3f::cross(vec3f v) {
	float X = (y * v.z) - (z * v.y);
	float Y = (z * v.x) - (x * v.z);
	float Z = (x * v.y) - (y * v.x);

	return vec3f(X, Y, Z);
}

#pragma region Operator Overloads
inline bool vec3f::operator==(const vec3f& v) const {
	return (this->x == v.x && this->y == v.y && this->z == v.z);
}

inline bool vec3f::operator!=(const vec3f& v) const {
	return (this->x != v.x && this->y != v.y && this->z != v.z);
}

inline vec3f vec3f::operator-(void) const {
	return vec3f(-x, -y, -z);
}

inline vec3f vec3f::operator-(const vec3f& v) const {
	vec3f res;
	res.x = this->x - v.x;
	res.y = this->y - v.y;
	res.z = this->z - v.z;
	return res;
}

inline vec3f vec3f::operator+(const vec3f& v) const {
	vec3f res;
	res.x = this->x + v.x;
	res.y = this->y + v.y;
	res.z = this->z + v.z;
	return res;
}

inline vec3f vec3f::operator*(float s) const {
	vec3f res;
	res.x = this->x * s;
	res.y = this->y * s;
	res.z = this->z * s;
	return res;
}

inline vec3f vec3f::operator*(const vec3f& v) const {
	vec3f res;
	res.x = this->x * v.x;
	res.y = this->y * v.y;
	res.z = this->z * v.z;
	return res;
}

inline vec3f operator*(float s, const vec3f& v) {
	return v * s;
}

inline vec3f vec3f::operator/(float s) const {
	vec3f res;
	res.x = this->x / s;
	res.y = this->y / s;
	res.z = this->z / s;
	return res;
}

inline vec3f vec3f::operator/(const vec3f& v) const {
	vec3f res;
	res.x = this->x / v.x;
	res.y = this->y / v.y;
	res.z = this->z / v.z;
	return res;
}
#pragma endregion