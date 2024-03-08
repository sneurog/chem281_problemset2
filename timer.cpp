// timer.cpp
#include "timer.h"
#include <iostream>
#include <iomanip>
#include <sstream>

namespace MyTimer {
    Timer::Timer(const std::string &label, bool should_print)
        : label(label), should_print(should_print)
    {
#ifdef ENABLE_TIMERS
        running = false;
#endif
    }

    Timer::~Timer() {
#ifdef ENABLE_TIMERS
        if (running && should_print) {
            stop();
            print();
        }
#endif
    }

    void Timer::set_label(const std::string &l) {
        label = l;
    }

    Timer &Timer::start() {
#ifdef ENABLE_TIMERS
        if (!running) {
            start_time = std::chrono::high_resolution_clock::now();
            running = true;
        }
#endif
        return *this;
    }

Timer &Timer::stop() {
#ifdef ENABLE_TIMERS
    // std::cout << "Stopping timer..." << std::endl;  // Debug output
    if (running) {
        end_time = std::chrono::high_resolution_clock::now();
        running = false;
    }
#endif
    return *this;
}


    Timer &Timer::reset() {
#ifdef ENABLE_TIMERS
        start_time = std::chrono::high_resolution_clock::now();
        running = true;
#endif
        return *this;
    }

    Timer &Timer::reset_and_print() {
#ifdef ENABLE_TIMERS
        if (should_print) {
            print();
        }
        reset();
#endif
        return *this;
    }

double Timer::count() const {
#ifdef ENABLE_TIMERS
    // std::cout << "Calculating time count..." << std::endl;  // Debug output
    if (running) {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::micro>(now - start_time).count();
    } else {
        return std::chrono::duration<double, std::micro>(end_time - start_time).count();
    }
#else
    return 0.0;
#endif
}

  std::string Timer::to_pretty_str(double n) const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << n;
    return stream.str();
}

 Timer &Timer::print()  {
    #ifdef ENABLE_TIMERS
    // std::cout << "Attempting to print timer..." << std::endl; // Debugging line
    if (should_print) {
        std::cout << "Printing timer for '" << label << "': "
                  << to_pretty_str(count()) << " microseconds." << std::endl;
    } else {
        std::cout << "Print flag not set for timer '" << label << "'." << std::endl;
    }
    #endif
    return *this;
}

}
