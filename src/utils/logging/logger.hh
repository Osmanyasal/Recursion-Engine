#ifndef RECURSION_ENGINE__SRC__UTILS__LOGGING__LOGGER_HH
#define RECURSION_ENGINE__SRC__UTILS__LOGGING__LOGGER_HH

#include <deployment_config.hh>
#include <logger_config.hh>
#include <string>
#include <memory>
#include <spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <imgui_logger.hh>
namespace Recursion::utils::logger
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
#define STRINGIFY(...) #__VA_ARGS__

// ENGINE CORE LOGGERS
#define REC_CORE_DEBUG(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_client_logger()->debug(__VA_ARGS__)
#define REC_CORE_TRACE(...)                                                                                                         \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_core_logger()->trace(__VA_ARGS__)
#define REC_CORE_INFO(...)                                                                                                          \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_core_logger()->info(__VA_ARGS__)
#define REC_CORE_WARN(...)                                                                                                          \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_core_logger()->warn(__VA_ARGS__)
#define REC_CORE_ERROR(...)                                                                                                         \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_core_logger()->error(__VA_ARGS__)

// CLIENT LOGGERS
#define REC_DEBUG(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_client_logger()->debug(__VA_ARGS__)
#define REC_TRACE(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_client_logger()->trace(__VA_ARGS__)
#define REC_INFO(...)                                                                                                               \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_client_logger()->info(__VA_ARGS__)
#define REC_WARN(...)                                                                                                               \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_client_logger()->warn(__VA_ARGS__)
#define REC_ERROR(...)                                                                                                              \
    spdlog::set_pattern("[%n][%^%l%$][%Y-%m-%d %H:%M:%S.%f][" + std::string(__FILE__) + ":" + std::to_string(__LINE__) + "] [%v]"); \
    Recursion::utils::logger::BaseLogger::get_client_logger()->error(__VA_ARGS__);\
    ImGuiLogger::AddLog(__VA_ARGS__);

// Get rid of things that shouldn't be on production..
#if CONF__PORTING__IS_PRODUCTION || !CONF__LOG__ENABLE_TRACE

    #undef REC_CORE_TRACE
    #undef REC_TRACE

    #define REC_CORE_TRACE(...)
    #define REC_TRACE(...)

#endif

#if CONF__PORTING__IS_PRODUCTION || !CONF__LOG__ENABLE_DEBUG

    #undef REC_CORE_DEBUG
    #undef REC_DEBUG

    #define REC_CORE_DEBUG(...)
    #define REC_DEBUG(...)

#endif

#if !CONF__LOG__ENABLE_INFO

    #undef REC_CORE_INFO
    #undef REC_INFO

    #define REC_CORE_INFO(...)
    #define REC_INFO(...)

#endif

#if !CONF__LOG__ENABLE_WARN

    #undef REC_CORE_WARN
    #undef REC_WARN

    #define REC_CORE_WARN(...)
    #define REC_WARN(...)

#endif


#if !CONF__LOG__ENABLE_ERROR

    #undef REC_CORE_ERROR
    #undef REC_ERROR

    #define REC_CORE_ERROR(...)
    #define REC_ERROR(...)

#endif

#endif