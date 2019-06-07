// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"
#include <iostream>

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;

    double getAmount() const;

    int getRenterPoints() const;

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

inline double  Rental::
getAmount() const {
    // determine amounts for the rental
    double thisAmount = this->getMovie().getPriceCode()->getAmount(this->getDaysRented());




//    switch ( this->getMovie().getPriceCode() ) {
//        case Movie::REGULAR:
//            thisAmount += 2;
//            if ( this->getDaysRented() > 2 )
//                thisAmount += ( this->getDaysRented() - 2 ) * 1.5 ;
//            break;
//        case Movie::NEW_RELEASE:
//            thisAmount += this->getDaysRented() * 3;
//            break;
//        case Movie::CHILDRENS:
//            thisAmount += 1.5;
//            if ( this->getDaysRented() > 3 )
//                thisAmount += ( this->getDaysRented() - 3 ) * 1.5;
//            break;
//    }

    return thisAmount;

}

inline int  Rental::
getRenterPoints() const {

    // add frequent renter points
    int frequentRenterPoints = 1;
    // add bonus for a two day new release rental
    if ( ( this->getMovie().getPriceCode()->getPriceCode() == PriceCode::NEW_RELEASE )
         && this->getDaysRented() > 1 ) frequentRenterPoints++;

    return frequentRenterPoints;

}

inline std::ostream & operator<<(std::ostream & Str, Rental const & rental) {

    Str << "\t" << rental.getMovie().getTitle() << "\t"
               << rental.getAmount() << "\n";
    return Str;
}


#endif // RENTAL_H