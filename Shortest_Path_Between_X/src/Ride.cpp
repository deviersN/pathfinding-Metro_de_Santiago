#include "Ride.hpp"

Ride::Ride(/* args */)
{
}

Ride::Ride(std::string entry, std::string exit, std::vector<size_t> id) : _id(id), _stations({entry, exit}), _dist(0)
{
}

Ride::~Ride()
{
}

std::vector<std::string> Ride::getStations(void) const
{
	return this->_stations;
}

std::vector<std::string> Ride::getStops(void) const
{
	return this->_stops;
}

size_t Ride::getDist(void) const
{
	return this->_dist;
}

void Ride::setStops(const std::vector<std::string> path)
{
	this->_stops = path;
}

void Ride::setDist(const size_t dist)
{
	this->_dist = dist;
}