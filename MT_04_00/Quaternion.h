#pragma once
#include <math.h>

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
//// 5. 転置行列
//Quaternion Transpose(const Quaternion m);

