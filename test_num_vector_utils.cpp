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
    vector<int> nums1 = {2, 4, 6, 8};
    string numstr1 = render_num_vector(nums1);
    string expected1 = "2 4 6 8";
    CHECK(numstr1 == expected1);
    vector<int> nums2 = {1, 3, 5};
    string numstr2 = render_num_vector(nums2);
    string expected2 = "1 3 5";
    CHECK(numstr2 == expected2);
}
TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
    vector<int> nums_2 = {2, 4, 6};
    CHECK(12 == num_vector_sum(nums_2));
    vector<int> nums_3 = {1, 3, 5, 7};
    CHECK(16 == num_vector_sum(nums_3));
}
TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {2, 3, 7};
    CHECK(42 == num_vector_product(nums));
}
TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);
}
TEST_CASE("Testing only_odds") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> odds = only_odds(nums);
    string expected = "1 3 7 11 27";
    CHECK(render_num_vector(odds) == expected);
}
TEST_CASE("Testing nums_between function") {
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    vector<int> nums2 = nums_between(nums, 10, 20);
    string expected = "11 13 10 19 20 14";
    CHECK(render_num_vector(nums2) == expected);
}
TEST_CASE("Testing mean function"){
    vector<int> nums = {1, 3, 5, 7};
    double expected = 4.0;
    CHECK(mean(nums) == expected);
}
TEST_CASE("Testing median function"){
    vector<int> nums = {1, 3, 5, 7, 9};
    int expected = 5;
    CHECK(median(nums) == expected);
}
TEST_CASE("Testing mode function"){
    vector<int> nums = {0, 1, 2, 1, 3};
    vector<int> expected = {1};
    CHECK(mode(nums)==expected);
}
