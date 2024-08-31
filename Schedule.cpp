#include<iostream>
#include"Schedule.h"

Schedule::Schedule() {

}
Schedule::Schedule(std::string date, int startHour, int endHour, Movie movie, Room room) {
	this->date = date;
	this->startHour = startHour;
	this->endHour = endHour;
	this->movie = movie;
	this->room = room;
}


Schedule::~Schedule() {

}

//Getters
Movie Schedule::getMovie() {
	return this->movie;
}
std::string Schedule::getDate() {
	return this->date;
}
Room Schedule::getRoom() {
	return this->room;
}