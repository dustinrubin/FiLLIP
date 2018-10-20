#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef unordered_map<string, int> wordCount;

wordCount countWords(const vector<string> & input)
{
    wordCount returnValue;
    for(const string& word : input)
    {
        if (returnValue.find(word) == returnValue.end())
        {
            returnValue.insert(make_pair(word,1));
        }
        else 
        {
            returnValue.at(word)++;
        }
    }
    return returnValue;
}

bool checkMagazine(const vector<string> & magazine,const vector<string> & note) 
{
    const wordCount & magazineWordCount = countWords(magazine);
    const wordCount & noteWordCount = countWords(note);
    for(const pair<string, int>& item : noteWordCount)
    {
        string word = item.first;
        if (magazineWordCount.find(word) == magazineWordCount.end())
        {
            return false;
        }
        else if (noteWordCount.at(word) > magazineWordCount.at(word))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //Test examples! 

    vector<string> magzine1 = split_string("give me one grand today night");
    vector<string> note1 = split_string("give one grand today");
    cout << "Trial1:" << (checkMagazine(magzine1, note1) ? "YES" : "NO") << "\n";



    vector<string> magzine2 = split_string("two times three is not four");
    vector<string> note2 = split_string("two times two is four");
    cout << "Trial2:" << (checkMagazine(magzine2, note2) ? "YES" : "NO") << "\n";


    vector<string> magzine3 = split_string("ive got a lovely bunch of coconuts");
    vector<string> note3 = split_string("ive got some coconuts");
    cout << "Trial3:" << (checkMagazine(magzine3, note3) ? "YES" : "NO") << "\n";

    return 0;
}




vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
