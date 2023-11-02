#pragma once
#include <vector>
#include "gun.h"
#include "time.h"
class StorageElement;
class StorageBird;

class SkeetStorage
{
public:
	std::vector<StorageElement>::iterator begin() {
			
			return elements.begin();
		}

	std::vector<StorageElement>::iterator end() {
			return elements.end();
	}
	void add(StorageElement element);

	int getPoints() { return points; }
	int getNumKilled() { return numKilled; }
	int getNumMIssed() { return numBirds - numKilled; }
	Time getTime() {return time;}
	Gun getGun() { return gun; }
	typedef std::vector<StorageElement>::iterator IteratorBird;
	typedef std::vector<StorageElement>::iterator IteratorBullet;
	IteratorBird beginBird();
	IteratorBird endBird();
	IteratorBullet beginBullet();
	IteratorBullet endBullet();
	void reset();

	class IteratorBird {
	// private:
	// 	StorageBird* bird;

	// public:
	// 	IteratorBird(StorageBird* bird) : bird(bird) {};

	// 	IteratorBird operator++() {
	// 		++birdIterator;
	// 		return *this;
	// 	}
	};
    
    class IteratorBullet {
        
    };

	class Iterator {

	};

private:
	std::vector<StorageElement> elements;
	int points;
	int numBirds;
	int numKilled;
	Time time; //StorageTime time;
	Gun gun; //StorageGun gun;
};
