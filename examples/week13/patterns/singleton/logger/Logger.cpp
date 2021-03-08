#include <cctype>
#include <iostream>
#include <string>

#include "Logger.h"

namespace mesa {

  void Logger::level (const std::string& log_level)
  {
    switch (toupper(log_level[0])) {
      case 'T':
        log_level_ = LogLevel::TRACE;
        break;
      case 'D':
        log_level_ = LogLevel::DEBUG;
        break;
      case 'I':
        log_level_ = LogLevel::INFO;
        break;
      case 'W':
        log_level_ = LogLevel::WARN;
        break;
      case 'E':
        log_level_ = LogLevel::ERROR;
        break;
      case 'F':
        log_level_ = LogLevel::FATAL;
        break;
      case 'A':
        log_level_ = LogLevel::ALWAYS;
        break;
      default:
        log_level_ = LogLevel::INFO;
        break;
    }
  }

  void Logger::at (const LogLevel& log_level, const std::string& message) const
  {
    if (log_level_ <= log_level) {
      std::cerr << level_to_string(log_level) << ":\t" << message << std::endl;
    }
  }

  const std::string& level_to_string(LogLevel log_level)
  {
    static std::map<LogLevel, const std::string> log_name = {
      {LogLevel::TRACE,  "TRACE"},
      {LogLevel::DEBUG,  "DEBUG"},
      {LogLevel::INFO,   "INFO"},
      {LogLevel::WARN,   "WARN"},
      {LogLevel::ERROR,  "ERROR"},
      {LogLevel::FATAL,  "FATAL"},
      {LogLevel::ALWAYS, "ALWAYS"}
    };
    return log_name[log_level];
  }

}


