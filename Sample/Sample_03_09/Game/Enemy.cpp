#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

void Enemy::Init(Vector3 initPos)
{
	m_position = initPos;
	m_rotation.SetRotationY(Math::PI);
	// step-1 �v���C���[�̃C���X�^���X�̃A�h���X����������B

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
	
	// step-3 �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g����\������B

	// step-4 �v���C���[�Ƃ̋������v�Z����B

	// step-5 �v���C���[�Ƃ̋�����200�ȉ��ɂȂ�����A�v���C���[�𔭌������Ƃ������b�Z�[�W��\������B
	
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}