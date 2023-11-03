#pragma once
#include "position.h"
#include "GunStorage.h"

class GunLogic
{
private:
   GunStorage storage;

public:
	GunLogic() : storage(Position(800.0, 0.0)) {};
	void input(int clockwise, int counterClockwise);
   Position getPosition() const { return storage.getPosition(); }
   double getAngle() const { return storage.getAngle(); }
};

