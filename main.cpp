#include "header.h"

/**
 * Classe Fraction permettant de représenter et de manipuler des fractions.
 */
Fraction::Fraction() : num(0), den(1) {}

/**
 * Constructeur de Fraction avec numérateur et dénominateur spécifiés.
 * @param num Numérateur de la fraction.
 * @param den Dénominateur de la fraction (ne peut pas être zéro).
 * @throws std::runtime_error si le dénominateur est zéro.
 */
Fraction::Fraction(const int &num, const int &den) : num(num), den(den) {
    if (den == 0) {
        throw std::runtime_error("Denominator cannot be zero.");
    }
}

/**
 * Setter pour le numérateur de la fraction.
 * @param num Nouveau numérateur.
 */
void Fraction::setNum(const int &num) {
    this->num = num;
}

/**
 * Setter pour le dénominateur de la fraction.
 * @param den Nouveau dénominateur (ne peut pas être zéro).
 * @throws std::runtime_error si le dénominateur est zéro.
 */
void Fraction::setDen(const int &den) {
    if (den == 0) {
        throw std::runtime_error("Denominator cannot be zero.");
    }
    this->den = den;
}

/**
 * Opérateur de surcharge pour l'addition de deux fractions.
 * @param other Fraction à ajouter à la fraction actuelle.
 * @return Nouvelle fraction résultante de l'addition.
 */
Fraction Fraction::operator+(const Fraction &other) {
    return Fraction(this->num * other.den + this->den * other.num, this->den * other.den);
}

/**
 * Opérateur de surcharge pour la soustraction de deux fractions.
 * @param other Fraction à soustraire de la fraction actuelle.
 * @return Nouvelle fraction résultante de la soustraction.
 */
Fraction Fraction::operator-(const Fraction &other) {
    return Fraction(this->num * other.den - this->den * other.num, this->den * other.den);
}

/**
 * Opérateur de surcharge pour la multiplication de deux fractions.
 * @param other Fraction à multiplier par la fraction actuelle.
 * @return Nouvelle fraction résultante de la multiplication.
 */
Fraction Fraction::operator*(const Fraction &other) {
    return Fraction(this->num * other.num, this->den * other.den);
}

/**
 * Opérateur de surcharge pour la division de deux fractions.
 * @param other Fraction à diviser par la fraction actuelle (ne peut pas avoir un dénominateur égal à zéro).
 * @return Nouvelle fraction résultante de la division.
 * @throws std::runtime_error si le dénominateur de 'other' est zéro.
 */
