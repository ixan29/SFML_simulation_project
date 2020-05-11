struct Complex
{
    float r, i;

    Complex(float r_=0, float i_=0)
    :r(r_)
    ,i(i_)
    {}

    float lengthSq() const;
    float length() const;
    Complex conjugate() const;
};

Complex operator+(const Complex& first, const Complex& second);
Complex operator-(const Complex& first, const Complex& second);
Complex operator*(const Complex& first, const Complex& second);
Complex operator/(const Complex& first, const Complex& second);

Complex eulerComplexRotation(float angle);
Complex power(float n, const Complex& c);