#include<iostream>
#include"Movie.h"

Movie::Movie() : withData(false) {

}

Movie::~Movie() {

}

Movie::Movie(const std::string& n, int y, int t, const std::string& c, int r) {
    this->name = n;
    this->year = y;
    this->time = t;
    this->country = c;
    this->reviews = r;
}
//Getters
std::string Movie::getName() {
    return this->name;
}

int Movie::getYear() {
    return this->year;
}

int Movie::getTime() {
    return this->time;
}

std::string Movie::getCountry() {
    return this->country;
}

int Movie::getReview() {
    return this->reviews;
}

bool Movie::getWithData() {
    return this->withData;
}

//Setters
void Movie::setName(const std::string& n) {
    this->name = n;
}

void Movie::setYear(int y) {
    this->year = y;
}

void Movie::setTime(int t) {
    this->time = t;
}

void Movie::setCountry(const std::string& c) {
    this->country = c;
}

void Movie::setReview(int r) {
    this->reviews = r;
}

void Movie::setWithData(bool withData) {
    this->withData = withData;
}

