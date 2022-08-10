#ifndef anagrams_h
#define anagrams_h

#include <iostream>

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

//function definitions for three required functions
int lexiconBuilder(std::istream& dictfile, std::string dict[]);
int theJumbler(std::string word, const std::string dict[], int size, std::string results[]);
void divulgeSolutions(const std::string results[], int size);

//function definitions for helper functions
int readDictFile(int current, std::istream& dictfile, std::string dict[]);
bool exists(std::string word, std::string results[], int current, int size);
int searchDictFile(int current, std::string word, const std::string dict[], int dictSize, int resFound, std::string results[]);
std::string removeLetter(char letter, std::string word, int current, std::string currWord);
bool isAnagram(std::string word1, std::string word2);
void displayNext(int current, int size, const std::string results[]);



#endif /* anagrams_h */
