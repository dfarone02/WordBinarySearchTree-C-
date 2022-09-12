//Daniel Farone
//CSCI 3110-001
//Project #5
//Due: 04/04/22
//This file is the driver for the WordTree class. It instantiates a WordTree object,
//opens and reads the input.txt file and adds each string from the file into the tree until all words have been added.
//Next, the queries.txt file is opened and read, and the options depending on the character are executed.
#include "wordtree.h"
#include <fstream>
#include <vector>
#include <algorithm> //for converting uppercase strings to lowercase

void Split(const std::string& s, char c, std::vector<std::string>& v);

int main()
{
  //instantiate the word tree
  WordTree wt;
  
  //create a vector and string to hold the converted to lowercase strings 
  std::ifstream infile1;
  infile1.open("input.txt");
  std::string phrase;
  std::vector<std::string> words;
  //splits the string into a vector and converts all strings to lowercase 
  getline(infile1, phrase);
  Split(phrase, ' ', words);
  int length = words.size();
  for(int i = 0; i < length; i++)
  {
    //converts string to lowercase
    std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
    wt.addWord(words[i]);
  }
  std::cout << "Word tree built and loaded" << std::endl;
  // 
  std::ifstream infile2;
  infile2.open("queries.txt");
  char query;
  std::string toFind;
  int threshold;
  while(infile2 >> query)
  {
    //Searches the tree for the specified character following the 'F' in queries.txt
    if(query == 'F')
    {
      infile2 >> toFind;
      std::cout << std::endl;
      std::cout << "Searching for occurences of the word '" << toFind << "'" << std::endl;
      wt.findWord(toFind);
    }
    //Searches the tree for all the words that appear more than the integer value that follows 'C' in queries.txt
    else
    {
      infile2 >> threshold;
      std::cout << std::endl;
      std::cout << "Finding all words with " << threshold << " or more occurences:" << std::endl;
      wt.getCounts(threshold);
    }
  }
  
  
	return 0;
}

// From book "C++ Cookbook" by Jeff Cogswell, Jonathan Turkanis, Christopher Diggins, D. Ryan Stephens
// Splits a string s, using character c as a delimeter, and places individual words into a vector of strings
void Split(const std::string& s, char c, std::vector<std::string>& v) 
{
   std::string::size_type i = 0;
   std::string::size_type j = s.find(c);

   while (j != std::string::npos) 
   {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == std::string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}