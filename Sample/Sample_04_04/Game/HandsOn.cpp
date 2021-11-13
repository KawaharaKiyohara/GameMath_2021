#include "stdafx.h"

/// <summary>
/// �|���S���̖@�����v�Z����
/// </summary>
/// <param name="p0">�O�Ԗڂ̒��_���W</param>
/// <param name="p1">�P�Ԗڂ̒��_���W</param>
/// <param name="p2">�Q�Ԗڂ̒��_���W</param>
/// <returns></returns>
Vector3 CalcNormal(Vector3 p0, Vector3 p1, Vector3 p2)
{
	Vector3 normal;
	// step-1 0�Ԗڂ̒��_����P�Ԗڂ̒��_�Ɍ������ĐL�т�x�N�g��v1���v�Z����B
	Vector3 v1 = p1 - p0;
	// step-2 0�Ԗڂ̒��_����Q�Ԗڂ̒��_�Ɍ������ĐL�т�x�N�g��v2���v�Z����B
	Vector3 v2 = p2 - p0;
	// step-3 v1��v2�ɐ����ȃx�N�g�������߂�B
	normal = Cross(v1, v2);
	// step-4 �O�ςŋ��߂��x�N�g���͒P�ʃx�N�g���ł͂Ȃ��̂ŁA���K������B
	normal.Normalize();

	return normal;
}