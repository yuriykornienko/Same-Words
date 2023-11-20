#pragma once
#include <fstream>
#include "list.h"
#include "logger.h"

class sameWordsAnalyzer
{
private:
    logger log;
    list mylist;
    std::ofstream ofs;
    std::ifstream ifs;
public:
    sameWordsAnalyzer(logger log = logger());
    ~sameWordsAnalyzer();
    void createListFromFile(const std::string path, char separator = ' ');
    void createReportFile(const std::string path);
};