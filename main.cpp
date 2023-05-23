#include <iostream>
#include <optional>
#include <string>
#include <cmath>

struct Signal {
    // return initial value
    virtual double generate() { return 1.0; }
};

struct SquareDecorator : Signal {
   private:
    Signal* m_sig;

    // return +amplitude or -amplitude
    double generate_square() { return 2.0; }
    // double generate_square() { return -2.0; }

   public:
    SquareDecorator(Signal* const sig) : m_sig(sig) {}
    double generate() override {
        std::cout << "Decorating with square\n";
        return m_sig->generate() + generate_square();
    }
};

struct SineDecorator : Signal {
   private:
    Signal* m_sig;

    // output = amplitude * sin(2 * pi * time / period)
    // return 0.0 if you don't want to decorate by sinus
    double generate_sine() { return 0.0; }
    //double generate_sine() { return 1.0 * sin(2.0 * 3.14159 * 1.0 / 12.0); }

   public:
    SineDecorator(Signal* const sig) : m_sig(sig) {}
    double generate() override {
        std::cout << "Decorating with sine\n";
        return m_sig->generate() + generate_sine();
    }
};

struct TriangleDecorator : Signal {
   private:
    Signal* m_sig;

    // output = (2 * amplitude / 3.14) * asin(sin(2 * 3.14 * time / period));
    //double generate_triangle() { return 0.0; }
    double generate_triangle() { return (2.0 * 1.0 / 3.14) * asin(sin(2.0 * 3.14 * 1.0 / 12.0)); }

   public:
    TriangleDecorator(Signal* const sig) : m_sig(sig) {}
    double generate() override {
        std::cout << "Decorating with triangle\n";
        return m_sig->generate() + generate_triangle();
    }
};

int main() {
    Signal sig;
    // decorate by all additional signals
    SineDecorator sine_dec(&sig);
    TriangleDecorator tr_dec(&sine_dec);
    SquareDecorator sq_dec(&tr_dec);

    std::cout << sq_dec.generate();
}
