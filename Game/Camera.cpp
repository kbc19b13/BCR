#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

bool Camera::Start()
{
	//�����_���王�_�܂ł̃x�N�g����ݒ�B
	m_toCameraPos.Set(0.0f, 50.0f, 100.0f);
	//�v���C���[�̃C���X�^���X��T���B
	m_player = FindGO<Player>("doll");

	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��B
	MainCamera().SetNear(1.0f);
	MainCamera().SetFar(20000.0f);

	return true;
}
