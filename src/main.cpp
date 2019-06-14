#include <iostream>

#include "Customer.h"
#include "gtest/gtest.h"

int main() {

    Customer customer("Isaia");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", new PriceNew_Release() ), 5));
    customer.addRental( Rental( Movie("Snow White",  new PriceChildrens() ), 3 ));

    std::cout << customer.statement() << std::endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}