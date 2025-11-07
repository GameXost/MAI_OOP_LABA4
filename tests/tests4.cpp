#include <gtest/gtest.h>
#include <memory>
#include <sstream>
#include <cmath>

#include "../point.h"
#include "../figure.h"
#include "../array.h"
#include "../square.h"
#include "../rectangle.h"
#include "../trapez.h"

//Point
TEST(PointTest, DefaultConstructor) {
    Point<double> p;
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point<double> p(3.5, 4.5);
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, 4.5);
}

TEST(PointTest, CopyConstructor) {
    Point<double> p1(3.5, 4.5);
    Point<double> p2(p1);
    EXPECT_DOUBLE_EQ(p2.x, 3.5);
    EXPECT_DOUBLE_EQ(p2.y, 4.5);
}

TEST(PointTest, IntegerType) {
    Point<int> p(3, 4);
    EXPECT_EQ(p.x, 3);
    EXPECT_EQ(p.y, 4);
}

//Square
TEST(SquareTest, DefaultConstructor) {
    Square<double> sq;
    EXPECT_NO_THROW(sq.Center());
}

TEST(SquareTest, ParameterizedConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq(p1, p2, p3, p4);
    EXPECT_NEAR(sq.area(), 1.0, 1e-9);
}

TEST(SquareTest, Area) {
    Point<double> p1(0, 0);
    Point<double> p2(2, 0);
    Point<double> p3(2, 2);
    Point<double> p4(0, 2);

    Square<double> sq(p1, p2, p3, p4);
    EXPECT_NEAR(sq.area(), 4.0, 1e-9);
}

TEST(SquareTest, Center) {
    Point<double> p1(0, 0);
    Point<double> p2(2, 0);
    Point<double> p3(2, 2);
    Point<double> p4(0, 2);

    Square<double> sq(p1, p2, p3, p4);
    Point<double> center = sq.Center();

    EXPECT_NEAR(center.x, 1.0, 1e-9);
    EXPECT_NEAR(center.y, 1.0, 1e-9);
}

TEST(SquareTest, CopyConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq1(p1, p2, p3, p4);
    Square<double> sq2(sq1);

    EXPECT_NEAR(sq1.area(), sq2.area(), 1e-9);
    EXPECT_TRUE(sq1 == sq2);
}

TEST(SquareTest, MoveConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq1(p1, p2, p3, p4);
    double area1 = sq1.area();

    Square<double> sq2(std::move(sq1));
    EXPECT_NEAR(sq2.area(), area1, 1e-9);
}

TEST(SquareTest, CopyAssignment) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq1(p1, p2, p3, p4);
    Square<double> sq2;
    sq2 = sq1;

    EXPECT_NEAR(sq1.area(), sq2.area(), 1e-9);
}

TEST(SquareTest, MoveAssignment) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq1(p1, p2, p3, p4);
    double area1 = sq1.area();

    Square<double> sq2;
    sq2 = std::move(sq1);

    EXPECT_NEAR(sq2.area(), area1, 1e-9);
}

TEST(SquareTest, EqualityOperator) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq1(p1, p2, p3, p4);
    Square<double> sq2(p1, p2, p3, p4);

    EXPECT_TRUE(sq1 == sq2);
}

TEST(SquareTest, DoubleConversion) {
    Point<double> p1(0, 0);
    Point<double> p2(2, 0);
    Point<double> p3(2, 2);
    Point<double> p4(0, 2);

    Square<double> sq(p1, p2, p3, p4);
    double area = static_cast<double>(sq);

    EXPECT_NEAR(area, 4.0, 1e-9);
}

TEST(SquareTest, InvalidSquare) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(2, 0);
    Point<double> p4(3, 0);

    EXPECT_THROW(Square<double>(p1, p2, p3, p4), std::invalid_argument);
}

TEST(SquareTest, Print) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq(p1, p2, p3, p4);
    std::ostringstream oss;
    oss << sq;

    std::string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Square"), std::string::npos);
}

//Rectangle
TEST(RectangleTest, ParameterizedConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(3, 0);
    Point<double> p3(3, 2);
    Point<double> p4(0, 2);

    Rectangle<double> rect(p1, p2, p3, p4);
    EXPECT_NEAR(rect.area(), 6.0, 1e-9);
}

