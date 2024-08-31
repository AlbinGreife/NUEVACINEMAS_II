#pragma once
#include<iostream>
#include"Movie.h"
#include"Room.h"
#include"Schedule.h"
#include"Booking.h"
#include"Sale.h"

class Cinema {
private:
    Movie cinemaMovies[4];
    Room cinemaRooms[2];
    Schedule cinemaSchedules[4];
    Booking cinemaBookings[50];
    Sale sales[50];

public:
    Cinema();
    ~Cinema();

    void print();
    void generateMovie();
    void generateRooms();
    void generateSchedules();
    void addMovie();

};