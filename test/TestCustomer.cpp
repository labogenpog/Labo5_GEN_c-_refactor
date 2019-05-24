#include <src/Customer.h>
#include <src/testing/mock_Movie.h>
#include "gtest/gtest.h"

using ::testing::AtLeast;  // # 1 Mock

TEST(TestCustomer, essai1) {

    ASSERT_EQ(1,1);

}

TEST(TestCustomer, essai2) {

    Customer customer("Isaia");
    ASSERT_EQ(customer.getName(),"Isaia");

    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

//    ASSERT_EQ(customer.statement(),"Rental Record for Isaia\n"
//                                   "        Karate Kid      9.5\n"
//                                   "        Avengers: Endgame       15\n"
//                                   "        Snow White      1.5\n"
//                                   "Amount owed is 26\n"
//                                   "You earned 4 frequent renter points");

}

TEST(TestCustomer, testMockMovie) {
    MockMovie movie("film1");                          // #2 Crée l'objet mock
    EXPECT_CALL(movie, getTitle())              // #3 Préviens quelle méthode doit être appelé combien de fois
            .Times(AtLeast(0));
    EXPECT_CALL(movie, getPriceCode())
            .Times(AtLeast(0));

    Rental rental(movie,7);                   // #4 Utilise l'objet

    Customer customer("Isaia");
    ASSERT_EQ(customer.getName(),"Isaia");
    customer.addRental( rental);

    //EXPECT_TRUE(customer.statement());          
}                                             // #5 Quand l'objet est détruit, vérifie si tous a été satisfaits.

