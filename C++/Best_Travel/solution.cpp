#include <iostream>
#include <vector>

class CombinationGenerator
{
public:
    CombinationGenerator(std::vector<int> inputVector, int combinationLength)
        : inputVector_(inputVector), combinationLength_(combinationLength)
    {
        generateAllCombinations();
    }
    std::vector<int> getSums();

private:
    std::vector<int> inputVector_;
    std::vector<std::vector<int>> allCombinations_{};
    const int combinationLength_;
    void generateAllCombinations();
    void recursiveCombinationFunction(const int startPos, const int combinationLength);
};

void CombinationGenerator::recursiveCombinationFunction(
    const int startPos,
    const int combinationLength)
{
    static std::vector<int> currentCombination{};

    if (combinationLength == 0)
    {
        allCombinations_.push_back(currentCombination);
        return;
    }

    for (int currentPos{startPos}; currentPos < inputVector_.size(); currentPos++)
    {
        currentCombination.push_back(inputVector_[currentPos]);
        recursiveCombinationFunction(currentPos + 1,
                                     combinationLength - 1);
        currentCombination.pop_back();
    }
}

void CombinationGenerator::generateAllCombinations()
{
    recursiveCombinationFunction(0, combinationLength_);
}

std::vector<int> CombinationGenerator::getSums()
{
    std::vector<int> result{};

    for (std::vector<int> currentCombination : allCombinations_)
    {
        int sum{0};
        for (int value : currentCombination)
            sum += value;
        result.push_back(sum);
    }
    return result;
}

int getBiggestValueUnder(const std::vector<int> &a, const int max)
{
    int bestValue{-1};
    for (const int &currentValue : a)
    {
        if (currentValue > bestValue && currentValue <= max)
            bestValue = currentValue;
    }
    return bestValue;
}

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int> &ls)
    {
        if (ls.size() < k)
            return -1;

        std::vector<int> sums{CombinationGenerator(ls, k).getSums()};
        return getBiggestValueUnder(sums, t);
    }
};