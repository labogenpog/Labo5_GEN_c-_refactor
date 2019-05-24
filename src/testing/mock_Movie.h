//
// Created by spine on 24.05.2019.
//

#ifndef LABO5_C___REFACTOR_MOCK_MOVIE_H
#define LABO5_C___REFACTOR_MOCK_MOVIE_H

#include <src/Movie.h>
#include "gmock/gmock.h"  // Brings in Google Mock.


class MockMovie : public Movie {
public:

    MockMovie( const std::string& title, int priceCode = REGULAR) : Movie(title, priceCode) {}

    MOCK_CONST_METHOD0(getPriceCode, int() );
    MOCK_METHOD1(setPriceCode, void ( int arg ));
    MOCK_CONST_METHOD0(getTitle, std::string ());
};


#endif //LABO5_C___REFACTOR_MOCK_MOVIE_H
