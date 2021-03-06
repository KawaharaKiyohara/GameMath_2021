#include "stdafx.h"
#include "system/system.h"
#include "Background.h"

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	Background* bg = NewGO< Background>(0);

	g_camera3D->SetTarget(g_vec3Zero);
	g_camera3D->SetPosition({ 0.0f, 0.0f, -200.0f });
	
	g_sceneLight->SetDirectionLight(1, { 0.0f, 0.0f, 1.0f }, { 1.2f, 1.2f, 1.2f });
	
	// ベクトルを定義する。
	Vector3 v;
	v.x = 20.0f;
	v.y = 0.0f;
	v.z = 0.0f;

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		// step-1 コントローラーの入力でベクトルを拡大して回転させる。
		if (g_pad[0]->IsTrigger(enButtonA)) {
			// 拡大行列と回転行列を記憶する変数を定義する。
			Matrix mScale, mRot;
			// X軸方向に4倍する。
			mScale.MakeScaling(2.0f, 1.0f, 1.0f);
			// Z軸周りに45度回す。
			mRot.MakeRotationZ(Math::DegToRad(45.0f));
			// 拡大行列と回転行列を乗算する。
			Matrix m;
			m = mScale * mRot;
			// 合成した行列を使ってベクトルを空間変換する。
			m.Apply(v);
		}


		//  確認のためにベクトルを表示する。
		g_k2Engine->DrawVector(
			v,			// 表示したいベクトル。
			g_vec3Zero	// 表示する座標。
		);

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

