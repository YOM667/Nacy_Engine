#include "pch.h"
#include "Animation.h"
namespace Utility
{
	double linear(double startTime, double startPoint, double distance, double time)
	{
		return distance * startTime / time + startPoint;
	}
	double easeInQuad(double startTime, double startPoint, double distance, double time) {
		return distance * (startTime /= time) * startTime + startPoint;
	}
	double easeOutQuad(double startTime, double startPoint, double distance, double time) {
		return -distance * (startTime /= time) * (startTime - 2) + startPoint;
	}

	Animator::Animator(double ms, Easing easing, double start, double end)
		: ms(ms), easing(easing), start(start), end(end), time(0), direction(Direction::FORWARD)
	{
		this->point = start;
	}
	double multi(int count, double data)
	{
		if (count == 0 || count == 1)
		{
			return data;
		}
		double result = 0.0;
		for (int index = 0; index < count; index++)
		{
			result *= data;
		}
		return result;
	}
	double Animator::GetPoint(double delta)
	{
		time += (delta);
		switch (this->easing)
		{
		case Easing::Linear:
			this->point = linear(time, point, end - point, ms);
			break;
		case Easing::EaseInQuad:
			this->point = easeInQuad(time, point, end - point, ms);
			break;
		case Easing::EaseOutQuad:
			this->point = easeOutQuad(time, point, end - point, ms);
			break;
		}
		return this->point;

	}
	bool Animator::HasFinished()
	{
		return this->point == this->end;
	}

	void Animator::ChangeDirection(Direction direction)
	{
		auto cache = 0.0;
		cache = end;
		end = start;
		start = cache;

		this->time = 0;
		this->point = start;
		this->direction = direction;
	}

	Direction Animator::GetDirection()
	{
		return this->direction;
	}
}
