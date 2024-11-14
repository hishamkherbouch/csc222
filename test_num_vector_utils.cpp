#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
    vector<int> nums1 = {2, 4, 6};
    string numstr1 = render_num_vector(nums1);
    string expected1 = "2 4 6";
    CHECK(numstr1 == expected1);
    vector<int> nums2 = {1, 3, 5};
    string numstr2 = render_num_vector(nums2);
    string expected2 = "1 3 5";
    CHECK(numstr2 == expected2);
}
