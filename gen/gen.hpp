#ifndef GEN_H
#define GEN_H


class Comp_Gen
{
public:
    virtual ~Comp_Gen() = default;
    virtual double generate() = 0;
};


class Comp_Concrete : public Comp_Gen
{
public:
    Comp_Concrete(double value) : m_value(value) {}
    ~Comp_Concrete() = default;

    double generate() override { return m_value; }

private:
    double m_value;
};


class Decorator : public Comp_Gen
{
public:
    Decorator(Comp_Gen *generator) : m_generator(generator) {}
    ~Decorator() = default;

    double generate() override
    {
        return m_generator->generate();
    }

protected:
    Comp_Gen *m_generator;
};


#endif
