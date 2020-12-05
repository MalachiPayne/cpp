#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> word_frequencies;
    word_frequencies["red"] = 2;
    word_frequencies["blue"] = 10;
    word_frequencies["green"] = 5;
    word_frequencies["yellow"] = 8;

    unordered_map<string, int>::iterator itr;
    int sum, pairNumber = 0;

    for (itr = word_frequencies.begin(); itr != word_frequencies.end(); itr++)
    {
        sum += itr->second;
        pairNumber++;
        cout << "Pair [" << pairNumber << "] -> " << itr->first << " " << itr->second << endl;
    }
    cout << "Sum of Values: " << sum << endl;

    return 0;
}