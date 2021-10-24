#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

void Enemy::Init(Vector3 initPos)
{
	m_position = initPos;
	m_rotation.SetRotationY(Math::PI);
	// step-1 �v���C���[�̃C���X�^���X�̃A�h���X����������B
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
	// step-2 �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g�����v�Z����B
	Vector3 toPlayer = m_player->m_position - m_position;
	
	// step-3 �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g����\������B
	g_k2Engine->DrawVector(toPlayer, m_position);

	// step-4 �v���C���[�Ƃ̋������v�Z����B
	float distToPlayer = toPlayer.Length();

	// step-5 �v���C���[�Ƃ̋�����200�ȉ��ɂȂ�����A�v���C���[�𔭌������Ƃ������b�Z�[�W��\������B
	if (distToPlayer < 200) {
		MessageBoxA(nullptr, "�v���C���[���������B", "�ʒm", MB_OK);
	}
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}