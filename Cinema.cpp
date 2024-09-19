#include<iostream>
#include"Cinema.h"

Cinema::Cinema() {
    numMovies = 4;
    numRooms = 2;
    numSchedules = 4;
    numBookings = 0;

    bookingNumber = new int[50];
    cinemaMovies = new Movie * [numMovies];
    cinemaRooms = new Room * [numRooms];
    cinemaSchedules = new Schedule * [numSchedules];

    generateMovies();
    generateRooms();
    generateSchedules();
    addMovie();
}
Cinema::~Cinema() {
    // Delete movies
    for (int i = 0; i < numMovies; i++) {
        delete cinemaMovies[i];
    }
    delete[] cinemaMovies;

    // Delete Rooms
    for (int i = 0; i < numRooms; i++) {
        delete cinemaRooms[i];
    }
    delete[] cinemaRooms;

    // Delete schedules
    for (int i = 0; i < numSchedules; i++) {
        delete cinemaSchedules[i];
    }
    delete[] cinemaSchedules;

    // Delete booking numbers reservation
    delete[] bookingNumber;
}
Movie* Cinema::getMovie(int index) {
    if (index >= 0 && index < numMovies) {
        return cinemaMovies[index];
    }
    else {
        // Fix if index is out
        return nullptr; // Return an empty movie object as default
    }
}
int Cinema::getNumMovies() {
    return numMovies;
}
Schedule* Cinema::getSchedule(int index) {
    if (index >= 0 && index < numSchedules) {
        return cinemaSchedules[index];
    }
    else {
        // Fix if index is out
        return nullptr; // Return nullptr if can't find schedule
    }
}
int Cinema::getNumSchedules() {
    return numSchedules;
}
Room* Cinema::getRoom(int index) {
    if (index >= 0 && index < numRooms) {
        return cinemaRooms[index];
    }
    else {
        // Fix if index is out
        return nullptr; // Return nullptr if can't find room
    }
}
int* Cinema::getBookingNumber() {
    return bookingNumber;
}
int Cinema::getNumBookings() const {
    return numBookings;
}
Booking* Cinema::getBooking(int bookingIndex) {
    if (bookingIndex >= 0 && bookingIndex < numBookings) {
        return cinemaBookings[bookingIndex];
    }
    else {
        // Fix if index is out 
        std::cout << "Error: Out-of-range benchmark." << std::endl;
        return nullptr;
    }
}

void Cinema::setBookingNumber(int bookingNum) {
    bookingNumber[numBookings] = bookingNum;
    numBookings++;
}

void Cinema::addBooking(Booking* newBooking) {
    if (numBookings < 50) {
        cinemaBookings[numBookings] = newBooking;  // Guarda la nueva reserva
        numBookings++;  // Incrementa el número de reservas
    }
    else {
        std::cout << "Can't add more reservations." << std::endl;
    }
}
