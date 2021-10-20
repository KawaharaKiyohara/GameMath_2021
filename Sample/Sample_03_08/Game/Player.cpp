#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_modelRender.SetShadowCasterFlag(true);
	
	// �O�������ɐi�ރx�N�g��
	m_moveVec.z = 2.0f;
	return true;
}
void Player::Update()
{	
	// step-1 A�{�^���̓��͂ŉE�����̃x�N�g����������

	// step-2 B�{�^���̓��͂ō������̃x�N�g����������B
	
	// step-3 X�{�^���̓��͂Ŏ΂߉E�����̃x�N�g����������B
	
	// step-4 Y�{�^���̓��͂Ŏ΂߉E�����̃x�N�g����������B
	

	// �ړ��x�N�g���ƍ��W�𑫂��Z����  
	m_position += m_moveVec;

	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

	g_k2Engine->DrawVector(
		m_moveVec * 40.0f, // �x�N�g�����������Č����Ȃ��̂ŁA10�{����
		{ m_position.x, m_position.y + 50.0f, m_position.z }
	);
}
void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	
}