#pragma once
#include <list>

class StorageElement;
class StorageBullet;
class StorageEffect;
class StorageBird;

class LogicElement {
public:
	virtual void advance(StorageElement* storage) = 0;
	virtual void turn(StorageElement* storage) {};
	bool isOutOfBounds(StorageElement* storage)
	{
		return (storage->getPosition()->getX() < -storage->getRadius() || storage->getPosition()->getX() >= storage->getDimensions().getX() + storage->getRadius() ||
			storage->getPosition()->getY() < -storage->getRadius() || storage->getPosition()->getY() >= storage->getDimensions().getY() + storage->getRadius());
	}
	int randomInt(int min, int max);
	double randomFloat(double min, double max);
};

class LogicPellet : public LogicElement {
public:
	void advance(StorageBullet* storage, std::list<StorageEffect*>& effects);
};

class LogicMissle : public LogicElement {
public:
	void advance(StorageBullet* storage, std::list<StorageEffect*>& effects);
};

class LogicBomb : public LogicElement {
public:
	void death(std::list<StorageBullet*>& bullets, StorageBullet* storage);
	void advance(StorageBullet* storage, std::list<StorageEffect*>& effects);
};

class LogicShrapnel : public LogicElement {
public:
	void advance(StorageEffect* storage, std::list<StorageEffect*>& effects);
};

class LogicFragment : public LogicElement {
public:
	void advance(StorageEffect* storage);
};

class LogicExhaust : public LogicElement {
public:
	void advance(StorageEffect* storage);
};

class LogicStreek : public LogicElement {
public:
	void advance(StorageEffect* storage);
};

class LogicStandard : public LogicElement {
public:
	void advance(StorageStandard* storage);
};

class LogicSinker : public LogicElement {
public:
	void advance(StorageElement* storage);
};

class LogicFloater : public LogicElement {
public:
	void advance(StorageElement* storage);
};

class LogicCrazy : public LogicElement {
public:
	void advance(StorageElement* storage);
	void turn(StorageElement* storage);
};
