#pragma once
#include <iostream>

class Movie {
private:
    std::string name;
    int year;
    int time;
    std::string country;
    int reviews; //From 0 to 10
    bool withData;

public:
    Movie();
    ~Movie();
    Movie(std::string name, int year, int time, std::string country, int review);
    void setName(std::string name);
    void setYear(int year);
    void setTime(int time);
    void setCountry(std::string country);
    void setReview(int review);
    void setWithData(bool withData);

    int getTime();
    std::string getCountry();
    int getReview();
    bool getWithData();
    std::string getName();
    int getYear();
};


