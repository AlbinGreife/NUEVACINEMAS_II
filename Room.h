#pragma once
#include<iostream>
#include"Seat.h"

class Room {
private:
    int seats;
    float price;
    int number;
    int seatsNumber;
    Seat roomSeats[10][10]; //seats

public:
    Room();
    Room(int num, int seatCount, double p);
    ~Room();
    float getPrice();
    int getNumber();
    int getSeats();
    std::string getSeatState(int row, int col);
    void setNumber(int num);
    void setSeats(int seatCount);
    void setPrice(double p);
    void setSeatState(int row, int col, const std::string& state);
};