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
