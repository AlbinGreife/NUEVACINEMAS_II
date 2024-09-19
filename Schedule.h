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
    Schedule(std::string d, int start, int end, Movie& m, Room& r);
    ~Schedule();
    std::string getDate();
    int getStartHour();
    int getEndHour();
    Movie getMovie();
    Room getRoom();
    void setDate(std::string& d);
    void setStartHour(int start);
    void setEndHour(int end);
    void setMovie(Movie& m);
    void setRoom(Room& r);
};