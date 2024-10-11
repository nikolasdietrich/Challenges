#include <string>
#include <vector>

std::string toString(const std::vector<int> &digits)
{
    std::string result{""};
    for (auto num : digits)
        result += std::to_string(num);
    return result;
}

int getLastDigit(int num) { return num % 10; }

int removeLastDigit(int num) { return num / 10; }

std::vector<int> multiplyDigits(const std::vector<int> &digits, const int multiplicator)
{
    // based on the "multiplication by hand" learned in school

    std::vector<int> result{};
    int carry{0};
    for (int idx = digits.size() - 1; idx >= 0; idx--)
    {
        int resultForDigit = digits[idx] * multiplicator + carry;
        result.insert(result.begin(), getLastDigit(resultForDigit));
        carry = removeLastDigit(resultForDigit);
    }
    while (carry > 0)
    {
        result.insert(result.begin(), getLastDigit(carry));
        carry = removeLastDigit(carry);
    }
    return result;
}

std::string factorial(int inputNbr)
{
    if (inputNbr < 0)
        return "";
    std::vector<int> result{1};
    for (int nextNumber = 1; nextNumber <= inputNbr; nextNumber++)
        result = multiplyDigits(result, nextNumber);

    return toString(result);
}