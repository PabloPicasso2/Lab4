#include <iostream>
#include <optional>
#include <string>
#include <cmath>

struct Signal {
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

    // return 0.0 if you don't want to decorate by sinus
    double generate_sine() { return 0.0; }
    //double generate_sine() { return sin(2.0 * 3.14159 /12.0); }

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

    //double generate_triangle() { return 0.0; }
    double generate_triangle() { return (2 * 1 / 3.14) * asin(sin(2 * 3.14 * 1 / 12)); }

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
