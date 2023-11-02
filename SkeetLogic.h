#pragma once
#include <vector> // for vectors 
#include <iterator> // for iterators
#include "logicElement.h"
#include "SkeetStorage.h"

class SkeetLogic
{
public:
	void Logic();
	void advance();
	void spawn();
	void input();
	std::vector<StorageElement>::iterator begin() {
		return storage.begin();
	}
	std::vector<StorageElement>::iterator end() {
		return storage.end();
	}


	int getFramesLeft();
	int getLevelNumber();
	double getGunAngle();
	bool isPlaying();
	bool isGameOver();
	double getPercentLeft();

private:
	SkeetStorage storage;
};

