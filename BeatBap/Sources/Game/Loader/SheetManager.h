#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

struct Beat
{
	int channel;
	double appearance;
	double speed;
};

struct Sheet
{
	std::string name;
	int time;
	std::vector<Beat> beats;
};

class SheetLoader
{
	using json = nlohmann::json;
public:
	Sheet Read();
};

