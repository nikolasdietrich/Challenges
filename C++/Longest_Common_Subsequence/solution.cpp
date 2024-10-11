#include <vector>
#include <string>

using namespace std;

string lcs(const string &x, const string &y)
{
    if (x == y)
        return x;
    if (x == "" || y == "")
        return "";

    vector<vector<string>> results(x.length() + 1, vector<string>(y.length() + 1, ""));

    for (size_t xLen{1}; xLen <= x.length(); xLen++)
    {
        for (size_t yLen{1}; yLen <= y.length(); yLen++)
        {

            if (x.substr(0, xLen).back() == y.substr(0, yLen).back())
            {
                results[xLen][yLen] = results[xLen - 1][yLen - 1] + x.substr(0, xLen).back();
            }

            else
            {
                if (results[xLen][yLen - 1].length() >= results[xLen - 1][yLen].length())
                {
                    results[xLen][yLen] = results[xLen][yLen - 1];
                }
                else
                {
                    results[xLen][yLen] = results[xLen - 1][yLen];
                }
            }
        }
    }
    return results[x.length()][y.length()];
}