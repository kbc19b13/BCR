#include "stdafx.h"
#include "Camera.h"
#include "Player.h"

Camera::Camera()
{
}


Camera::~Camera()
{
}

bool Camera::Start()
{
	//�����_���王�_�܂ł̃x�N�g����ݒ�B
	m_toCameraPos.Set(0.0f, 30.0f,10.0f);
	//�v���C���[�̃C���X�^���X��T���B
	m_player = FindGO<Player>("doll");

	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��B
	MainCamera().SetNear(1.0f);
	MainCamera().SetFar(20000.0f);

	return true;
}

void Camera::Update()
{
	//�����_���v�Z�B
	CVector3 target = m_player->GetPosition();
	target.y += 100.0f;

	//���_���v�Z����B
	CVector3 pos = target + m_toCameraPos;
	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��B
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);

	//�J�����̍X�V�B
	MainCamera().Update();
}