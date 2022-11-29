# six_degrees_kevin_bacon

# Description

This program is a twist on the "Six Degrees of Kevin Bacon" game(https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon). The program takes two actors
as input and finds the shortest path between them(actors are connected via co-actors). For example, if we want to find the path between the two actors
Brad Pitt and Tom Cruise, the program will output: "Brad_Pitt -(Moneyball:_Playing_the_Game)- Philip_Seymour_Hoffman -(The_Making_of_the_Mission)- Tom_Cruise".
This means that: Brad Pitt acted with Philip Seymour Hoffman in Moneyball and Philip Seymour Hoffman acted with Tom Cruise in The Making of the Mission.

# How it works

Each line of the text file "cleaned_movielist.txt" contains a movie with all of its actors. With this I create a graph using an adjacency list(utiizing an
unordered_map for quick actor lookup). Then a BST search is done from the first actor until the second actor is found, and the shortest path is found by
tracing back from the last actor's parent vertex back to the first actor.

# How to install and run the project

Download all the files and keep them in the same directory. Run "make" to compile the code:
    ```
    make
    ```
After the code a compiled, an executable names "sixdegrees" is made. Two arguments are required: an input text file and output text file.
    ```
    ./sixdegrees input.txt output.txt
    ```
The input txt can be any provided text file with two actor names in each line. The output text file contains the shortest path of each input(see input.txt
and output.txt for reference).

