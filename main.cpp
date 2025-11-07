#include <iostream>
#include <limits>
#include <memory>

#include "point.h"
#include "figure.h"
#include "array.h"
#include "square.h"
#include "rectangle.h"
#include "trapez.h"

using ScalarType = double;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addSquare(Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    std::cout << "Введите 4 точки для квадрата (x y):" << std::endl;

    try {
        Point<ScalarType> points[4];
        for (int i = 0; i < 4; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        if (!std::cin) {
            clearInput();
            std::cout << "Ошибка ввода" << std::endl;
            return;
        }

        auto square = std::make_shared<Square<ScalarType>>(
            points[0], points[1], points[2], points[3]
        );

        figures.pushBack(square);
        std::cout << "Квадрат успешно добавлен" << std::endl;
    } catch (const std::exception& err) {
        std::cout << "Произошла ошибка: " << err.what() << std::endl;
        clearInput();
    }
}

void addRectangle(Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    std::cout << "Введите 4 точки для прямоугольника (x y):" << std::endl;

    try {
        Point<ScalarType> points[4];
        for (int i = 0; i < 4; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        if (!std::cin) {
            clearInput();
            std::cout << "Ошибка ввода" << std::endl;
            return;
        }

        auto rectangle = std::make_shared<Rectangle<ScalarType>>(
            points[0], points[1], points[2], points[3]
        );

        figures.pushBack(rectangle);
        std::cout << "Прямоугольник успешно добавлен" << std::endl;
    } catch (const std::exception& err) {
        std::cout << "Произошла ошибка: " << err.what() << std::endl;
        clearInput();
    }
}

void addTrapezoid(Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    std::cout << "Введите 4 точки для трапеции (x y):" << std::endl;

    try {
        Point<ScalarType> points[4];
        for (int i = 0; i < 4; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        if (!std::cin) {
            clearInput();
            std::cout << "Ошибка ввода" << std::endl;
            return;
        }

        auto trapezoid = std::make_shared<Trapezoid<ScalarType>>(
            points[0], points[1], points[2], points[3]
        );

        figures.pushBack(trapezoid);
        std::cout << "Трапеция успешно добавлена" << std::endl;
    } catch (const std::exception& err) {
        std::cout << "Произошла ошибка: " << err.what() << std::endl;
        clearInput();
    }
}

void showFigures(const Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    if (figures.isEmpty()) {
        std::cout << "Массив пуст, добавьте фигуры" << std::endl;
        return;
    }

    for (size_t i = 0; i < figures.getSize(); ++i) {
        std::cout << "\n[" << i << "] ";
        std::cout << *figures[i] << std::endl;

        Point<ScalarType> center = figures[i]->Center();
        std::cout << "Центр: (" << center.x << ", " << center.y << ")" << std::endl;
        std::cout << "Площадь: " << figures[i]->area() << std::endl;
    }
}

void totalArea(const Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    if (figures.isEmpty()) {
        std::cout << "Массив пуст" << std::endl;
        return;
    }

    double total = 0.0;
    for (size_t i = 0; i < figures.getSize(); ++i) {
        total += static_cast<double>(*figures[i]);
    }
    std::cout << "Общая площадь: " << total << std::endl;
}

void removeFigure(Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    if (figures.isEmpty()) {
        std::cout << "Массив пуст" << std::endl;
        return;
    }

    std::cout << "Введите индекс (0-" << figures.getSize() - 1 << "): ";
    size_t index;
    std::cin >> index;

    if (!std::cin) {
        clearInput();
        std::cout << "Некорректный ввод" << std::endl;
        return;
    }

    try {
        figures.remove(index);
        std::cout << "Фигура удалена по индексу: " << index << std::endl;
    } catch (const std::exception& err) {
        std::cout << "Ошибка: " << err.what() << std::endl;
    }
}

void clearArray(Array<std::shared_ptr<Figure<ScalarType>>>& figures) {
    if (figures.isEmpty()) {
        std::cout << "Массив уже пуст" << std::endl;
        return;
    }
    figures.clear();
    std::cout << "Массив очищен" << std::endl;
}

void printMenu() {
    std::cout << "\n========== МЕНЮ ==========" << std::endl;
    std::cout << "1. Добавить квадрат" << std::endl;
    std::cout << "2. Добавить прямоугольник" << std::endl;
    std::cout << "3. Добавить трапецию" << std::endl;
    std::cout << "4. Показать все фигуры" << std::endl;
    std::cout << "5. Показать общую площадь" << std::endl;
    std::cout << "6. Удалить фигуру по индексу" << std::endl;
    std::cout << "7. Очистить все фигуры" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Выбор: ";
}

void demonstrateSquareArray() {
    std::cout << "\n=== Демонстрация Array<std::shared_ptr<Square<double>>> ===" << std::endl;

    Array<std::shared_ptr<Square<double>>> squares;

    // Добавляем несколько квадратов
    auto sq1 = std::make_shared<Square<double>>(
        Point<double>(0, 0), Point<double>(1, 0),
        Point<double>(1, 1), Point<double>(0, 1)
    );

    auto sq2 = std::make_shared<Square<double>>(
        Point<double>(2, 2), Point<double>(4, 2),
        Point<double>(4, 4), Point<double>(2, 4)
    );

    squares.pushBack(sq1);
    squares.pushBack(sq2);

    std::cout << "Добавлено квадратов: " << squares.getSize() << std::endl;
    for (size_t i = 0; i < squares.getSize(); ++i) {
        std::cout << "Квадрат " << i << " - площадь: "
                  << squares[i]->area() << std::endl;
    }
}

int main() {
    Array<std::shared_ptr<Figure<ScalarType>>> figures;

    demonstrateSquareArray();

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        if (!std::cin) {
            clearInput();
            std::cout << "Некорректный ввод" << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                addSquare(figures);
                break;
            case 2:
                addRectangle(figures);
                break;
            case 3:
                addTrapezoid(figures);
                break;
            case 4:
                showFigures(figures);
                break;
            case 5:
                totalArea(figures);
                break;
            case 6:
                removeFigure(figures);
                break;
            case 7:
                clearArray(figures);
                break;
            case 0:
                std::cout << "Выход из программы" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 0);

    return 0;
}