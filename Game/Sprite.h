#pragma once
class Sprite
{
public:
	void Init(const wchar_t* filePath, float w, float h, bool isDraw3D = false);


private:
	bool m_isDraw3D = false;		//!<3D��Ԃŕ`�悷��H
	CShaderResourceView m_texture;	//!<�e�N�X�`���B
	CSprite	m_sprite;				//!<�X�v���C�g�B
};

