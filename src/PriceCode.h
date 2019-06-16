// PriceCode.h
#ifndef PRICECODE_H
#define PRICECODE_H
#include "Movie.h"
#include <iostream>

class PriceCode {
public:
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    PriceCode( int priceCode );

    virtual double getAmount(int daysRental) const;
    int getPriceCode() const;
    void setPriceCode(int priceCode);

    virtual ~PriceCode() {};

protected:
    int _priceCode;
};

inline PriceCode::
PriceCode( int priceCode)
        : _priceCode( priceCode ){}

inline int PriceCode::
getPriceCode() const { return _priceCode; }

inline void PriceCode::
setPriceCode(int priceCode) { _priceCode = priceCode; }

inline double PriceCode::
getAmount(int daysRental) const {
    double thisAmount = 2;
    if ( daysRental > 2 )
        thisAmount += ( daysRental - 2 ) * 1.5 ;
    return thisAmount;
}

// Heritage de PriceCode avec CHILDRENS
class PriceChildrens : public PriceCode{
public:
    PriceChildrens( );
    double getAmount(int daysRental) const ;
    ~PriceChildrens();
};
inline PriceChildrens::
PriceChildrens()
        : PriceCode( CHILDRENS ){}

inline PriceChildrens::~PriceChildrens(){}

inline double PriceChildrens::
getAmount(int daysRental) const {
    double thisAmount = 1.5;
    if ( daysRental > 3 )
        thisAmount += ( daysRental - 3 ) * 1.5 ;
    return thisAmount;
}


// Heritage de PriceCode avec REGULAR
class PriceRegular : public PriceCode{
public:
    PriceRegular( );
    double getAmount(int daysRental) const ;
    ~PriceRegular() ;
};
inline PriceRegular::
PriceRegular()
        : PriceCode( REGULAR ){}
inline PriceRegular::~PriceRegular(){}
inline double PriceRegular::
getAmount(int daysRental) const {
    double thisAmount = 2;
    if ( daysRental > 2 )
        thisAmount += ( daysRental - 2 ) * 1.5 ;
    return thisAmount;
}


// Heritage de PriceCode avec NEW_RELEASE
class PriceNew_Release : public PriceCode{
public:
    PriceNew_Release( );
    double getAmount(int daysRental) const ;
    ~PriceNew_Release();
};
inline PriceNew_Release::
PriceNew_Release()
        : PriceCode( NEW_RELEASE ){}
inline PriceNew_Release::~PriceNew_Release(){}

inline double PriceNew_Release::
getAmount(int daysRental) const {
    return daysRental * 3;;
}


#endif // PRICECODE_H