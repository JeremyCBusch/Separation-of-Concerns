#pragma once

//#include "uiInteract.h"

class LogicMissile;
class UserInput;
class LogicElement;
class StorageElement;
class Position;
class StorageBullet;

//class Interface {
//private:
//	LogicElement * logic;
//public:
//	void interface();
//	void input(UserInput input);
//	void processing();
//	void output();
//
//};


class InterfaceElement {
public:
	InterfaceElement() = default;
	virtual void draw(StorageElement storage) = 0;
   virtual void input(UserInput input, LogicMissile logic, StorageBullet storage);
protected:
   void drawDot(const Position& point, double radius, double red, double green, double blue) const;
   void drawLine(const Position& begin, const Position& end, double red, double green, double blue) const;
   void drawDisk(const Position& center, double radius, double red, double green, double blue) const;
   void glVertexPoint(const Position& point) const;
};

class InterfacePellet : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceMissle : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
   void input (UserInput input, LogicMissile logic, StorageBullet storage) override;
};

class InterfaceBomb : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceShrapnel : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceFragment : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceExhaust : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceStreek : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceStandard : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceSinker : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceFloater : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};

class InterfaceCrazy : public InterfaceElement {
public:
	void draw(StorageElement storage) override;
};
