
/*

File Name: Graph.cpp

*/

#include <iostream>
#include "Graph.h"

using namespace std;


//This is the constructor, which will simulate the vertices of the graph within a value entered as an input.
Graph::Graph(int val) : verticesGraph(val) 
{
    adjacentList.resize(verticesGraph); // Resize the adjacency list to hold 'vertices' number of vectors
}

//This is a function to create an adjacency list inside a graph class from user input.
void Graph::generateGraphList() 
{
    for (int i = 0; i < verticesGraph; i++) 
    {
        cout << endl;

        cout << "For Vertex " << i << ": " << "who are their Neighbors? (-1 stops inquiry)" << endl;    //This is a vertex input by the user.


        int nearestAdjacent;

        while (true) 
        {
            cin >> nearestAdjacent; //This will read the nearest vertex number from user input.
            
            if (nearestAdjacent == -1)  //This execution will break when it stops in the vertex when -1 is entered as an input.
            {
                break;
            }
            
            //This finds the nearest adjacent.
            if (nearestAdjacent >= 0 && nearestAdjacent < verticesGraph) 
            {
                adjacentList[i].push_back(nearestAdjacent); //This will add the neighbor to the adjacency list.
            } 
            
            else 
            {
                cout << endl;

                cout << "Incorrect input. The nearest adjacent must be between 0 and " << (verticesGraph - 1) << endl;  // This will let the user know of invalid input and prompt again if value is not in the range.
            }
        }
    }
}


//This is a function to print the adjacency list to the screen after prompting for a graph of vertices.
void Graph::displayGraph() const 
{
    for (int list = 0; list < verticesGraph; list++) 
    {
        cout << list << ": ";
        
        for (int nearestAdjacent : adjacentList[list]) 
        {
            cout << nearestAdjacent << " ";
        }
        
        cout << endl;
    }
}



//This is a function to prompt user for a walk and test if the provided walk is valid.
void Graph::userWalkTest() const 
{
    vector<int> userSequence;

    int input;
    
    //This will prompt user for a walk from v0 to vL for testing.
    cout << "\nInput walk sequence of alternating vertices that starts and ends with a vertex: (-1 stops input)" << endl;
    while (true) 
    {
        cin >> input;
        
        if (input == -1) 
        {
            break;

        }

        if (input >= 0 && input < verticesGraph) 
        {
            userSequence.push_back(input);

        } 


        else 
        {
            cout << "Invalid vertex. The input should be around 0 and " << (verticesGraph - 1) << ". " << " Please try entering the input again." << endl;

        }
        
    }
    
    if (userSequence.size() < 2) 
    {
        cout << "WALK NOT VALID!" << endl;  //This will check if the walk sequence has at least 2 vertices.
        return;

    }

    bool adjacentWalks = true;

    for (size_t i = 0; i < userSequence.size() - 1; i++) 
    {
        int vertexCheck = userSequence[i];

        int nearestVertex = userSequence[i + 1];

        //This will search for nearestVertex in the adjacency list of vertexCheck.
        bool adjList = false;

        for (int nearestAdjacent : adjacentList[vertexCheck]) 
        {
            //This means that if the vertices are adjacent, the walk is valid.
            if (nearestAdjacent == nearestVertex) 
            {
                adjList = true;

                break;

            }
        }

        //This means that if the vertices are not adjacent, the walk is invalid.
        if (!adjList) 
        {
            adjacentWalks = false;

            break;

        }
    }
    
    //This is an output of the provided walk after user input test.
    if (adjacentWalks) 
    {
        cout << "WALK IS VALID!" << endl;   //This prints out that the walk is valid.

    }

    else 
    {
        cout << "WALK NOT VALID!" << endl;  //This prints out that the walk is invalid.

    }
}


// This is a function for Part 4, which analyzes and prints the properties of a valid walk sequence (Open/Closed, Trail, Path, Circuit, Cycle).
 void Graph::analyzeWalkProperties(const vector<int>& walkSequence) const 
 {
    cout << "\nThe Walk Sequence <";
    for (size_t i = 0; i < walkSequence.size(); i++) 
    {
        cout << walkSequence[i];
        if (i < walkSequence.size() - 1) cout << ", ";
    }
     cout << "> has the following properties:\n";

   // Check if the walk is Open or Closed.
     bool isClosed = (walkSequence[0] == walkSequence[walkSequence.size() - 1]);
    cout << (isClosed ? "CLOSED" : "OPEN") << endl;
 
     // Check if the walk is a Trail (no repeated edges).
    bool isTrail = true;
    vector<pair<int, int>> edges;
    for (size_t i = 0; i < walkSequence.size() - 1; i++) 
    {
         int u = walkSequence[i];
        int v = walkSequence[i + 1];
         pair<int, int> edge = (u < v) ? make_pair(u, v) : make_pair(v, u);
         for (const auto& e : edges) 
         {
             if (e == edge) 
             {
                 isTrail = false;
                 break;
            }
         }
         if (!isTrail) break;
         edges.push_back(edge);
     }
     if (isTrail) cout << "TRAIL" << endl;
 
    // Check if the walk is a Path (no repeated vertices, except possibly first and last if closed).
     bool isPath = true;
     for (size_t i = 0; i < walkSequence.size() - 1; i++) 
     {
        for (size_t j = i + 1; j < walkSequence.size(); j++) 
         {
             if (isClosed && i == 0 && j == walkSequence.size() - 1) continue;
             if (walkSequence[i] == walkSequence[j]) 
             {
               isPath = false;
                 break;
            }
         }
         if (!isPath) break;
     }
    if (isPath) cout << "PATH" << endl;
 
    // Check if the walk is a Circuit (closed trail).
    if (isClosed && isTrail) 
     {
         cout << "CIRCUIT" << endl;
         // Check if the walk is a Cycle (circuit with no repeated vertices except first and last).
         bool isCycle = true;
         for (size_t i = 0; i < walkSequence.size() - 1; i++) 
         {
             for (size_t j = i + 1; j < walkSequence.size() - 1; j++) 
             {
                if (walkSequence[i] == walkSequence[j]) 
                 {
                     isCycle = false;
                    break;
                 }
            }
             if (!isCycle) break;
         }
         if (isCycle) cout << "CYCLE" << endl;
     }
 }