//
// Created by Ana on 3/15/2023.
//

#ifndef LABOR2_LENGTH_H
#define LABOR2_LENGTH_H


#include <string>

class Length {

private:
        float value;
        std::string unit;
        Length convert(std::string new_unit);

public:
    //!constructor
    Length(float value, std::string unit);

    float get_value() const;
    std::string get_unit();


    //!Erstellen Sie die Methoden add, substract so, dass die Datenkomponenten des
    //!Objektes unverändert bleiben, der zweite Operand als Parameter übergeben wird und
    //!der Rückgabewert das Ergebnis der Operation enthält.
    Length add(Length other);
    Length substract(Length other);

    //!Erstellen Sie eine scale Methode, welche eine Länge mit einer Zahl multipliziert.
    Length scale(float mul);

    //!Erstellen Sie eine divide Methode, welche eine Länge durch eine Zahl dividiert.
    Length divide(float div);

    //!Erstellen Sie eine text Methode, welche den Länge mit Einheit als Zeichenkette
    //!darstellt.
    std::string text();

    //!Erstellen Sie eine compare Methode, welche zwei Längen vergleicht, wobei
    //!len1.compare(len2) folgende Rückgabewerte hat:
    //! -1 für len1<len2, 0 len1=len2, +1 für len1>len2
    int compare(Length other);

    Length operator+(Length other);
    Length operator-(Length other);
    Length operator*(float mul);
    Length operator/(float div);

};


#endif //LABOR2_LENGTH_H
