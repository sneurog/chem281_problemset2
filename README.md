# Chem 281 Problem set 2 

The purpose of Problem 2 is to extend and implement operations from the standard library `std::bit` to work with templated datatype `std::bitset<N>`, enabling these operations for any choice of `N`. This involves implementing functions like `std::popcount` (population count) and `std::countr_zero` (trailing zeros) using methods that avoid explicit for-loops over individual bits. The problem explores two approaches: one using bit manipulation with direct bit access via `operator[]`, and another utilizing bitwise operations and recursion with underlying data access through `to_ulong()` or `to_ullong()`. Timing comparisons between these implementations and the standard library's `std::bit` functions are conducted, assessing their performance for various multiples of 64 bits. Additionally, the problem delves into the necessity of defining comparison functor objects for sorting collections of `std::bitset<N>` in STL containers like `std::set` or `std::map`. This entails creating logic to compare bitsets of arbitrary size, both with and without explicit bit-wise iteration. Furthermore, the problem introduces a real-world application by tasking the implementation of a function to count the number of occupied orbitals between two designated bits in a string of bits representing orbital occupations. This function is optimized using different strategies, including array representations of 64-bit `std::bitsets`, and its performance is compared across various bit sizes. Overall, Problem 2 aims to enhance understanding of bit manipulation techniques and their applications in computational tasks while fostering proficiency in optimizing code for improved performance.





In this repository, there are 14 files:



1. **README.md:**
2. **hw1-1.h:** API for toy test obtained from problem set 1, problem 1.
3. **hw2-1.cpp:** Implementaion of timing class to time toy test
4. **hw2-2.cpp:** Contains functions related to problem two.
5. **hw2-2times.cpp:** Problem 2 timing.
6. **plots.ipynb:** Jupyter notebook containing plots for problem 1 and problem 2 times.
7. **problem1timesFullyOptimization.txt:** Problem 1 times with full optimization.
8. **problem1timesHalfOptimization.txt:** Problem 1 times with half optimization.
9. **problem1timesNoOptimization.txt:** Problem 1 times without optimization.
10. **problem2timeHalf_optimized.txt:** Problem 2 times with half optimization.
11. **problem2timesFullOptimization.txt:** Problem 2 times with full optimization.
12. **problem2timesNoOptimization.txt:** Problem 2 times without optimization.
13. **timer.cpp:** Timer class implementation in C++.
14. **timer.h:** Header file for Timer class implementation.
15. **chem281_Problemset_2Answers.pdf:** PDF file containing problem set 2 Discussion answers

## Steps to compile Problem 1: 

**Note** You need to `-DENABLE_TIMERS` to enable the timers 

### **Fully Optimized**

Step 1: 
```
g++ -std=c++20 -O3 -DENABLE_TIMERS -c timer.cpp -o timer.o
```
Step 2: 
```
g++ -std=c++20 -O3 -DENABLE_TIMERS -c hw2-1.cpp -o hw2-1.o
```
Step 3:
```
g++ -std=c++20 timer.o hw2-1.o -o hw2-1O32
```
Step 4:
```
./hw2-1O32
```

#### **Half Optimized**

Step 7: 
```
g++ -std=c++20 -O0 -DENABLE_TIMERS -c timer.cpp -o timer.o
```

Step 8: 
```
g++ -std=c++20 -O3 -DENABLE_TIMERS -c hw2-1.cpp -o hw2-1.o
```

Step 9: 
```
g++ -std=c++20 timer.o hw2-1.o -o hw2-1O3
```

Step 4:
```
./hw2-1O3
```




#### **No Optimization**

Step 1:
```
g++ -std=c++20 -O0 -DENABLE_TIMERS -c timer.cpp -o timer.o
```

Step 2:
```
g++ -std=c++20 -O0 -DENABLE_TIMERS -c hw2-1.cpp -o hw2-1.o
```

Step 3:
```
g++ -std=c++20 timer.o hw2-1.o -o hw2-1O0
```

Step 4:
```
./hw2-1O0
```



## Steps to compile Problem 2: 



### **Half Optimized**

Step 1: 
```
g++ -std=c++20 -O0 -DENABLE_TIMERS -c timer.cpp -o timer.o
```

Step 2: 
```
g++ -std=c++20 -O3 -DENABLE_TIMERS -c hw2-2times.cpp -o hw2-2O3.o
```

Step 3: 
```
g++ -std=c++20 timer.o hw2-1.o -o hw2-2O3
```


Step 4:
```
./hw2-2O3
```



### **Fully Optimized**

Step 1: 
```
g++ -std=c++20 -O3 -DENABLE_TIMERS -c timer.cpp -o timer.o
```

Step 2: 
```
g++ -std=c++20 -O3 -DENABLE_TIMERS hw2-2times.cpp -o hw2-2O32.o
```

Step 3: 
```
g++ -std=c++20 timer.o hw2-2O32.o -o hw2-2O32
```


Step 4:
```
./hw2-2O32
```

### **No Optimization**

Step 1: 
```
g++ -std=c++20 -O0 -DENABLE_TIMERS -c timer.cpp -o timer.o
```

Step 2: 
```
g++ -std=c++20 -O0 -DENABLE_TIMERS hw2-2times.cpp -o hw2-2O0.o
```

Step 3: 
```
g++ -std=c++20 timer.o hw2-2O0.o  -o hw2-2O0
```


Step 4:
```
./hw2-2O32
```

