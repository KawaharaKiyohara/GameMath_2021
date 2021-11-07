#pragma once
class Player : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;

	ModelRender m_modelRender;
	Vector3 m_position;		// ���W
	Vector3 m_moveVec;		// �ړ��x�N�g��
};

