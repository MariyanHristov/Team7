#pragma once
#include "Animal.h"
#include "String.h"

class Zoopark
{
private:
	String name;
	Array<Animal*> animals;
	bool cleaned;

public:
	Zoopark(); //Niki 

	void clean();
	void feed();
	void addAnimal();
	// addHippopotamus
	void addTurtle();
	// addPenguin
	void printFacts();
	void removeAnimal();
};