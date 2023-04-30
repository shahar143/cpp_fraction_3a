//
// Created by super on 4/15/23.
//

#ifndef CPP_FRACTION_3A_FRACTION_HPP
#define CPP_FRACTION_3A_FRACTION_HPP

#endif //CPP_FRACTION_3A_FRACTION_HPP
#include <ostream>
using namespace std;

namespace ariel{
    class Fraction{
    private:
        int num;
        int den;
    public:
        Fraction(int numerator, int denominator);
        //Fraction(const Fraction& frc);
        explicit Fraction(int numerator);

        int get_num() const;
        int get_den() const;
        friend const Fraction dub_to_frc(float num1);

        const Fraction operator+(const Fraction& frc) const;
        const Fraction operator-(const Fraction& frc) const;
        const Fraction operator*(const Fraction& frc) const;
        const Fraction operator/(const Fraction& frc) const;

        Fraction& operator+=(const Fraction& frc);
        Fraction& operator-=(const Fraction& frc);
        Fraction& operator+=(float num1);
        Fraction& operator-=(float num1);

        //prefix
        Fraction& operator++();
        Fraction& operator--();

        //postfix
        const Fraction operator++(int);
        const Fraction operator--(int);

        bool operator>(const Fraction& frc) const;
        bool operator<(const Fraction& frc) const;
        bool operator>=(const Fraction& frc) const;
        bool operator<=(const Fraction& frc) const;
        bool operator==(Fraction frc) const;
        bool operator!=(const Fraction& frc) const;

        //Fraction& operator=(const Fraction& frc);

        friend ostream &operator<<(ostream &ost, const Fraction& fraction);
        friend istream& operator>>(istream& ist, Fraction& fraction);

        friend const Fraction operator+(float num1, const Fraction& frc);
        friend const Fraction operator-(float num1, const Fraction& frc);
        friend const Fraction operator*(float num1, const Fraction& frc);
        friend const Fraction operator/(float num1, const Fraction& frc);

        const Fraction operator+(float num1) const;
        const Fraction operator-(float num1) const;
        const Fraction operator*(float num1) const;
        const Fraction operator/(float num1) const;

        bool operator>(float num1) const;
        bool operator<(float num1) const;
        bool operator>=(float num1) const;
        bool operator<=(float num1) const;
        bool operator==(float num1) const;

        friend bool operator>(float num1, const Fraction& frc);
        friend bool operator<(float num1, const Fraction& frc);
        friend bool operator>=(float num1, const Fraction& frc);
        friend bool operator<=(float num1, const Fraction& frc);
        friend bool operator==(float num1, const Fraction& frc);

        void reduce();
        int gcd(int anum, int bnum) const;

    };
}