#pragma once
#include<iostream>

class Seat {
private:
    int id;
    std::string state; //Disponible | Reservada | Vendida

public:
    Seat();
    ~Seat();

};