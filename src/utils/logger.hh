#ifndef RECURSION_ENGINE__SRC__UTILS__LOGGER_HH
#define RECURSION_ENGINE__SRC__UTILS__LOGGER_HH

#include <string>
#include <memory>
#include <spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
namespace Recursion::utils
{
    class BaseLogger final
    {
    public:
        static void init();
        static std::shared_ptr<spdlog::logger> get_core_logger();
        static std::shared_ptr<spdlog::logger> get_client_logger();

    private:
        static std::shared_ptr<spdlog::logger> core_logger;
        static std::shared_ptr<spdlog::logger> client_logger;

        BaseLogger() {}
        ~BaseLogger() {}
    };
}

// ENGINE CORE LOGGERS
#define REC_CORE_TRACE(...)                                                                                                         \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_core_logger()->trace(__VA_ARGS__)
#define REC_CORE_INFO(...)                                                                                                          \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_core_logger()->info(__VA_ARGS__)
#define REC_CORE_WARN(...)                                                                                                          \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_core_logger()->warn(__VA_ARGS__)
#define REC_CORE_ERROR(...)                                                                                                         \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_core_logger()->error(__VA_ARGS__)
#define REC_CORE_FATAL(...)                                                                                                         \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_core_logger()->fatal(__VA_ARGS__)

// CLIENT LOGGERS
#define REC_TRACE(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_client_logger()->trace(__VA_ARGS__)
#define REC_INFO(...)                                                                                                               \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_client_logger()->info(__VA_ARGS__)
#define REC_WARN(...)                                                                                                               \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_client_logger()->warn(__VA_ARGS__)
#define REC_ERROR(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_client_logger()->error(__VA_ARGS__)
#define REC_FATAL(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::BaseLogger::get_client_logger()->fatal(__VA_ARGS__)

#endif