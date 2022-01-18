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

	// step-1 �x�N�g�����`����B

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-3 �R���g���[���[�̓��͂�Z������̉�]�s����쐬���ĉ�]������B
		
		// step-4 �R���g���[���[�̓��͂�X������̉�]�s����쐬���ĉ�]������B

		// step-5 �R���g���[���[�̓��͂�Y������̉�]�s����쐬���ĉ�]������B

		// step-2 �m�F�̂��߂Ƀx�N�g����\������B

		K2Engine::GetInstance()->Execute();

	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

