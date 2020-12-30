#ifndef PATHFINDER_HPP_
#define PATHFINDER_HPP_

#include <iostream>
#include <vector>

#include "Station.hpp"

class PathFinder
{
public:
	PathFinder(/* args */);
	~PathFinder();
	void doYouKnowDaWey(Station *, Station *);

private:
	void explore(Station *, int);
};

#endif /* PATHFINDER_HPP_ */