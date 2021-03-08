#include <cctype>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Logger.h"

/**
 * General mesa namespace.
 */
namespace mesa {

  static void show_usage(const std::string name)
  {
    std::cerr << "Usage: " << name << " [-h] [-l log_level] -f <file name>\n"
      << "Options:\n"
      << "  -h   Show this text\n\n"
      << "  -l   Optional. Set the log detail level.\n"
      << "       The default is 'info'\n\n"
      << "  -f   Required. File name containing commands for the sequencer\n"
      << "       The file should be plain text, 1 command per line\n"
      << "       If no file is specified, the program will exit.\n\n"
      << std::endl;
  }
}

int main(int argc, char** argv) {
  using namespace mesa;

  auto cmd = 0;
  std::string fname;

  Logger& log = Logger::instance();
  log.level("INFO");

  int count = 0;

  while ((cmd = getopt (argc, argv, "hf:l:")) != -1) {
    log.at(LogLevel::TRACE, "loop count: " + std::to_string(++count));
    log.at(LogLevel::DEBUG, "in loop");
    log.at(LogLevel::INFO, "checking args");
    switch (cmd) {
      case 'f':
        fname = optarg;
        break;
      case 'l':
        log.level(optarg);
        break;
      case 'h':
      default:
        show_usage(argv[0]);
        return 1;
    }
  }

  log.at(LogLevel::TRACE, "about to check required argument . . .");

  if (fname.empty()) {
    log.at(LogLevel::FATAL, "No input file specified!  Exiting.");
    show_usage(argv[0]);
    return -1;
  }

  log.at(LogLevel::INFO, "program complete.");

  return 0;
}


