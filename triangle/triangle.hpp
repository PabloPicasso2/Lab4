#ifndef DEC_TRIANGLE_H
#define DEC_TRIANGLE_H

#include "../gen/gen.hpp"

class Dec_triangle : public Decorator
{
public:
    Dec_triangle(Comp_Gen *generator, double amplitude, double period)
        : Decorator(generator), m_amplitude(amplitude), m_period(period), m_time(0.0), output(0.0), prev_output(-m_amplitude) {}
    double generate() override;

private:
    double m_amplitude, m_period, m_time, output, prev_output;
};

#endif