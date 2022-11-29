#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>


using namespace std;

// adds an edge between two vertices. Keeps track of co-actors and weights of each edge(movie)
void addEdge(unordered_map <string, vector<pair<string, string>>> &adj, string a1, string a2, string movie){
  adj[a1].push_back(make_pair(a2, movie));
  adj[a2].push_back(make_pair(a1, movie));
}

// takes two actors and a movie and conenct them, for each line in the movie file 
void connect_actors(unordered_map <string, vector<pair<string, string>>> &adj, vector<string> tokens){
  for(unsigned int i = 1; i < tokens.size(); i++){
      for(unsigned int j = 1; j < tokens.size(); j++){
          if(i != j){
            addEdge(adj, tokens[i], tokens[j], tokens[0]);
          }
      }
    }
}

bool actors_exist(unordered_map <string, vector<pair<string, string>>> &adj, string actor1, string actor2){
  if (adj.find(actor1) == adj.end() || adj.find(actor2) == adj.end()) {
    return false;
} else {
  return true;
}
}


// Find shortest link between two actors 
vector<pair<pair<string,string>, string>> bfs(unordered_map <string, vector<pair<string, string>>> &adj, string actor1, string actor2){
  // Mark all vertices as not visited 
  //cout << "MOVIE: " << adj[actor1][1].second << endl;
  unordered_map<string, bool> visited;

  vector<pair<pair<string,string>, string>> return_vector;
  // Create a queue 
  list<string> queue;

  /*
  if (visited.find(actor1) == visited.end()){
    visited[actor1] = true;
  }
  */
  queue.push_back(actor1);

  while(!queue.empty()){
    // dequeue vertex from queue 
    
    string actor = queue.front();
    //cout << actor << " ";
    queue.pop_front();
    if (!(visited.find(actor2) == visited.end())){
      break;
    }
    // get all adjacent vertices of dequeued actor. If a adjacent has not been visisted, mark as visited and enqueue it
    for(unsigned int i = 0; i < adj[actor].size(); i++){
      // not visisted 
      if (visited.find(adj[actor][i].first) == visited.end()){
        pair<string, string> p1 = make_pair(actor, adj[actor][i].first);
        return_vector.push_back(make_pair(p1, adj[actor][i].second));
        visited[adj[actor][i].first] = true;
        queue.push_back(adj[actor][i].first);
      }
    }

  }
  return return_vector;
}


vector<pair<string, string>> find_path(vector<pair<pair<string,string>, string>> return_vector, string actor1, string actor2){
  vector<pair<string, string>> shortest_path;
  // reverses the vector 
  reverse(return_vector.begin(), return_vector.end());
  string child = actor2;
  for(unsigned int i = 0; i < return_vector.size(); i++){
    if(return_vector[i].first.second == child){
      shortest_path.push_back(make_pair(return_vector[i].first.second, return_vector[i].second));
      child = return_vector[i].first.first;
    }
  }
  return shortest_path;
}

string path(vector<pair<string, string>> shortest, string actor1){
  string return_path = actor1;
  reverse(shortest.begin(), shortest.end());
  for(unsigned int i = 0; i < shortest.size(); i++){
    string line = " -(" + shortest[i].second + ")- " +  shortest[i].first;
    return_path.append(line);
  }
  return return_path;
}
