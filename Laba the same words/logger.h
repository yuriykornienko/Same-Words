#pragma once
#include <fstream>

class logger
{
private:
	std::ofstream ofs;
	std::string path;
public:
	logger(std::string path = "log.txt");
	~logger();
	logger(const logger& log);
	void log(const std::string str);
};
