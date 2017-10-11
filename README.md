# Data Structures and Algorithms
## Author: Raghav Ravisankar

This repository contains the following directory structure:
- cpp/
  - autocomplete/
  - huffmann/
- py/
  - graph/
  - list/

## Project Descriptions:
### Autocomplete:

- Directory: cpp/autocomplete
- Description: 
  - This project takes in an input dictionary and some user input and creates predictions using a multi-way trie to predict word completions out of the given user input.
- Usage: 
  - The input dict should be a dict of words with the occurrences in the values and should be name unique_freq_dict.txt in the form 
"key value \n" for each key
  - Commands:
   - "gcc test.cpp" 
   - ./test

- Files:
  - ./test.cpp
  - ./Trie.cpp
  - ./trie.hpp
  - ./util.cpp
  - ./util.hpp

### Huffmann:
- Directory: cpp/huffmann
- Description: 
  - This project takes in a corpus of text and the occurences of words in the text and makes a Hoffmann tree out of the words in the text. Each word is hoffman encoded.
- Usage:
  - Run the ./huffmann file to see the sample output of the algorithm.
  - Add your file to dict and run ./huffman (Coming Soon)
- Files:
  - huffman
  - huffman/BitInputStream.o
  - huffman/BitOutputStream.o
  - huffman/HCNode.o
  - huffman/huffman
  - huffman/huffman.c
  - huffman/input_files
  
### Simple Data Structures in Python
- Directories: 
  - py/list/ 
  - py/ 
  - py/tree/
- Description:
  - This project contains implementations of circular list, dequeue, queue, linkedlist, stack and BST in OOP form.
- Files:
  - py/list/circular.py
  - py/list/dequeue.py
  - py/list/linkedlist.py
  - py/list/queue.py
  - py/stack.py
  - py/tree
  - py/tree/bst.py
- Usage:
  - Run each of the python files using the command python file.py
  
### Graph Algorithms in Python
- Directories
  - py/graph
- Description:
  -  This project contains implementations of djikstras, prims and max flow algorithms for graphs in Python.
- Files 
  - py/graph/djikstras.py
  - py/graph/max_flow.py
  - py/graph/prims.py
- Usage:
  - Run each of the python files using the command python file.py
