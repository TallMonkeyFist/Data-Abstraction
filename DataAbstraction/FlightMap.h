#pragma once
#include <string>

class FlightMap
{
private:
	class City
	{

	};

public:
	void readFlightMap(std::string cityFileName, std::string flightFileName);
	void displayFlightMap();
	void displayAllCities();
	void displayAdjacentCities(City aCity);
	void markVisited(City aCity);
	void unvisitAll();
	bool isVisited(City aCity);
	void insertAdjacent(City aCity, City adjCity);
	City getNextCity(City fromCity);
	bool isPath(City fromCity, City toCity);
};