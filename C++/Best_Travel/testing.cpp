#include <assert.h>
#include "solution.cpp"
#include <iostream>

int main()
{
    std::vector<int> distances = {50, 55, 56, 57, 58};
    assert(BestTravel::chooseBestSum(163, 3, distances) == 163);

    distances = {50};
    assert(BestTravel::chooseBestSum(163, 3, distances) == -1);

    distances = {91, 74, 73, 85, 73, 81, 87};
    assert(BestTravel::chooseBestSum(230, 3, distances) == 228);
    assert(BestTravel::chooseBestSum(331, 2, distances) == 178);
    assert(BestTravel::chooseBestSum(331, 4, distances) == 331);
    assert(BestTravel::chooseBestSum(331, 5, distances) == -1);
    assert(BestTravel::chooseBestSum(331, 1, distances) == 91);
    assert(BestTravel::chooseBestSum(700, 8, distances) == -1);
    assert(BestTravel::chooseBestSum(700, 6, distances) == 491);

    distances = {100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50, 132, 123, 34, 89};
    assert(BestTravel::chooseBestSum(230, 4, distances) == 230);
    assert(BestTravel::chooseBestSum(430, 5, distances) == 430);
    assert(BestTravel::chooseBestSum(430, 8, distances) == -1);
    assert(BestTravel::chooseBestSum(880, 8, distances) == 876);
    assert(BestTravel::chooseBestSum(2430, 15, distances) == 1287);
    assert(BestTravel::chooseBestSum(100, 2, distances) == 100);
    assert(BestTravel::chooseBestSum(276, 3, distances) == 276);
    assert(BestTravel::chooseBestSum(3760, 17, distances) == 3654);
    assert(BestTravel::chooseBestSum(3760, 40, distances) == -1);
    assert(BestTravel::chooseBestSum(50, 1, distances) == 50);
    assert(BestTravel::chooseBestSum(1000, 18, distances) == -1);

    distances = {100, 64, 123, 2333, 144, 50, 132, 123, 34, 89};
    assert(BestTravel::chooseBestSum(230, 4, distances) == -1);
    assert(BestTravel::chooseBestSum(230, 2, distances) == 223);
    assert(BestTravel::chooseBestSum(2333, 1, distances) == 2333);
    assert(BestTravel::chooseBestSum(2333, 8, distances) == 825);

    distances = {1000, 640, 1230, 2333, 1440, 500, 1320, 1230, 340, 890, 732, 1346};
    assert(BestTravel::chooseBestSum(2300, 4, distances) == 2212);
    assert(BestTravel::chooseBestSum(2300, 5, distances) == -1);
    assert(BestTravel::chooseBestSum(2332, 3, distances) == 2326);
    assert(BestTravel::chooseBestSum(23331, 8, distances) == 10789);
    assert(BestTravel::chooseBestSum(331, 2, distances) == -1);

    std::cout << "All tests finished succesfully" << std::endl;
}