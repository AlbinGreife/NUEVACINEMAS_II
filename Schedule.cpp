#include<iostream>
#include"Schedule.h"

Schedule::Schedule() {

}
Schedule::Schedule(std::string d, int start, int end, Movie& m, Room& r) {
	this->date = d;
	this->startHour = start;
	this->endHour = end;
	this->movie = m;
	this->room = r;
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
int Schedule::getEndHour() {
	return this->endHour;
}
int Schedule::getStartHour() {
	return this->startHour;
}

//Setters
void Schedule::setDate(std::string& d) {
	date = d;
}
void Schedule::setStartHour(int start) {
	Schedule::startHour = start;
}
void Schedule::setEndHour(int end) {
	endHour = end;
}
void Schedule::setMovie(Movie& m) {
	movie = m;
}
void Schedule::setRoom(Room& r) {
	room = r;
}