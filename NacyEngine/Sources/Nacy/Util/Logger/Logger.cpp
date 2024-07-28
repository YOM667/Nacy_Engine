#include "pch.h"
#include "Logger.h"

#include "Nacy/Util/Utilities.h"

const char* LOGGER_OUTPUT_FORMAT = "%s %s [%s %d]: ";

const char* LOGGER_TIME_FORMAT = "%Y-%m-%d %H:%M:%S";

namespace Utility
{
	const char* Logger::levels[5] = {
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
		this->localFile = filePath + "logs_" + GetTime("%Y-%m-%d %H_%M_%S") + ".log";

		this->Open();
	}
	Logger::~Logger()
	{
		Close();
	}
	Logger* Logger::Instance()
	{
		if (logInstance == nullptr)
		{
			logInstance = new Logger();
		}
		return logInstance;
	}

	void Logger::Open()
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

	void Logger::Close()
	{
		outStream.close();
	}

	void Logger::Log(LogType level, const char* file, int line, const char* message, ...)
	{
		const char* format = LOGGER_OUTPUT_FORMAT;
		int size = snprintf(nullptr, 0, format, GetTime(LOGGER_TIME_FORMAT).c_str(), levels[(int)level], file, line);
		if (size > 0)
		{
			char* buffer = new char[size + 1];
			snprintf(buffer, size + 1, format, GetTime(LOGGER_TIME_FORMAT).c_str(), levels[(int)level], file, line);
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