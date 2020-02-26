#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>


class Edge
{
public:
	Edge();
	Edge(size_t start_, size_t end_);
	Edge(const Edge& edge);
	Edge(Edge&& edge);
	~Edge();
	
	Edge& operator=(const Edge& edge);
	Edge& operator=(Edge&& edge);
	
	size_t getStart() const;
	void setStart(const size_t &value);
	
	size_t getEnd() const;
	void setEnd(const size_t &value);
	
private:
	size_t start;
	size_t end;
};

#endif // EDGE_H
