#include <Novice.h>
#include "myMath.h"
#include "physicsEngine.h"
#include "ImGui.h"
#include "Quaternion.h"

const char kWindowTitle[] = "MT4_05_カン_ケンリャン";

int kWindowWidth = 1280, kWindowHeight = 720;

///=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
/// 重要定義、構造体作り
///=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

// キー入力結果を受け取る箱
char keys[256] = { 0 };
char preKeys[256] = { 0 };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);


	///=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
	/// 初期化
	///=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

	Quaternion q1 = { 2.0f, 3.0f, 4.0f, 1.0f };
	Quaternion q2 = { 1.0f, 3.0f, 5.0f, 2.0f };
	Quaternion identity = IdentityQuaternion();
	Quaternion conj = Conjugate(q1);
	Quaternion inv = Inverse(q1);
	Quaternion normal = Normalize(q1);
	//Quaternion mul1 = q1* q2;
	//Quaternion mul2 = q2* q1;
	Quaternion mul1 = Multiply(q1, q2);
	Quaternion mul2 = Multiply(q2, q1);

	float norm = Norm(q1);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
		/// ボタン処理
		///=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=



		///=========================================================================================================================================================================================
		/// 更新処理
		///=========================================================================================================================================================================================

		///=========================================================================================================================================================================================
		/// 描画処理
		///=========================================================================================================================================================================================

		{
			int lineHeight = 20;
			int unitWidth = 60;
			{
				Novice::ScreenPrintf(0 * unitWidth, 0 * lineHeight, "%.02f", identity.x);
				Novice::ScreenPrintf(1 * unitWidth, 0 * lineHeight, "%.02f", identity.y);
				Novice::ScreenPrintf(2 * unitWidth, 0 * lineHeight, "%.02f", identity.z);
				Novice::ScreenPrintf(3 * unitWidth, 0 * lineHeight, "%.02f", identity.w);
			}
			{
				Novice::ScreenPrintf(0 * unitWidth, 1 * lineHeight, "%.02f", conj.x);
				Novice::ScreenPrintf(1 * unitWidth, 1 * lineHeight, "%.02f", conj.y);
				Novice::ScreenPrintf(2 * unitWidth, 1 * lineHeight, "%.02f", conj.z);
				Novice::ScreenPrintf(3 * unitWidth, 1 * lineHeight, "%.02f", conj.w);
			}
			{
				Novice::ScreenPrintf(0 * unitWidth, 2 * lineHeight, "%.02f", inv.x);
				Novice::ScreenPrintf(1 * unitWidth, 2 * lineHeight, "%.02f", inv.y);
				Novice::ScreenPrintf(2 * unitWidth, 2 * lineHeight, "%.02f", inv.z);
				Novice::ScreenPrintf(3 * unitWidth, 2 * lineHeight, "%.02f", inv.w);
			}
			{
				Novice::ScreenPrintf(0 * unitWidth, 3 * lineHeight, "%.02f", normal.x);
				Novice::ScreenPrintf(1 * unitWidth, 3 * lineHeight, "%.02f", normal.y);
				Novice::ScreenPrintf(2 * unitWidth, 3 * lineHeight, "%.02f", normal.z);
				Novice::ScreenPrintf(3 * unitWidth, 3 * lineHeight, "%.02f", normal.w);
			}
			{
				Novice::ScreenPrintf(0 * unitWidth, 4 * lineHeight, "%.02f", mul1.x);
				Novice::ScreenPrintf(1 * unitWidth, 4 * lineHeight, "%.02f", mul1.y);
				Novice::ScreenPrintf(2 * unitWidth, 4 * lineHeight, "%.02f", mul1.z);
				Novice::ScreenPrintf(3 * unitWidth, 4 * lineHeight, "%.02f", mul1.w);
			}
			{
				Novice::ScreenPrintf(0 * unitWidth, 5 * lineHeight, "%.02f", mul2.x);
				Novice::ScreenPrintf(1 * unitWidth, 5 * lineHeight, "%.02f", mul2.y);
				Novice::ScreenPrintf(2 * unitWidth, 5 * lineHeight, "%.02f", mul2.z);
				Novice::ScreenPrintf(3 * unitWidth, 5 * lineHeight, "%.02f", mul2.w);
			}
			{
				Novice::ScreenPrintf(0 * unitWidth, 6 * lineHeight, "%.02f", norm);
			}




			Novice::ScreenPrintf(5 * unitWidth, 0 * lineHeight, ": Identity");
			Novice::ScreenPrintf(5 * unitWidth, 1 * lineHeight, ": Conjugate");
			Novice::ScreenPrintf(5 * unitWidth, 2 * lineHeight, ": Inverse");
			Novice::ScreenPrintf(5 * unitWidth, 3 * lineHeight, ": Normalize");
			Novice::ScreenPrintf(5 * unitWidth, 4 * lineHeight, ": Multiply(q1, q2)");
			Novice::ScreenPrintf(5 * unitWidth, 5 * lineHeight, ": Multiply(q2, q1)");
			Novice::ScreenPrintf(5 * unitWidth, 6 * lineHeight, ": Norm");
		}

		/// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
		/// StageEND
		/// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
