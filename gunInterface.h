#pragma once

#include "position.h"
#include "uiInteract.h"
#include "gunLogic.h"

class GunInterface
{
private:
   GunLogic logic;

public:
	GunInterface() = default;
   void input(UserInput ui);
	void display() const;
};

