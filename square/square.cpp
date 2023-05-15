#include "square.hpp"

/*
Dec_square::Dec_square(Gen_Comp *generator, double amplitude, double period)
{
    Dekorator(*generator);
    m_amplitude = amplitude;
    m_period = period;
    m_time = 0.0;
    output = 0.0;
}
*/

double Dec_square::generate()
{
    // end of previous period is beginning of next period
    if (m_time == m_period)
        m_time = 0.0;

    // calculate square output
    if (m_time < m_period / 2.0)
        output = -m_amplitude;
    else
        output = m_amplitude;

    // next call of generate() will be for the next sample
    m_time += 1;

    return output;
}
