//LAB ASSIGNMENT 11- SHREYA SATIJA(202123047)
//BACON NUMBER
//Ques 1 and 2

#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int main() {

    // file reading helping variables
    fstream testCase;

    string line, actor, movie;
    char file[250];

    int len;
    cout<<"Enter name of the file(with .txt extension): ";
    cin.getline(file,250);
    testCase.open(file);
    //testCase.open("sample.txt");

    // helper data structures
    map<string, vector<string>> movieActors, adj;
    map<string, int> actorCount, minDist;
    map<int, vector<string>> distanceActors;

    // file reading
    while(testCase) {
        movie = "";
        actor = "";
        getline(testCase, line);
        len = (int)line.size();
        bool f = 0;
        for(int i=0; i<len; i++) {
            if(line[i] == '|') {
                f = 1;
                continue;
            }
            if(!f) actor += line[i];
            else movie += line[i];
        }
        actorCount[actor]++;
        movieActors[movie].push_back(actor); // a list containing all the actors of a movie
    }

    // adjancency list
    for(auto entry: movieActors) {
        vector<string> actors = entry.second;
        for(int i=0; i<(int)actors.size(); i++) {
            for(int j=i+1; j<(int)actors.size(); j++) {
                adj[actors[i]].push_back(actors[j]);
                adj[actors[j]].push_back(actors[i]); // since the actors form an undirected edge we push both of them into the others list
               }
        }
    }

    // bfs code
    string root = "Kevin Bacon (I)";
    queue<string> q;
    minDist[root] = 0;
    q.push(root);
    while(!q.empty()) {
        string tp = q.front();
        q.pop();
        vector<string> actorsAdj = adj[tp];
        for(int i=0; i<(int)actorsAdj.size(); i++) {
            if(!minDist[actorsAdj[i]] && actorsAdj[i] != root) {
                minDist[actorsAdj[i]] = minDist[tp] + 1;
                q.push(actorsAdj[i]);
            }
        }
    }

    // updating distance of those actors which do not form a connected component with Kevin Bacon (I)
    for(auto actor: actorCount) {
        if(actor.first != root && !minDist[actor.first] && (int)actor.first.size()) {
            minDist[actor.first] = -1;
        }
    }
    cout<<"-1 here denotes infinity (doesnt form a connected component)"<<endl;

    // printing the distance of every actor and storing the actors' distance in a map
    for(auto actor: actorCount) {
        if((int)actor.first.size()) {
            cout << actor.first << " " << minDist[actor.first] << endl;
            distanceActors[minDist[actor.first]].push_back(actor.first);
        }
    }

    char str[250];
    cout << "Enter the name of the actor: ";
    cin.getline(str, 250);
    cout << "The bacon number of the actor is: " << minDist[str] << endl;
    //cout << minDist["Willie Allemang"];

    // printing the actors who are at a particular distance from the root actor
    cout<< "Number of actors corresponding to each bacon number are: "<<endl;
    for(auto distance: distanceActors) {
        if(distance.first <= 10) {
            cout << distance.first << ": ";
            cout << distance.second.size() << endl;
            // for(auto actor: distance.second) {
                // if((int)actor.size()) cout << actor << ", ";
            // }
            // cout << "\n\n";
        }
    }


}

