# GraphAdjacencyWalkAnalyzer

**Author**: Nathanlie Ortega


**Email**: NathanlieOrtega.Dev@gmail.com


## Brief Description

C++ console app by Nathanlie Ortega using an adjacency list to create and analyze graphs. Features walk validation (open/closed, trail, path, cycle, circuit) and a user-friendly interface. Demonstrates core graph theory using vectors.


## Files and Structure

- `main.cpp`: Main logic and user input for graph creation and walk testing.

- `Graph.h`, `Graph.cpp`: Graph class and operations for adjacency list and walk analysis.


## Compilation and Execution

1. Navigate to the project folder:

   cd GraphAdjacencyWalkAnalyzer

2. Compile:

    g++ Graph.cpp main.cpp

3. Run:

    ./a.exe


## Alternative Way to Compile and Execute:

1. Navigate to the project folder:

   cd GraphAdjacencyWalkAnalyzer

2. Compile:

    g++ Graph.cpp main.cpp -o GraphAdjacencyWithWalkAnalyzer.exe

3. Run:

    ./GraphAdjacencyWithWalkAnalyzer.exe


## Expected Output:
``````````````````````````````````````````````````````

+-------------------------------------------------+       
|      Graph Adjacency List and Walk Analyzer     |       
|      Author name: Nathanlie Ortega              |       
|      NathanlieOrtega.Dev@gmail.com              |       
+-------------------------------------------------+   


How many Vertices are in this Graph? (Non-Negative Values)
4

For Vertex 0: who are their Neighbors? (-1 stops inquiry)
1
2
-1

For Vertex 1: who are their Neighbors? (-1 stops inquiry)
0
3
-1

For Vertex 2: who are their Neighbors? (-1 stops inquiry)
1
3
2
-1

For Vertex 3: who are their Neighbors? (-1 stops inquiry)
1
3
3
2
-1

Printing the Adjacency List:

0: 1 2
1: 0 3
2: 1 3 2
3: 1 3 3 2


Input walk sequence of alternating vertices that starts and ends with a vertex: (-1 stops input)
0
1
3
-1

WALK IS VALID!

(Continuation)......

````````````````````````````````````````````````````````