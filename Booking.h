#pragma once
#include<iostream>
#include"Schedule.h"
#include"Seat.h"

class Booking {
private:
    Movie movie;
    Room room;
    Schedule schedule; //*
    Seat bookSeats[5]; //5 seats max per booking
    double totalPrice;
    int* bookingNumber;
    int numBookings;
    char seatRow;
    int seatColumn;
    bool sold;

public:
    Booking();
    Booking(Movie m, Room r, Schedule s, char row, int col, int numBookings);
    ~Booking();

    Movie getMovie();
    Room getRoom();
    Schedule getSchedule();
    char getSeatRow();
    int getSeatColumn();
    double getPrice();
    int* getBookingNumbers();

    void setSold(bool isSold);

    bool isSold();
};
