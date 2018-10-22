#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string input) 
{
    char lastCharacter = ' ';
    int deletedCharacters = 0;
    for (const auto & charater : input)
    {
        if(lastCharacter == ' ')
        {
            lastCharacter = charater;
            continue;
        }
        if(lastCharacter == charater)
        {
            deletedCharacters++;
        }
        else
        {
            lastCharacter = charater;
        }
    }
    return deletedCharacters;
}

int main()
{
    cout << alternatingCharacters("AAAA") << endl;

    cout << alternatingCharacters("BBBB") << endl;

    cout << alternatingCharacters("ABAB") << endl;

    cout << alternatingCharacters("AAABBB") << endl;

    return 0;
}