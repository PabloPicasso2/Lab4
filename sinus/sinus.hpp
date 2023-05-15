#ifndef DEC_SINUS_H
#define DEC_SINUS_H

#include "../gen/gen.hpp"

class Dec_sinus : public Decorator
{
public:
    Dec_sinus(Comp_Gen *generator, double amplitude, double period)
        : Decorator(generator), m_amplitude(amplitude), m_period(period), m_time(0.0) {}
    double generate() override;

private:
    double m_amplitude, m_period, m_time, output;
};

#endif