//
// Created by Ugo WAREMBOURG on 05/11/2023.
//

#ifndef TP4_5_HEADER_H
#define TP4_5_HEADER_H

#include <iostream>
#include <stdexcept>

/**
 * Classe Point pour représenter un point en 2D avec des coordonnées x et y.
 */
class Point {
private:
    float x;
    float y;

public:
    Point(float x, float y);

    /**
     * Opérateur de surcharge pour l'addition de deux points.
     * @param other Point à ajouter au point actuel.
     * @return Nouveau point résultant de l'addition.
     */
    Point operator+(const Point &other);

    /**
     * Opérateur de surcharge pour le produit scalaire de deux points.
     * @param other Point à multiplier par le point actuel.
     * @return Résultat du produit scalaire.
     */
    float operator*(const Point &other);

    /**
     * Opérateur de surcharge pour le calcul du point médian entre deux points.
     * @param other Point avec lequel calculer le point médian.
     * @return Point médian entre le point actuel et 'other'.
     */
    Point operator|(const Point &other);

    /**
     * Opérateur de surcharge pour la saisie d'un point depuis une entrée en continu.
     * @param in Flux d'entrée.
     * @param point Point à saisir.
     * @return Flux d'entrée après la saisie.
     */
    friend std::istream &operator>>(std::istream &in, Point &point);

    /**
     * Opérateur de surcharge pour l'affichage d'un point.
     * @param out Flux de sortie.
     * @param point Point à afficher.
     * @return Flux de sortie après l'affichage.
     */
    friend std::ostream &operator<<(std::ostream &out, const Point &point);
};

/**
 * Classe Fraction permettant de représenter et de manipuler des fractions.
 */
class Fraction {
private:
    int num;
    int den;

public:
    Fraction();
    Fraction(const int &num, const int &den);

    void setNum(const int &num);
    void setDen(const int &den);

    /**
     * Opérateur de surcharge pour l'addition de deux fractions.
     * @param other Fraction à ajouter à la fraction actuelle.
     * @return Nouvelle fraction résultante de l'addition.
     */
    Fraction operator+(const Fraction &other);

    /**
     * Opérateur de surcharge pour la soustraction de deux fractions.
     * @param other Fraction à soustraire de la fraction actuelle.
     * @return Nouvelle fraction résultante de la soustraction.
     */
    Fraction operator-(const Fraction &other);

    /**
     * Opérateur de surcharge pour la multiplication de deux fractions.
     * @param other Fraction à multiplier par la fraction actuelle.
     * @return Nouvelle fraction résultante de la multiplication.
     */
    Fraction operator*(const Fraction &other);

    /**
     * Opérateur de surcharge pour la division de deux fractions.
     * @param other Fraction à diviser par la fraction actuelle.
     * @return Nouvelle fraction résultante de la division.
     * @throws std::runtime_error si le dénominateur de 'other' est zéro.
     */
    Fraction operator/(const Fraction &other);

    /**
     * Opérateur de surcharge pour l'addition et la modification de la fraction actuelle.
     * @param other Fraction à ajouter à la fraction actuelle.
     * @return Référence vers la fraction modifiée.
     */
    Fraction &operator+=(const Fraction &other);

    /**
     * Opérateur de surcharge pour la comparaison d'égalité entre deux fractions.
     * @param other Fraction à comparer avec la fraction actuelle.
     * @return 'true' si les deux fractions sont égales, sinon 'false'.
     */
    bool operator==(const Fraction &other);

    /**
     * Opérateur de surcharge pour la comparaison d'inégalité entre deux fractions.
     * @param other Fraction à comparer avec la fraction actuelle.
     * @return 'true' si les deux fractions ne sont pas égales, sinon 'false'.
     */
    bool operator!=(const Fraction &other);

    /**
     * Opérateur de surcharge pour la comparaison de supériorité entre deux fractions.
     * @param other Fraction à comparer avec la fraction actuelle.
     * @return 'true' si la fraction actuelle est supérieure à 'other', sinon 'false'.
     */
    bool operator>(const Fraction &other);

    /**
     * Opérateur de surcharge pour la comparaison d'infériorité entre deux fractions.
     * @param other Fraction à comparer avec la fraction actuelle.
     * @return 'true' si la fraction actuelle est inférieure à 'other', sinon 'false'.
     */
    bool operator<(const Fraction &other);

    /**
     * Opérateur de surcharge pour la comparaison de supériorité ou d'égalité entre deux fractions.
     * @param other Fraction à comparer avec la fraction actuelle.
     * @return 'true' si la fraction actuelle est supérieure ou égale à 'other', sinon 'false'.
     */
    bool operator>=(const Fraction &other);

    /**
     * Opérateur de surcharge pour la comparaison d'infériorité ou d'égalité entre deux fractions.
     * @param other Fraction à comparer avec la fraction actuelle.
     * @return 'true' si la fraction actuelle est inférieure ou égale à 'other', sinon 'false'.
     */
    bool operator<=(const Fraction &other);

    /**
     * Opérateur de surcharge pour la saisie d'une fraction depuis une entrée en continu.
     * @param in Flux d'entrée.
     * @param frac Fraction à saisir.
     * @return Flux d'entrée après la saisie.
     * @throws std::runtime_error si le dénominateur est zéro.
     */
    friend std::istream &operator>>(std::istream &in, Fraction &frac);

    /**
     * Opérateur de surcharge pour l'affichage d'une fraction.
     * @param out Flux de sortie.
     * @param frac Fraction à afficher.
     * @return Flux de sortie après l'affichage.
     */
    friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);
};

#endif //TP4_5_HEADER_H
