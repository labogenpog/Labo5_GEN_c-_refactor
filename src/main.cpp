#include <iostream>

#include "Customer.h"
#include "gtest/gtest.h"

int main() {

    Customer customer("Isaia");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::cout << customer.statement() << std::endl;

    return RUN_ALL_TESTS();
}