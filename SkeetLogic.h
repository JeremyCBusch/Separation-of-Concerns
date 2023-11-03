#pragma once
#include <vector> // for vectors 
#include <iterator> // for iterators
#include "logicElement.h"
#include "SkeetStorage.h"
#include "uiInteract.h"

class SkeetLogic
{
public:
	void Logic();
	void advance();
	void spawn();
	void input(UserInput ui);
	std::vector<StorageElement>::iterator begin() {
		return storage.begin();
	}
	std::vector<StorageElement>::iterator end() {
		return storage.end();
	}
   SkeetStorage::IteratorBullet beginBullet() {
      return storage.beginBullet();
   }

   SkeetStorage::IteratorBullet endBullet() {
      return storage.endBullet();
   }

   SkeetStorage::IteratorBird beginBird() {
      return storage.beginBird();
   }

   SkeetStorage::IteratorBird endBird() {
      return storage.endBird();
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

