#ifndef POINT_H
#define POINT_H

#include <concepts>
template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
struct Point {
    T x;
    T y;

    Point() : x(T()), y(T()) {}
    Point(T x_val, T y_val) : x(x_val), y(y_val) {}

    Point(const Point& other) = default;
    Point(Point&& other) noexcept = default;
    Point& operator=(const Point& other) = default;
    Point& operator=(Point&& other) noexcept = default;
};

#endif