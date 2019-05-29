
#include <Customer.h>
#include <testing/mock_Movie.h>
#include "gtest/gtest.h"

using ::testing::AtLeast;  // # 1 Mock

TEST(TestCustomer, essai1) {

    ASSERT_EQ(1,1);

}

TEST(TestCustomer, testStatmentRegularMore2_ChildrenLess3_New_ReleaseMore1) {

    Customer customer("Tommy");
    ASSERT_EQ(customer.getName(),"Tommy");

    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 2 ));

    ASSERT_EQ(customer.statement(), "Rental Record for Tommy\n\tKarate Kid\t9.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 26\nYou earned 4 frequent renter points");

}

TEST(TestCustomer, testStatmentREGULARLess2) {

    Customer customer("Tommy");
    ASSERT_EQ(customer.getName(),"Tommy");

    customer.addRental( Rental( Movie("Karate Kid"), 1));

    ASSERT_EQ(customer.statement(), "Rental Record for Tommy\n\tKarate Kid\t2\nAmount owed is 2\nYou earned 1 frequent renter points");

}

TEST(TestCustomer, testStatmentCHILDRENSMore3) {

    Customer customer("Isaia");
    ASSERT_EQ(customer.getName(),"Isaia");

    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 6 ));

    ASSERT_EQ(customer.statement(), "Rental Record for Isaia\n\tSnow White\t6\nAmount owed is 6\nYou earned 1 frequent renter points");

}

TEST(TestCustomer, testStatmentNew_ReleaseLess1) {

    Customer customer("Basile");
    ASSERT_EQ(customer.getName(),"Basile");

    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 1));

    ASSERT_EQ(customer.statement(), "Rental Record for Basile\n\tAvengers: Endgame\t3\nAmount owed is 3\nYou earned 1 frequent renter points");

}

TEST(TestCustomer, testStatmentLimitsINT_MAX) {

    Customer customer("Basile");
    ASSERT_EQ(customer.getName(),"Basile");

    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), INT_MAX));

    ASSERT_EQ(customer.statement(), "Rental Record for Basile\n\tAvengers: Endgame\t2.14748e+09\nAmount owed is 2.14748e+09\nYou earned 2 frequent renter points");

}

TEST(TestCustomer, testStatmentLimitsINT_MIN) {

    Customer customer("Basile");
    ASSERT_EQ(customer.getName(),"Basile");

    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), INT_MIN));

    ASSERT_EQ(customer.statement(), "Rental Record for Basile\n\tAvengers: Endgame\t-2.14748e+09\nAmount owed is -2.14748e+09\nYou earned 1 frequent renter points");

}

// Devrait être faux ! getTitle devrait être appelé 1 fois et getPriceCode 2 fois

// C'est N'IMP!!!!!!!!!!!!!
TEST(TestCustomer, testMockMovie) {
    MockMovie movie("film1");                          // #2 Crée l'objet mock

    // Ajouter virtuel aux fonction de Movie
    // Movie* movieq = &movie; (on passe deja par des adresses
    // Classe abstraite ! methode pas définie virtual
    // unique_ptr<MockMovie> movie ( new MockMovie());
    // Ne compile pas...
    // EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(ReturnRef("film1"));  movie.get()

    EXPECT_CALL(movie, getTitle())              // #3 Préviens quelle méthode doit être appelé combien de fois
            .Times(AtLeast(0));
    EXPECT_CALL(movie, getPriceCode())
            .Times(AtLeast(0));


    ASSERT_EQ(movie.getTitle(),"");
    ASSERT_EQ(movie.getPriceCode(),Movie::REGULAR);


    Rental rental(movie,7);                   // #4 Utilise l'objet


    Customer customer("Isaia");
    ASSERT_EQ(customer.getName(),"Isaia");
    customer.addRental( rental);



    ASSERT_EQ(customer.statement(), "Rental Record for Isaia\n\tfilm1\t9.5\nAmount owed is 9.5\nYou earned 1 frequent renter points");
    //EXPECT_TRUE();
}                                             // #5 Quand l'objet est détruit, vérifie si tous a été satisfaits.

