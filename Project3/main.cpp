/*
 Name: Takao Oba
 Anagrams Project
 */

#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>
#include <cassert>
#include "anagrams.h"
using namespace std;

int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;


    dictfile.open("words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }

    nwords = lexiconBuilder(dictfile, dict);

    cout << "Please enter a string for an anagram: ";
    cin >> word;

    int numMatches = theJumbler(word, dict, nwords, results);
    if (!numMatches) {
        cout << "No matches found" << endl;
    }
    else {
        divulgeSolutions(results, numMatches);
    }

    return 0;

}
