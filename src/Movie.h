// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "PriceCode.h"

class Movie {
public:

    Movie( const std::string& title, PriceCode* priceCode = new PriceRegular());

    virtual PriceCode* getPriceCode() const;
    virtual void setPriceCode( PriceCode* priceCode );
    virtual std::string getTitle() const;

private:
    std::string _title;
    PriceCode* _priceCode;
};

inline PriceCode* Movie::
getPriceCode() const { return _priceCode; }

inline void Movie::
setPriceCode( PriceCode* priceCode ) { _priceCode = priceCode; }

inline std::string Movie::
getTitle() const { return _title; }

inline Movie::
Movie( const std::string& title, PriceCode* priceCode )
        : _title( title )
        , _priceCode( priceCode )
{}


#endif // MOVIE_H