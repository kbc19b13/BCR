#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"

//�O���錾
class BubbleCreator;
class Camera;
class BackGround;

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

	int Gets_up() {
		return s_up;
	}
	int Gethp_up() {
		return hp_up;
	}

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

	CVector3 scale = { s, 1.0f, 1.0f };

	float s = 15.0f;

	//�A�C�e���̌��\��
	//�X�v���C�g�����_�[
	prefab::CSpriteRender* s_up_spriteRender[10] = { nullptr };
	prefab::CSpriteRender* hp_up_spriteRender[10] = { nullptr };
	//�X�v���C�g�����_�[�̍��W
	CVector3 s_up_position = { 0.0f,0.0f,0.0f };
	CVector3 hp_up_position = { 0.0f,0.0f,0.0f };
	//�A�C�e����
	int s_up = 0;
	int hp_up = 0;

	//std::vector<Sprite*> s_up_spriteRender;

	//�N���X�����[�h
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	BubbleCreator* isi = nullptr;
	prefab::CDirectionLight* m_dirLig = nullptr;
};