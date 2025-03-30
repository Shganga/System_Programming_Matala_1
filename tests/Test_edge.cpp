#include "doctest.h"
#include "Edge.hpp"

TEST_CASE("Edge class functionality") {
    Edge e(1, 5);

    CHECK(e.getDestination() == 1);  // Destination should be 1
    CHECK(e.getWeight() == 5);       // Weight should be 5
}
