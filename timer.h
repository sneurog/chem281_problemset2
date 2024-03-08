// timer.h
#ifndef TIMER_H
#define TIMER_H

#include <string>

#ifdef ENABLE_TIMERS
#include <chrono>
#endif

namespace MyTimer {
    class Timer {
    private:
#ifdef ENABLE_TIMERS
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time, end_time;
        bool running = false;
#endif
        std::string label;
        bool should_print;

    public:
        explicit Timer(const std::string &label = "some function/code", bool should_print = true);
        ~Timer();

        void set_label(const std::string &l);
        Timer &start();
        Timer &stop();
        Timer &reset();
        Timer &reset_and_print();
        double count() const;
         Timer &print(); 


    private:
        std::string to_pretty_str(double n) const;
       
    };
}

#endif /* TIMER_H */
