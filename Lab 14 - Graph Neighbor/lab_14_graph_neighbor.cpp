/*
Bradley Gallardo
CS41
Graph
Displays graph vertices, matrix, and neighbors
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

#include "graph.h"
using namespace main_savitch_15;

void set_graph_test_1(graph<int> &);
void set_graph_test_2(graph<int> &);
void set_graph_test_3(graph<int> &);

void display_vertices(graph<int>);
void display_matrix(graph<int>);
void display_neighbors(graph<int>);

int main()
{
	graph<int> graph1;
	graph<int> graph2;
	graph<int> graph3;


	//--------------- Test 1 ---------------//
	cout << "******************** TEST 1 ********************" << endl;
	
	//set graph with vertices and edges
	set_graph_test_1(graph1);

	//display vertices
	display_vertices(graph1);

	//display adjacency matrix
	display_matrix(graph1);

	//display neighbors
	display_neighbors(graph1);
	cout << endl;


	//--------------- Test 2 ---------------//
	cout << "******************** TEST 2 ********************" << endl;
	
	//set graph with vertices and edges
	set_graph_test_2(graph2);

	//display vertices
	display_vertices(graph2);

	//--- display adjacency matrix ---
	display_matrix(graph2);

	//--- display neighbors ---
	display_neighbors(graph2);
	cout << endl;


	//--------------- Test 3 ---------------//
	cout << "******************** TEST 3 ********************" << endl;
	
	//set graph with vertices and edges
	set_graph_test_3(graph3);

	//display vertices
	display_vertices(graph3);

	//--- display adjacency matrix ---
	display_matrix(graph3);

	//--- display neighbors ---
	display_neighbors(graph3);
	cout << endl;


	//--- end of program ---
	system("pause");
	return 0;
}

void set_graph_test_1(graph<int> &g) {

	//add vertices
	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(3);

	//add edges
	g.add_edge(0, 0);
	g.add_edge(0, 2);
	g.add_edge(1, 0);
	g.add_edge(1, 3);
	g.add_edge(2, 3);
	g.add_edge(3, 2);
	g.add_edge(3, 0);
}

void set_graph_test_2(graph<int> &g) {
	
	//add vertices
	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(3);
	g.add_vertex(4);
	g.add_vertex(5);
	g.add_vertex(6);
	g.add_vertex(7);

	//add edges
	g.add_edge(1, 6);
	g.add_edge(1, 4);
	g.add_edge(2, 7);
	g.add_edge(3, 4);
	g.add_edge(3, 7);
	g.add_edge(4, 5);
	g.add_edge(7, 5);
	g.add_edge(7, 0);

}

void set_graph_test_3(graph<int> &g) {
	
	//add vertices
	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(3);
	g.add_vertex(4);
	g.add_vertex(5);
	g.add_vertex(6);

	//add edges
	g.add_edge(0, 2);
	g.add_edge(0, 4);
	g.add_edge(1, 3);
	g.add_edge(2, 0);
	g.add_edge(2, 5);
	g.add_edge(3, 2);
	g.add_edge(5, 1);
	g.add_edge(6, 5);
	g.add_edge(6, 1);

}


void display_vertices(graph<int> g) {
	cout << "Vertices: ";
	for (int i = 0; i < g.size(); i++)
	{
		cout << g[i] << ", ";
	}
	cout << endl << endl;
}

void display_matrix(graph<int> g) {
	cout << "Adjacency Matrix: \n";
	g.display_matrix();
	cout << endl;
}

void display_neighbors(graph<int> g) {

	set<std::size_t> mySet;
	set<std::size_t>::iterator iter;

	//get neighbor for each iteration and display set
	for (int i = 0; i < g.size(); ++i) {
		//get neighbor for value i
		mySet = g.neighbors(i);

		cout << "The neighbors of vertex " << i << " are: ";

		//if set is not empty display values
		if (!mySet.empty()) {
			for (iter = mySet.begin(); iter != mySet.end(); ++iter)
				cout << *iter << ", ";
		}
		//if set is empty display none
		else
			cout << "none";

		cout << endl;
	}
	cout << endl;
}


/*
******************** TEST 1 ********************
Vertices: 0, 1, 2, 3,

Adjacency Matrix:
        0  1  2  3
      ------------
  0 |   1  0  1  0
  1 |   1  0  0  1
  2 |   0  0  0  1
  3 |   1  0  1  0


The neighbors of vertex 0 are: 0, 2,
The neighbors of vertex 1 are: 0, 3,
The neighbors of vertex 2 are: 3,
The neighbors of vertex 3 are: 0, 2,


******************** TEST 2 ********************
Vertices: 0, 1, 2, 3, 4, 5, 6, 7,

Adjacency Matrix:
        0  1  2  3  4  5  6  7
      ------------------------
  0 |   0  0  0  0  0  0  0  0
  1 |   0  0  0  0  1  0  1  0
  2 |   0  0  0  0  0  0  0  1
  3 |   0  0  0  0  1  0  0  1
  4 |   0  0  0  0  0  1  0  0
  5 |   0  0  0  0  0  0  0  0
  6 |   0  0  0  0  0  0  0  0
  7 |   1  0  0  0  0  1  0  0


The neighbors of vertex 0 are: none
The neighbors of vertex 1 are: 4, 6,
The neighbors of vertex 2 are: 7,
The neighbors of vertex 3 are: 4, 7,
The neighbors of vertex 4 are: 5,
The neighbors of vertex 5 are: none
The neighbors of vertex 6 are: none
The neighbors of vertex 7 are: 0, 5,


******************** TEST 3 ********************
Vertices: 0, 1, 2, 3, 4, 5, 6,

Adjacency Matrix:
        0  1  2  3  4  5  6
      ---------------------
  0 |   0  0  1  0  1  0  0
  1 |   0  0  0  1  0  0  0
  2 |   1  0  0  0  0  1  0
  3 |   0  0  1  0  0  0  0
  4 |   0  0  0  0  0  0  0
  5 |   0  1  0  0  0  0  0
  6 |   0  1  0  0  0  1  0


The neighbors of vertex 0 are: 2, 4,
The neighbors of vertex 1 are: 3,
The neighbors of vertex 2 are: 0, 5,
The neighbors of vertex 3 are: 2,
The neighbors of vertex 4 are: none
The neighbors of vertex 5 are: 1,
The neighbors of vertex 6 are: 1, 5,


Press any key to continue . . .
*/