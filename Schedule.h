#pragma once
#include<iostream>
#include"Movie.h"
#include"Room.h"

class Schedule {
private:
    std::string date;
    int startHour;
    int endHour;
    Movie movie; 
    Room room; 

public:
    Schedule();
    Schedule(std::string date, int startHour, int endHour, Movie movie, Room room);
    ~Schedule();
    std::string getDate();
    Movie getMovie();
    Room getRoom();
};