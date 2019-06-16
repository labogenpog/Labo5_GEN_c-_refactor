//
// Created by basile on 16/06/19.
//

#ifndef MOCKPRICECODE_H
#define MOCKPRICECODE_H
#include "PriceCode.h"
#include "gmock/gmock.h"

class MockPriceCode : public PriceCode {
public:
    MockPriceCode(): PriceCode(REGULAR) {};
    MOCK_CONST_METHOD1(getAmount, double(int days));
    MOCK_CONST_METHOD0(getPriceCode, int());


};



#endif //MOCKPRICECODE_H
