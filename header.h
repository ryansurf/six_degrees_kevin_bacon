#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


// Node to keep track each movies name and co-actors for each actor
typedef struct Node{
  vector<string> movies;
  set<string> co_actors;
}Node;


void addEdge(unordered_map <string, vector<pair<string, string>>> &adj, string a1, string a2, string movie);
void connect_actors(unordered_map <string, vector<pair<string, string>>> &adj, vector<string> tokens);
vector<pair<pair<string,string>,string>> bfs(unordered_map <string, vector<pair<string, string>>> &adj, string actor1, string actor2);
vector<pair<string, string>> find_path(vector<pair<pair<string,string>, string>> return_vector, string actor1, string actor2);
string path(vector<pair<string, string>> shortest, string actor1);
bool actors_exist(unordered_map <string, vector<pair<string, string>>> &adj, string actor1, string actor2);