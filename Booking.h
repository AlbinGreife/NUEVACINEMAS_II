#pragma once
#include<iostream>
#include"Schedule.h"
#include"Seat.h"

class Booking {
private:
    Schedule schedule; 
    Seat bookSeats[5]; //5 seats max per booking
    double totalPrice;
    int bookingNumber;

public:
    Booking();
    ~Booking();
};