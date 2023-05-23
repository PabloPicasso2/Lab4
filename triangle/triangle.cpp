#include <cmath>
#include "triangle.hpp"

double Dec_triangle::generate()
{
    // end of previous period is beginning of next period
    if (m_time == m_period)
        m_time = 0.0;

    output = (2 * m_amplitude / 3.14) * asin(sin(2 * 3.14 * m_time / m_period));

    // next call of generate() will be for the next sample
    m_time += 1;

    return output + generator;
}
