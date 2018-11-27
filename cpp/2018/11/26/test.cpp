#include <catch2/catch.hpp>
#include <vector>
#include "multiply_sibling_elements.h"

TEST_CASE("Vector elements are multiplied by siblings", "[multiply_sibling_elements]")
{
    REQUIRE(algorithm::multiply_sibling_elements(std::vector<int>{1, 2, 3}) == std::vector<int>{6, 3, 2});
    REQUIRE(algorithm::multiply_sibling_elements(std::vector<int>{1, 2, 3, 4, 5}) == std::vector<int>{120, 60, 40, 30, 24});
    REQUIRE(algorithm::multiply_sibling_elements(std::vector<int>{3, 2, 1}) == std::vector<int>{2, 3, 6});
}