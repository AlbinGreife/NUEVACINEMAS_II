#pragma once
#include<iostream>
#include"Movie.h"
#include"Room.h"
#include"Schedule.h"
#include"Booking.h"
#include"Sale.h"

class Cinema {
private:
    Movie** cinemaMovies;
    Room** cinemaRooms;
    Schedule** cinemaSchedules;
    int numMovies;
    int numRooms;
    int numSchedules;
    int numBookings;
    int* bookingNumber;
    Booking* cinemaBookings[50];
    Sale sales[50];

public:
    Cinema();
    ~Cinema();

    Movie* getMovie(int index);
    int getNumMovies();
    Schedule* getSchedule(int index);
    int getNumSchedules();
    Room* getRoom(int bookingIndex);
    Booking* getBooking(int index);
    int* getBookingNumber();
    int getNumBookings() const;

    void setBookingNumber(int bookingNum);

    void print();
    void generateMovies();
    void generateRooms();
    void generateSchedules();
    void addMovie();
    void addBooking(Booking* newBooking);

    void modifyMovies();
    void modifyRooms();
    void modifySchedules();

};
