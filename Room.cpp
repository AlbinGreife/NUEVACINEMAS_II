#include<iostream>
#include"Room.h"

Room::Room() {

}
Room::Room(int id, int seatsNumber, double price) {
	this->id = id;
	this->seatsNumber = seatsNumber;
	this->price = price;
}
Room::~Room() {

}

//Getters
double Room::getPrice() {
	return this->price;
}