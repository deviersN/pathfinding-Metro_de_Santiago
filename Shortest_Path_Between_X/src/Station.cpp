#include "Station.hpp"

Station::Station(/* args */)
{
}

Station::Station(std::string stationName, int stationLine) : _name(stationName), _line(stationLine), _weight(0)
{
}

Station::~Station()
{
}

std::vector<Station *> Station::getStationLinks(void) const
{
	return this->_links;
}

std::string Station::getStationName(void) const
{
	return this->_name;
}

int Station::getStationLine(void) const
{
	return this->_line;
}

int Station::getStationWeight(void) const
{
	return this->_weight;
}

void Station::setStationLink(Station *next)
{
	this->_links.push_back(next);
}

void Station::setStationWeight(int newWeight)
{
	this->_weight = newWeight;
}