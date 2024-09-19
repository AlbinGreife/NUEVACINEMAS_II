#include <iostream>
#include "Cinema.h"

//Prototipos de función
void showMenu(bool& logOut);
void gestionarArchivo(bool& logOut);
void gestionarMantenimiento(Cinema& cinema);
void gestionarReserva(Cinema& cinema);
void gestionarVenta(Cinema& cinema);

void showMenu(bool& logOut, Cinema& cinema) {
    int option;
    do {
        std::cout << "\n";
        std::cout << "1. Archivo\n";
        std::cout << "2. Mantenimiento\n";
        std::cout << "3. Reserva\n";
        std::cout << "4. Venta\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> option;
        std::cout << "\n";

        switch (option) {
        case 1:
            gestionarArchivo(logOut);
            break;
        case 2:
            gestionarMantenimiento(cinema);
            break;
        case 3:
            gestionarReserva(cinema);
            break;
        case 4:
            gestionarVenta(cinema);
            break;

        default:
            std::cout << "Invalid option. Try again.\n";
        }
    } while (!logOut);


}

void gestionarArchivo(bool& logOut) {
    int option;
    std::cout << "1. About\n";
    std::cout << "2. Exit\n";
    std::cout << "Select an option: ";
    std::cin >> option;
    std::cout << "\n";

    switch (option) {
    case 1:
        std::cout << "System dev by Lic.AJGC B).\n";
        break;
    case 2:
        std::cout << "Logging out...\n";
        logOut = true;
        break;
    default:
        std::cout << "Invalid option. Try again.\n";
    }
}

