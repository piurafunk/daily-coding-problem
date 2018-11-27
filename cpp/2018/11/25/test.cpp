#include <catch2/catch.hpp>
#include <vector>
#include "contains_sum_pair.h"

TEST_CASE( "Vector contains a sum pair", "[contains_sum_pair]" ) {
    REQUIRE( algorithm::contains_sum_pair({1, 2, 3, 4, 5}, 9) == true );
    REQUIRE( algorithm::contains_sum_pair({5, 10, 15, 20}, 35) == true );
    REQUIRE( algorithm::contains_sum_pair({1, 3, 5, 7, 9}, 6) == true );
    REQUIRE( algorithm::contains_sum_pair({1546, 2341, 153, 215}, 2494) == true );
}

TEST_CASE( "Vector does not contain a sum pair", "[contains_sum_pair]" ) {
    REQUIRE( algorithm::contains_sum_pair({1, 2, 3, 4, 5}, 500) == false );
    REQUIRE( algorithm::contains_sum_pair({5, 10, 15, 20}, 1000) == false );
    REQUIRE( algorithm::contains_sum_pair({1, 3, 5, 7, 9}, 1531) == false );
    REQUIRE( algorithm::contains_sum_pair({1546, 2341, 153, 215}, 0) == false );
}