//
// Created by spine on 24.05.2019.
//

#ifndef LABO5_C___REFACTOR_MOCK_MOVIE_H
#define LABO5_C___REFACTOR_MOCK_MOVIE_H

#include <Movie.h>
#include "gmock/gmock.h"  // Brings in Google Mock.

// Hérite de la classe
class MockMovie : public Movie {
public:
    MockMovie(const std::string& title, PriceCode* priceCode = new PriceRegular()): Movie( title, priceCode){

    }
    // MockMovie( const std::string& title, int priceCode = REGULAR) : Movie(title, priceCode) {}
    // Si c'est constant - 0 param
    MOCK_CONST_METHOD0(getPriceCode, PriceCode*());
    // pas const - 1 param
    MOCK_METHOD1(setPriceCode, void ( int arg ));
    MOCK_CONST_METHOD0(getTitle, std::string ());
};



#endif //LABO5_C___REFACTOR_MOCK_MOVIE_H
