// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (auto &rental : _rentals){

        // add frequent renter points
        frequentRenterPoints += rental.getRenterPoints();

        // show figures for this rental
        result << rental;

        // add amount of rental
        totalAmount += rental.getAmount();
    }
    // add footer lines
    result  << "Amount owed is " << totalAmount << "\n"
            << "You earned " << frequentRenterPoints
            << " frequent renter points";

    return result.str();
}