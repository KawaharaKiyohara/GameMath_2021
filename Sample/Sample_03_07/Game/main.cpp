#include "stdafx.h"
#include "system/system.h"
#include "Background.h"
#include "Player.h"
#include "GameCamera.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	
	auto bg = NewGO<Background>(0);
	auto pl = NewGO<Player>(0,"Player");
	auto cam = NewGO<GameCamera>(0);

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

