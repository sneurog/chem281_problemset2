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
    // Vector of steps for testing
    std::vector<int> steps = {2, 5, 10, 20, 30, 40};

    // Check if timers are enabled
#ifdef ENABLE_TIMERS
    std::cout << "Timers are enabled." << std::endl;

    // Create timers
    MyTimer::Timer totalTimer("Total", true);  
    MyTimer::Timer recursiveTimer("Recursive", true);
    MyTimer::Timer reverseTimer("Reverse", true);
    
    // Start total timer
    totalTimer.start();
    
    // Start recursive timer
    recursiveTimer.start();
    // Run recursive_sqrt function for each step
    for (int n : steps) {
        float x = 100.0f;
        float sqrtValue = recursive_sqrt(x, n);
    }
    // Stop recursive timer
    recursiveTimer.stop();
    
    // Start reverse timer
    reverseTimer.start();
    // Run reverse_process function for each step
    for (int n : steps) {
        float x = 100.0f;
        float sqrtValue = recursive_sqrt(x, n);
        float reconstructedValue = reverse_process(sqrtValue, n);
    }
    // Stop reverse timer
    reverseTimer.stop();
    
    // Stop total timer
    totalTimer.stop();

    // Print the durations of each timer
    totalTimer.print();
    recursiveTimer.print();
    reverseTimer.print();
#else
    // If timers are disabled
    std::cout << "*Timers are disabled. Please Enable Timers in the terminal by compiling with -DENABLE_TIMERS*  " << std::endl;
#endif

    return 0;
}

