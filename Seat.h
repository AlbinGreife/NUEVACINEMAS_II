#pragma once
#include<iostream>

class Seat {
private:
    int id;
    std::string state; //Available | Reserved | Sold


public:
    Seat();
    ~Seat();
    void setState(const std::string& newState);
    std::string getState() const;
};