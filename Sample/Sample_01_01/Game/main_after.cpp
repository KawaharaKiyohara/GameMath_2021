#include "stdafx.h"
#include "system/system.h"


///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 0.0f, -1500.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();

	// step-1 ModelRender�N���X�̃I�u�W�F�N�g���T��`����B
	ModelRender starRender[5];

	// step-2 ���̃��f�������[�h����B
	for (int i = 0; i < 5; i++) {
		starRender[i].Init("Assets/modelData/star.tkm");
	}

	// step-3 �f�J���g���W�n�ł̍��W���w�肷��B
	starRender[0].SetPosition( -400.0f,   0.0f, 0.0f );
	starRender[1].SetPosition( -200.0f, 100.0f, 0.0f );
	starRender[2].SetPosition(    0.0f, 200.0f, 0.0f );
	starRender[3].SetPosition(  200.0f, 100.0f, 0.0f );
	starRender[4].SetPosition(  400.0f,   0.0f, 0.0f );


	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-4 ���̂���₱�����X�V����B
		for (int i = 0; i < 5; i++) {
			starRender[i].Update();
		}
		// step-5 ����`�悷��B
		for (int i = 0; i < 5; i++) {
			starRender[i].Draw(renderContext);
		}

		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

