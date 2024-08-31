#include<iostream>
#include"Movie.h"

Movie::Movie() : withData(false) {

}

Movie::~Movie() {

}

Movie::Movie(std::string name, int year, int time, std::string country, int review) {
    this->name = name;
    this->year = year;
    this->time = time;
    this->country = country;
    this->reviews = reviews;
    this->withData = true;
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
void Movie::setName(std::string name) {
    this->name = name;
}

void Movie::setYear(int year) {
    this->year = year;
}

void Movie::setTime(int time) {
    this->time = time;
}

void Movie::setCountry(std::string country) {
    this->country = country;
}

void Movie::setReview(int review) {
    this->reviews = review;
}

void Movie::setWithData(bool withData) {
    this->withData = withData;
}

