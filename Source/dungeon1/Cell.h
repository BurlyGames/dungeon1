/*
The individual Cell object
*/

#pragma once
#include "CoreMinimal.h"
#include <string>
#include <vector>

class Cell
{
public:

	// Constructors
	Cell();
	Cell(int32 Row, int32 Column, FString Name);

	// Members
	FString Name;
	Cell* North = nullptr;
	Cell* South = nullptr;
	Cell* East = nullptr;
	Cell* West = nullptr;
	std::vector<Cell*> Links;
	std::vector<Cell*> Neighbors;

	// Methods
	bool IsLinked(Cell* cell);
	void Link(Cell* cell);
	void Unlink(Cell* cell);
	std::vector<Cell*> GetNeighbors();

	// Distances GetDistances();

private:

	int32 _row, _column;
	FString _name;

	Cell* _north;
	Cell* _south;
	Cell* _east;
	Cell* _west;
};

