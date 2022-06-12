#include "Fauna.h"

Fauna::Fauna() : Organism(), isPredator(false) {}

Fauna::Fauna(const StringC& name, double lifeSpan, const VectorC<StringC>& habitats, const StringC& consLevel, bool isPredator)
	: Organism(name, lifeSpan, habitats, consLevel), isPredator(isPredator) {}

Organism* Fauna::clone() const
{
	return new Fauna(*this);
}

void Fauna::print() const
{
	Organism::print();
	std::cout << "Is predator: " << std::boolalpha << isPredator << std::endl;
}