#include "pch.h"
#include "Utilities.h"

namespace Utilities
{
	namespace Log
	{
		const char* Logger::levels[LEVEL_COUNT] = {
			"DEBUG", "INFO", "WARN", "ERROR", "FATAL"
		};

		Logger* Logger::logInstance = nullptr;

		Logger::Logger()
		{
			std::string filePath = "./log/";
			if (!std::filesystem::exists(filePath))
			{
				std::filesystem::create_directory(filePath);
			}
			this->localFile = filePath + "logs_" + Time::getTime("%Y-%m-%d %H_%M_%S") + ".log";

			this->open();
		}
		Logger::~Logger()
		{
			close();
		}
		Logger* Logger::instance()
		{
			if (logInstance == nullptr)
			{
				logInstance = new Logger();
			}
			return logInstance;
		}

		void Logger::open()
		{
			try
			{
				outStream.exceptions(std::ofstream::failbit | std::ofstream::badbit);
				outStream.open(this->localFile, std::ios::app);
				outStream.exceptions(std::ofstream::goodbit);
			}
			catch (std::ofstream::failure const& exception)
			{
				std::cout << exception.what() << std::endl;
			}
		}

		void Logger::close()
		{
			outStream.close();
		}

		void Logger::log(Level level, const char* file, int line, const char* message, ...)
		{
			const char* format = LOGGER_OUTPUT_FORMAT;
			int size = snprintf(nullptr, 0, format, Time::getTime(LOGGER_TIME_FORMAT).c_str(), levels[level], file, line);
			if (size > 0)
			{
				char* buffer = new char[size + 1];
				snprintf(buffer, size + 1, format, Time::getTime(LOGGER_TIME_FORMAT).c_str(), levels[level], file, line);
				buffer[size] = 0;
				std::cout << buffer;
				outStream << buffer;
				delete[] buffer;
			}
			va_list argPointer;
			va_start(argPointer, message);
			size = vsnprintf(nullptr, 0, message, argPointer);
			va_end(argPointer);
			if (size > 0)
			{
				char* content = new char[size + 1];
				va_start(argPointer, message);
				vsnprintf(content, size + 1, message, argPointer);
				va_end(argPointer);
				std::cout << content << std::endl;
				outStream << content;
			}
			outStream << "\n";
			outStream.flush();
		}
	}
	namespace Animation
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
		double Animator::getPoint(double delta)
		{
			time += (delta * 0.001F * (1000 - (ms * 100) + multi(ms, ms)));
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
		bool Animator::hasFinished()
		{
			return this->point == this->end;
		}

		void Animator::changeDirection(Direction direction)
		{
			auto cache = 0.0;
			cache = end;
			end = start;
			start = cache;

			this->time = 0;
			this->point = start;
			this->direction = direction;
		}

		Direction Animator::getDirection()
		{
			return this->direction;
		}
	}

	namespace Time
	{
		double getGLFWTime()
		{
			return glfwGetTime();
		}
		std::string getTime(const char* format)
		{
			std::chrono::time_point<std::chrono::system_clock> now_time = std::chrono::system_clock::now();
			time_t t_time = std::chrono::system_clock::to_time_t(now_time);
			tm tm = *gmtime(&t_time);
			std::stringstream time_stream;
			time_stream << std::put_time(&tm, format);
			return time_stream.str();
		}
	    long long getNowTime()
		{
			std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

			std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());

			return ns.count();
		}
	}
}

