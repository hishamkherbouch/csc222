#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <Car.h>
using namespace std;

TEST_CASE("Test can create and render MyObject") {
    Car myobj("BMW", "White", "X3", 2025, 0, 100.0 );
    CHECK(myobj.to_string() == "This is MyObject");
}

