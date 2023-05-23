#include <cmath>
#include "sinus.hpp"

/*
Dec_sinus::Dec_sinus(Gen_Comp *generator, double amplitude, double period)
{
    Dekorator(*generator);
    m_amplitude = amplitude;
    m_period = period;
    m_time = 0.0;
    output = 0.0;
}
*/

double Dec_sinus::generate()
{
    // end of previous period is beginning of next period
    if (m_time == m_period)
        m_time = 0.0;

    // calculate sinus output
    output = m_amplitude * sin(2 * 3.14159 *m_time / m_period);
    
    // next call of generate() will be for the next sample
    m_time += 1;

    return output;
}
