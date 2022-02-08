#include "stdafx.h"
#include "system/system.h"
#include "Background.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	Background* bg = NewGO< Background>(0);

	g_camera3D->SetTarget(g_vec3Zero);
	g_camera3D->SetPosition({ 0.0f, 0.0f, -200.0f });
	
	g_sceneLight->SetDirectionLight(1, { 0.0f, 0.0f, 1.0f }, { 1.2f, 1.2f, 1.2f });
	
	// �x�N�g�����`����B
	Vector3 v;
	v.x = 20.0f;
	v.y = 0.0f;
	v.z = 0.0f;

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-1 �R���g���[���[�̓��͂Ńx�N�g�����g�債�ĉ�]������B
		if (g_pad[0]->IsTrigger(enButtonA)) {
			// �g��s��Ɖ�]�s����L������ϐ����`����B
			Matrix mScale, mRot;
			// X��������4�{����B
			mScale.MakeScaling(2.0f, 1.0f, 1.0f);
			// Z�������45�x�񂷁B
			mRot.MakeRotationZ(Math::DegToRad(45.0f));
			// �g��s��Ɖ�]�s�����Z����B
			Matrix m;
			m = mScale * mRot;
			// ���������s����g���ăx�N�g������ԕϊ�����B
			m.Apply(v);
		}


		//  �m�F�̂��߂Ƀx�N�g����\������B
		g_k2Engine->DrawVector(
			v,			// �\���������x�N�g���B
			g_vec3Zero	// �\��������W�B
		);

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

