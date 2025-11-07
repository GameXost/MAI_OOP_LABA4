#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <memory>
#include <cmath>
#include <stdexcept>

template<Scalar T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> dots[4];

public:
    Trapezoid() {
        for (int i = 0; i < 4; ++i) {
            dots[i] = std::make_unique<Point<T>>();
        }
    }

    Trapezoid(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
        dots[0] = std::make_unique<Point<T>>(p1);
        dots[1] = std::make_unique<Point<T>>(p2);
        dots[2] = std::make_unique<Point<T>>(p3);
        dots[3] = std::make_unique<Point<T>>(p4);

        if (area() < 1e-9) {
            throw std::invalid_argument("points are collinear or degenerate");
        }
    }

    Trapezoid(const Trapezoid& other) {
        for (int i = 0; i < 4; ++i) {
            dots[i] = std::make_unique<Point<T>>(*other.dots[i]);
        }
    }

    Trapezoid(Trapezoid&& other) noexcept {
        for (int i = 0; i < 4; ++i) {
            dots[i] = std::move(other.dots[i]);
        }
    }

    Trapezoid& operator=(const Trapezoid& other) {
        if (this != &other) {
            for (int i = 0; i < 4; ++i) {
                dots[i] = std::make_unique<Point<T>>(*other.dots[i]);
            }
        }
        return *this;
    }

    Trapezoid& operator=(Trapezoid&& other) noexcept {
        if (this != &other) {
            for (int i = 0; i < 4; ++i) {
                dots[i] = std::move(other.dots[i]);
            }
        }
        return *this;
    }

    Point<T> Center() const override {
        T centerX = (dots[0]->x + dots[1]->x + dots[2]->x + dots[3]->x) / T(4);
        T centerY = (dots[0]->y + dots[1]->y + dots[2]->y + dots[3]->y) / T(4);
        return Point<T>(centerX, centerY);
    }

    T area() const override {
        T sum = T(0);
        for (int i = 0; i < 4; ++i) {
            int j = (i + 1) % 4;
            sum += dots[i]->x * dots[j]->y;
            sum -= dots[j]->x * dots[i]->y;
        }
        return std::abs(sum) / T(2);
    }

    explicit operator double() const override {
        return static_cast<double>(this->area());
    }

    bool operator==(const Trapezoid& other) const {
        return std::abs(static_cast<double>(this->area() - other.area())) < 1e-9;
    }

    void Print(std::ostream& outS) const override {
        outS << "Trapezoid dots: ";
        for (int i = 0; i < 4; ++i) {
            outS << "(" << dots[i]->x << ", " << dots[i]->y << ") ";
        }
    }

    void Read(std::istream& inpS) override {
        Point<T> temp[4];
        for (int i = 0; i < 4; ++i) {
            inpS >> temp[i].x >> temp[i].y;
        }

        if (!inpS) {
            throw std::runtime_error("failed to read trapezoid data");
        }

        for (int i = 0; i < 4; ++i) {
            dots[i] = std::make_unique<Point<T>>(temp[i]);
        }
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Trapezoid<T>>(*this);
    }

    ~Trapezoid() override = default;
};

#endif