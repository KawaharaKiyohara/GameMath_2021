#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_modelRender.SetShadowCasterFlag(true);
	
	return true;
}
void Player::Update()
{
	// step-1 �Q�[���p�b�h�̍��X�e�B�b�N�̓��͗ʂ���L�����N�^�[�̈ړ��x�N�g�����쐬����B

	// step-2 �ړ��x�N�g����10�{�ɂ���

	// step-3 �ړ��x�N�g���ƍ��W�𑫂��Z����  
	
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

	g_k2Engine->DrawVector(
		m_moveVec * 20.0f, // �x�N�g�����������Č����Ȃ��̂ŁA10�{����
		{ m_position.x, m_position.y + 50.0f, m_position.z }
	);
}
void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	
}