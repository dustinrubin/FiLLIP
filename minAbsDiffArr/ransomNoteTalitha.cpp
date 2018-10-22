#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

// REQUIREMENTS
    /*
        - must have some way to check if a word has been used 
            (if "me" only appears once in the mag, you cannot use "me" twice in the note)
            could be bool or deleting once used? 
            int counter to increment/decrement
        - actual word
    */

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) 
{
    //hash map
    unordered_map<string, int> availableWords;

    // map words from magazine 
    for(int i = 0; i < magazine.size(); i++)
    {
        string word = magazine[i];
        if( availableWords.find(word) == availableWords.end())
        {
            //word has yet to be placed into map
            availableWords.insert({word, 1});
        }
        else
        {
           // word is already in map, another instance has been found
            availableWords.at(word)++;
        }
    }

    // use words in note
    for (int i = 0; i < note.size(); i++)
    {
        string word = note[i];
        if( (availableWords.find(word) == availableWords.end()) || availableWords.at(word) < 1)
        {
            //word does not exist in magazine OR all copies of the word have been used
            cout << "NO" << endl;
            return;
        }
        else
        {
            // word has been used, time to decrement
            availableWords.at(word)--;
        }       
    }

    // if loop completes, everything needed for the note is in the magazine
    cout << "YES" << endl;
    return;

}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

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