TEST(RectangleTest, Area) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(4, 3);
    Point<double> p4(0, 3);

    Rectangle<double> rect(p1, p2, p3, p4);
    EXPECT_NEAR(rect.area(), 12.0, 1e-9);
}

TEST(RectangleTest, Center) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(4, 2);
    Point<double> p4(0, 2);

    Rectangle<double> rect(p1, p2, p3, p4);
    Point<double> center = rect.Center();

    EXPECT_NEAR(center.x, 2.0, 1e-9);
    EXPECT_NEAR(center.y, 1.0, 1e-9);
}

TEST(RectangleTest, CopyConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(3, 0);
    Point<double> p3(3, 2);
    Point<double> p4(0, 2);

    Rectangle<double> rect1(p1, p2, p3, p4);
    Rectangle<double> rect2(rect1);

    EXPECT_NEAR(rect1.area(), rect2.area(), 1e-9);
}

TEST(RectangleTest, EqualityOperator) {
    Point<double> p1(0, 0);
    Point<double> p2(3, 0);
    Point<double> p3(3, 2);
    Point<double> p4(0, 2);

    Rectangle<double> rect1(p1, p2, p3, p4);
    Rectangle<double> rect2(p1, p2, p3, p4);

    EXPECT_TRUE(rect1 == rect2);
}

TEST(RectangleTest, InvalidRectangle) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(2, 0);
    Point<double> p4(3, 0);

    EXPECT_THROW(Rectangle<double>(p1, p2, p3, p4), std::invalid_argument);
}

//Trapezoid
TEST(TrapezoidTest, ParameterizedConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapezoid<double> trap(p1, p2, p3, p4);
    EXPECT_GT(trap.area(), 0.0);
}

TEST(TrapezoidTest, Area) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapezoid<double> trap(p1, p2, p3, p4);
    EXPECT_NEAR(trap.area(), 6.0, 1e-9);
}

TEST(TrapezoidTest, Center) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapezoid<double> trap(p1, p2, p3, p4);
    Point<double> center = trap.Center();

    EXPECT_NEAR(center.x, 2.0, 1e-9);
    EXPECT_NEAR(center.y, 1.0, 1e-9);
}

TEST(TrapezoidTest, CopyConstructor) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapezoid<double> trap1(p1, p2, p3, p4);
    Trapezoid<double> trap2(trap1);

    EXPECT_NEAR(trap1.area(), trap2.area(), 1e-9);
}

TEST(TrapezoidTest, EqualityOperator) {
    Point<double> p1(0, 0);
    Point<double> p2(4, 0);
    Point<double> p3(3, 2);
    Point<double> p4(1, 2);

    Trapezoid<double> trap1(p1, p2, p3, p4);
    Trapezoid<double> trap2(p1, p2, p3, p4);

    EXPECT_TRUE(trap1 == trap2);
}

TEST(TrapezoidTest, InvalidTrapezoid) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(2, 0);
    Point<double> p4(3, 0);

    EXPECT_THROW(Trapezoid<double>(p1, p2, p3, p4), std::invalid_argument);
}

//Array
TEST(ArrayTest, DefaultConstructor) {
    Array<int> arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, ParameterizedConstructor) {
    Array<int> arr(10);
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 10);
}

TEST(ArrayTest, PushBack) {
    Array<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, PushBackResize) {
    Array<int> arr(2);
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_GE(arr.getCapacity(), 3);
}

TEST(ArrayTest, Remove) {
    Array<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    arr.remove(1);

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
}

TEST(ArrayTest, RemoveInvalidIndex) {
    Array<int> arr;
    arr.pushBack(1);

    EXPECT_THROW(arr.remove(5), std::out_of_range);
}

TEST(ArrayTest, Clear) {
    Array<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);

    arr.clear();

    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, OperatorBracket) {
    Array<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(ArrayTest, OperatorBracketOutOfRange) {
    Array<int> arr;
    arr.pushBack(1);

    EXPECT_THROW(arr[5], std::out_of_range);
}

TEST(ArrayTest, MoveConstructor) {
    Array<int> arr1;
    arr1.pushBack(1);
    arr1.pushBack(2);

    Array<int> arr2(std::move(arr1));

    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, MoveAssignment) {
    Array<int> arr1;
    arr1.pushBack(1);
    arr1.pushBack(2);

    Array<int> arr2;
    arr2 = std::move(arr1);

    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr1.getSize(), 0);
}

