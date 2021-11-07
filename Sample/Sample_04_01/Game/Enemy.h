#pragma once

class Player;

class Enemy : public IGameObject
{
public:
	void Init(Vector3 initPos);
	bool Start();
	void Update() ;
	void Render(RenderContext& rc) ;

	ModelRender m_modelRender;	// ���f�������_���[�B
	Vector3 m_position;			// ���W�B
	Quaternion m_rotation;		// ��]�B
	Player* m_player = nullptr;	// �v���C���[�̃A�h���X���L������ϐ��B
};

