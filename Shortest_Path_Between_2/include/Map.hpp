#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <vector>

class Map
{
public:
	Map(/* args */);
	~Map();
	static std::vector<std::string> getLineOne(void);
	static std::vector<std::string> getLineTwo(void);
	static std::vector<std::string> getLineThree(void);
	static std::vector<std::string> getLineFour(void);
	static std::vector<std::string> getLineFive(void);
	static std::vector<std::string> getLineSix(void);
	static std::vector<std::string> getLineSeven(void);
};

#endif /* MAP_HPP_ */