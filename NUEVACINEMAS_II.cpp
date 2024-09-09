#include <iostream>
#include"Cinema.h"

void showMenu(bool& logOut);
void gestionarArchivo(bool& logOut);
void gestionarMantenimiento(Cinema& cinema);

void showMenu(bool& logOut, Cinema& cinema) {
    int option;
    do {
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
            //gestionarReserva();
            break;
        case 4:
            //gestionarVenta();
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
        std::cout << "logOut = " << logOut << std::endl;  // Debugging print
        break;
    default:
        std::cout << "Invalid option. Try again.\n";
    }
}

void gestionarMantenimiento(Cinema& cinema) {
    int option;
    do
    {
        std::cout << "1. Movies\n";
        std::cout << "2. Rooms\n";
        std::cout << "3. Schedule\n";
        std::cout << "4. Back to main menu\n";
        std::cout << "Select an option: ";
        std::cin >> option;
        std::cout << "\n";

        switch (option) {
        case 1:
            cinema.addMovie();
            break;
        case 2:
            cinema.generateRooms();
            break;
        case 3:
            cinema.generateSchedules();
            break;
        case 4:
            return;
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    } while (true);
}

void Cinema::print() {//Print movie info
    for (int i = 0; i < 4; ++i) {
        std::cout << "Horario " << (i + 1) << ":\n";
        std::cout << "Fecha: " << cinemaSchedules[i].getDate() << "\n";
        std::cout << "Pelicula: " << cinemaSchedules[i].getMovie().getName() << "\n";
        std::cout << "Sala: " << cinemaSchedules[i].getRoom().getPrice() << "\n\n";
    }
}
void Cinema::generateMovie() {
    Movie movie1("DeadPool&Wolverine", 2024, 2, "USA", 10);
    cinemaMovies[0] = movie1;

    Movie movie2("Avatar Way of Water", 2022, 1, "USA", 8);
    cinemaMovies[1] = movie2;

    Movie movie3("Avengers Infinity War", 2021, 3, "USA", 10);
    cinemaMovies[2] = movie3;

    Movie movie4("Quiet Place Day One", 2024, 2, "USA", 6);
    cinemaMovies[3] = movie4;

}
void Cinema::generateRooms() {
    Room room1(1, 25, 4000);
    cinemaRooms[0] = room1;

    Room room2(2, 25, 4000);
    cinemaRooms[1] = room2;
}
void Cinema::generateSchedules() {
    Schedule schedule1("27/08/2024", 6, 8, cinemaMovies[0], cinemaRooms[0]);
    cinemaSchedules[0] = schedule1;

    Schedule schedule2("27/08/2024", 6, 8, cinemaMovies[1], cinemaRooms[1]);
    cinemaSchedules[1] = schedule2;

    Schedule schedule3("27/08/2024", 6, 8, cinemaMovies[2], cinemaRooms[0]);
    cinemaSchedules[2] = schedule3;

    Schedule schedule4("27/08/2024", 6, 8, cinemaMovies[3], cinemaRooms[1]);
    cinemaSchedules[3] = schedule4;
}
void Cinema::addMovie() {
    int moviesNumber = 0;
    std::cout << "numero de peliculas: ";
    std::cin >> moviesNumber;
    std::cout << "\n";

    if (moviesNumber < 1 || moviesNumber > 10) {
        return;
    }

    std::string name = "", country = "";
    int year = 0, time = 0, reviews = 0;
    for (int index = 0; index < moviesNumber; index++) {
        if (!cinemaMovies[index].getWithData()) {
            std::cout << "name: ";
            std::cin >> name;
            std::cout << "year: ";
            std::cin >> year;
            std::cout << "time: ";
            std::cin >> time;
            std::cout << "reviews: ";
            std::cin >> reviews;
            std::cout << "country: ";
            std::cin >> country;

            //Save movie's info
            cinemaMovies[index].setName(name);
            cinemaMovies[index].setYear(year);
            cinemaMovies[index].setTime(time);
            cinemaMovies[index].setReview(reviews);
            cinemaMovies[index].setCountry(country);
            cinemaMovies[index].setWithData(true);
        }
    }

}
int main()
{
    bool logOut = false;
    Cinema cinema;
    cinema.print();
    showMenu(logOut, cinema);
    //gestionarMantenimiento(cinema);

    std::cout << "\n\n\n\n";
    return 0;
}