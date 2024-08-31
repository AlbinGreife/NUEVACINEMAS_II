#pragma once
#include<iostream>
#include"Seat.h"

class Room {
private:
    int id;
    int seatsNumber;
    double price;
    Seat roomSeats[10][10]; //Seats

public:
    Room();
    Room(int id, int seatsNumber, double price);
    ~Room();
    double getPrice();
};