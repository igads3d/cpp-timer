#include "timer.h"

#include <iostream>
#include <iomanip>

namespace toolbox {

Timer::Timer() {
    time_vector_.reserve(2);
}


Timer::Timer(unsigned int n) {
    if (n > 2) {
        time_vector_.reserve(n);
    } else {
        time_vector_.reserve(2);
    }
}


void Timer::start() {
    time_vector_.push_back(std::chrono::high_resolution_clock::now());
    has_started_ = true;
}


void Timer::stop() {
    if (has_started_) {
        time_vector_.push_back(std::chrono::high_resolution_clock::now());
    }
}


double Timer::check_ms(unsigned int starting_index, unsigned int intervals_count) {
    std::chrono::duration<double> duration =
            time_vector_[starting_index + intervals_count] - time_vector_[starting_index];

    // because duration.count() is in seconds
    return duration.count() * 1000.0f;
}


void Timer::print_results() {
    double overall_time = this->check_ms(0, time_vector_.size() - 1);
    std::cout << "-----------------------------";

    if (time_vector_.size() > 2) {
        std::cout << std::endl;
        for (unsigned int i = 0; i < time_vector_.size() - 1; i++) {
            std::cout << i << "\t"      << std::fixed << std::setprecision(6) <<
                      this->check_ms(i) << " ms\t\t"  << std::setprecision(3) <<
                      100 / (overall_time / this->check_ms(i)) << "%\n";
        }
    }

    std::cout << "\nOverall time: " << std::fixed << std::setprecision(9) << overall_time << " ms\n" <<
    "-----------------------------\n";
}

Timer::~Timer() {
    if (time_vector_.size() < 2) {
        this->stop();
        this->print_results();
    }
}
  
}  // namespace toolbox
