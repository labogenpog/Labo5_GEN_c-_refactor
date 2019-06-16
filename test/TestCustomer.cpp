
#include <Customer.h>
#include "testing/mock_Movie.h"
#include "gtest/gtest.h"
#include <memory>


using ::testing::AtLeast;  // # 1 Mock

TEST(TestCustomer, essai1) {

    ASSERT_EQ(1,1);

}

TEST(TestCustomer, testStatmentRegularMore2_ChildrenLess3_New_ReleaseMore1) {

    Customer customer("Tommy");
    ASSERT_EQ(customer.getName(),"Tommy");
    Movie m1( "Karate Kid", new PriceChildrens());
    Movie m2( "Snow White", new PriceChildrens());
    Movie m3( "Avengers: Endgame", new PriceNew_Release());


    customer.addRental( Rental( &m1, 7));
    customer.addRental( Rental( &m3, 5));
    customer.addRental( Rental( &m2, 2 ));

    ASSERT_EQ(customer.statement(), "Rental Record for Tommy\n\tKarate Kid\t7.5\n\tAvengers: Endgame\t15\n\tSnow White\t1.5\nAmount owed is 24\nYou earned 4 frequent renter points");

}

TEST(TestCustomer, testStatmentREGULARLess2) {

    Customer customer("Tommy");
    ASSERT_EQ(customer.getName(),"Tommy");
    Movie m( "Karate Kid", new PriceChildrens());

    customer.addRental(Rental(&m, 1));

    ASSERT_EQ(customer.statement(), "Rental Record for Tommy\n\tKarate Kid\t1.5\nAmount owed is 1.5\nYou earned 1 frequent renter points");

}

TEST(TestCustomer, testStatmentCHILDRENSMore3) {

    Customer customer("Isaia");
    ASSERT_EQ(customer.getName(),"Isaia");
    Movie m( "Snow White", new PriceChildrens());

    customer.addRental( Rental(&m, 6 ));

    ASSERT_EQ(customer.statement(), "Rental Record for Isaia\n\tSnow White\t6\nAmount owed is 6\nYou earned 1 frequent renter points");

}

TEST(TestCustomer, testStatmentNew_ReleaseLess1) {

    Customer customer("Basile");
    ASSERT_EQ(customer.getName(),"Basile");
    Movie m( "Avengers: Endgame", new PriceNew_Release());

    customer.addRental( Rental(&m, 1));

    ASSERT_EQ(customer.statement(), "Rental Record for Basile\n\tAvengers: Endgame\t3\nAmount owed is 3\nYou earned 1 frequent renter points");

}

TEST(TestCustomer, testStatmentLimitsINT_MAX) {

    Customer customer("Basile");
    ASSERT_EQ(customer.getName(),"Basile");
    Movie m( "Avengers: Endgame", new PriceNew_Release());

    customer.addRental( Rental( &m, INT_MAX));

    ASSERT_EQ(customer.statement(), "Rental Record for Basile\n\tAvengers: Endgame\t2.14748e+09\nAmount owed is 2.14748e+09\nYou earned 2 frequent renter points");

}

TEST(TestCustomer, testStatmentLimitsINT_MIN) {

    Customer customer("Basile");
    ASSERT_EQ(customer.getName(),"Basile");
    Movie m( "Avengers: Endgame", new PriceNew_Release());

    customer.addRental( Rental(&m, INT_MIN));

    ASSERT_EQ(customer.statement(), "Rental Record for Basile\n\tAvengers: Endgame\t-2.14748e+09\nAmount owed is -2.14748e+09\nYou earned 1 frequent renter points");

}


TEST(TestCustomer, testStatement) {

   // std::unique_ptr <MockMovie> movie ( new MockMovie("film1"));
    MockMovie* movie ( new MockMovie("Film Lambda"));
    PriceCode *pc = new PriceRegular();
    EXPECT_CALL(*movie, getPriceCode()).WillRepeatedly(testing::Return(pc));
    EXPECT_CALL(*movie, getTitle()).WillRepeatedly(testing::Return("Film Lambda"));

    ASSERT_EQ(movie->getTitle(),"Film Lambda");
    ASSERT_EQ(movie->getPriceCode(), pc);

    Rental rental(movie, 7);

    Customer customer("Isaia");
    ASSERT_EQ(customer.getName(),"Isaia");

    customer.addRental(rental);

    ASSERT_EQ(customer.statement(), "Rental Record for Isaia\n\tFilm Lambda\t9.5\nAmount owed is 9.5\nYou earned 1 frequent renter points");
    delete movie, pc;
}

