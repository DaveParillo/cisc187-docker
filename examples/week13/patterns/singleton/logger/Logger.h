#pragma once

#include <map>
#include <string>

namespace mesa
{
  /**
   * Defines the level of detail of a message.
   * 
   * Every message must define a single LogLevel.
   * The log level controls when the message is printed.
   * Messages equal to or greater in severity to the current log level are printed.
   */
  enum class LogLevel 
  {
    /** 
     * The most detailed log level.  Use for function parameter logging, return values, etc.
     */
    TRACE,
    /** 
     * A detailed log level.  Use for items you don't want to see logged often.
     */
    DEBUG,
    /** 
     * A general log level.  The default level.
     */
    INFO,
    /** 
     * Warnings.  Things that may impact correct output.
     */
    WARN,
    /** 
     * Errors.  Errors are unexpected and nearly always mean our results are incorrect.
     */
    ERROR,
    /** 
     * If we get this, we expect the program to exit prematurely.
     */
    FATAL,
    /**
     * Not an severity level, just something we *always* want to see in the log.
     */
    ALWAYS
  };

    
  /**
   * A simple console logger implemented as a Singleton.
   */
  class Logger {
    public:
      static Logger& instance() {
          static Logger singleton;
          return singleton;
      }

      Logger(const Logger&)         = delete; // prevent copying
      void operator=(const Logger&) = delete; // prevent copying

      /**
       * Change the logging threshold.
       * @param log_level the desired minimum logging level.
       */
      void level (const std::string& log_level);
      /**
       * Change the logging threshold.
       * @param log_level the desired minimum logging level.
       */
      void level (const LogLevel log_level) { log_level_ = log_level;}
      /**
       * Get the logging threshold.
       * @return the system logging threshold.
       */
      LogLevel level () const {return log_level_;}
      /**
       * Log a message at a specified importance.
       * @param log_level the importance of this message.
       * @param message the text to log.
       */
      void at    (const LogLevel& log_level, const std::string& message) const;

      
    private:
      Logger() = default;         // only Logger can make a logger
      LogLevel     log_level_;    /**< The logging threshold. */
  };



  /**
   * Allows the LogLevel enum class members to be printed with meaningful strings.
   * Example:
   *
   *     cout << "Level is " << level_to_string(LogLevel::FATAL) << endl;
   * @param log_level the LogLevel to be converted
   * @return the std::string representation of the LogLevel
   */
  const std::string& level_to_string(LogLevel log_level);

}


