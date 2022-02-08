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
	v.x = 0.0f;
	v.y = 100.0f;
	v.z = 0.0f;

	// step-1 �x�N�g���̍��W��\���ϐ����`����B

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-2 �R���g���[���[�̓��͂Ńx�N�g����X������2���s�ړ�������B
		
		// step-3 �R���g���[���[�̓��͂Ńx�N�g����Y������2���s�ړ�������B

		// step-4 �R���g���[���[�̓��͂Ńx�N�g����Z������2���s�ړ�������B

		// step-5 �m�F�̂��߃x�N�g����\������B
		

		K2Engine::GetInstance()->Execute();
	
	}
	// DeleteGO(bg);
	K2Engine::DeleteInstance();

	return 0;
}