Fraction Fraction::operator/(const Fraction &other) {
    if (other.num == 0) {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    return Fraction(this->num * other.den, this->den * other.num);
}

/**
 * Opérateur de surcharge pour l'addition et la modification de la fraction actuelle.
 * @param other Fraction à ajouter à la fraction actuelle.
 * @return Référence vers la fraction modifiée.
 */
Fraction &Fraction::operator+=(const Fraction &other) {
    *this = *this + other;
    return *this;
}

/**
 * Opérateur de surcharge pour la comparaison d'égalité entre deux fractions.
 * @param other Fraction à comparer avec la fraction actuelle.
 * @return 'true' si les deux fractions sont égales, sinon 'false'.
 */
bool Fraction::operator==(const Fraction &other) {
    return (this->num * other.den == this->den * other.num);
}

/**
 * Opérateur de surcharge pour la comparaison d'inégalité entre deux fractions.
 * @param other Fraction à comparer avec la fraction actuelle.
 * @return 'true' si les deux fractions ne sont pas égales, sinon 'false'.
 */
bool Fraction::operator!=(const Fraction &other) {
    return !(*this == other);
}

/**
 * Opérateur de surcharge pour la comparaison de supériorité entre deux fractions.
 * @param other Fraction à comparer avec la fraction actuelle.
 * @return 'true' si la fraction actuelle est strictement supérieure à 'other', sinon 'false'.
 */
bool Fraction::operator>(const Fraction &other) {
    return (this->num * other.den > this->den * other.num);
}

/**
 * Opérateur de surcharge pour la comparaison d'infériorité entre deux fractions.
 * @param other Fraction à comparer avec la fraction actuelle.
 * @return 'true' si la fraction actuelle est strictement inférieure à 'other', sinon 'false'.
 */
bool Fraction::operator<(const Fraction &other) {
    return (this->num * other.den < this->den * other.num);
}

/**
 * Opérateur de surcharge pour la comparaison de supériorité ou d'égalité entre deux fractions.
 * @param other Fraction à comparer avec la fraction actuelle.
 * @return 'true' si la fraction actuelle est supérieure ou égale à 'other', sinon 'false'.
 */
bool Fraction::operator>=(const Fraction &other) {
    return !(*this < other);
}

/**
 * Opérateur de surcharge pour la comparaison d'infériorité ou d'égalité entre deux fractions.
 * @param other Fraction à comparer avec la fraction actuelle.
 * @return 'true' si la fraction actuelle est inférieure ou égale à 'other', sinon 'false'.
 */
bool Fraction::operator<=(const Fraction &other) {
    return !(*this > other);
}

/**
 * Opérateur de surcharge pour la saisie d'une fraction depuis une entrée en continu.
 * @param in Flux d'entrée.
 * @param frac Fraction à saisir.
 * @return Flux d'entrée après la saisie.
 * @throws std::runtime_error si le dénominateur est zéro.
 */
std::istream &operator>>(std::istream &in, Fraction &frac) {
    int newNum, newDen;
    in >> newNum >> newDen;
    if (newDen == 0) {
        throw std::runtime_error("Denominator cannot be zero.");
    }
    frac.setNum(newNum);
    frac.setDen(newDen);
    return in;
}

/**
 * Opérateur de surcharge pour l'affichage d'une fraction.
 * @param out Flux de sortie.
 * @param frac Fraction à afficher.
 * @return Flux de sortie après l'affichage.
 */
std::ostream &operator<<(std::ostream &out, const Fraction &frac) {
    out << frac.num << "/" << frac.den;
    return out;
}

/**
 * Classe Point pour représenter un point en 2D avec des coordonnées x et y.
 */
Point::Point(float x, float y) : x(x), y(y) {}

/**
 * Opérateur de surcharge pour l'addition de deux points.
 * @param other Point à ajouter au point actuel.
 * @return Nouveau point résultant de l'addition.
 */
Point Point::operator+(const Point &other) {
    return Point(this->x + other.x, this->y + other.y);
}

/**
 * Opérateur de surcharge pour le produit scalaire de deux points.
 * @param other Point à multiplier par le point actuel.
 * @return Résultat du produit scalaire.
 */
float Point::operator*(const Point &other) {
    return this->x * other.x + this->y * other.y;
}

/**
 * Opérateur de surcharge pour le calcul du point médian entre deux points.
 * @param other Point avec lequel calculer le point médian.
 * @return Point médian entre le point actuel et 'other'.
 */
Point Point::operator|(const Point &other) {
    return Point((this->x + other.x) / 2, (this->y + other.y) / 2);
}

/**
 * Opérateur de surcharge pour la saisie d'un point depuis une entrée en continu.
 * @param in Flux d'entrée.
 * @param point Point à saisir.
 * @return Flux d'entrée après la saisie.
 */
std::istream &operator>>(std::istream &in, Point &point) {
    in >> point.x >> point.y;
    return in;
}

/**
 * Opérateur de surcharge pour l'affichage d'un point.
 * @param out Flux de sortie.
 * @param point Point à afficher.
 * @return Flux de sortie après l'affichage.
 */
std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.x << ", " << point.y << ")";
}

int main() {
    // Testez la classe Fraction
    Fraction frac1(5, 4);
    Fraction frac2(10, 8);

    std::cout << "frac1 = " << frac1 << std::endl;
    std::cout << "frac2 = " << frac2 << std::endl;

    Fraction sum = frac1 + frac2;
    std::cout << "frac1 + frac2 = " << sum << std::endl;

    // Testez la classe Point
    Point point1(1.0, 2.0);
    Point point2(3.0, 4.0);

    std::cout << "point1 = " << point1 << std::endl;
    std::cout << "point2 = " << point2 << std::endl;

    Point pointSum = point1 + point2;
    std::cout << "point1 + point2 = " << pointSum << std::endl;

    float dotProduct = point1 * point2;
    std::cout << "Point1 * Point2 = " << dotProduct << std::endl;

    Point midPoint = point1 | point2;
    std::cout << "Midpoint of point1 and point2 = " << midPoint << std::endl;

    return 0;
}
