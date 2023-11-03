//
// Created by Ryan Madsen on 11/3/23.
//
#include "SkeetLogic.h"
#include "uiInteract.h"

class SkeetInterface
{
private:
   SkeetLogic logic;

public:
   SkeetInterface() {};
   void input(UserInput ui);
   void processing();
   void output();
};
