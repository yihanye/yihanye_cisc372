PI: Computing PI  
CISC372 Final Project  
Author: Yihan Ye, Daichen, Haosen Wang

1. Compile code  
    gcc compiler: `gcc src/pi.c src/pi_main.c -std=c99 -lm -O2 -fopenmp -o pi`
    clang compulter: `clang -Xpreprocessor -fopenmp -lomp src/pi.c src/pi_main.c -o pi`
2. Run code, you can change yoru thread number and iteration number here.  
    `env OMP_NUM_THREADS=2 ./pi 100000000`

3. You can change different methods to calculate pi in this project,
    you need to modify the code in order to do so.  
    In the "pi_main.c" 55 line, `out_result = pi_v5_s(param_steps)'`
    you can change `pi_v5_s` to others to calculate pi in other ways.  
    You have 10 options:  

    Serial Code:  
    Calculus approach:`pi_v1_s(int N)`  
    Gregory-Leibniz Series:`pi_v2_s(int N)`  
    Nilakantha Series:`pi_v3_s(int N)`  
    Monte Carlo:`pi_v4_s(int N)`  
    Chudnovsky Algorithm:`pi_v5_s(int N)`

    Parallel Code:
    Calculus approach:`pi_v1_s(int N)`  
    Gregory-Leibniz Series:`pi_v2_s(int N)`  
    Nilakantha Series:`pi_v3_s(int N)`  
    Monte Carlo:`pi_v4_s(int N)`  
    Chudnovsky Algorithm:`pi_v5_s(int N)`

* The original code is from https://www.appentra.com/training/courses/using-parallelware-trainer/. We added others methods to calculate pi based on the code provided by Appentra.
