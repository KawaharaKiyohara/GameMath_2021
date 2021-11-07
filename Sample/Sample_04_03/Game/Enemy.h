#pragma once

class Player;

class Enemy : public IGameObject
{
public:
	void Init(Vector3 initPos);
	bool Start();
	void Update() ;
	void Render(RenderContext& rc) ;

	ModelRender m_modelRender;		// ���f�������_���[�B
	Vector3 m_position;				// ���W�B
	Quaternion m_rotation;			// ��]�B
	Vector3 m_enemyFowrad = {0.0f, 0.0f, -1.0f};	// �G�̑O���x�N�g��
	Player* m_player = nullptr;		// �v���C���[�̃A�h���X���L������ϐ��B
};

