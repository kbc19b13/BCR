#include "stdafx.h"
#include "awa.h"

awa::awa()
{
	m_awa = NewGO<prefab::CSkinModelRender>(0);
	m_awa->Init(L"modelData/awa.cmo");
}
awa::~awa()
{

}

void awa::Update()
{
	p_awa.z += 1.0f;
}