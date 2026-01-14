#pragma once
#include <math.h>
#include "Vector3.h"

struct Vector3;
typedef struct Quaternion {

	///定義
	float x, y, z, w;

	///演算子再定義
	Quaternion operator+(const Quaternion& target);
	Quaternion operator-(const Quaternion& target);
	Quaternion operator*(const Quaternion& target);
	Quaternion operator/(const Quaternion& target);

}Quaternion;

// 積
Quaternion Multiply(const Quaternion& m1, const Quaternion& m2);
// 単位行列の作成
Quaternion IdentityQuaternion();
// 共役
Quaternion Conjugate(const Quaternion& target);
// ノルム
float Norm(const Quaternion& target);
// 単位化
Quaternion Normalize(const Quaternion& target);
// 4. 逆行列
Quaternion Inverse(const Quaternion& target);


// 任意軸回転を表すQuaternionの作成
Quaternion MakeRotateAxisAngleQuaternioin(const Vector3& axis, float angle);

