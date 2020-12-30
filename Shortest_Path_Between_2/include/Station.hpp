#ifndef STATION_HPP_
#define STATION_HPP_

#include <iostream>
#include <vector>

class Station
{
public:
	Station(/* args */);
	Station(std::string, int);
	~Station();
	std::vector<Station *> getStationLinks(void) const;
	std::string getStationName(void) const;
	int getStationLine(void) const;
	int getStationWeight(void) const;
	void setStationLink(Station *);
	void setStationWeight(int);

private:
	std::vector<Station *> _links;
	std::string _name;
	int _line;
	int _weight;
};

#endif /* STATION_HPP_ */