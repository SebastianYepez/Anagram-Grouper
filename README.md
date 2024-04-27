# Anagram-Grouper

## Description
A C++ program that utilizes an unordered map to group lists of anagrams from an input file and output the sizes of said groups. It sorts each word and uses each unique sorted word as a key of the map, the subsequent value pair would be an array of the words that are constructed from this sorted word.

## Algorithm Functionality
An anagram is a word formed by the same letters as another word, but in a different order. So, if we iterate through the list of words we get as an input and sort each one of them alphabetically, we could use these sorted values in order to see which words are indeed anagrams.

To do so, I utilized an unordered map (because of its constant retrieval time) in order to use the sorted letters as a key and storing the original WORDS (group) as the value. 

Ex: aet (key) -> {eat, tea, ate} (value)

Then I counted the size of each key's associated vector and print from highest to lowest.

## Usage
To utilize this program, one simply has to download the main.cpp file and the words.txt file. To compile using GCC, run the command "g++ main.cpp" in the terminal and execute the command "./a.out words.txt." If desired, one could add more words into the file to see the change in output.
