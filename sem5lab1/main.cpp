#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "RectangularPrism.h"
#include "Cone.h"
#include "Keeper.h"
#include <iostream>

// Функция для ввода целого числа с проверкой корректности ввода
int getIntInput() {
    int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
            std::cout << "Invalid input. Please enter an integer: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем лишние символы из буфера
            return input;
        }
    }
}

// Функция для ввода вещественного числа с проверкой корректности ввода
double getDoubleInput() {
    double input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
            std::cout << "Invalid input. Please enter a number: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем лишние символы из буфера
            return input;
        }
    }
}

int main() {
    Keeper keeper;

    int mainChoice;

    do {
        std::cout << "\nMain Menu:\n"
            << "1. Add Flat Figure\n"
            << "2. Add Volume Figure\n"
            << "3. Remove Figure\n"
            << "4. Print All Figures\n"
            << "5. Save to File\n"
            << "6. Load from File\n"
            << "7. Exit\n"
            << "Enter your choice: ";

        mainChoice = getIntInput();

        switch (mainChoice) {
        case 1: {
            int flatChoice;
            do {
                std::cout << "\nFlat Figures Menu:\n"
                    << "1. Add Circle\n"
                    << "2. Add Rectangle\n"
                    << "3. Add Triangle\n"
                    << "4. Return to Main Menu\n"
                    << "5. Exit\n"
                    << "Enter your choice: ";

                flatChoice = getIntInput();

                switch (flatChoice) {
                case 1: {
                    double radius;
                    std::cout << "Enter the radius of the circle: ";
                    radius = getDoubleInput();
                    auto circle = std::make_unique<Circle>(radius);
                    std::cout << "Area of the circle: " << circle->calculateArea() << std::endl;
                    keeper.addFigure(std::move(circle));
                    break;
                }

                case 2: {
                    double length, width;
                    std::cout << "Enter the length of the rectangle: ";
                    length = getDoubleInput();
                    std::cout << "Enter the width of the rectangle: ";
                    width = getDoubleInput();
                    auto rectangle = std::make_unique<Rectangle>(length, width);
                    std::cout << "Area of the rectangle: " << rectangle->calculateArea() << std::endl;
                    keeper.addFigure(std::move(rectangle));
                    break;
                }

                case 3: {
                    double base, height;
                    std::cout << "Enter the base of the triangle: ";
                    base = getDoubleInput();
                    std::cout << "Enter the height of the triangle: ";
                    height = getDoubleInput();
                    auto triangle = std::make_unique<Rectangle>(base, height);
                    std::cout << "Area of the triangle: " << triangle->calculateArea() << std::endl;
                    keeper.addFigure(std::move(triangle));
                    break;
                }

                case 4:
                    break; // Возвращаемся в главное меню

                case 5:
                    std::cout << "Exiting the program.\n";
                    return 0; // Завершаем программу
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                }
            } while (flatChoice != 4);

            break;
        }

        case 2: {
            int volumeChoice;
            do {
                std::cout << "\nVolume Figures Menu:\n"
                    << "1. Add Sphere\n"
                    << "2. Add Rectangular Prism\n"
                    << "3. Add Cone\n"
                    << "4. Return to Main Menu\n"
                    << "5. Exit\n"
                    << "Enter your choice: ";

                volumeChoice = getIntInput();

                switch (volumeChoice) {
                case 1: {
                    double radius;
                    std::cout << "Enter the radius of the sphere: ";
                    radius = getDoubleInput();
                    auto sphere = std::make_unique<Sphere>(radius);
                    std::cout << "Volume of the sphere: " << sphere->calculateVolume() << std::endl;
                    keeper.addFigure(std::move(sphere));
                    break;
                }

                case 2: {
                    double length, width, height;
                    std::cout << "Enter the length of the rectangular prism: ";
                    length = getDoubleInput();
                    std::cout << "Enter the width of the rectangular prism: ";
                    width = getDoubleInput();
                    std::cout << "Enter the height of the rectangular prism: ";
                    height = getDoubleInput();
                    auto prism = std::make_unique<RectangularPrism>(length, width, height);
                    std::cout << "Volume of the rectangular prism: " << prism->calculateVolume() << std::endl;
                    keeper.addFigure(std::move(prism));
                    break;
                }

                case 3: {
                    double radius, height;
                    std::cout << "Enter the radius of the cone: ";
                    radius = getDoubleInput();
                    std::cout << "Enter the height of the cone: ";
                    height = getDoubleInput();
                    auto cone = std::make_unique<Cone>(radius, height);
                    std::cout << "Volume of the Cone: " << cone->calculateVolume() << std::endl;
                    keeper.addFigure(std::move(cone));
                    break;
                }

                case 4:
                    break; // Возвращаемся в главное меню

                case 5:
                    std::cout << "Exiting the program.\n";
                    return 0; // Завершаем программу
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                }
            } while (volumeChoice != 4);

            break;
        }

        case 3: {
            int removeChoice;
            std::cout << "Enter the index of the figure to remove: ";
            removeChoice = getIntInput();

            if (removeChoice >= 1 && removeChoice < keeper.getFigureCount()) {
                keeper.removeFigure(removeChoice-1);
                std::cout << "Figure at index " << removeChoice << " removed.\n";
            }
            else {
                std::cout << "Invalid index. Please enter a valid index.\n";
            }
            break;
        }

        case 4:
            keeper.printAllFiguresInfo();
            break;

        case 5: {
            std::string filename;
            std::cout << "Enter the filename to save: ";
            std::cin >> filename;
            keeper.saveToFile(filename);
            break;
        }

        case 6: {
            std::string filename;
            std::cout << "Enter the filename to load: ";
            std::cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }

        case 7:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }

    } while (mainChoice != 7);

    return 0;
}

