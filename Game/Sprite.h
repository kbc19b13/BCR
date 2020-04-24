#pragma once
class Sprite
{
public:
	void Init(const wchar_t* filePath, float w, float h, bool isDraw3D = false);


private:
	bool m_isDraw3D = false;		//!<3D空間で描画する？
	CShaderResourceView m_texture;	//!<テクスチャ。
	CSprite	m_sprite;				//!<スプライト。
};

