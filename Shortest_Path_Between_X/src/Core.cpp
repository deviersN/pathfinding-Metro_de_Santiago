#include "Core.hpp"

Core::Core(/* args */)
{
}

Core::Core(std::vector<std::string> stations)
{
	this->_stations = stations;
	this->_size = stations.size();
	formMatrix();
	travelsLength();
}

Core::~Core()
{
	//	deleteMatrix();
	for (size_t i = 0; i < this->_rides.size(); i += 1)
	{
		delete this->_rides[i];
	}
}

Ride *Core::storeLiaison(int combo)
{
	Ride *ride;
	std::vector<size_t> id;
	std::vector<std::string> orderedStations;
	int n = this->_stations.size();
	static size_t iteration = 0;

	for (int i = 0; i < n; ++i)
	{
		if ((combo >> i) & 1)
		{
			id.push_back(i);
			orderedStations.push_back(this->_stations[i]);
		}
	}
	this->_matchmaking.push_back(id);
	ride = new Ride(orderedStations[0], orderedStations[1], id);
	iteration += 1;
	return ride;
}

void Core::travelsLength(void)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int n = this->_stations.size();
	int combo = (1 << 2) - 1;

	while (combo < 1 << n)
	{
		this->_rides.push_back(storeLiaison(combo));
		x = combo & -combo;
		y = combo + x;
		z = (combo & ~y);
		combo = z / x;
		combo >>= 1;
		combo |= y;
	}
}

int Core::start(void)
{
	Grapher *arquitect;
	PathFinder *guide;
	std::vector<std::string> inAndOut;
	int distance = 1;

	for (size_t i = 0; i < this->_rides.size(); ++i)
	{
		inAndOut = this->_rides[i]->getStations();
		arquitect = new Grapher(inAndOut[0], inAndOut[1]);
		guide = new PathFinder();
		arquitect->buildGraph();
		if (arquitect->getWayIn() == nullptr || arquitect->getWayOut() == nullptr)
			return 1;
		this->_rides[i]->setStops(guide->doYouKnowDaWey(arquitect->getWayIn(), arquitect->getWayOut(), distance));
		this->_rides[i]->setDist(distance);
		distance = 1;
	}
	for (size_t i = 0; i < this->_rides.size(); ++i)
	{
		this->_matrix[this->_matchmaking[i][0]][this->_matchmaking[i][1]] = this->_rides[i]->getDist();
		this->_matrix[this->_matchmaking[i][1]][this->_matchmaking[i][0]] = this->_rides[i]->getDist();
	}
	//	printMatrix();
	salesman();
	printResult();
	delete arquitect;
	delete guide;
	return 0;
}

void Core::printResult(void)
{
	size_t length = 0;

	std::cout << "To go to all stations required spending the least time possible in the metro, MHB should follow this path : " << std::endl;
	std::cout << this->_stations[0] << std::endl;
	for (size_t i = 0; i < this->_streak.size(); i += 1)
	{
		std::cout << this->_stations[this->_streak[i]] << std::endl;
	}
	std::cout << std::endl
			  << "Such travel would lead him through the following stations in this order : " << std::endl;
	length = showPath(0, this->_streak[0]);
	for (size_t i = 1; i < this->_streak.size(); i += 1)
	{
		length = showPath(this->_streak[i - 1], this->_streak[i]);
	}
	std::cout << std::endl
			  << "During the trip, MHB will pass through " << length << " metro stations." << std::endl;
}

size_t Core::showPath(size_t in, size_t out)
{
	static size_t cumuled_size = 0;

	for (size_t i = 0; i < this->_rides.size(); i += 1)
	{
		if (this->_rides[i]->_id[0] == in && this->_rides[i]->_id[1] == out)
		{
			std::vector<std::string> stations = this->_rides[i]->getStops();
			std::cout << std::endl
					  << "G. Travel length: " << stations.size() - 1 << std::endl;
			for (size_t i = 0; i < stations.size(); i += 1)
			{
				std::cout << stations[i] << std::endl;
			}
			cumuled_size += stations.size() - 1;
		}
		else if (this->_rides[i]->_id[1] == in && this->_rides[i]->_id[0] == out)
		{
			std::vector<std::string> stations = this->_rides[i]->getStops();
			std::cout << std::endl
					  << "R. Travel length: " << stations.size() - 1 << std::endl;
			for (size_t i = stations.size() - 1; i > 0; i -= 1)
			{
				std::cout << stations[i] << std::endl;
			}
			cumuled_size += stations.size() - 1;
			std::cout << stations[0] << std::endl;
		}
	}
	return cumuled_size;
}

void Core::salesman(void)
{
	int ans = INT_MAX;
	size_t size = this->_stations.size();
	std::vector<bool> visited(size);

	for (size_t i = 0; i < size; i++)
		visited[i] = false;
	visited[0] = true;
	travelling(this->_matrix, visited, 0, size, 1, 0, ans);
}

void Core::travelling(int **graph, std::vector<bool> &visited, int currPos, int size, int count, int cost, int &ans)
{
	if (count == size && graph[currPos][0])
	{
		if (std::min(ans, cost + graph[currPos][0]) == cost + graph[currPos][0])
			_streak = _tmp;
		ans = std::min(ans, cost + graph[currPos][0]);
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (!visited[i] && graph[currPos][i])
		{
			visited[i] = true;
			_tmp.push_back(i);
			travelling(graph, visited, i, size, count + 1, cost + graph[currPos][i], ans);
			visited[i] = false;
			_tmp.pop_back();
		}
	}
};

void Core::formMatrix(void)
{
	size_t size = this->_stations.size();

	this->_matrix = new int *[size];
	for (size_t i = 0; i < size; ++i)
	{
		this->_matrix[i] = new int[size];
		for (size_t j = 0; j < size; ++j)
		{
			this->_matrix[i][j] = 0;
		}
	}
}

void Core::printMatrix(void)
{
	size_t size = this->_stations.size();

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			std::cout << this->_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void Core::deleteMatrix(void)
{
	size_t size = this->_stations.size();

	for (size_t i = 0; i < size; ++i)
	{
		delete this->_matrix[i];
	}
	delete this->_matrix;
}