#include "PathFinder.hpp"

PathFinder::PathFinder(/* args */)
{
}

PathFinder::~PathFinder()
{
}

void PathFinder::explore(Station *station, int weight)
{
	unsigned int i = 0;

	station->setStationWeight(weight);
	while (i < station->getStationLinks().size())
	{
		if (station->getStationLinks()[i]->getStationWeight() == 0 || station->getStationLinks()[i]->getStationWeight() > weight + 1)
		{
			this->explore(station->getStationLinks()[i], weight + 1);
		}
		i += 1;
	}
}

std::vector<std::string> PathFinder::doYouKnowDaWey(Station *wayIn, Station *wayOut, int &distance)
{
	std::vector<std::string> path;

	this->explore(wayOut, 1);
	//	std::cout << "To reach his destination from " << wayIn->getStationName() << ", MHB will pass by " << std::endl;
	//	std::cout << wayIn->getStationName() << std::endl;
	path.push_back(wayIn->getStationName());

	for (int dist = wayIn->getStationWeight(); dist > 1; dist--)
	{
		int i = 0;
		while (wayIn->getStationLinks()[i]->getStationWeight() != dist - 1 && i < 4)
		{
			i += 1;
		}
		wayIn = wayIn->getStationLinks()[i];
		path.push_back(wayIn->getStationName());
		//		std::cout << wayIn->getStationName() << std::endl;
		distance += 1;
	}
	//	std::cout << "The whole trip was " << distance << " stations long. Have fun MHB !" << std::endl;
	return path;
}