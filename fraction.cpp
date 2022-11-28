#include <cmath>
#include <iostream>
using namespace std;

struct Fraction {
    int num = 0, den = 1;
};

void input(Fraction& a, int i) {
    cout << "nhap tu so phan so thu " << i + 1 << ": ";
    cin >> a.num;
    cout << "nhap mau so phan so thu " << i + 1 << ": ";
    cin >> a.den;
}

bool isValid(const Fraction a) { return (a.den == 0); }

void printF(const Fraction& a) {
    if (a.den == 1)
        cout << a.num << " ";
    else
        cout << a.num << "/" << a.den << " ";
}

void printArrayF(const Fraction listf[], const int n) {
    for (int i = 0; i < n; i++) printF(listf[i]);
}

int fgcd(const int a, const int b) {
    if (a == b || b == 0)
        return a;
    else
        return fgcd(b, a % b);
}

void simplify(Fraction& a) {
    int gcd = fgcd(abs(a.num), abs(a.den));
    if (a.den < 0) gcd = -gcd;
    a.num /= gcd;
    a.den /= gcd;
}

Fraction add_up(Fraction a, Fraction b) {
    Fraction result;
    simplify(a);
    simplify(b);
    int lcm = (a.den * b.den) / fgcd(a.den, b.den);
    result.num = (lcm / a.den) * a.num + (lcm / b.den) * b.num;
    result.den = lcm;
    simplify(result);
    return result;
}

bool cmpl(const Fraction& a, const Fraction& b) {
    double fa = (double)a.num / a.den, fb = (double)b.num / b.den;
    if (fa == fb)
        return a.num > b.num;
    else
        return fa > fb;
}

void selection_sort(Fraction listf[], const int& n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (cmpl(listf[i], listf[j])) swap(listf[i], listf[j]);
}

int main() {
    int n;
    Fraction listf[100000], sum;
    do {
        cout << "Nhap so phan so: ";
        cin >> n;
    } while (0 <= n && n >= 100000);
    for (int i = 0; i < n; i++) {
        input(listf[i], i);
        while (isValid(listf[i])) input(listf[i], i);
    }
    for (int i = 0; i < n; i++) sum = add_up(sum, listf[i]);
    cout << "Tong cac phan so la: ";
    printF(sum);
    cout << endl;
    selection_sort(listf, n);
    cout << "Day phan so sau khi duoc sap xep la: ";
    printArrayF(listf, n);
    return 0;
}
