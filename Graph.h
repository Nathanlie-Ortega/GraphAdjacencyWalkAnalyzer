
/*

File Name: Graph.h

*/
#include <iostream>
#include <vector>

using namespace std;

class Graph 
{
    private:
        int verticesGraph; //This is a variable that would represent the number of vertices in the graph.

        vector<vector<int>> adjacentList; //This is a vector that represents the adjacency list inside a vector and an integer.


    public:
        Graph(int val); //This is a constructor for graph within a value.

        void generateGraphList(); //This is a function for Part 1, which is to create an adjacency list inside a graph class from user input.

        void displayGraph() const; //This is a function for Part 2, which is to print the adjacency list to the screen after prompting for a graph of vertices.

        void userWalkTest() const;  //This is a function for Part 3, which is to prompt user for a walk and test if the provided walk is valid.
		
		void analyzeWalkProperties(const vector<int>& walkSequence) const; // This is a function for Part 4, which analyzes and prints the properties of a valid walk sequence.
    
};
