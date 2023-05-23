#include "gen/gen.hpp"
#include "square/square.hpp"
#include "sinus/sinus.hpp"
#include "triangle/triangle.hpp"
#include <iostream>

int main()
{
    Comp_Gen *generator = new Comp_Concrete(0.0);
    double period1 = 12.0, amplitude1 = 1.0;
    // Dec_square: period = 10.0, amplitude1 = 1.0
    //generator = new Dec_square(generator, amplitude1, period1);
    // Dec_sinus: period = 12.0, amplitude1 = 1.0
    //generator = new Dec_sinus(generator, amplitude1, period1);
    // Dec_triangle: period = 12.0, amplitude1 = 1.0
    generator = new Dec_triangle(generator, amplitude1, period1);

    for (int i = 0; i < 2*period1; ++i)
    {
        std::cout << generator->generate() << std::endl;
    }

    delete generator;
    std::cin.get();
}
