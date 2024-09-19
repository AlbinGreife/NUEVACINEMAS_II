#include<iostream>
#include"Seat.h"

Seat::Seat() {
	this->state = "DIS";
}
Seat::~Seat() {

}
void Seat::setState(const std::string& newState) {
	state = newState;
}
std::string Seat::getState() const {
	return this->state;
}