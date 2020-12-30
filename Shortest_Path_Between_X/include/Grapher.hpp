#ifndef GRAPHER_HPP_
#define GRAPHER_HPP_

#include <iostream>
#include <vector>
#include "Station.hpp"
#include "Map.hpp"

class Grapher
{
public:
	Grapher(/* args */);
	Grapher(std::string, std::string);
	~Grapher();
	void buildGraph(void);
	Station *getNetwork(void) const;
	Station *getWayIn(void) const;
	Station *getWayOut(void) const;

private:
	void setupFirstLine(void);
	void setupSecondLine(void);
	void setupThirdLine(void);
	void setupFourthLine(void);
	void setupFifthLine(void);
	void setupSixthLine(void);
	void setupSeventhLine(void);
	void entryAndExit(Station *);

	std::string _wayIn;
	std::string _wayOut;
	Station *_stationIn;
	Station *_stationOut;

	Station *_network;
	Station *_metro2;
	Station *_metro3;
	Station *_metro4;
	Station *_metro5;
	Station *_metro6;
	Station *_metro7;
	std::vector<Station *> _hub;

	enum hubName
	{
		SAN_PABLO = 0,
		LOS_HEROES,
		U_CHILE,
		BAQUEDANO,
		LOS_LEONES,
		TOBALABA,
		PUENTE_CAL,
		SANTA_ANA,
		FRANKLIN,
		CISTERNA,
		PLAZA_ARMAS,
		IRARRAZAVAL,
		NUNOA,
		PLAZA_ENGANA,
		VICUNA,
		VICENTE,
		NUBLE
	};
};

#endif /* GRAPHER_HPP_ */