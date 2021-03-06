#pragma once
class Background : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	ModelRender m_modelRender;	// モデル描画処理。
};

