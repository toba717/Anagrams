#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>
#include <cassert>

#include "anagrams.h"

using namespace std;

//helper function to read the dictionary file recursively
int readDictFile(int current, istream& dictfile, string dict[]) {
    //check if the maximum number of words have been read
    if (current >= MAXDICTWORDS) {
        return current;
    }
    else {
        //read the next word and add it to the dictionary
        string word;
        if (getline(dictfile, word)) {
            dict[current] = word;
            return readDictFile(current + 1, dictfile, dict);
        }
        else {
            //return the number of words read
            return current;
        }
    }
}

//function to populate the dictionary file
int lexiconBuilder(istream& dictfile, string dict[]) {
    //call the recursive function to read the file
    return readDictFile(0, dictfile, dict);
}

//check if a word exists in the results array
bool exists(string word, string results[], int current, int size) {
    //check if the entire array has already been checked
    if (current >= size) {
        return false;
    }
    //if the current words match return true
    else if (word == results[current]) {
        return true;
    }
    else {
        //check the next work
        return exists(word, results, current + 1, size);
    }
}

//search the dictionary for anagrams
int searchDictFile(int current, string word, const string dict[], int dictSize, int resFound, string results[]) {
    //check if the entire dictionary has already been checked
    if (current >= dictSize) {
        return resFound;
    }
    else {
        //check if the current word is an anagram of the provided word
        string currWord = dict[current];

        if (isAnagram(currWord, word)) {
            //if it is an anagram and has not already been added to the results array
            if (!exists(currWord, results, 0, resFound))
                //add it
                results[resFound++] = currWord;
        }
        //check the next word
        return searchDictFile(current + 1, word, dict, dictSize, resFound, results);
    }
}

//remove the given letter from the current word
string removeLetter(char letter, string word, int current, string currWord) {
    //check if the end of the word has been reached
    if (current >= word.length()) {
        return word;
    }
    //if the letter matches remove it and return the new word
    else if (word.at(current) == letter) {
        currWord += word.substr(current + 1, word.length() - current - 1);
        return currWord;
    }
    //if not add to the prefix and check the next letter
    else {
        currWord += word.at(current);
        return removeLetter(letter, word, current + 1, currWord);
    }
}

//function to check if two strings are anagrams
bool isAnagram(string word1, string word2) {
    //if the two words are the same return true
    if (word1 == word2) {
        return true;
    }
    //if the two words have different lengths return false
    else if (word1.length() != word2.length()) {
        return false;
    }
    else {
        //remove the same character from both words and check again
        char letter = word1.at(0);
        string newWord1 = word1.substr(1, word1.length() - 1);
        string newWord2 = removeLetter(letter, word2, 0, "");
        return isAnagram(newWord1, newWord2);
    }
}

//function to search for anagrams
int theJumbler(string word, const string dict[], int size, string results[]) {
    return searchDictFile(0, word, dict, size, 0, results);
}

//display the next word in the array
void displayNext(int current, int size, const string results[]) {
    //check if the end of the array has been reached
    if (current >= size){
        return;
    }
    //display the current word
    cout << "Matching word " << results[current] << endl;
    //display the next word
    displayNext(current + 1, size, results);
}

//function to display the output results
void divulgeSolutions(const string results[], int size) {
    if (size == 0) {
        cout << "No matches found\n";
    }
    else {
        //call the function to display the words in the results array
        displayNext(0, size, results);
    }
}


