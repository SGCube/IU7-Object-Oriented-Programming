#include "edge.h"

Edge::Edge() : start(0), end(0) {}

Edge::Edge(size_t start_, size_t end_) : start(start_), end(end_) {}

Edge::Edge(const Edge& edge)
{
	this->start = edge.start;
	this->end = edge.end;
}

Edge::Edge(Edge&& edge)
{
	this->start = edge.start;
	this->end = edge.end;
	edge.~Edge();
}

Edge::~Edge()
{
	this->start = 0;
	this->end = 0;
}

Edge& Edge::operator=(const Edge& edge)
{
	this->start = edge.start;
	this->end = edge.end;
	return *this;
}

Edge& Edge::operator=(Edge&& edge)
{
	this->start = edge.start;
	this->end = edge.end;
	edge.~Edge();
	return *this;
}

size_t Edge::getStart() const
{
	return start;
}

void Edge::setStart(const size_t &value)
{
	start = value;
}

size_t Edge::getEnd() const
{
	return end;
}

void Edge::setEnd(const size_t &value)
{
	end = value;
}
