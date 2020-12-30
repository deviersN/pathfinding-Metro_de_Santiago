#ifndef RIDE_HPP_
#define RIDE_HPP_

#include <iostream>
#include <vector>

class Ride
{
public:
	Ride(/* args */);
	Ride(std::string, std::string, std::vector<size_t>);
	~Ride();
	std::vector<std::string> getStations(void) const;
	std::vector<std::string> getStops(void) const;
	size_t getDist(void) const;
	void setStops(const std::vector<std::string>);
	void setDist(const size_t);
	std::vector<size_t> _id;

private:
	std::vector<std::string> _stations;
	std::vector<std::string> _stops;
	size_t _dist;
};

#endif /* RIDE_HPP_ */
