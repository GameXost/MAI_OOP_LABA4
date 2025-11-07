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

// Point tests
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

TEST(PointTest, CopyWorks) {
    Point<double> p1(3.5, 4.5);
    Point<double> p2(p1);
    EXPECT_DOUBLE_EQ(p2.x, 3.5);
    EXPECT_DOUBLE_EQ(p2.y, 4.5);
}

TEST(PointTest, IntType) {
    Point<int> p(3, 4);
    EXPECT_EQ(p.x, 3);
    EXPECT_EQ(p.y, 4);
}

// Square tests
TEST(SquareTest, DefaultWorks) {
    Square<double> sq;
    EXPECT_NO_THROW(sq.Center());
}

TEST(SquareTest, CreateSquare) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq(p1, p2, p3, p4);
    EXPECT_NEAR(sq.area(), 1.0, 1e-9);
}

TEST(SquareTest, AreaCalc) {
    Point<double> p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    Square<double> sq(p1, p2, p3, p4);
    EXPECT_NEAR(sq.area(), 4.0, 1e-9);
}

TEST(SquareTest, CenterCalc) {
    Point<double> p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    Square<double> sq(p1, p2, p3, p4);
    Point<double> center = sq.Center();
    EXPECT_NEAR(center.x, 1.0, 1e-9);
    EXPECT_NEAR(center.y, 1.0, 1e-9);
}

TEST(SquareTest, CopyWorks) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq1(p1, p2, p3, p4);
    Square<double> sq2(sq1);
    EXPECT_NEAR(sq1.area(), sq2.area(), 1e-9);
    EXPECT_TRUE(sq1 == sq2);
}

TEST(SquareTest, MoveWorks) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq1(p1, p2, p3, p4);
    double a = sq1.area();
    Square<double> sq2(std::move(sq1));
    EXPECT_NEAR(sq2.area(), a, 1e-9);
}

TEST(SquareTest, AssignWorks) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq1(p1, p2, p3, p4);
    Square<double> sq2;
    sq2 = sq1;
    EXPECT_NEAR(sq1.area(), sq2.area(), 1e-9);
}

TEST(SquareTest, MoveAssign) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq1(p1, p2, p3, p4);
    double a = sq1.area();
    Square<double> sq2;
    sq2 = std::move(sq1);
    EXPECT_NEAR(sq2.area(), a, 1e-9);
}

TEST(SquareTest, EqualityCheck) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq1(p1, p2, p3, p4);
    Square<double> sq2(p1, p2, p3, p4);
    EXPECT_TRUE(sq1 == sq2);
}

TEST(SquareTest, ConvertToDouble) {
    Point<double> p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    Square<double> sq(p1, p2, p3, p4);
    double a = static_cast<double>(sq);
    EXPECT_NEAR(a, 4.0, 1e-9);
}

TEST(SquareTest, BadSquare) {
    Point<double> p1(0, 0), p2(1, 0), p3(2, 0), p4(3, 0);
    EXPECT_THROW(Square<double>(p1, p2, p3, p4), std::invalid_argument);
}

TEST(SquareTest, PrintCheck) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> sq(p1, p2, p3, p4);
    std::ostringstream oss;
    oss << sq;
    std::string s = oss.str();
    EXPECT_FALSE(s.empty());
    EXPECT_NE(s.find("Square"), std::string::npos);
}

// Rectangle tests
TEST(RectangleTest, CreateRect) {
    Point<double> p1(0, 0), p2(3, 0), p3(3, 2), p4(0, 2);
    Rectangle<double> r(p1, p2, p3, p4);
    EXPECT_NEAR(r.area(), 6.0, 1e-9);
}

TEST(RectangleTest, AreaCalc) {
    Point<double> p1(0, 0), p2(4, 0), p3(4, 3), p4(0, 3);
    Rectangle<double> r(p1, p2, p3, p4);
    EXPECT_NEAR(r.area(), 12.0, 1e-9);
}

TEST(RectangleTest, CenterCalc) {
    Point<double> p1(0, 0), p2(4, 0), p3(4, 2), p4(0, 2);
    Rectangle<double> r(p1, p2, p3, p4);
    Point<double> c = r.Center();
    EXPECT_NEAR(c.x, 2.0, 1e-9);
    EXPECT_NEAR(c.y, 1.0, 1e-9);
}

TEST(RectangleTest, CopyWorks) {
    Point<double> p1(0, 0), p2(3, 0), p3(3, 2), p4(0, 2);
    Rectangle<double> r1(p1, p2, p3, p4);
    Rectangle<double> r2(r1);
    EXPECT_NEAR(r1.area(), r2.area(), 1e-9);
}

