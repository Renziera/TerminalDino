/*
 * @Author: Renz 
 * @Date: 2018-11-25 21:19:43 
 * @Last Modified by:   Stanley Heryanto 
 * @Last Modified time: 2018-11-25 21:19:43 
 */
#include "timekeeper.hpp"

void sleep(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}