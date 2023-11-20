#include <iostream>
#include <fstream>
#include "logger.h"

logger::logger(std::string path) : path(path) {}

logger::~logger()
    {
        if (ofs.is_open())
            ofs.close();
    }

logger::logger(const logger& log)
    {
        this->path = log.path;
    }

void logger::log(const std::string str)
    {
        if (!ofs.is_open())
        {
            ofs.open(path);
            if (!ofs)
                ofs.open("log.txt");
        }

        ofs << str << std::endl;
    }
