#include "Game/BeatBap.h"

int main()
{
	auto beatbap = new BeatBap();
	auto app = BeatBap::GetApplication();
	beatbap->Init();
	beatbap->Run();
	beatbap->Stop();
	delete beatbap;
	return 0;
}