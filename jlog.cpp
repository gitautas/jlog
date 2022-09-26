#include <ctime>
#include <iostream>
#include <jlog.hpp>
#include <nlohmann/json.hpp>
#include <ostream>
#include <utility>

namespace jlog {

Logger::Logger() {
  LogConfig configuration;
  config = configuration;
  trace(message(
      "did not receive configuration object, proceeding with defaults"));
}

Logger::Logger(LogConfig config) : config(config) {}

document Logger::timestamp() {
  if (config.timestamp) {
    return {"timestamp", time(nullptr)};
  }
  return nullptr;
};

void Logger::log(std::string level, document object...) {
  document j = {
      {"level", level},
      timestamp(),
      object,
  };
  *config.stream << j << std::endl;
}


void Logger::metrics(document object) {
  log("info", object);
};

void Logger::trace(document object...) { log("trace", object); };
void Logger::debug(document object...) { log("debug", object); };
void Logger::info(document object...) { log("info", object); };
void Logger::warning(document object...) { log("warn", object); };
void Logger::error(document object...) { log("error", object); };
void Logger::fatal(document object...) { log("fatal", object); };

} // namespace jlog
