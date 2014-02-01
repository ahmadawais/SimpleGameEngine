//
//  Vector3.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Vector3.h"
#include <math.h>
#include <ostream>
#include <sstream>

using namespace sge;


#pragma mark Constructors and Destructors -

Vector3::Vector3()
: Vector3(0.0f, 0.0f, 0.0f) {}

Vector3::Vector3(float x, float y, float z)
: x(x), y(y), z(z) {}

Vector3::Vector3(float value)
: Vector3(value, value, value) {}

Vector3::~Vector3() {}

#pragma mark - Assignment -

Vector3& Vector3::operator=(const Vector3& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator+=(float amount) {
	x += amount;
	x += amount;
	z += amount;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator-=(float amount) {
	x -= amount;
	y -= amount;
	z -= amount;
	return *this;
}

Vector3& Vector3::operator*=(float scale) {
	x *= scale;
	y *= scale;
	z *= scale;
	return *this;
}

Vector3& Vector3::operator/=(float scale) {
	x /= scale;
	y /= scale;
	z /= scale;
	return *this;
}

#pragma mark - Methods -

float Vector3::sqrmagnitude() const {
	return x*x + y*y + z*z;
}

float Vector3::magnitude() const {
    return sqrt(x*x + y*y + z*z);
}

const Vector3 Vector3::normalize() const {
    Vector3 ret;
    float mag = magnitude();
	
    if(mag != 0.0f) {
        ret.x = x / mag;
        ret.y = y / mag;
		ret.z = z / mag;
    }
	
    return ret;
}

Vector3& Vector3::inormalize() {
    float mag = magnitude();
	
    if(mag != 0.0f) {
        x /= mag;
        y /= mag;
		z /= mag;
    }
	
    return *this;
}

float Vector3::sqrdistance(const Vector3& other) const {
	float dx = other.x - x;
	float dy = other.y - y;
	float dz = other.z - z;
	return dx*dx + dy*dy + dz*dz;
}

float Vector3::distance(const Vector3& other) const {
	float dx = other.x - x;
	float dy = other.y - y;
	float dz = other.z - z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

float Vector3::dot(const Vector3& other) const {
	return x * other.x + y * other.y + z * other.z;
}

#pragma mark - Comparison Operators -

bool sge::operator<(const Vector3& l, const Vector3& r) {
	return l.magnitude() < r.magnitude();
}

bool sge::operator>(const Vector3& l, const Vector3& r) {
	return l.magnitude() > r.magnitude();
}

bool sge::operator<=(const Vector3& l, const Vector3& r) {
	return l.magnitude() <= r.magnitude();
}

bool sge::operator>=(const Vector3& l, const Vector3& r) {
	return l.magnitude() >= r.magnitude();
}

bool sge::operator==(const Vector3& l, const Vector3& r) {
	return l.x == r.x && l.y == r.y && l.z == r.z;
}

bool sge::operator!=(const Vector3& l, const Vector3& r) {
	return l.x != r.x || l.y != r.y || l.z != r.z;
}

// Left side
bool sge::operator<(const Vector3& l, float mag) {
	return l.magnitude() < mag;
}

bool sge::operator>(const Vector3& l, float mag) {
	return l.magnitude() > mag;
}

bool sge::operator<=(const Vector3& l, float mag) {
	return l.magnitude() <= mag;
}

bool sge::operator>=(const Vector3& l, float mag) {
	return l.magnitude() >= mag;
}

// Right side
bool sge::operator<(float mag, const Vector3& r) {
	return mag < r.magnitude();
}

bool sge::operator>(float mag, const Vector3& r) {
	return mag > r.magnitude();
}

bool sge::operator<=(float mag, const Vector3& r) {
	return mag <= r.magnitude();
}

bool sge::operator>=(float mag, const Vector3& r) {
	return mag >= r.magnitude();
}

#pragma mark - Arithmetic -

const Vector3 sge::operator+(const Vector3& vec, const Vector3& other) {
	Vector3 ret;
	ret.x = vec.x + other.x;
	ret.y = vec.y + other.y;
	ret.z = vec.z + other.z;
	return ret;
}

const Vector3 sge::operator+(const Vector3& vec, float amount) {
	Vector3 ret;
	ret.x = vec.x + amount;
	ret.y = vec.y + amount;
	ret.z = vec.z + amount;
	return ret;
}

const Vector3 sge::operator+(float amount, const Vector3& vec) {
	Vector3 ret;
	ret.x = vec.x + amount;
	ret.y = vec.y + amount;
	ret.z = vec.z + amount;
	return ret;
}

const Vector3 sge::operator-(const Vector3& vec) {
	Vector3 ret;
	ret.x = -vec.x;
	ret.y = -vec.y;
	ret.z = -vec.z;
	return ret;
}

const Vector3 sge::operator-(const Vector3& vec, const Vector3& other) {
	Vector3 ret;
	ret.x = vec.x - other.x;
	ret.y = vec.y - other.y;
	ret.z = vec.z - other.z;
	return ret;
}

const Vector3 sge::operator-(const Vector3& vec, float amount) {
	Vector3 ret;
	ret.x = vec.x - amount;
	ret.y = vec.y - amount;
	ret.z = vec.z - amount;
	return ret;
}

const Vector3 sge::operator-(float amount, const Vector3& vec) {
	Vector3 ret;
	ret.x = amount - vec.x;
	ret.y = amount - vec.y;
	ret.z = amount - vec.z;
	return ret;
}

const Vector3 sge::operator*(const Vector3& vec, float scale) {
	Vector3 ret;
	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	ret.z = vec.z * scale;
	return ret;
}

const Vector3 sge::operator*(float scale, const Vector3& vec) {
	Vector3 ret;
	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	ret.z = vec.z * scale;
	return ret;
}

const Vector3 sge::operator/(const Vector3& vec, float scale) {
	Vector3 ret;
	ret.x = vec.x / scale;
	ret.y = vec.y / scale;
	ret.z = vec.z / scale;
	return ret;
}

#pragma mark - Stream Insertion -

std::ostream& sge::operator<<(std::ostream& stream, const Vector3& vec) {
	std::stringstream ss;
	ss << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	stream << ss.str();
	return stream;
}

