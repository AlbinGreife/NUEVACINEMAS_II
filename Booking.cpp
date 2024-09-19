#include<iostream>
#include"Booking.h"

Booking::Booking() {

}
Booking::Booking(Movie m, Room r, Schedule s, char row, int col, int numBooking) {
	movie = m;
	room = r;
	schedule = s;
	seatRow = row;
	seatColumn = col;
	sold = false;
	numBookings = numBookings;
	bookingNumber = new int[numBookings];
	for (int i = 0; i < numBookings; ++i) {
		bookingNumber[i] = i + 1; // Assign sequential reservation numbers
	}
}
Booking::~Booking() {
	delete[] bookingNumber;
}
Movie Booking::getMovie() {
	return movie;
}
Room Booking::getRoom() {
	return room;
}
Schedule Booking::getSchedule() {
	return schedule;
}
char Booking::getSeatRow() {
	return seatRow;
}
int Booking::getSeatColumn() {
	return seatColumn;
}
bool Booking::isSold() {
	return sold;
}
void Booking::setSold(bool isSold) {
	sold = isSold;
}
double Booking::getPrice() {
	return room.getPrice();
}
int* Booking::getBookingNumbers() {
	return bookingNumber;
}