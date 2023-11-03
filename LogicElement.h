#pragma once
#include <list>

class StorageElement;
class StorageBullet;
class StorageEffect;
class StorageBird;

class LogicElement {
public:
	virtual void advance(StorageElement* storage, void (*addElement)(StorageElement *)) = 0;
	virtual void turn(StorageElement* storage) {};
	bool isOutOfBounds(StorageElement* storage);
	int randomInt(int min, int max);
	double randomFloat(double min, double max);
};

class LogicPellet : public LogicElement {
public:
	void advance(StorageElement * storage, void (*addElement)(StorageElement *)) override;
};

class LogicMissile : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
   void input(StorageBullet storage, bool isUp, bool isDown, bool isB);
};

class LogicBomb : public LogicElement {
public:
	void death(std::list<StorageBullet*>& bullets, StorageBullet* storage);
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicShrapnel : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicFragment : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicExhaust : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicStreek : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicStandard : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicSinker : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicFloater : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
};

class LogicCrazy : public LogicElement {
public:
	void advance(StorageElement* storage, void (*addElement)(StorageElement *)) override;
	void turn(StorageElement* storage);
};
