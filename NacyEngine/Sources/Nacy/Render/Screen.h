#pragma once
#include "Nacy/Core/GameWindow.h"
#include "Nacy/Core/Core.h"
#include "Graphic.h"
namespace Engine
{
	class NACY_API Screen
	{
	public:
		Screen(uint32_t ID);
		~Screen();
		//render in engine
		//if you want to update data, please override update method
		virtual void render(double delta) = 0;
		//update data
		//dont render anything in the method
		virtual void update(Mouse& mouse);

		virtual void mouseHandle(Mouse* mouse) {};

		virtual void keyPressed(int keyCode) {};
		virtual void keyReleased(int keyCode) {};
		virtual void keyTyped(int keyCode) {};
		bool operator==(Screen& screen);
		bool operator!=(Screen& screen);
		uint32_t GetID();

		void setGraphic(Graphic* m_graphic);
		void setScreenSize(uint32_t width, uint32_t height);
	protected:
		Mouse* mouse;
		Graphic* graphic;
		//Screen's size
		uint32_t screenWidth,screenHeight;
	private:
		//Use the id to determine if two screens are the same.
		uint32_t id;
	};
}
