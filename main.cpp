#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "header.h"


using namespace std;




int main(int argc, char **argv){
  // two cmd line args not provided
  if(argc != 3){
    throw invalid_argument("Invalid Arguemnt!");
  }
  

  // go through each line of cleaned_movielist.txt 
  ifstream movieList;
  ifstream read_input;
  ofstream out_file;
  read_input.open(argv[1]);
  out_file.open(argv[2]);
  movieList.open("cleaned_movielist.txt");
  string line;
  // this is our adjacency list 
  unordered_map<string, vector<pair<string, string>>> adj;
  // loop through each line in movieList 
  while(getline(movieList, line)){
    string buf;  //Buffer string 
    stringstream ss(line);  //Inserts the line into a stringstream
    vector<string> tokens;  // Vectors to store movie/actors
    // store each word into vector 
    while(ss >> buf){
      tokens.push_back(buf);
    }
    // add actors to each other 
    connect_actors(adj, tokens);
    
    // TEST

    // ENDTEST 
  }

// loop through input file 
string line2;
while(getline(read_input, line2)){
    string buf;  //Buffer string 
    stringstream ss(line2);  //Inserts the line into a stringstream
    vector<string> tokens;  // Vectors to store actor input
    // store each word into vector 
    while(ss >> buf){
      tokens.push_back(buf);
    }
    string actor1 = tokens[0];
    string actor2 = tokens[1];
    // EDGE CASES 
    if(!(actors_exist(adj, actor1, actor2))){
      out_file << "Not present" << endl;
      continue;
    }
    if(actor1 == actor2){
      out_file << actor1 << endl;
      continue;
    }
    // EDGE CASES 


    vector<pair<pair<string,string>,string>> my_vector = bfs(adj, actor1, actor2);

    vector<pair<string, string>> shortest = find_path(my_vector, actor1, actor2);

    string return_path = path(shortest, actor1);
    if (!(return_path.find(' ')<return_path.length()|| return_path.find('-')<return_path.length() || return_path.find('(')<return_path.length())){
      out_file << "Not present" << endl;
      continue;
    }
    out_file << return_path<< endl;
}


// END MAIN BRACKET 
}