//Array с фигурами
TEST(ArrayFiguresTest, PushBackSquares) {
    Array<std::shared_ptr<Figure<double>>> figures;

    auto sq1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );

    auto sq2 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 2), Point<double>(0, 2)
    );

    figures.pushBack(sq1);
    figures.pushBack(sq2);

    EXPECT_EQ(figures.getSize(), 2);
    EXPECT_NEAR(figures[0]->area(), 1.0, 1e-9);
    EXPECT_NEAR(figures[1]->area(), 4.0, 1e-9);
}

TEST(ArrayFiguresTest, MixedFigures) {
    Array<std::shared_ptr<Figure<double>>> figures;

    auto sq = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );

    auto rect = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(3, 0),
        Point<double>(3, 2), Point<double>(0, 2)
    );

    auto trap = std::make_shared<Trapezoid<double>>(
        Point<double>(0, 0), Point<double>(4, 0),
        Point<double>(3, 2), Point<double>(1, 2)
    );

    figures.pushBack(sq);
    figures.pushBack(rect);
    figures.pushBack(trap);

    EXPECT_EQ(figures.getSize(), 3);

    double totalArea = 0.0;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        totalArea += static_cast<double>(*figures[i]);
    }

    EXPECT_GT(totalArea, 0.0);
}

TEST(ArrayFiguresTest, RemoveFigure) {
    Array<std::shared_ptr<Figure<double>>> figures;

    auto sq1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );

    auto sq2 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 2), Point<double>(0, 2)
    );

    figures.pushBack(sq1);
    figures.pushBack(sq2);

    EXPECT_EQ(figures.getSize(), 2);

    figures.remove(0);

    EXPECT_EQ(figures.getSize(), 1);
    EXPECT_NEAR(figures[0]->area(), 4.0, 1e-9);
}

TEST(ArrayFiguresTest, ClearFigures) {
    Array<std::shared_ptr<Figure<double>>> figures;

    auto sq = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );

    figures.pushBack(sq);
    figures.pushBack(sq);

    EXPECT_EQ(figures.getSize(), 2);

    figures.clear();

    EXPECT_EQ(figures.getSize(), 0);
    EXPECT_TRUE(figures.isEmpty());
}

//Array
TEST(ArraySpecificTest, ArrayOfSquares) {
    Array<std::shared_ptr<Square<double>>> squares;

    auto sq1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );

    auto sq2 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 2), Point<double>(0, 2)
    );

    squares.pushBack(sq1);
    squares.pushBack(sq2);

    EXPECT_EQ(squares.getSize(), 2);
    EXPECT_NEAR(squares[0]->area(), 1.0, 1e-9);
    EXPECT_NEAR(squares[1]->area(), 4.0, 1e-9);
}

TEST(ArraySpecificTest, ArrayOfRectangles) {
    Array<std::shared_ptr<Rectangle<double>>> rectangles;

    auto rect1 = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 1), Point<double>(0, 1)
    );

    auto rect2 = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(3, 0),
        Point<double>(3, 2), Point<double>(0, 2)
    );

    rectangles.pushBack(rect1);
    rectangles.pushBack(rect2);

    EXPECT_EQ(rectangles.getSize(), 2);
    EXPECT_NEAR(rectangles[0]->area(), 2.0, 1e-9);
    EXPECT_NEAR(rectangles[1]->area(), 6.0, 1e-9);
}

//Clone
TEST(CloneTest, SquareClone) {
    Point<double> p1(0, 0);
    Point<double> p2(1, 0);
    Point<double> p3(1, 1);
    Point<double> p4(0, 1);

    Square<double> sq1(p1, p2, p3, p4);
    auto sq2 = sq1.clone();

    EXPECT_NEAR(sq1.area(), sq2->area(), 1e-9);
}

TEST(CloneTest, RectangleClone) {
    Point<double> p1(0, 0);
    Point<double> p2(3, 0);
    Point<double> p3(3, 2);
    Point<double> p4(0, 2);

    Rectangle<double> rect1(p1, p2, p3, p4);
    auto rect2 = rect1.clone();

    EXPECT_NEAR(rect1.area(), rect2->area(), 1e-9);
}

