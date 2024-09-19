#include<iostream>
#include"Room.h"

Room::Room(int num, int seatCount, double p) {
	this->number = num;
	this->seats = seatCount;
	this->price = p;
}
Room::Room() {

}
Room::~Room() {

}

//Getters
float Room::getPrice() {
	return this->price;
}
int Room::getSeats() {
	return this->seats;
}
int Room::getNumber() {
	return this->number;
}
std::string Room::getSeatState(int row, int col) {
	return roomSeats[row][col].getState();
}
//Setters
void Room::setNumber(int num) {
	number = num;
}
void Room::setSeats(int seatCount) {
	seats = seatCount;
}
void Room::setPrice(double p) {
	price = p;
}
void Room::setSeatState(int row, int col, const std::string& state) {
	roomSeats[row][col].setState(state);
}