TEST(RectangleTest, EqualityCheck) {
    Point<double> p1(0, 0), p2(3, 0), p3(3, 2), p4(0, 2);
    Rectangle<double> r1(p1, p2, p3, p4);
    Rectangle<double> r2(p1, p2, p3, p4);
    EXPECT_TRUE(r1 == r2);
}

TEST(RectangleTest, BadRect) {
    Point<double> p1(0, 0), p2(1, 0), p3(2, 0), p4(3, 0);
    EXPECT_THROW(Rectangle<double>(p1, p2, p3, p4), std::invalid_argument);
}

// Trapezoid tests
TEST(TrapezoidTest, CreateTrap) {
    Point<double> p1(0, 0), p2(4, 0), p3(3, 2), p4(1, 2);
    Trapezoid<double> t(p1, p2, p3, p4);
    EXPECT_GT(t.area(), 0.0);
}

TEST(TrapezoidTest, AreaCalc) {
    Point<double> p1(0, 0), p2(4, 0), p3(3, 2), p4(1, 2);
    Trapezoid<double> t(p1, p2, p3, p4);
    EXPECT_NEAR(t.area(), 6.0, 1e-9);
}

TEST(TrapezoidTest, CenterCalc) {
    Point<double> p1(0, 0), p2(4, 0), p3(3, 2), p4(1, 2);
    Trapezoid<double> t(p1, p2, p3, p4);
    Point<double> c = t.Center();
    EXPECT_NEAR(c.x, 2.0, 1e-9);
    EXPECT_NEAR(c.y, 1.0, 1e-9);
}

TEST(TrapezoidTest, CopyWorks) {
    Point<double> p1(0, 0), p2(4, 0), p3(3, 2), p4(1, 2);
    Trapezoid<double> t1(p1, p2, p3, p4);
    Trapezoid<double> t2(t1);
    EXPECT_NEAR(t1.area(), t2.area(), 1e-9);
}

TEST(TrapezoidTest, EqualityCheck) {
    Point<double> p1(0, 0), p2(4, 0), p3(3, 2), p4(1, 2);
    Trapezoid<double> t1(p1, p2, p3, p4);
    Trapezoid<double> t2(p1, p2, p3, p4);
    EXPECT_TRUE(t1 == t2);
}

TEST(TrapezoidTest, BadTrap) {
    Point<double> p1(0, 0), p2(1, 0), p3(2, 0), p4(3, 0);
    EXPECT_THROW(Trapezoid<double>(p1, p2, p3, p4), std::invalid_argument);
}

// Array tests
TEST(ArrayTest, DefaultWorks) {
    Array<int> arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, CreateWithCapacity) {
    Array<int> arr(10);
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 10);
}

TEST(ArrayTest, AddElements) {
    Array<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, AutoResize) {
    Array<int> arr(2);
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_GE(arr.getCapacity(), 3);
}

TEST(ArrayTest, RemoveElement) {
    Array<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.remove(1);
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
}

TEST(ArrayTest, RemoveBadIndex) {
    Array<int> arr;
    arr.pushBack(1);
    EXPECT_THROW(arr.remove(5), std::out_of_range);
}

TEST(ArrayTest, ClearAll) {
    Array<int> arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.clear();
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, AccessByIndex) {
    Array<int> arr;
    arr.pushBack(10);
    arr.pushBack(20);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(ArrayTest, BadIndexAccess) {
    Array<int> arr;
    arr.pushBack(1);
    EXPECT_THROW(arr[5], std::out_of_range);
}

TEST(ArrayTest, MoveWorks) {
    Array<int> arr1;
    arr1.pushBack(1);
    arr1.pushBack(2);
    Array<int> arr2(std::move(arr1));
    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, MoveAssign) {
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

// Array with figures
TEST(ArrayWithFigures, AddSquares) {
    Array<std::shared_ptr<Figure<double>>> figs;
    auto s1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );
    auto s2 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 2), Point<double>(0, 2)
    );
    figs.pushBack(s1);
    figs.pushBack(s2);
    EXPECT_EQ(figs.getSize(), 2);
    EXPECT_NEAR(figs[0]->area(), 1.0, 1e-9);
    EXPECT_NEAR(figs[1]->area(), 4.0, 1e-9);
}

