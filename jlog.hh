#pragma once

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/ordered_map.hpp>
#include <fmt/core.h>
#include <ostream>
#include <string>

namespace jlog {

enum class Level { Trace, Debug, Info, Warning, Error, Fatal };

using document = nlohmann::ordered_json;

struct LogConfig {
  std::ostream *stream = &std::cout;
  Level minLevel = Level::Error;
  bool timestamp = true;
  bool level = true;
};

class Logger {
public:
  Logger();
  Logger(LogConfig config);

  void metrics(document object); // Print an arbitrary JSON object, intended for
                                 // metrics use.
  void trace(document object...);
  void debug(document object...);
  void info(document object...);
  void warning(document object...);
  void error(document object...);
  void fatal(document object...);

  document message(std::string message); //TODO: Add formatting

private:
  void log(std::string level, document object...);
  document timestamp();
  LogConfig config;
};

} // namespace jlog
