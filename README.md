# cpp-timer
A simple timer library for C++. 
It can be used for measuring multiple time intervals and it also provides some percentage statistics.

# Usage
1. Create Timer object: `toolbox::Timer timer;`
2. Start the timer: `timer.start();`
3. Stop it as many times as you want: `timer.stop();`
4. ...
5. Profit: `timer.print_results();`


Output:
```
----------------------------------
0	0.685014ms	22.822%
1	0.364745ms	12.152%
2	1.264573ms	42.131%
3	0.687182ms	22.895%

Overall time: 3.001514 ms
----------------------------------
```
