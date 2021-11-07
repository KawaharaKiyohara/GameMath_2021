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
	// step-1 ����p45�x�ȓ��Ƀv���C���[�������Ă�����ǂ�������B
	// �G�l�~�[����v���C���[�Ɍ������ĐL�т�x�N�g�����v�Z����B
	Vector3 toPlayer = m_player->m_position - m_position;

	// �v���C���[�Ƃ̋������v�Z����B
	float distToPlayer = toPlayer.Length();

	// �v���C���[�Ƃ̋�����400�ȉ���������ǂ�������B
	if (distToPlayer < 400) {
		// �������王��p����
		// �v���C���[�Ɍ������ĐL�т�x�N�g���𐳋K������B
		Vector3 toPlayerDir = toPlayer;
		toPlayerDir.Normalize();
		// �G�l�~�[�̑O��������toPlayerDir�Ƃ̓��ς��v�Z����B
		float t = toPlayerDir.Dot(m_enemyFowrad);
		// ���ς̌��ʂ�acos�֐��ɓn���āAm_enemyFowrad��toPlayerDir�̂Ȃ��p�x�����߂�B
		float angle = acos(t);

		// ����p����
		// fabsf�͐�Βl�����߂�֐��I
		// �p�x�̓}�C�i�X�����݂��邩��A��Βl�Ŕ��肷��B
		if (fabsf(angle) < Math::DegToRad(45.0f)) {
			// �v���C���[�𔭌������̂ŁA�ǂ�������B
			// �G�l�~�[�̍��W�𓮂����B
			m_position += toPlayerDir * 2.0f;
			
			// �G�L�����̑O���������X�V����B
			m_enemyFowrad = toPlayerDir;
		}
	}
	
	
	m_rotation.SetRotationY(atan2(m_enemyFowrad.x, m_enemyFowrad.z));
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetRotation(m_rotation);
	m_modelRender.Update();
}
void Enemy::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}