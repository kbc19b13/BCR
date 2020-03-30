#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
//�O���錾
class BubbleCreator;
class Camera;

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();


	//////////�����o�֐�//////////
	void Update();
	bool Start();
	
	const CVector3& GetScale() const {
		
		return scale;
	}
	void SetScale(const CVector3& a_pos) {
		scale = a_pos;
	}

	////////////////////////////////////////////////
	//awa�̊m�F�p�ϐ�_��ŏ���
	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;
	///////////////////////////////////////////////
	float s = 15.0f;


	
	/////////Singleton�p�^�[��///////////////
		//Game1����̂Ɍ���
	static Game1* P_GetInstance()
	{
		return m_instance;
	}
private:
	static Game1* m_instance;
	/////////////////////////////////////////

	//////////�����o�ϐ�//////////
	//�X�L�����f�������_�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//���x��
	CLevel m_level;							
	//�X�v���C�g�����_�[
	prefab::CSpriteRender* m_spriteRender;//hp�o�[
	prefab::CSpriteRender* h_spriteRender;//hp
	//�X�v���C�g�����_�[�̍��W
	CVector3 m_position = { -460,320,0 };
	CVector3 h_position = { -460,320,0 };

	CVector3 scale = {s, 1.0f, 1.0f};
	

	//�N���X�����[�h
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	BubbleCreator* isi = nullptr;
	prefab::CDirectionLight* m_dirLig = nullptr;
};