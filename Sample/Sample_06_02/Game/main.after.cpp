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
	v.x = 80.0f;
	v.y = 80.0f;
	v.z = 0.0f;

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-1 �R���g���[���[�̓��͂�Z������̉�]�s����쐬���ĉ�]������B
		if (g_pad[0]->IsTrigger(enButtonA)) {
			Matrix m;
			// Z�������45�x��]����s����쐬����B
			m.MakeRotationZ(Math::DegToRad(45.0f));
			// �x�N�g���ƍs��̏�Z���s���B
			m.Apply(v);
		}
		// step-2 �R���g���[���[�̓��͂�X������̉�]�s����쐬���ĉ�]������B
		if (g_pad[0]->IsTrigger(enButtonB)) {
			Matrix m;
			// X�������45�x��]����s����쐬����B
			m.MakeRotationX(Math::DegToRad(45.0f));
			// �x�N�g���ƍs��̏�Z���s���B
			m.Apply(v);
		}

		// step-3 �R���g���[���[�̓��͂�Y������̉�]�s����쐬���ĉ�]������B
		if (g_pad[0]->IsTrigger(enButtonX)) {
			Matrix m;
			// Y�������45�x��]����s����쐬����B
			m.MakeRotationY(Math::DegToRad(45.0f));
			// �x�N�g���ƍs��̏�Z���s���B
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

