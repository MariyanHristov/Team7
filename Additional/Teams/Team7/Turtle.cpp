﻿#include <iostream>
#include <fstream>

#include "Turtle.h"

const int BUFFER_SIZE = 1024;

Turtle::Turtle()
{
	weightType = MEDIUM;
	consumerType = OMNIVORE;
	name = "";
	sound = "Woaaaaaa!";
	setFacts();
}

Turtle::Turtle(String name)
{
	weightType = MEDIUM;
	consumerType = OMNIVORE;
	this->name = name;
	sound = "Woaaaaaa!";
	setFacts();
}

bool Turtle::setFacts()
{
	std::ifstream file("TurtleFacts.txt");
	if (!file.is_open())
	{
		return false;
	}

	char temp[BUFFER_SIZE];
	while (file.getline(temp, BUFFER_SIZE))
	{
		String* string = new String(temp);
		facts.pushBack(string->clone());
	}
	file.close();

	return true;
}

Turtle* Turtle::clone() const
{
	return new Turtle(*this);
}

void Turtle::makeSound()
{
	std::cout << getSound();
}
