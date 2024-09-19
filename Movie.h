#pragma once
#include <iostream>

class Movie {
private:
    std::string name;
    int year;
    int time;
    std::string country;
    int reviews; //Del 0 al 10
    bool withData;

public:
    Movie();
    ~Movie();
    Movie(const std::string& n, int y, int t, const std::string& c, int r);
    void setName(const std::string& n);
    void setYear(int y);
    void setTime(int t);
    void setCountry(const std::string& c);
    void setReview(int r);
    void setWithData(bool withData);

    int getTime();
    std::string getCountry();
    int getReview();
    bool getWithData();
    std::string getName();
    int getYear();
};


