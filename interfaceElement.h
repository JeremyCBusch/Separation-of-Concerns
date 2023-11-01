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
	virtual void draw() = 0;
};



class InterfacePellet {
public:
	void draw();
};

class InterfaceMissle {
public:
	void draw();
};

class InterfaceBomb {
public:
	void draw();
};

class InterfaceShrapnel {
public:
	void draw();
};

class InterfaceFragment {
public:
	void draw();
};

class InterfaceExhaust {
public:
	void draw();
};

class InterfaceStreek {
public:
	void draw();
};

class InterfaceStandard {
public:
	void draw();
};

class InterfaceSinker {
public:
	void draw();
};

class InterfaceFloater {
public:
	void draw();
};

class InterfaceCrazy {
public:
	void draw();
};
