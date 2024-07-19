#pragma once

// it is ok that you can in your source file define marco about logger
#ifndef LOGGER_OUTPUT_FORMAT
#define LOGGER_OUTPUT_FORMAT "%s %s [%s %d]: "
#endif

#ifndef LOGGER_TIME_FORMAT
#define LOGGER_TIME_FORMAT "%Y-%m-%d %H:%M:%S"
#endif

#define debug(message, ...) Utilities::Log::Logger::instance()->log(Utilities::Log::Logger::LEVEL_DEBUG,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define info(message, ...) Utilities::Log::Logger::instance()->log(Utilities::Log::Logger::LEVEL_INFO,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define error(message, ...) Utilities::Log::Logger::instance()->log(Utilities::Log::Logger::LEVEL_ERROR,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define warning(message, ...) Utilities::Log::Logger::instance()->log(Utilities::Log::Logger::LEVEL_WARN,__FILE__,__LINE__, message, ##__VA_ARGS__)

#define fatal(message, ...) Utilities::Log::Logger::instance()->log(Utilities::Log::Logger::LEVEL_FATAL,__FILE__,__LINE__, message, ##__VA_ARGS__)



namespace Utilities
{

    namespace Log
    {
        //The logger marco function to output and restore in log file
        class __declspec(dllexport) Logger
        {
        public:
            enum Level
            {
                LEVEL_DEBUG = 0,
                LEVEL_INFO,
                LEVEL_WARN,
                LEVEL_ERROR,
                LEVEL_FATAL,
                LEVEL_COUNT
            };
            Logger();
            ~Logger();
            //THE FUNCTION CAN GET A LOGGER INSTANCE JUST ONLY HAVE ONE LOGGER INSTANCE
            static Logger* instance();
            //Open log file
            //if not exist, the function will create a new file
            void open();
            //Close log file
            void close();
            //@pragam level   : want to output log level, by marco select
            //@pragam file    : need a __FILE__ marco, it can replace to file's path in the system
            //@pragam file    : need a __LINE__ marco, it can replace to 'invoke line' in some files
            //@pragam message : the message you want to output in consoles and log file
            //...     : this is a variable arguments that can format output message such as printf("%s",str)
            void log(Level level, const char* file, int line, const char* message, ...);
        private:
            //the logger output log file path
            std::string localFile;
            //output stream, to write log
            std::ofstream outStream;
            //levels string and enum shift
            static const char* levels[LEVEL_COUNT];
            //log instance
            static Logger* logInstance;
        };
    }

    namespace Animation
    {
        enum class __declspec(dllexport) Direction
        {
            FORWARD, BACK
        };
        enum class __declspec(dllexport) Easing
        {
            Linear, EaseInQuad, EaseOutQuad, EaseInOutQuad
        };
        class __declspec(dllexport) Animator
        {
        public:
            Animator(double ms, Easing easing, double start, double end);
            double getPoint(double delta);
            bool hasFinished();
            void changeDirection(Direction direction);
            Direction getDirection();
        private:
            double time, ms;
            double start, end;
            double point;
            Easing easing;
            Direction direction;
        };

    }

    namespace Time
    {
        __declspec(dllexport) double getGLFWTime();
        //get format time
        __declspec(dllexport) std::string getTime(const char* format);
        //get nano time include ms
        __declspec(dllexport) long long getNowTime();
    }
}

