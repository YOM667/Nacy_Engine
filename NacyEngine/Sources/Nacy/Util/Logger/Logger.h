#pragma once

#include "Nacy/Core/Core.h"

// it is ok that you can in your source file define marco about logger


#define Debug(message, ...) Utility::Logger::Instance()->Log(Utility::LogType::LEVEL_DEBUG,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define Info(message, ...) Utility::Logger::Instance()->Log(Utility::LogType::LEVEL_INFO,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define Error(message, ...) Utility::Logger::Instance()->Log(Utility::LogType::LEVEL_ERROR,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define Warning(message, ...) Utility::Logger::Instance()->Log(Utility::LogType::LEVEL_WARN,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define Fatal(message, ...) Utility::Logger::Instance()->Log(Utility::LogType::LEVEL_FATAL,__FILE__,__LINE__, message, ##__VA_ARGS__)


namespace Utility
{
    enum class LogType
    {
        LEVEL_DEBUG = 0, LEVEL_INFO, LEVEL_WARN, LEVEL_ERROR,LEVEL_FATAL
    };
	class Logger
	{
    public:

        NACY_API Logger();
        NACY_API ~Logger();
        //THE FUNCTION CAN GET A LOGGER INSTANCE JUST ONLY HAVE ONE LOGGER INSTANCE
        NACY_API static Logger* Instance();
        //Open log file
        //if not exist, the function will create a new file
        NACY_API void Open();
        //Close log file
        NACY_API void Close();
        //@pragam level   : want to output log level, by marco select
        //@pragam file    : need a __FILE__ marco, it can replace to file's path in the system
        //@pragam file    : need a __LINE__ marco, it can replace to 'invoke line' in some files
        //@pragam message : the message you want to output in consoles and log file
        //...     : this is a variable arguments that can format output message such as printf("%s",str)
        NACY_API void Log(LogType level, const char* file, int line, const char* message, ...);
    private:
        //the logger output log file path
        std::string localFile;
        //output stream, to write log
        std::ofstream outStream;
        //levels string and enum shift
        static const char* levels[5];
        //log Instance
        static Logger* logInstance;

	};
}


