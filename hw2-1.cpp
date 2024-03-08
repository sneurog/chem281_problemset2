#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "timer.h"

float recursive_sqrt(float x, int n) { 
    for (int i = 0; i < n; ++i) {
        x = sqrtf(x);
    }
    return x;
}

float reverse_process(float x, int n) {
    float original_value = 1.0f;
    for (int i = 0; i < n; ++i) {
        original_value *= x;
    }
    return original_value;
}

int main() {
    std::vector<int> steps = {2, 5, 10, 20, 30, 40};
    std::cout << "Output for question 1 times:" << std::endl;

    #ifdef ENABLE_TIMERS
    std::cout << "Timers are enabled." << std::endl;

    MyTimer::Timer totalTimerRecursive("Total recursive", true);  
    MyTimer::Timer totalTimerReverse("Total reverse", true);
    
    totalTimerRecursive.start();
    for (int n : steps) {
        float x = 100.0f;
        float sqrtValue = recursive_sqrt(x, n);
    }
    totalTimerRecursive.stop();
    totalTimerRecursive.print();

    totalTimerReverse.start();
    for (int n : steps) {
        float x = 100.0f;
        float sqrtValue = recursive_sqrt(x, n);
        float reconstructedValue = reverse_process(sqrtValue, n);
    }
    totalTimerReverse.stop();
    totalTimerReverse.print();
    #else
    std::cout << "*Timers are disabled. Please Enable Timers in the terminal by compiling with -DENABLE_TIMERS*  " << std::endl;
    #endif

    return 0;
}
