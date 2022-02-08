#pragma once
class Background : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	ModelRender m_modelRender;	// ���f���`�揈���B
};

