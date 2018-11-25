#include "timekeeper.hpp"

void sleep(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}