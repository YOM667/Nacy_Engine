#include "BeatBap.hpp"

int main()
{
	auto app = BeatBap::GetInstance();
	app->Start();

	return 0;
}