#include "Quaternion.h"
#include "myMath.h"


#define USE_NOVICE

#ifdef USE_NOVICE
#include "Novice.h"
#endif




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

#ifdef USE_NOVICE
void QuaternionScreenPrintf(int x, int y, Quaternion& quaternion, const char* name) {

    if (name == nullptr) {
        Novice::ScreenPrintf(x, y, "%.02f   %.02f   %.02f   %.02f", quaternion.x, quaternion.y, quaternion.z, quaternion.w);
    } else {
        Novice::ScreenPrintf(x, y, "%.02f   %.02f   %.02f   %.02f   %s", quaternion.x,quaternion.y,quaternion.z,quaternion.w, name);
    }
}
#endif // 

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

Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle) {
    Vector3 nAxis = Normalize(axis);
    if (nAxis.x == 0 && nAxis.y == 0 && nAxis.z == 0) {
        return IdentityQuaternion();
	}

    float halfAngle = angle * 0.5f;
    float sinHalfAngle = sinf(halfAngle);
    float cosHalfAngle = cosf(halfAngle);
    return {
        nAxis.x * sinHalfAngle,
        nAxis.y * sinHalfAngle,
        nAxis.z * sinHalfAngle,
        cosHalfAngle
	};
}

Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion) {
	Quaternion q = Normalize(quaternion); // 确保四元数是单位四元数
    Quaternion p = { vector.x, vector.y, vector.z, 0.0f };
    Quaternion qInv = Conjugate(q); // 假設 q 已經 normalize

    Quaternion result = q * p * qInv;

    return { result.x, result.y, result.z };


}

Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion) {
	float x = quaternion.x;
	float y = quaternion.y;
	float z = quaternion.z;
	float w = quaternion.w;

    return {
		x* x - y * y - z * z + w * w,        2.0f * (x * y + z * w),	     2.0f * (x * z - y * w),			0.0f,
		      2.0f * (x * y - z * w),  w* w - x * x + y * y - z * z,	     2.0f * (y * z + x * w),			0.0f,
              2.0f * (x * z + y * w),		 2.0f * (y * z - x * w),  w * w -x * x - y * y + z * z ,	        0.0f,
		                        0.0f,						   0.0f,						   0.0f,			1.0f
    };
}

