#include "SheetManager.h"

Sheet SheetLoader::Read()
{
	//Read Sheet File json
	std::ifstream sheetFile("Resources/Sheets/Engine x Start.json");
	//parse json
	json data = json::parse(sheetFile);
	//create a continer to stroge Beat
	std::vector<Beat> beats;

	//foreach beats
	for (int index = 0; index < data["beats"].size(); index++) {

		json beatData = data["beats"][index];
		//become a Beat struct
		Beat beat{
			beatData["channel"].get<int>(),
			beatData["appearance"].get<double>(),
			beatData["speed"].get<double>()
		};
		//push in the beats continer
		beats.push_back(beat);
	}
	//finally sheet
	return Sheet{
		data["name"].get<std::string>(),
		data["time"].get<int>(),
		beats
	};
}