void gestionarMantenimiento(Cinema& cinema) {
    int option;
    do
    {
        std::cout << "1. Change Movies\n";
        std::cout << "2. Change Rooms\n";
        std::cout << "3. Change Schedule\n";
        std::cout << "4. Back to main menu\n";
        std::cout << "Select an option: ";
        std::cin >> option;
        std::cout << "\n";

        switch (option) {
        case 1:
            cinema.modifyMovies();
            break;
        case 2:
            cinema.modifyRooms();
            break;
        case 3:
            cinema.modifySchedules();
            break;
        case 4:
            return;
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    } while (true);
}
void gestionarReserva(Cinema& cinema) {
    int movieIndex = 0, scheduleIndex = 0, roomIndex = 0;

    // Show movies
    std::cout << "Movies available:\n";
    cinema.print();

    // Select movies
    std::cout << "Select the movie index: ";
    std::cin >> movieIndex;

    if (movieIndex < 0 || movieIndex >= cinema.getNumMovies()) {
        std::cout << "Invalid movie selection. Try again.\n";
        return;
    }

    std::cout << "Available schedules for the selected movie:\n";
    for (int i = 0; i < cinema.getNumSchedules(); ++i) {
        if (cinema.getSchedule(i)->getMovie().getName() == cinema.getMovie(movieIndex)->getName()) {
            std::cout << i << ". Date: " << cinema.getSchedule(i)->getDate()
                << ", Start: " << cinema.getSchedule(i)->getStartHour()
                << ", Room: " << cinema.getSchedule(i)->getRoom().getNumber() << "\n";
        }
    }

    // Select schedule
    std::cout << "Select the schedule index: ";
    std::cin >> scheduleIndex;

    if (scheduleIndex < 0 || scheduleIndex >= cinema.getNumSchedules()) {
        std::cout << "Invalid schedule selection. Try again.\n";
        return;
    }

    // get room
    roomIndex = cinema.getSchedule(scheduleIndex)->getRoom().getNumber();
    Room* selectedRoom = cinema.getRoom(roomIndex - 1); // Fit to array index

    // Show 'DIS' seats
    std::cout << "Seat availability in Room " << roomIndex << ":\n";
    for (int i = 0; i < 10; ++i) { //  10 rows (A-J)
        for (int j = 0; j < 10; ++j) { // 10 seats per row
            std::cout << selectedRoom->getSeatState(i, j) << " ";
        }
        std::cout << "\n";
    }

    // Select a seat
    char row;
    int column;
    std::cout << "Select a seat (row letter A-J and column number 1-10): ";
    std::cin >> row >> column;

    int rowIndex = row - 'A';
    int columnIndex = column - 1;

    if (rowIndex < 0 || rowIndex >= 10 || columnIndex < 0 || columnIndex >= 10) {
        std::cout << "Invalid seat selection. Try again.\n";
        return;
    }

    // Verify 'DIS' seat
    if (selectedRoom->getSeatState(rowIndex, columnIndex) == "DIS") {
        selectedRoom->setSeatState(rowIndex, columnIndex, "RES"); // Book seat
        std::cout << "Seat reserved successfully!\n";
    }
    else {
        std::cout << "Seat is already reserved or sold. Try another one.\n";
        return;
    }

    // Getting price
    double price = selectedRoom->getPrice();
    std::cout << "The price of the ticket is: $" << price << "\n";

    // Generate consec
    static int currentBookingNumber = 0;
    cinema.setBookingNumber(currentBookingNumber++);
    std::cout << "Booking number: " << currentBookingNumber - 1 << "\n";

}
void gestionarVenta(Cinema& cinema) {
    int bookingIndex;

    // Ask booking number
    std::cout << "Enter the booking number: ";
    std::cin >> bookingIndex;

    if (bookingIndex < 0 || bookingIndex >= 50) {  // Check if index is in the range
        std::cout << "Invalid booking number.\n";
        return;
    }
    // Check if book already exist
    Booking* booking = cinema.getBooking(bookingIndex);
    if (booking == nullptr) {
        std::cout << "Booking not found. Please try again.\n";
        return;
    }

    // Get the vector of booking numbers
    int* bookingNumbers = booking->getBookingNumbers();

    // Show booking numbers
    std::cout << "Reservation number: " << bookingNumbers[bookingIndex] << "\n";

    // Check if book already sold
    if (booking->isSold()) {
        std::cout << "This booking has already been sold.\n";
        return;
    }

    // Set n booking as sold
    booking->setSold(true);

    // Show sell details
    std::cout << "Sale successful! Here are the details:\n";
    std::cout << "Movie: " << booking->getMovie().getName() << "\n";
    std::cout << "Schedule: " << booking->getSchedule().getDate() << " at " << booking->getSchedule().getStartHour() << "\n";
    std::cout << "Room: " << booking->getRoom().getNumber() << "\n";
    std::cout << "Seat: Row " << booking->getSeatRow() << ", Seat " << booking->getSeatColumn() << "\n";
    std::cout << "Total price: $" << booking->getPrice() << "\n";
}


void Cinema::modifyMovies() {
    int index;
    std::cout << "Select a movie to modify (0 to " << numMovies - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < numMovies) {
        std::string name, country;
        int year, duration, reviews;

        std::cout << "New name: ";
        std::cin >> name;
        std::cout << "New year: ";
        std::cin >> year;
        std::cout << "New duration (min): ";
        std::cin >> duration;
        std::cout << "New country: ";
        std::cin >> country;
        std::cout << "New reviews: ";
        std::cin >> reviews;

        cinemaMovies[index]->setName(name);
        cinemaMovies[index]->setYear(year);
        cinemaMovies[index]->setTime(duration);
        cinemaMovies[index]->setCountry(country);
        cinemaMovies[index]->setReview(reviews);
    }
}
void Cinema::modifyRooms() {
    int index;
    std::cout << "Select a room to modify (0 to " << numRooms - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < numRooms) {
        int number, seats;
        double price;

        std::cout << "New n of rooms: ";
        std::cin >> number;
        std::cout << "New n of seats: ";
        std::cin >> seats;
        std::cout << "New price: ";
        std::cin >> price;

        cinemaRooms[index]->setNumber(number);
        cinemaRooms[index]->setSeats(seats);
        cinemaRooms[index]->setPrice(price);
    }
}
void Cinema::modifySchedules() {
    int index;
    std::cout << "Select a schedule to modify (0 to " << numSchedules - 1 << "): ";
    std::cin >> index;

    if (index >= 0 && index < numSchedules) {
        std::string date;
        int startHour, endHour;

        std::cout << "New date: ";
        std::cin >> date;
        std::cout << "New start hour: ";
        std::cin >> startHour;
        std::cout << "New end hour: ";
        std::cin >> endHour;

        cinemaSchedules[index]->setDate(date);
        cinemaSchedules[index]->setStartHour(startHour);
        cinemaSchedules[index]->setEndHour(endHour);
    }
}

