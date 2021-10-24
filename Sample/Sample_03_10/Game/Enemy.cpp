#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

void Enemy::Init(Vector3 initPos)
{
	m_position = initPos;
	m_rotation.SetRotationY(Math::PI);
	// �����o�ϐ���m_player�ɃA�h���X���L�����Ă����B�A
	m_player = FindGO<Player>("Player");
}
bool Enemy::Start()
{
	m_modelRender.Init("Assets/modelData/enemy/enemy.tkm");
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetScale({ 3.0f, 3.0f, 3.0f });
	return true;
}
void Enemy::Update()
{
	// �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g�����v�Z����B
	Vector3 toPlayer = m_player->m_position - m_position;
	
	// �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g����\������B
	g_k2Engine->DrawVector(toPlayer, m_position);

	// �v���C���[�Ƃ̋������v�Z����B
	float distToPlayer = toPlayer.Length();

	// �v���C���[�Ƃ̋�����400�ȉ���������ǂ�������B
	if (distToPlayer < 400) {
		// step-1 �v���C���[�Ɍ������ĐL�т�x�N�g���𐳋K������B

		// step-2 step-1�ŋ��߂��x�N�g���𗘗p���āA�G�l�~�[�̍��W�𓮂����B
		
	}
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}