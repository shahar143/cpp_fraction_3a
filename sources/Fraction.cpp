//
// Created by super on 4/15/23.
//

#include "Fraction.hpp"
#include <iostream>
#include <math.h>
using namespace std;
namespace ariel{

    Fraction::Fraction(int numerator, int denominator){
        if(denominator == 0){
            throw invalid_argument("denominator can't be 0");
        }
        num = numerator;
        den = denominator;
        reduce();
    }

    Fraction::Fraction(const Fraction& frc){
        this->num = frc.get_num();
        this->den = frc.get_den();
        reduce();
    }

    Fraction::Fraction(int numerator){
        Fraction(numerator, 1);
    }

    int Fraction::get_num() const{
        return num;
    }

    int Fraction::get_den() const{
        return den;
    }

    const Fraction dub_to_frc(double num1){
        return Fraction((int)(num1*1000), 1000);
    }

    const Fraction Fraction::operator+(const Fraction& frc) const{
        int num1 = num*frc.get_den() + frc.get_num()*den;
        if(num1 == 0) return Fraction(0, 1);
        return Fraction(num*frc.get_den() + frc.get_num()*den, den*frc.get_den());
    }

    const Fraction Fraction::operator-(const Fraction& frc) const{
        int num1 = num*frc.get_den() - frc.get_num()*den;
        if(num1 == 0) return Fraction(0,1);
        return Fraction(num1, den*frc.get_den());
    }

    const Fraction Fraction::operator*(const Fraction& frc) const{
        int num1 = num*frc.get_num();
        if(num1 == 0) return Fraction(0,1);
        return Fraction(num1, den*frc.get_den());
    }

    const Fraction Fraction::operator/(const Fraction& frc) const{
        if(frc.get_num() == 0) throw invalid_argument("can't divide by 0");
        if(num == 0) return Fraction(0, 1);
        return Fraction(num*frc.get_den(), den*frc.get_num());
    }

    Fraction& Fraction::operator+=(const Fraction& frc){
        *this = *this + frc;
        this->reduce();
        return *this;
    }

    Fraction& Fraction::operator-=(const Fraction& frc){
        *this = *this - frc;
        this->reduce();
        return *this;
    }

    Fraction& Fraction::operator+=(double num1){
        Fraction f = dub_to_frc(num1);
        *this = *this + f;
        this->reduce();
        return *this;
    }

    Fraction& Fraction::operator-=(double num1){
        Fraction f = dub_to_frc(num1);
        *this = *this - f;
        this->reduce();
        return *this;
    }

//prefix
    Fraction& Fraction::operator++(){
        *this += Fraction(1, 1);
        return *this;
    }

//postfix
    const Fraction Fraction::operator++(int){
        Fraction frc(*this);
        *this += Fraction(1, 1);
        return frc;

    }

//prefix
    Fraction& Fraction::operator--(){
        *this -= Fraction(1, 1);
        return *this;
    }

//postfix
    const Fraction Fraction::operator--(int){
        Fraction frc(*this);
        *this -= Fraction(1, 1);
        return frc;
    }

    bool Fraction::operator>(const Fraction& frc) const{
        double this_frc = ((double)this->get_num())/((double)this->get_den());
        double other_frc = ((double)frc.get_num())/((double)frc.get_den());
        if(this_frc > other_frc) return true;
        return false;
    }

    bool Fraction::operator<(const Fraction& frc) const{
        double this_frc = ((double)this->get_num())/((double)this->get_den());
        double other_frc = ((double)frc.get_num())/((double)frc.get_den());
        if(this_frc < other_frc) return true;
        return false;
    }

    bool Fraction::operator>=(const Fraction& frc) const{
        double this_frc = ((double)this->get_num())/((double)this->get_den());
        double other_frc = ((double)frc.get_num())/((double)frc.get_den());
        if(this_frc >= other_frc) return true;
        return false;
    }

    bool Fraction::operator<=(const Fraction& frc) const{
        double this_frc = ((double)this->get_num())/((double)this->get_den());
        double other_frc = ((double)frc.get_num())/((double)frc.get_den());
        if(this_frc <= other_frc) return true;
        return false;
    }

    bool Fraction::operator==(Fraction frc) const{
        return (num == frc.get_num() && den == frc.get_den());
    }

    bool Fraction::operator!=(const Fraction& frc) const{
        return (this->get_num() != frc.get_num() || this->get_den() != frc.get_den());
    }

    Fraction& Fraction::operator=(const Fraction& frc){
        if(*this != frc){
            num = frc.get_num();
            den = frc.get_den();
        }
        return *this;
    }

    ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << "" << fraction.get_num() << "/" << fraction.get_den();
        return os;
    }

    istream& operator>>(istream& is, Fraction& fraction) {
        int num, den;
        char c;
        is >> num >> c >> den;
        if(c != '/'){
            throw invalid_argument("invalid input");
        }
        fraction = Fraction(num, den);
        return is;
    }

    void Fraction::reduce(){
        int gcd_val = gcd(num, den);
        num = ((int)(num))/gcd_val;
        den = ((int)(den))/gcd_val;
        //cout << "num after reduce " << num << " den after reduce " << den << endl;
    }

    int Fraction::gcd(int a, int b) {

        int minN = min(a,b);
        int res = 1;

        for(int i=1; i<=minN; i++){
            if(a%i==0 && b%i==0)
                res =i;
        }
        return res;
    }

    const Fraction operator+(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        f += frc;
        f.reduce();
        return f;
    }

    const Fraction operator-(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return f - frc;
    }

    const Fraction operator*(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return f * frc;
    }

    const Fraction operator/(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return f / frc;
    }

    const Fraction Fraction::operator+(double num1) const{
        Fraction f = dub_to_frc(num1);
        return *this + f;
    }

    const Fraction Fraction::operator-(double num1) const{
        Fraction f = dub_to_frc(num1);
        return *this - f;
    }

    const Fraction Fraction::operator*(double num1) const{
        Fraction f = dub_to_frc(num1);
        return *this * f;
    }

    const Fraction Fraction::operator/(double num1) const{
        Fraction f = dub_to_frc(num1);
        return *this / f;
    }

    bool Fraction::operator>(double num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this < f);
    }

    bool Fraction::operator<(double num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this > f);
    }

    bool Fraction::operator>=(double num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this >= f);
    }

    bool Fraction::operator<=(double num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this <= f);
    }

    bool Fraction::operator==(double num1) const{
        return (*this == Fraction(num1));
    }

    bool operator>(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f > frc);
    }

    bool operator<(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f < frc);
    }

    bool operator>=(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f >= frc);
    }

    bool operator<=(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f <= frc);
    }

    bool operator==(double num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f == frc);
    }
}