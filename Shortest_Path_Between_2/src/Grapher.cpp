#include "Grapher.hpp"

Grapher::Grapher(/* args */)
{
}

Grapher::Grapher(std::string in, std::string out) : _wayIn(in), _wayOut(out), _stationIn(nullptr), _stationOut(nullptr),
													_network(new Station("_start_", 1)), _metro2(new Station("_start_", 2)),
													_metro3(new Station("_start_", 3)), _metro4(new Station("_start_", 4)),
													_metro5(new Station("_start_", 5)), _metro6(new Station("_start_", 6)),
													_metro7(new Station("_start_", 7))
{
	this->_network->setStationWeight(-1);
	this->_metro2->setStationWeight(-1);
	this->_metro3->setStationWeight(-1);
	this->_metro4->setStationWeight(-1);
	this->_metro5->setStationWeight(-1);
	this->_metro6->setStationWeight(-1);
	this->_metro7->setStationWeight(-1);
}

Grapher::~Grapher()
{
	delete this->_network;
	delete this->_metro2;
	delete this->_metro3;
	delete this->_metro4;
	delete this->_metro5;
	delete this->_metro6;
	delete this->_metro7;
}

void Grapher::buildGraph(void)
{
	this->setupFirstLine();
	this->setupSecondLine();
	this->setupThirdLine();
	this->setupFourthLine();
	this->setupFifthLine();
	this->setupSixthLine();
	this->setupSeventhLine();
}

void Grapher::setupFirstLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineOne();
	Station *created = new Station(metroLine[0], 1);

	this->_network->setStationLink(created);
	created->setStationLink(this->_network);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = new Station(metroLine[i], 1);
		toCreate->setStationLink(created);
		created->setStationLink(toCreate);
		created = toCreate;
		if (i == 0) //San Pablo
			this->_hub.push_back(toCreate);
		if (i == 10) //Los Heroes
			this->_hub.push_back(toCreate);
		if (i == 12) //La U. de Chile
			this->_hub.push_back(toCreate);
		if (i == 15) //Baquedano
			this->_hub.push_back(toCreate);
		if (i == 19) //Los Leones
			this->_hub.push_back(toCreate);
		if (i == 20) //Tobalaba
			this->_hub.push_back(toCreate);
		this->entryAndExit(toCreate);
	}
}

void Grapher::setupSecondLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineTwo();
	Station *created = new Station(metroLine[0], 2);

	this->_metro2->setStationLink(created);
	created->setStationLink(this->_metro2);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = nullptr;
		if (i == 9) // Los Heroes
		{
			toCreate = this->_hub[LOS_HEROES];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else
		{
			toCreate = new Station(metroLine[i], 2);
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
			if (i == 7) //Puente Cal
				this->_hub.push_back(toCreate);
			if (i == 8) //Santa Ana
				this->_hub.push_back(toCreate);
			if (i == 13) //Franklin
				this->_hub.push_back(toCreate);
			if (i == 19) //Cisterna
				this->_hub.push_back(toCreate);
		}
		this->entryAndExit(toCreate);
	}
}

void Grapher::setupThirdLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineThree();
	Station *created = new Station(metroLine[0], 3);

	this->_metro3->setStationLink(created);
	created->setStationLink(this->_metro3);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = nullptr;
		if (i == 6) // Pueste Cal y Canto
		{
			toCreate = this->_hub[PUENTE_CAL];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 8) // U de Chile
		{
			toCreate = this->_hub[U_CHILE];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else
		{
			toCreate = new Station(metroLine[i], 3);
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
			if (i == 7) //Plaza de Armas
				this->_hub.push_back(toCreate);
			if (i == 11) //Plaza Irravanzal
				this->_hub.push_back(toCreate);
			if (i == 13) //Nunoa
				this->_hub.push_back(toCreate);
			if (i == 16) //Plaza Engana
				this->_hub.push_back(toCreate);
		}
		this->entryAndExit(toCreate);
	}
}

void Grapher::setupFourthLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineFour();
	Station *created = new Station(metroLine[0], 4);

	this->_metro4->setStationLink(created);
	created->setStationLink(this->_metro4);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = nullptr;
		if (i == 0) // Tobalaba
		{
			toCreate = this->_hub[TOBALABA];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 5) // Plaza Engana
		{
			toCreate = this->_hub[PLAZA_ENGANA];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else
		{
			toCreate = new Station(metroLine[i], 4);
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
			if (i == 12) //Vicuna Mackenna
				this->_hub.push_back(toCreate);
			if (i == 13) //Vicente Valdes
				this->_hub.push_back(toCreate);
		}
		this->entryAndExit(toCreate);
	}
}

void Grapher::setupFifthLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineFive();
	Station *created = new Station(metroLine[0], 5);

	this->_metro5->setStationLink(created);
	created->setStationLink(this->_metro5);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = nullptr;
		if (i == 0) // La Cisterna
		{
			toCreate = this->_hub[CISTERNA];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 5) // Vicuna Mackenna
		{
			toCreate = this->_hub[VICUNA];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else
		{
			toCreate = new Station(metroLine[i], 5);
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		this->entryAndExit(toCreate);
	}
}

void Grapher::setupSixthLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineSix();
	Station *created = new Station(metroLine[0], 6);

	this->_metro6->setStationLink(created);
	created->setStationLink(this->_metro6);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = nullptr;
		if (i == 8) // San Pablo
		{
			toCreate = this->_hub[SAN_PABLO];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 14) // Santa Ana
		{
			toCreate = this->_hub[SANTA_ANA];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 15) // Plaza de Armas
		{
			toCreate = this->_hub[PLAZA_ARMAS];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 17) // Baquedano
		{
			toCreate = this->_hub[BAQUEDANO];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 20) // Irarrazaval
		{
			toCreate = this->_hub[IRARRAZAVAL];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 29) // Vicente Valdes
		{
			toCreate = this->_hub[VICENTE];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else
		{
			toCreate = new Station(metroLine[i], 6);
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
			if (i == 19) //Nuble
				this->_hub.push_back(toCreate);
		}
		this->entryAndExit(toCreate);
	}
}

void Grapher::setupSeventhLine(void)
{
	int i = 0;
	std::vector<std::string> metroLine = Map::getLineSeven();
	Station *created = new Station(metroLine[0], 7);

	this->_metro7->setStationLink(created);
	created->setStationLink(this->_metro7);
	this->entryAndExit(created);
	for (std::vector<std::string>::iterator it = metroLine.begin() + 1; it != metroLine.end(); it++, i++)
	{
		Station *toCreate = nullptr;
		if (i == 3) // Franklin
		{
			toCreate = this->_hub[FRANKLIN];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 5) // Nuble
		{
			toCreate = this->_hub[NUBLE];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 7) // Nunoa
		{
			toCreate = this->_hub[NUNOA];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else if (i == 9) // Los Leones
		{
			toCreate = this->_hub[LOS_LEONES];
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		else
		{
			toCreate = new Station(metroLine[i], 7);
			toCreate->setStationLink(created);
			created->setStationLink(toCreate);
			created = toCreate;
		}
		this->entryAndExit(toCreate);
	}
}

void Grapher::entryAndExit(Station *station)
{
	if (station->getStationName().compare(this->_wayIn) == 0)
	{
		this->_stationIn = station;
	}
	if (station->getStationName().compare(this->_wayOut) == 0)
	{
		this->_stationOut = station;
	}
}

Station *Grapher::getNetwork(void) const
{
	return this->_network;
}

Station *Grapher::getWayIn(void) const
{
	return this->_stationIn;
}

Station *Grapher::getWayOut(void) const
{
	return this->_stationOut;
}