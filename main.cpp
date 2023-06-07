/**
 * @file main.cpp
 * @author Pawel Smieja
 * @brief program for testing generator decorator - sinus, square and triangle. You can decorate basic input by these decorators separately or by superimpose
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "comp_concrete/comp_concrete.hpp"
#include "square/square.hpp"
#include "sinus/sinus.hpp"
#include "triangle/triangle.hpp"
#include <iostream>
#include <iomanip>

int main()
{
    // create basic input and display it's value
    Comp_Gen *generator = new Comp_Concrete(2.0);
    std::cout << "basic input = " << generator->simulate() << "\n\n";
    std::cout << "input with decorator: \n";
    // parameters for decorators
    double period1 = 12.0, amplitude1 = 1.0;

    // decorating separately
    Comp_Gen *generator1 = new Dec_square(generator, amplitude1, period1);
    Comp_Gen *generator2 = new Dec_sinus(generator, amplitude1, period1);
    Comp_Gen *generator3 = new Dec_triangle(generator, amplitude1, period1);

    // decorating by superimpose
    // Comp_Gen *generator1 = new Dec_square(generator, amplitude1, period1);
    // Comp_Gen *generator2 = new Dec_sinus(generator1, amplitude1, period1);
    // Comp_Gen *generator3 = new Dec_triangle(generator2, amplitude1, period1);

    // view header of table
    std::cout << std::left;
    std::cout << std::setw(12) << "Base input";
    std::cout << std::setw(12) << "Dec_square";
    std::cout << std::setw(12) << "Dec_sinus";
    std::cout << std::setw(12) << "Dec_triangle";
    std::cout << "\n";

    // in each row are values for decorating in each time-step. Two periods of each signal will be displayed
    for (int i = 0; i < 2 * period1; ++i)
    {
        std::cout << std::left;
        std::cout << std::setw(12) << generator->simulate();
        std::cout << std::setw(12) << generator1->simulate();
        std::cout << std::setw(12) << generator2->simulate();
        std::cout << std::setw(12) << generator3->simulate();
        std::cout << "\n";
    }

    // get memory back
    delete generator;
    delete generator1;
    delete generator2;
    delete generator3;

    std::cin.get();
}