/*
 * @Author: Renz 
 * @Date: 2018-11-25 21:19:43 
 * @Last Modified by: Stanley Heryanto
 * @Last Modified time: 2018-11-25 22:38:41
 */
#include "timekeeper.hpp"

void sleep(int milliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}