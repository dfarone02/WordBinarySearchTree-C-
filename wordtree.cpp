//Daniel Farone
//CSCI 3110-001
//Project #5
//Due: 04/04/22
//This file implements the WordTree class. It creates a new tree, deletes a tree, adds a word to the tree
//searches for a specific word in the tree, and outputs all the nodes that appear more than a specified threshold.
#include "wordtree.h"

//Constructor for the WordTree class that creates an empty tree by setting the root pointer to null.
WordTree::WordTree()
{
  root = nullptr;
}

//Destructor for the WordTree class that calls the deleteSubTree function beginning at root node
WordTree::~WordTree()
{
  deleteSubTree(root);
}

//This function takes the root pointer and word to be found as arguments. It creates and initializes a new node to add the word.
//If the tree is empty, the word becomes the root, if the node equals the word, it accumulates the count of that word in the tree
//otherwise, it moves left or right in the tree until a nullptr is found
void WordTree::addWord(TreeNode *& leaf, std::string w)
{
  TreeNode *newNode = new TreeNode;
  newNode->value = w;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->count = 1;
  
  if(leaf == nullptr)
    leaf = newNode;
  else if(leaf->value == w)
    leaf->count++;
  else if(w < leaf->value)
    addWord(leaf->left, w);
  else
    addWord(leaf->right, w);
}

//Uses postorder traversal to deallocate all of the nodes in the tree
//Takes the root as an argument and continues to traverse the tree until the root is deleted
void WordTree::deleteSubTree(TreeNode *leaf)
{
  if(leaf != nullptr)
  {
    deleteSubTree(leaf->left);
    deleteSubTree(leaf->right);
    delete leaf;
  }
}

//This function takes the root pointer, the counter of occurences of a particular word, and the threshold value
//Outputs the words that exceed the threshold and how many times that word appears in the tree
void WordTree::getCounts(TreeNode *leaf, int roof, int& sum) const
{
  if(leaf != nullptr)
  {
    getCounts(leaf->left, roof, sum);
    if(leaf->count >= roof)
    {
      sum++;
      std::cout << leaf->value << "(" << leaf->count << ")" << std::endl;
    }
    getCounts(leaf->right, roof, sum);
  }
}

//This function takes the word to be added as an argument. It calls the private recursive addWord() function 
//and passes the root pointer and word to be added to this recursive function.
void WordTree::addWord(std::string word)
{
  addWord(root, word);
}

void WordTree::findWord(std::string word)
{
  TreeNode *temp = root;
  while(temp != nullptr && temp->value != word)
  {
    if(word <= temp->value)
      temp = temp->left;
    else
      temp = temp->right;
  }
  if(temp != nullptr)
    std::cout<< "The word '" << word << "' occurs " << temp->count << " time(s) in the text." << std::endl;
  else
    std::cout<< "The word '" << word << "' was not found in the text." << std::endl;
}

//This void function takes the int threshold from the driver file as an argument then 
//initializes a counter for the occurences of that individual word, and ends with a call to the private recursive 
//getCounts() and passes the root pointer, the threshold, and counter to it.
void WordTree::getCounts(int cap)
{
  int total = 0;
  getCounts(root,cap,total);
  std::cout << total << " nodes had words with " << cap << " or more occurence(s)." << std::endl;
}
