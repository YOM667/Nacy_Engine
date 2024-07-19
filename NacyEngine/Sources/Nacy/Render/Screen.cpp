#include "pch.h"
#include "Screen.h"
#include "../Core/NApplication.h"
namespace Engine
{
	Screen::Screen(uint32_t ID) : id(ID)
	{
		//Nothing to do
	}
	Screen::~Screen()
	{
		//if (this->graphic != nullptr) { delete this->graphic; }
		if (this->mouse != nullptr) { delete this->mouse; }
	}

	void Screen::update(Mouse& mouse)
	{
		this->mouse = &mouse;
	}

	bool Screen::operator==(Screen& screen)
	{
		return screen.GetID() == this->id;
	}

	bool Screen::operator!=(Screen& screen)
	{
		return screen.GetID() != this->id;
	}

	uint32_t Screen::GetID()
	{
		return this->id;
	}

	void Screen::setGraphic(Graphic* m_graphic)
	{
		this->graphic = m_graphic;
	}

	void Screen::setScreenSize(uint32_t width, uint32_t height)
	{
		this->screenWidth = width;
		this->screenHeight = height;
	}


}