TEST(ArrayWithFigures, MixedTypes) {
    Array<std::shared_ptr<Figure<double>>> figs;
    auto sq = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );
    auto rc = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(3, 0),
        Point<double>(3, 2), Point<double>(0, 2)
    );
    auto tr = std::make_shared<Trapezoid<double>>(
        Point<double>(0, 0), Point<double>(4, 0),
        Point<double>(3, 2), Point<double>(1, 2)
    );
    figs.pushBack(sq);
    figs.pushBack(rc);
    figs.pushBack(tr);
    EXPECT_EQ(figs.getSize(), 3);
    double total = 0.0;
    for (size_t i = 0; i < figs.getSize(); ++i) {
        total += static_cast<double>(*figs[i]);
    }
    EXPECT_GT(total, 0.0);
}

TEST(ArrayWithFigures, RemoveFig) {
    Array<std::shared_ptr<Figure<double>>> figs;
    auto s1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );
    auto s2 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 2), Point<double>(0, 2)
    );
    figs.pushBack(s1);
    figs.pushBack(s2);
    EXPECT_EQ(figs.getSize(), 2);
    figs.remove(0);
    EXPECT_EQ(figs.getSize(), 1);
    EXPECT_NEAR(figs[0]->area(), 4.0, 1e-9);
}

TEST(ArrayWithFigures, ClearFigs) {
    Array<std::shared_ptr<Figure<double>>> figs;
    auto sq = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );
    figs.pushBack(sq);
    figs.pushBack(sq);
    EXPECT_EQ(figs.getSize(), 2);
    figs.clear();
    EXPECT_EQ(figs.getSize(), 0);
    EXPECT_TRUE(figs.isEmpty());
}

// Specific type arrays
TEST(SpecificArrays, OnlySquares) {
    Array<std::shared_ptr<Square<double>>> squares;
    auto s1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );
    auto s2 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 2), Point<double>(0, 2)
    );
    squares.pushBack(s1);
    squares.pushBack(s2);
    EXPECT_EQ(squares.getSize(), 2);
    EXPECT_NEAR(squares[0]->area(), 1.0, 1e-9);
    EXPECT_NEAR(squares[1]->area(), 4.0, 1e-9);
}

TEST(SpecificArrays, OnlyRectangles) {
    Array<std::shared_ptr<Rectangle<double>>> rects;
    auto r1 = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(2, 0),
        Point<double>(2, 1), Point<double>(0, 1)
    );
    auto r2 = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(3, 0),
        Point<double>(3, 2), Point<double>(0, 2)
    );
    rects.pushBack(r1);
    rects.pushBack(r2);
    EXPECT_EQ(rects.getSize(), 2);
    EXPECT_NEAR(rects[0]->area(), 2.0, 1e-9);
    EXPECT_NEAR(rects[1]->area(), 6.0, 1e-9);
}

// Clone tests
TEST(CloneTest, SquareClone) {
    Point<double> p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1);
    Square<double> s1(p1, p2, p3, p4);
    auto s2 = s1.clone();
    EXPECT_NEAR(s1.area(), s2->area(), 1e-9);
}

TEST(CloneTest, RectClone) {
    Point<double> p1(0, 0), p2(3, 0), p3(3, 2), p4(0, 2);
    Rectangle<double> r1(p1, p2, p3, p4);
    auto r2 = r1.clone();
    EXPECT_NEAR(r1.area(), r2->area(), 1e-9);
}

TEST(CloneTest, TrapClone) {
    Point<double> p1(0, 0), p2(4, 0), p3(3, 2), p4(1, 2);
    Trapezoid<double> t1(p1, p2, p3, p4);
    auto t2 = t1.clone();
    EXPECT_NEAR(t1.area(), t2->area(), 1e-9);
}

// Integration test
TEST(Integration, FullWorkflow) {
    Array<std::shared_ptr<Figure<double>>> figs;
    auto sq = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );
    auto rc = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), Point<double>(3, 0),
        Point<double>(3, 2), Point<double>(0, 2)
    );
    auto tr = std::make_shared<Trapezoid<double>>(
        Point<double>(0, 0), Point<double>(4, 0),
        Point<double>(3, 2), Point<double>(1, 2)
    );
    figs.pushBack(sq);
    figs.pushBack(rc);
    figs.pushBack(tr);
    EXPECT_EQ(figs.getSize(), 3);
    double total = 0.0;
    for (size_t i = 0; i < figs.getSize(); ++i) {
        total += static_cast<double>(*figs[i]);
    }
    EXPECT_GT(total, 0.0);
    figs.remove(1);
    EXPECT_EQ(figs.getSize(), 2);
    figs.clear();
    EXPECT_TRUE(figs.isEmpty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}