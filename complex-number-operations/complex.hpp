class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex();
    Complex(double r, double i);

    // Operations
    Complex add(const Complex& c) const;
    Complex subtract(const Complex& c)const ;
    Complex multiply(const Complex& c) const;
    Complex divide(const Complex& c) const;

    // Norm (magnitude)
    double norm() const;
    Complex conjugate() const;


    // Display
    void display() const;
};