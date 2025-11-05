#pragma once
#include <iostream>

namespace jack {

template <typename T>
void print(T var) {
    std::cout << var << ' ';
}

template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << ' ';
    print(rest...);
}

template <typename... Args>
void println(Args... args) {
    print(args...);
    std::cout << '\n';
}

}
