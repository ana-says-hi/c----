//
// Created by Ana on 3/15/2023.
//

//TODO check type of value in hw
//TODO better implement compare and make a coverter

#include "length.h"
#include <iomanip>
#include <cmath>
#include <exception>

std::exception NotSameUnit;

Length::Length(float value, std::string unit) {
    this->value = value;
    this->unit = unit;
}

float Length::get_value() const{
    return this->value;
}

std::string Length::get_unit() {
    return this->unit;
}

Length Length::add(Length other) {
    if (this->unit == other.unit) {
        return Length(this->value + other.value, this->unit);
    } else throw std::invalid_argument("incorrect unit");
}

Length Length::substract(Length other) {
    if (this->unit == other.unit)
        return Length(this->value - other.value, this->unit);
    else throw NotSameUnit;
}

Length Length::scale(float mul) {
    return Length(this->value * mul, this->unit);
}

Length Length::divide(float div) {
    return Length(this->value / div, this->unit);
}

std::string Length::text() {
    std::stringstream buffer;
    buffer << "value: " << std::fixed << std::setprecision(2) << this->value
           << "\t unit: " << this->unit << std::endl;
    return buffer.str();
}


//!-1 für len1<len2, 0 len1=len2, +1 für len1>len2
int Length::compare(Length other) {
    Length conv_this=this->convert(other.unit);
    return (conv_this.value - other.value)/fabs(conv_this.value - other.value);
    //    if (conv_this.value - other.value == 0)
//        return 0;
//    else if (conv_this.value- other.value > 0)
//        return 1;
//    else return -1;
        //return this->value-other.value;
}

Length Length::operator+(Length other) {
    Length conv_this=this->convert(other.unit);
    return Length(conv_this.value + other.value, other.unit);
}

Length Length::operator-(Length other) {
    Length conv_this=this->convert(other.unit);
    return Length(conv_this.value - other.value, other.unit);
}

Length Length::operator*(float mul) {
    return Length(this->value * mul, this->unit);
}

Length Length::operator/(float div) {
    return Length(this->value / div, this->unit);
}

Length Length::convert(std::string new_unit) {
    std::string measure[7] = {"mm", "cm", "dm", "m", "dam", "hm", "km"};
    std::string special_mes1 = "mi";
    std::string special_mes2 = "in";

    if (this->get_unit() == new_unit)
        return Length(this->get_value(), this->get_unit());
    else {
        int p = 1;
        int first = -1; //0 if .unit, 1 if new unit
        if (new_unit == special_mes1) {
            p *= 25.4;
            new_unit = "mm";
        }
        if (this->get_unit() == special_mes1) {
            p *= 25.4;
            this->unit = "mm";
        }
        if (new_unit == special_mes2) {
            p *= 1.60;
            new_unit = "km";
        }
        if (this->get_unit() == special_mes2) {
            p *= 1.60;
            this->unit = "km";
        }

        for (int i = 0; i < 7; i++) {
            if (measure[i] == this->get_unit() and first == -1)
                first = 0;
            else if (measure[i] == new_unit and first == -1)
                first = 1;
            else if (first != -1 and (measure[i] == new_unit or measure[i] == this->get_unit()))
                break;
            else p *= 10;
        }
        if (first == 1)
            return Length(this->get_value() * p, new_unit);

        return Length(this->get_value() / p, new_unit);
    }
}



