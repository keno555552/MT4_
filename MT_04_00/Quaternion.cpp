#include "Quaternion.h"

Quaternion Quaternion::operator+(const Quaternion& target) {
    return {x + target.x, y + target.y, z + target.z , w + target.w};
}

Quaternion Quaternion::operator-(const Quaternion& target) {
    return { x - target.x, y - target.y, z - target.z , w - target.w };
}

Quaternion Quaternion::operator*(const Quaternion& target) {
    return {
        w * target.x + x * target.w + y * target.z - z * target.y,
        w * target.y - x * target.z + y * target.w + z * target.x,
        w * target.z + x * target.y - y * target.x + z * target.w,
        w * target.w - x * target.x - y * target.y - z * target.z
	};
}

Quaternion Quaternion::operator/(const Quaternion& target) {
	return { x / target.x, y / target.y, z / target.z , w / target.w };
}

Quaternion Multiply(const Quaternion& m1, const Quaternion& m2) {
    Quaternion result = m1;
	return result * m2;
}

Quaternion IdentityQuaternion() {
    return {0.0f, 0.0f, 0.0f, 1.0f};
}

Quaternion Conjugate(const Quaternion& target) {
    return { -target.x,-target.y,-target.z,target.w };
}

float Norm(const Quaternion& target) {
    return sqrtf(target.x * target.x + target.y * target.y + target.z * target.z + target.w * target.w );
}

Quaternion Normalize(const Quaternion& target) {
	float norm = Norm(target);
    if (norm != 0) {
        return { target.x / norm, target.y / norm, target.z / norm, target.w / norm };
    } 
    return { 0,0,0,0 };
}

Quaternion Inverse(const Quaternion& target) {
    float sqNorm = target.x * target.x + target.y * target.y + target.z * target.z + target.w * target.w;

    if (sqNorm <= 1e-12f) {
        return { 0,0,0,0 };
    }

    Quaternion c = Conjugate(target);
    float invSq = 1.0f / sqNorm;
    return { c.x * invSq, c.y * invSq, c.z * invSq, c.w * invSq };
}

