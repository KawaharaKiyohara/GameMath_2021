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
	v.x = 8.0f;
	v.y = 8.0f;
	v.z = 8.0f;

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-1 �R���g���[���[�̓��͂�X���@�ɂւ̊g��s����쐬���Ċg�傳����B
		if (g_pad[0]->IsPress(enButtonA)) {
			float m[3][3];
			// 1�s��
			m[0][0] = 1.02f;	// 1.02�{����
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			// 2�s��
			m[1][0] = 0.0f;
			m[1][1] = 1.0f;
			m[1][2] = 0.0f;
			// 3�s��
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.0f;

			// �x�N�g���ƍs��̏�Z���s���B
			Vector3 vSrc = v;
			v.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + v.z * m[2][0];
			v.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + v.z * m[2][1];
			v.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + v.z * m[2][2];
		}
		// step-2 �R���g���[���[�̓��͂�Y�������ւ̊g��s����쐬���Ċg�傳����B
		if (g_pad[0]->IsPress(enButtonB)) {
			float m[3][3];
			// 1�s��
			m[0][0] = 1.0f;	
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			// 2�s��
			m[1][0] = 0.0f;
			m[1][1] = 1.02f; // 1.02�{����
			m[1][2] = 0.0f;
			// 3�s��
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.0f;

			// �x�N�g���ƍs��̏�Z���s���B
			Vector3 vSrc = v;
			v.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + v.z * m[2][0];
			v.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + v.z * m[2][1];
			v.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + v.z * m[2][2];
		}

		// step-3 �R���g���[���[�̓��͂�Z�������ւ̊g��s����쐬���Ċg�傳����B
		if (g_pad[0]->IsPress(enButtonY)) {
			float m[3][3];
			// 1�s��
			m[0][0] = 1.0f;
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			// 2�s��
			m[1][0] = 0.0f;
			m[1][1] = 1.0f;
			m[1][2] = 0.0f;
			// 3�s��
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.02f; // 1.02�{����

			// �x�N�g���ƍs��̏�Z���s���B
			Vector3 vSrc = v;
			v.x = vSrc.x * m[0][0] + vSrc.y * m[1][0] + v.z * m[2][0];
			v.y = vSrc.x * m[0][1] + vSrc.y * m[1][1] + v.z * m[2][1];
			v.z = vSrc.x * m[0][2] + vSrc.y * m[1][2] + v.z * m[2][2];
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

