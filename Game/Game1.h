#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"

//�O���錾
class BubbleCreator;
class Camera;
class BackGround;
class Hartsprit;

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();


	//////////�����o�֐�//////////
	void Update();
	bool Start();

	/*const CVector3& GetScale() const {

		return scale;
	}
	void SetScale(const CVector3& a_pos) {
		scale = a_pos;
	}*/

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
	prefab::CSkinModelRender* mo = nullptr;
	//���x��
	CLevel m_level;
	
	//�T�E���h
	prefab::CSoundSource* BGM = nullptr;
	prefab::CSoundSource* BGM2 = nullptr;

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
	Hartsprit* hsp = nullptr;
	prefab::CDirectionLight* m_dirLig = nullptr;
};