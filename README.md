# WordBinarySearchTree-C-

Description:

The program opens and reads an input file (named input.txt), and builds a binary search tree of the words and their
counts. The words will be stored in alphabetical order in the tree. The program ignores the case of the words, so
that “Branch” and “branch” are considered the same. However, words that are actually spelled differently — such as
“tree” and “trees” — are considered distinct, and are stored in separate nodes. All words will be stored in the
tree in their lowercase form. 

Upon reading the file and placing it into the Binary Search Tree, queries are executed on the tree. These queries are stored in a file
named "queries.txt". There are an indeterminate number of queries, and all of these are considered in the search. Two forms of
queries are  supported by the tree class:

  1. A query for an individual word returns the number of occurrences of that word in the input file, as
  retrieved from searching the tree, or displays a message stating that the word was not found in the tree.
  This query will be represented in the queries file by the character F (for find) followed by the word being
  searched for (these 2 elements are separated by a space):
  
    F class – This sample query retrieves the number of times the word class shows up (if at all)
    
  2. A query for words that meet or exceed a threshold number of occurrences, results in the output of the
  words (and their counts) that meet that criteria, using inorder tree traversal. This type of query is shown in the queries.txt
  file by the character C (for count), followed by the threshold number of occurrences:
  
    C 15 – Retrieves all words with 15 or more occurrences, and prints the actual # of occurrences

Description Notes: 
  The query type character (F or C) will be in upper case.
  
  The nodes for the word tree are a struct with the following members: 
  
      a) A string containing the word itself
      b) An int containing the count of the number of occurrences of the word 
      c) One pointer
      
Specifications:

1. The program is split into 3 files. There is a WordTree class (with separate interface 'wordtree.h' and implementation file 'wordtree.cpp), and a
driver file 'wordtree_main.cpp'. The details are specified below:

  a) The WordTree class– This class represents a word binary search tree
     Files are named wordtree.h and wordtree.cpp
     Class is named WordTree
     The interface/header file is wordtree.h
     The following member functions in the class (as specified in header file) are:
    
      o A constructor – Initializes an empty tree
      o A destructor – Relies on recursive helper function deleteSubTree to explicitly release all nodes
      allocated during program execution. 
      o Three functions to provide the tree’s functionality. Note that the recursive functions are private, but
      have a public helper function that is callable from client/driver programs. This is done so as to
      not expose the tree’s root, its implementation, etc. to calling code.
      
         addWord – adds a word to the tree. The helper function takes a string (the word to
        be inserted into the tree), and call the recursive function. The recursive function adds
        a node containing the word to the tree, if the word is not found, or increment the word’s
        count, if it is already in the tree.
         findWord – Iterative function that searches for a word in the tree. If the word is found, it
        outputs the word and its occurrence count. Otherwise it displays a message stating that the
        word was not found (see sample output)
         getCounts – searches for words that meet or exceed a threshold count. The helper function
        takes an integer threshold value and calls the recursive function. It also outputs the number
        of words meeting the query, upon returning from the recursive function. The recursive
        function traverses the tree in order, outputting the words that meet or exceed the
        threshold, along with their counts (see sample output), and updating the accumulator.

  b) A driver, or client, file that:
  
     Named wordtree_main.cpp
     Instantiates the WordTree object
     Opens and reads the text file named input.txt and builds the word tree from the file by invoking the
    addWord function described above. The input file contains a single line of words consisting of only
    alphabetic characters (no numbers or punctuation). It is split using a single space character.
     Opens and reads the queries.txt file and invokes each query, as the file is read. The format of this file is as
    previously described. The number of queries in the file varies. You must handle all queries in this file.
  
2. Sample output:

  a) This output shows the program execution:
  ![image](https://user-images.githubusercontent.com/97635420/189779764-40e74751-1800-4261-b5f5-f7da1c3347b3.png)
