#include <fmt/core.h>
#include <iostream>
#include <jlog.hpp>
#include <string>

jlog::document generateMetrics() {
  jlog::document j;

  j["id"] = 0;
  j["cluster"] = "random value";
  j["number"] = time(nullptr) / 413;

  std::vector<jlog::document> arr;
  j["arr"].push_back({"name", "none"});
  j["arr"].push_back({"age", 12});
  j["arr"].push_back({"occupation", "plumber"});
  j["arr"].push_back({"location", "ukmerge"});
  j["nest"] = {{"object", "nest"}, {"otherObject", "otherNest"}};
  return { "metrics", j };
}

int main(int argc, char **argv) {
  if (argc != 1) {
    std::cout << argv[0] << " takes no arguments.\n";
    return 1;
  }

  auto log = jlog::Logger(jlog::LogConfig {
          .minLevel = jlog::Level::Trace
      });

  log.info({"favoriteFood", fmt::format("garbanzo {}", "beans")});


  log.debug(log.message("hello {}", "world"));

  log.metrics(generateMetrics());

  // for (int i = 0; i < 4; i++) {
  //     log.error(log.message("iteration {}", "a"));
  // }
}
