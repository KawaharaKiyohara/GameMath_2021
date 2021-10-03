#include "stdafx.h"
#include "system/system.h"



///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	g_camera3D->SetPosition(0.0f, 0.0f, -1000.0f);
	g_camera3D->SetTarget(0.0f, 0.0f, 0.0f);

	auto& renderContext = g_graphicsEngine->GetRenderContext();
	// ���C�g��^�ォ��ݒ�B
	g_sceneLight->SetDirectionLight(0, { 0.0f, -1.0f, 0.0f }, { 0.8f, 0.8f, 0.8f });
	g_renderingEngine->SetCascadeNearAreaRates(0.1f, 0.4f, 0.2f);
	

	// step-1 �x�N�g�����`����B
	Vector3 testVector;
	testVector.x = 5.0f;
	testVector.y = 4.0f;
	testVector.z = 3.0f;

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		// step-2 �x�N�g���̒������v�Z����B
		// x��2����v�Z����
		float x2 = testVector.x * testVector.x;
		// y��2����v�Z����
		float y2 = testVector.y * testVector.y;
		// z��2����v�Z����
		float z2 = testVector.z * testVector.z;
		// x^2 + y^2 + z^2���v�Z����B
		float t = x2 + y2 + z2;
		// x^2 + y^2 + z^2�̕��������v�Z���āA
		// �x�N�g���̒��������߂�B
		// C����ɂ͕����������߂�sqrt()�֐�������B
		float length = sqrt(t);

		// step-3 �x�N�g���̒��������b�Z�[�W�{�b�N�X�ŕ\������B
		char text[256];
		sprintf(text, "�x�N�g���̒����� %f �ł��B\n", length);
		MessageBoxA( nullptr, text, "���ʒʒm", MB_OK);
	
		K2Engine::GetInstance()->Execute();
	
	}
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

