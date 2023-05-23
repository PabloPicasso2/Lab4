#include <iostream>
#include <optional>
#include <string>

struct Signal {
    virtual int generate() { return 0; }
};

struct SquareDecorator : Signal {
   private:
    Signal* m_sig;

    int generate_square() { return 1; }

   public:
    SquareDecorator(Signal* const sig) : m_sig(sig) {}
    int generate() override {
        std::cout << "Decorating with square\n";
        return m_sig->generate() + generate_square();
    }
};

struct SineDecorator : Signal {
   private:
    Signal* m_sig;
    
    // output = m_amplitude * sin(2 * 3.14159 *m_time / m_period);
    int generate_sine() { return 2; }

   public:
    SineDecorator(Signal* const sig) : m_sig(sig) {}
    int generate() override {
        std::cout << "Decorating with sine\n";
        return m_sig->generate() + generate_sine();
    }
};

struct TriangleDecorator : Signal {
   private:
    Signal* m_sig;

    // output = (2 * m_amplitude / 3.14) * asin(sin(2 * 3.14 * m_time / m_period));
    int generate_triangle() { return 3; }

   public:
    TriangleDecorator(Signal* const sig) : m_sig(sig) {}
    int generate() override {
        std::cout << "Decorating with triangle\n";
        return m_sig->generate() + generate_triangle();
    }
};

int main() {
    Signal sig;
    SineDecorator sine_dec(&sig);
    TriangleDecorator tr_dec(&sine_dec);
    SquareDecorator sq_dec(&tr_dec);

    std::cout << sq_dec.generate();
}
