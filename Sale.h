#pragma once
#include<iostream>
#include"Booking.h"

class Sale {
private:
    Booking booking; //*
    std::string idClient;
    std::string cardNumber;

public:
    Sale();
    ~Sale();
    std::string getIdClient();
};