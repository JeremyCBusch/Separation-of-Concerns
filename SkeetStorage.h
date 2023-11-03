#pragma once
#include <vector>
//#include "gun.h"
//#include "time.h"
#include "GunStorage.h"
#include "StorageElement.h"

//class StorageElement;
class StorageBird;

class SkeetStorage
{
public:
   class IteratorBird {
   private:
      StorageElement * element;

   public:
      IteratorBird(StorageElement* bird) {};

      StorageElement& operator*() {
         return *element;
      }

      IteratorBird operator++() {
         while (element->getType() != StorageElement::BIRD && element != NULL) {
            element++;
         }

         return *this;
      }

      IteratorBird operator++(int postfix) {
         IteratorBird temp = *this;
         while (element->getType() != StorageElement::BIRD && element != NULL) {
            element++;
         }
         return temp;
      }

      bool operator==(const IteratorBird& rhs) {
         return element == rhs.element;
      }

      bool operator!=(const IteratorBird& rhs) {
         return element != rhs.element;
      }
   };

   class IteratorBullet {
   private:
      StorageElement * element;

   public:
      IteratorBullet(StorageElement* bullet) {};

      StorageBullet& operator*() {
         return static_cast<StorageBullet&>(*element);
      }

      // prefix
      IteratorBullet operator++() {
         while (element->getType() != StorageElement::BULLET && element != NULL) {
            element++;
         }

         return *this;
      }

      // postfix
      IteratorBullet operator++(int postfix) {
         IteratorBullet temp = *this;
         while (element->getType() != StorageElement::BULLET && element != NULL) {
            element++;
         }
         return temp;
      }

      bool operator==(const IteratorBullet& rhs) {
         return element == rhs.element;
      }

      bool operator!=(const IteratorBullet& rhs) {
         return element != rhs.element;
      }
   };

	std::vector<StorageElement>::iterator begin() {
      return elements.begin();
   }

	std::vector<StorageElement>::iterator end() {
			return elements.end();
	}

	void add(StorageElement element);
   void addPoints(int points) { this->points += points; }

	int getPoints() { return points; }
	int getNumKilled() { return numKilled; }
	int getNumMIssed() { return numBirds - numKilled; }
	Time getTime() {return time;}
	GunStorage& getGun() { return gun; }
//	typedef std::vector<StorageElement>::iterator IteratorBird;
//	typedef std::vector<StorageElement>::iterator IteratorBullet;
	IteratorBird beginBird() {
      for (auto element : elements) {
         if (element.getType() == StorageElement::BIRD) {
            return IteratorBird(&element);
         }
      }
   };
	IteratorBird endBird() {
      return IteratorBird(&*elements.end());
   };
	IteratorBullet beginBullet() {
      for (auto element : elements) {
         if (element.getType() == StorageElement::BULLET) {
            return IteratorBullet(&element);
         }
      }
   };
	IteratorBullet endBullet() {
      return IteratorBullet(&*elements.end());
   };
	void reset();
   void setBullseye(bool bullseye) { boolseye = bullseye; }
   bool aliveBirds() {
      for (auto element : elements) {
         if (element.getType() == StorageElement::BIRD) {
            return true;
         }
      }
      return false;
   }

   void clearElements() {
      elements.clear();
   }

   void incrementNumKilled() {
      numKilled++;
   }

private:
	std::vector<StorageElement> elements;
	int points;
	int numBirds;
	int numKilled;
	Time time; //StorageTime time;
	GunStorage gun; //StorageGun gun;
   bool boolseye;
};
