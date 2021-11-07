#include "stdafx.h"
#include "Player.h"


bool Player::Start()
{

	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model_4_1.fx";
	modelInitData.m_expandConstantBuffer = m_light;
	modelInitData.m_expandConstantBufferSize = sizeof(m_light);
	m_modelRender.InitForwardRendering(modelInitData);
	
	m_light[0].ligDir.Set(1.0f, -1.0f, 0.0f);
	m_light[0].ligDir.Normalize();
	m_light[0].ligColor.Set(1.0f, 0.0f, 0.0f, 0.0f);

	m_light[1].ligDir.Set(-1.0f, -1.0f, 0.0f);
	m_light[1].ligDir.Normalize();
	m_light[1].ligColor.Set(0.0f, 1.0f, 0.0f, 0.0f);

	m_light[2].ligDir.Set(1.0f, -1.0f, -1.0f);
	m_light[2].ligDir.Normalize();
	m_light[2].ligColor.Set(0.0f, 0.0f, 1.0f, 0.0f);

	m_light[3].ligDir.Set(-1.0f, -1.0f, -1.0f);
	m_light[3].ligDir.Normalize();
	m_light[3].ligColor.Set(0.0f, 1.0f, 1.0f, 0.0f);

	Quaternion qRot;
	qRot.SetRotationDegY(180.0f);
	m_modelRender.SetRotation(qRot);
	return true;
}
void Player::Update()
{	
	// �v���C���[�̈ړ��x�N�g�����v�Z����B
	m_moveVec.x = g_pad[0]->GetLStickXF();
	m_moveVec.z = g_pad[0]->GetLStickYF();
	m_moveVec *= 5.0f;

	// �ړ��x�N�g���ƍ��W�𑫂��Z����  
	m_position += m_moveVec;
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();

}
void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	
}