

/*

File Name: main.cpp

*/

#include <iostream>
#include "Graph.h"

using namespace std;


int main() 
{
	//A display of the title, my name, and e-mail address
	cout << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "|      Graph Adjacency List and Walk Analyzer	  |" << endl;
    cout << "|      Author name: Nathanlie Ortega              |" << endl;
    cout << "|      NathanlieOrtega.Dev@gmail.com              |" << endl;
    cout << "+-------------------------------------------------+\n" << endl;
	
    //This is first part of the execution to prompt user to input the number of vertices to create the adjacency list.
    int nonNegativeValue;

    cout << "\nHow many Vertices are in this Graph? (Non-Negative Values)" << endl;     //Prompt users to input the number of vertices and must be a non-negative value. 
    cin >> nonNegativeValue;
    

    //This will prompt users that the vertices entered is incorrect after entering the number of vertices that are negative values.
    if (nonNegativeValue < 0) 
    {
        cout << endl;

        cout << "Vertices entered is incorrect. The number of vertices has to be non-negative." << endl;

        cout << endl;
        return 1;
    }
    
    //This is a creation of the adjacency list inside a graph object.
    Graph listingGraph(nonNegativeValue);

    listingGraph.generateGraphList();   //Call the function through the construction of the adjacency list.
    
    //This is an execution to print the adjacency list
    cout << "\nPrinting the Adjacency List: \n" << endl;
    listingGraph.displayGraph();

    cout << endl;


    //This will call the userWalkTest function in which it prompts user for a walk and test if the provided walk is valid.
    listingGraph.userWalkTest();

    cout << endl;


    return 0;
}