void Cinema::print() {
    std::cout << " Movies:\n";
    for (int i = 0; i < numMovies; i++) {
        std::cout << i << ". " << cinemaMovies[i]->getName()
            << ", Year: " << cinemaMovies[i]->getYear()
            << ", Duration: " << cinemaMovies[i]->getTime() << " mins"
            << ", Country: " << cinemaMovies[i]->getCountry()
            << ", Reviews: " << cinemaMovies[i]->getReview() << "\n";
    }

    std::cout << "\nRooms:\n";
    for (int i = 0; i < numRooms; i++) {
        std::cout << i << ". Room " << cinemaRooms[i]->getNumber()
            << ", Seat: " << cinemaRooms[i]->getSeats()
            << ", Price: $" << cinemaRooms[i]->getPrice() << "\n";
    }

    std::cout << "\nSchedule:\n";
    for (int i = 0; i < numSchedules; i++) {
        std::cout << i << ". Date: " << cinemaSchedules[i]->getDate()
            << ", Start hour: " << cinemaSchedules[i]->getStartHour()
            << ", End hour: " << cinemaSchedules[i]->getEndHour()
            << ", Movie: " << cinemaSchedules[i]->getMovie().getName()
            << ", Room: " << cinemaSchedules[i]->getRoom().getNumber() << "\n";
    }
}

void Cinema::generateMovies() {
    cinemaMovies[0] = new Movie("DeadPool&Wolverine", 2024, 120, "USA", 10);
    cinemaMovies[1] = new Movie("Avatar Way of Water", 2022, 150, "USA", 8);
    cinemaMovies[2] = new Movie("Avengers Infinity War", 2021, 140, "USA", 10);
    cinemaMovies[3] = new Movie("Quiet Place Day One", 2024, 110, "USA", 6);
}

void Cinema::generateRooms() {
    cinemaRooms[0] = new Room(1, 100, 12.50);
    cinemaRooms[1] = new Room(2, 100, 10.00);
}
//revisar tipo de dato
void Cinema::generateSchedules() {
    cinemaSchedules[0] = new Schedule("2024-09-10", 14, 16, *cinemaMovies[0], *cinemaRooms[0]);
    cinemaSchedules[1] = new Schedule("2024-09-10", 16, 18, *cinemaMovies[1], *cinemaRooms[1]);
    cinemaSchedules[2] = new Schedule("2024-09-11", 14, 16, *cinemaMovies[2], *cinemaRooms[0]);
    cinemaSchedules[3] = new Schedule("2024-09-11", 16, 18, *cinemaMovies[3], *cinemaRooms[1]);
}
void Cinema::addMovie() {
    int moviesNumber = 0;
    std::cout << "How many movies? ";
    std::cin >> moviesNumber;
    std::cout << "\n";

    if (moviesNumber < 4 || moviesNumber > 10) {//Check input
        std::cout << "Invalid inout, try again";
        std::cout << "\n";
        return;
    }

    std::string name = "", country = "";
    int year = 0, time = 0, reviews = 0;

    for (int index = 0; index < moviesNumber; index++) {
        if (index >= numMovies) {
            std::cout << "Maximum movie limit reached.\n";
            break;
        }
        if (!cinemaMovies[index]->getWithData()) {
            std::cout << "name: ";
            std::cin >> name;
            // Verify if movie already exist
            bool movieExists = false;
            for (int i = 0; i < numMovies; i++) {
                if (cinemaMovies[i]->getName() == name) {
                    std::cout << "The movie already exist. Try another name.\n";
                    movieExists = true;
                    break;
                }
            }
            if (movieExists) {
                continue; // Avoid duplication and go ahead with next iteration
            }
            std::cout << "year: ";
            std::cin >> year;
            std::cout << "time: ";
            std::cin >> time;
            std::cout << "reviews: ";
            std::cin >> reviews;
            std::cout << "country: ";
            std::cin >> country;
            std::cout << "" << std::endl;

            //store info
            cinemaMovies[index]->setName(name);
            cinemaMovies[index]->setYear(year);
            cinemaMovies[index]->setTime(time);
            cinemaMovies[index]->setReview(reviews);
            cinemaMovies[index]->setCountry(country);
            cinemaMovies[index]->setWithData(true);

            numMovies++;
        }
    }

}

int main()
{
    bool logOut = false;
    Cinema cinema;
    cinema.print();
    showMenu(logOut, cinema);

    std::cout << "\n\n\n\n";
    cinema.print();
    return 0;
}
