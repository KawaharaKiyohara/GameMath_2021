#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_modelRender.SetShadowCasterFlag(true);
	
	return true;
}
void Player::Update()
{
	// step-1 ゲームパッドの左スティックの入力量からキャラクターの移動ベクトルを作成する。
	m_moveVec.x = g_pad[0]->GetLStickXF();
	m_moveVec.z = g_pad[0]->GetLStickYF();

	// step-2 移動ベクトルを10倍にする
	m_moveVec *= 10.0f;

	// step-3 移動ベクトルと座標を足し算する  
	m_position += m_moveVec;
	
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

	g_k2Engine->DrawVector(
		m_moveVec * 20.0f, // ベクトルが小さくて見えないので、10倍する
		{ m_position.x, m_position.y + 50.0f, m_position.z }
	);
}
void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	
}