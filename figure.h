#ifndef FIGURE_H
#define FIGURE_H

#include "Point.h"
#include <iostream>
#include <memory>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual Point<T> Center() const = 0;
    virtual T area() const = 0;
    virtual explicit operator double() const = 0;

    virtual void Print(std::ostream& outS) const = 0;
    virtual void Read(std::istream& inpS) = 0;

    virtual std::unique_ptr<Figure<T>> clone() const = 0;
};

template<Scalar T>
std::ostream& operator<<(std::ostream& outS, const Figure<T>& figure) {
    figure.Print(outS);
    return outS;
}

template<Scalar T>
std::istream& operator>>(std::istream& inpS, Figure<T>& figure) {
    figure.Read(inpS);
    return inpS;
}

#endif