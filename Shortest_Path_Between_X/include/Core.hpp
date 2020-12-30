#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include "Ride.hpp"
#include "Station.hpp"
#include "Grapher.hpp"
#include "PathFinder.hpp"

class Core
{
public:
	Core();
	Core(std::vector<std::string>);
	~Core();
	Ride *storeLiaison(int);
	void travelsLength(void);
	int start(void);
	void salesman(void);
	void travelling(int **, std::vector<bool> &, int, int, int, int, int &);
	void printResult(void);
	size_t showPath(size_t, size_t);
	void formMatrix(void);
	void printMatrix(void);
	void deleteMatrix(void);

private:
	std::vector<Ride *> _rides;
	std::vector<std::string> _stations;
	std::vector<std::vector<size_t>> _matchmaking;
	size_t _size;
	int **_matrix;
	std::vector<int> _tmp;
	std::vector<int> _streak;

	/* data */
};

#endif /* CORE_HPP_ */
