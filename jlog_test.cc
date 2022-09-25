#include <jlog.hh>
#include <iostream>
#include <fmt/core.h>
#include <string>

int main(int argc, char **argv) {
    if(argc != 1) {
        std::cout << argv[0] << " takes no arguments.\n";
        return 1;
    }

    auto log = jlog::Logger();

    log.info({"favoriteFood", fmt::format("garbanzo {}", "beans")});
    log.debug(log.message("hello"));

    log.debug(log.fmessage("hello {}", "world"));

    // for (int i = 0; i < 4; i++) {
    //     log.error(log.message("iteration {}", "a"));
    // }
}
