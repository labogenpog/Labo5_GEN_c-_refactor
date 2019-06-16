
#include <Customer.h>
#include "testing/mock_Movie.h"
#include "testing/MockPriceCode.h"
#include "gtest/gtest.h"
#include <memory>
#include <iostream>

TEST(TestCalcul, TestPriceCodeChildrenGetAmount) {
    PriceCode *p = new PriceChildrens();
    ASSERT_EQ(p->getAmount(1), 1.5);
    ASSERT_EQ(p->getAmount(5), 4.5);
    delete p;
}

TEST(TestCalcul, TestPriceCodeNewReleaseGetAmount) {
    PriceCode *p = new PriceNew_Release();
    ASSERT_EQ(p->getAmount(1), 3);
    ASSERT_EQ(p->getAmount(5), 15);
    delete p;
}

TEST(TestCalcul, TestPriceCodeRegularGetAmount) {
    PriceCode *p = new PriceRegular();
    ASSERT_EQ(p->getAmount(1), 2);
    ASSERT_EQ(p->getAmount(5), 6.5);
    delete p;
}

TEST(TestCalcul, TestRentalRenterPoint){
    MockPriceCode * p = new MockPriceCode();
    MockMovie * m = new MockMovie("A Title", p);
    EXPECT_CALL(*p, getPriceCode()).WillOnce(testing::Return(0))
                                    .WillOnce(testing::Return(1))
                                    .WillOnce(testing::Return(2));
    EXPECT_CALL(*m, getPriceCode()).WillRepeatedly(testing::Return(p));


    Rental rental(m, 5);

    ASSERT_EQ(rental.getRenterPoints(), 1);
    ASSERT_EQ(rental.getRenterPoints(), 2);
    ASSERT_EQ(rental.getRenterPoints(), 1);
    delete p;
    delete m;
}

TEST(TestCalcul, TestRentalgetDaysRented){
    MockMovie * m = new MockMovie("A Title");
    Rental rental(m, 5);
    ASSERT_EQ(rental.getDaysRented(), 5);
    delete m;
}

TEST(TestCalcul, TestRentalgetMovie){
    MockMovie * m = new MockMovie("A Title");
    Rental rental(m, 5);
    ASSERT_EQ(rental.getMovie(), m);
    delete m;
}

TEST(TestCalcul, TestRentalGetAmount){
    const int days = 5;
    MockMovie * m = new MockMovie("A Title");
    MockPriceCode * p = new MockPriceCode();
    EXPECT_CALL(*m, getPriceCode()).WillRepeatedly(testing::Return(p));
    EXPECT_CALL(*p, getAmount(days)).WillRepeatedly(testing::Return(10));
    Rental rental(m, days);
    ASSERT_EQ(rental.getAmount(), 10);
    delete p;
    delete m;
}