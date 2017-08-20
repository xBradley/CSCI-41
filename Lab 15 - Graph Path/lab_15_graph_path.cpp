/*
Bradley Gallardo
CS41
Graph Paths
Displays all posible paths for a vertex
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

#include "graph.h"
#include "searches.h"
using namespace main_savitch_15;

int main()
{
	graph<int> t;

	t.add_vertex(0);
	t.add_vertex(1);
	t.add_vertex(2);
	t.add_vertex(3);
	t.add_vertex(4);
	t.add_vertex(5);

	//t.add_edge(0, 0);
	t.add_edge(0, 1);
	t.add_edge(1, 2);
	t.add_edge(1, 3);
	t.add_edge(2, 4);
	t.add_edge(3, 4);
	t.add_edge(4, 5);
	t.add_edge(5, 0);

	// --- display labels --------------
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << ", ";
	}
	cout << endl;

	// --- display matrix --------------
	cout << "Adjacency Matrix: \n";
	t.display_matrix();
	cout << endl;

	// --- display graph paths --------------
	cout << "Graph Paths: " << endl << endl;

	cout << "vertex = 0 " << endl;
	t.vertex_paths(5);
	cout << endl;

	cout << "vertex = 2 " << endl;
	t.vertex_paths(1);
	cout << endl;

	cout << "vertex = 4 " << endl;
	t.vertex_paths(2);
	cout << endl;


	//--- end of program ---
	cout << endl;
	system("pause");
}

/*
Test Cases
0, 1, 2, 3, 4, 5,
Adjacency Matrix:
        0  1  2  3  4  5
      ------------------
  0 |   0  1  0  0  0  0
  1 |   0  0  1  1  0  0
  2 |   0  0  0  0  1  0
  3 |   0  0  0  0  1  0
  4 |   0  0  0  0  0  1
  5 |   1  0  0  0  0  0


Graph Paths:

vertex = 0
0 -> 1 -> 2 -> 4 -> 5 -> 0 ->
0 -> 1 -> 3 -> 4 -> 5 -> 0 ->

vertex = 2
2 -> 4 -> 5 -> 0 -> 1 -> 2 ->

vertex = 4
4 -> 5 -> 0 -> 1 -> 2 -> 4 ->
4 -> 5 -> 0 -> 1 -> 3 -> 4 ->


Press any key to continue . . .


0, 1, 2, 3, 4, 5,
Adjacency Matrix:
        0  1  2  3  4  5
      ------------------
  0 |   0  1  0  0  0  0
  1 |   0  0  1  1  0  0
  2 |   0  0  0  0  1  0
  3 |   0  0  0  0  1  0
  4 |   0  0  0  0  0  1
  5 |   1  0  0  0  0  0


Graph Paths:

vertex = 0
5 -> 0 -> 1 -> 2 -> 4 -> 5 ->
5 -> 0 -> 1 -> 3 -> 4 -> 5 ->

vertex = 2
1 -> 2 -> 4 -> 5 -> 0 -> 1 ->
1 -> 3 -> 4 -> 5 -> 0 -> 1 ->

vertex = 4
2 -> 4 -> 5 -> 0 -> 1 -> 2 ->


Press any key to continue . . .
*/