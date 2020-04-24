#include "stdafx.h"
#include "Sprite.h"

void Sprite::Init(const wchar_t* texFilePath, float w, float h, bool isDraw3D)
{
	m_isDraw3D = isDraw3D;
	m_texture.CreateFromDDSTextureFromFile(texFilePath);
	m_sprite.Init(m_texture, w, h);
}