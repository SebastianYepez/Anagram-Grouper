/*
    Written by Sebastian Yepez, 2024
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm> // for sorting
#include <unordered_map>

using namespace std;

/*
OUTLINE

1. Read in list of words from infile into a vector
2. Sort each word in vector into alphabetical order
3. Map each sortedWord to a vector of the anagrams
4. Calculate group sizes
5. Store group sizes in a vector and sort in descending order
6. Print vector with the values associated to the groups
*/

int main(int argc, char *argv[])
{
/* STEP 1 - read input file */
    // open the input file
    ifstream inputFile(argv[1]);

    // check for failure
    if (!inputFile)
    {
        cout << "Input File Error." << endl;
        return 0;
    }

    // vector to store the words from file
    vector<string> words;

    // store words w from input file into words vector
    string w;
    while (getline(inputFile, w)){
        if (!w.empty())
            words.push_back(w);
    }

    // close input file
    inputFile.close();

/* STEP 2 - sort each word */
    vector<string> sortedWords;
    for (string sortedWord : words)
    {
        sort(sortedWord.begin(), sortedWord.end());
        sortedWords.push_back(sortedWord);
    }

/* STEP 3 - map each sortedWord to a vector of the anagrams */
    unordered_map<string, vector<string> > anagramMap; // need a space between > > (or error)
    int i = 0;
    for (string s : sortedWords)
    {
        anagramMap[s].push_back(words[i]); // recall sortedWords.size() == words.size()
        // so, each sortedWord is the sorted word for word at index i from words vector
        // also, we are utilizing the [] shortcut of unordered_maps in two ways here
        // 1. if s does not already exist, it creates a new key (new group)
        // 2. this line adds the word at the index to the associated group
        //      ex: aet -> {eat, tea, ate}
        i++; // keeps up with the index of sortedWords vector
    }

    cout << "Amount of groups: " << anagramMap.size() << endl; // prints number of keys in map (number of groups)

/* STEP 4 - Calculate group sizes */
    // Calculate how many anagrams are in each group and store into a vector to easily sort in descending order
    unordered_map<string, int> numAnagrams;
    for (auto anagram : anagramMap)
    {
        // cout << anagram.first << " "; // debugging to print out groups and the anagram
        int anagramCount = 0;
        for (string s : anagram.second)
        {
        //    cout << s << " ";
            anagramCount++;
        }
        numAnagrams.insert(make_pair(anagram.first, anagramCount)); // inserts the pair between group and size into map
    }
/* STEP 5 - Store group sizes in a vector and sort in descending order */

    // Collect the values from numAnagrams, then insert into a vector and sort into descending order
    vector<int> groupSizes;
    for (auto a : numAnagrams)
    {
        groupSizes.push_back(a.second);
    }
    sort(groupSizes.begin(), groupSizes.end(), greater<int>()); // from <algorithm> library
    // sorts vector in DESCENDING order

/* STEP 6 - output the values */
    // print vector with the values associated to the groups
    int groupNum = 1;
    for (int size : groupSizes)
    {
        cout << "Group " << groupNum << " contains " << size << " words" << endl;
        groupNum++;
    }

    return 0;
}
