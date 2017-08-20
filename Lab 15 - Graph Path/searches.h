/*
Bradley Gallardo
CS41
graph path
searches.h
*/

#ifndef SEARCHES_H
#define SEARCHES_H
#include "graph.h"

namespace main_savitch_15
{
    template <class Process, class Item, class SizeType>
    void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[]);
 
    template <class Process, class Item, class SizeType>
    void depth_first(Process f, graph<Item>& g, SizeType start);

    template <class Process, class Item, class SizeType>
    void breadth_first(Process f, graph<Item>& g, SizeType start);

	
}

#include "searches.template" // Include the implementation.
#endif
