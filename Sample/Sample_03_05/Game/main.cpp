#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 2.0f, -10.0f);
	g_camera3D->SetTarget(0.0f, 2.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ���C�g��^�ォ��ݒ�B
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	
	// step-1 �x�N�g�����`����B


	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{

		// step-2 �R���g���[���[��A�{�^���̓��͂Ńx�N�g���𐳋K������B
		
		// step-3 �x�N�g����\������B
		

		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

