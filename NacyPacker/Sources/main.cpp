#include <NacyEngine.h>

#include <iostream>
int main()
{
	auto x = Engine::normalize(Engine::Vector2F(3.0f, 4.0f)).x;
	auto y = Engine::normalize(Engine::Vector2F(3.0f, 4.0f)).y;
	std::cout << "x: " << x << "y: " << y << std::endl;
	system("pause");
	return 0;
}