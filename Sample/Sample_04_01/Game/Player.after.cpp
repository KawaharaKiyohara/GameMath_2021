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
	if (g_pad[0]->IsTrigger(enButtonA)) {
		Vector3 vRight;
		vRight.x = 1.0f;
		vRight.y = 0.0f;
		vRight.z = 0.0f;
		m_moveVec += vRight * 2.0f;
	}
	// step-2 B�{�^���̓��͂ō������̃x�N�g����������B
	if (g_pad[0]->IsTrigger(enButtonB)) {
		Vector3 vLeft;
		vLeft.x = -1.0f;
		vLeft.y = 0.0f;
		vLeft.z = 0.0f;
		m_moveVec += vLeft * 2.0f;
	}
	// step-3 X�{�^���̓��͂Ŏ΂߉E�����̃x�N�g����������B
	if (g_pad[0]->IsTrigger(enButtonX)) {
		Vector3 v;
		v.x = 1.0f;
		v.y = 0.0f;
		v.z = 1.0f;
		v.Normalize();
		m_moveVec += v * 2.0f;
	}

	// step-4 Y�{�^���̓��͂Ŏ΂߉E�����̃x�N�g����������B
	if (g_pad[0]->IsTrigger(enButtonY)) {
		Vector3 v;
		v.x = -1.0f;
		v.y = 0.0f;
		v.z = 1.0f;
		v.Normalize();
		m_moveVec += v * 2.0f;
	}

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