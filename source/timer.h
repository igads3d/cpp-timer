#ifndef TIMER_LIBRARY_H
#define TIMER_LIBRARY_H

#include <vector>
#include <chrono>


namespace toolbox {
class Timer {
 private:
  bool has_started_ {false};

  // vector of time_point type
  std::vector<std::chrono::time_point<std::chrono::high_resolution_clock> > time_vector_;

  // Calculates the difference in milliseconds between starting_index of time_vector_
  // and intervals_count away index of that vector
  //
  // e.g. check_ms(1, 2) will calculate difference beteween indexes [1] and [3]
  double check_ms(unsigned int starting_index = 0, unsigned int intervals_count = 1);

 public:

  // Constructor without arguments makes a reserve of 2 objects of type
  // std::chrono::time_point<std::chrono::high_resolution_clock>
  // It doesn't start the timer, so one should use start() method
  Timer();


  // Constructor with unsigned int parameter reserves memory for n objects
  // of type std::chrono::time_point<std::chrono::high_resolution_clock>
  // It doesn't start the timer, so one should use start() method
  Timer(unsigned int n);


  // Starts the clock by pushing back current time in time_vector_
  // and setting has_started_ to true.
  // Technically can be used instead of stop() method, but this is semantiaclly wrong
  void start();


  // Pushes back current time in time_vector_ if has_started_ is set to true
  // Can be used multiple times, so you can measure multiple time intervals
  void stop();


  // Prints results of mesurements in following form:
  // ------------------------------------
  // 0 interval: 0.836933 ms     41.035%
  // 1 interval: 0.401061 ms	   19.664%
  // 2 interval: 0.586352 ms	   28.749%
  // 3 interval: 0.215227 ms	   10.553%
  //
  // Overall time: 2.039573000 ms
  // ------------------------------------

  // If you have only one interval e.g. time_point0 and time_point1
  // then it forms following report:

  // ------------------------------------
  // Overall time: 2.099933000 ms
  // ------------------------------------
  void print_results();


  // Destructor stops the timer and calls print_results()
  // That occurs only if you have started the timer but haven't stopped it
  // In other cases it doesn't do anything
  ~Timer();
};
}  // namespace toolbox

#endif //TIMER_LIBRARY_H
