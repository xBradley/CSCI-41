/*
Bradley Gallardo
CS41
graph path
graph.h
*/

#ifndef MAIN_SAVITCH_GRAPH_H
#define MAIN_SAVITCH_GRAPH_H
#include <cstdlib>  // Provides size_t
#include <set>      // Provides set
#include <deque>
#include <iostream>
#include <cassert>
#include <vector>

namespace main_savitch_15
{
    template <class Item>
    class graph
    {
    public:

        // MEMBER CONSTANTS
        static const std::size_t MAXIMUM = 20;

        // CONSTRUCTOR
        graph( ) { many_vertices = 0; }

        // MODIFICATION MEMBER FUNCTIONS
        void add_vertex(const Item& label);
        void add_edge(std::size_t source, std::size_t target);
        void remove_edge(std::size_t source, std::size_t target);
        Item& operator [ ] (std::size_t vertex);

        // CONSTANT MEMBER FUNCTIONS
        std::size_t size( ) const { return many_vertices; }
        bool is_edge(std::size_t source, std::size_t target) const;
        std::set<std::size_t> neighbors(std::size_t vertex) const;
        Item operator[ ] (std::size_t vertex) const;
		void display_matrix();


		//Displays graph paths for vertex to start on
		void vertex_paths(std::size_t start);
		

    private:
        bool edges[MAXIMUM][MAXIMUM];
        Item labels[MAXIMUM];
        std::size_t many_vertices;
    };

	template <class Item>
	void graph<Item>::vertex_paths(std::size_t start) { // <0>

		assert(start < size());								//To check if vertex is less than size of graph						
		std::deque<std::size_t> path;						//To hold the path of graph
		std::vector<std::size_t> blackList;					//To blacklist certain vertices
		std::size_t fork = 0,								//To store fork vertex
			vertex = start,									//To hold position of current vertex
			numPaths = 0;									//To know if a vertex has multiple paths ie it's fork
		bool done = false,									//To know when possible paths are displayed 
			whiteList = true;								//To allow only whitelisted vertices

		//insert starting position to deque
		path.push_back(start);

		//loop until all possible paths are dispalyed
		while (!done) { // <1>

			//for each value less than size of a vertex, check if it blacklisted fork and if 
			// has a path
			for (int i = 0; i < size(); i++) { // <2>

				//if current vertex is a fork, set whilelist to false when i == blacklist value 
				if (!blackList.empty() && vertex == fork && i == blackList[0]) {
					whiteList = false;
					blackList.clear();

				}
		
				//if edge is a neigbhor add to path
				if (edges[vertex][i] == true && whiteList) { // <3>
					
					//add one to num of paths for a vertex
					numPaths++;

					//if less than 2 paths of a single vertex
					if (numPaths < 2)
						path.push_back(i);
					//if 2 or more
					else {
						blackList.push_back(path.back());
						fork = path.back() - 1;
					}
				} // <3>

				whiteList = true;
			} // <2>

			numPaths = 0;
			vertex = path.back();

			//If a full cycle was made vertex should be back at starting vertex value
			if (vertex == start) {
				std::deque<std::size_t>::iterator iter;

				//display path
				for (iter = path.begin(); iter != path.end(); ++iter) 
					std::cout << *iter << " -> ";
				
				std::cout << std::endl;

				//clear path
				path.clear();

				//if blacklist is not empty and blacklist value is the same as start, then we are done
				if (!blackList.empty() && blackList[0] == start)
					done = true;
				//else we have another path to make
				else 
					path.push_back(start);
			}

			//If a full cycle was made vertex should be back at starting vertex value and blacklist is empty
			// then we are done
			if (vertex == start && blackList.empty()) {
				path.clear();
				done = true;
			}

			

		} // <1>
	} // <0>
	

}

#include "graph.template" // Include the implementation.
#endif
