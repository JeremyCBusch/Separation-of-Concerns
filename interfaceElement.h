#pragma once


class UserInput;
class LogicElement;
class Interface {
private:
	LogicElement logic;
public:
	void interface();
	void input(UserInput input);
	void processing();
	void output();

};


class InterfaceElement {
public:
	InterfaceElement() {};
	virtual void draw(StorageElement storage) = 0;
};


class InterfacePellet {
public:
	void draw(StorageElement storage);
};

class InterfaceMissle {
public:
	void draw(StorageElement storage);
};

class InterfaceBomb {
public:
	void draw(StorageElement storage);
};

class InterfaceShrapnel {
public:
	void draw(StorageElement storage);
};

class InterfaceFragment {
public:
	void draw(StorageElement storage);
};

class InterfaceExhaust {
public:
	void draw(StorageElement storage);
};

class InterfaceStreek {
public:
	void draw(StorageElement storage);
};

class InterfaceStandard {
public:
	void draw(StorageElement storage);
};

class InterfaceSinker {
public:
	void draw(StorageElement storage);
};

class InterfaceFloater {
public:
	void draw(StorageElement storage);
};

class InterfaceCrazy {
public:
	void draw(StorageElement storage);
};
