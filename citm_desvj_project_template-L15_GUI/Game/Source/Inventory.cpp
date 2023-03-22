#include "Inventory.h"

void Inventory::initialize(unsigned from)
{
	for (int i = 0; i < this->cap; i++)
	{
		this->items[i] = nullptr;
	}
}

void Inventory::expand()
{
	this->cap *= 2;
	Item** temp = new Item * [this->cap];

	for (int i = 0; i < this->nrOfItems; i++)
	{
		temp[i] = this->items[i];
	}

	//delete innecessary pointers
	delete[] this->items;

	this->items = temp;
	this->initialize(this->nrOfItems);
}

Inventory::Inventory(unsigned cap)
{
	this->cap = cap;
	this->nrOfItems = 0;
	this->items = new Item * [cap];
	this->initialize();
}

Inventory::Inventory(Inventory* other)
{
	this->cap = other->cap;
	this->nrOfItems = other->nrOfItems;

	this->items = new Item * [this->cap];

	this->initialize();

	for (int i = 0; i < this->nrOfItems; i++)
	{
		this->items[i] = new Item(*other->items[i]);
	}
}

Inventory::~Inventory() 
{
	//Delete the whole array
	for (int i = 0; i < this->nrOfItems; i++)
	{
		delete[] this->items;
	}
}

void Inventory::operator=(const Inventory& other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->nrOfItems; i++)
		{
			delete this->items[i];
		}
		delete[] this->items;

		this->cap = other.cap;
		this->nrOfItems = other.nrOfItems;

		this->items = new Item * [this->cap];

		this->initialize();

		for (int i = 0; i < this->nrOfItems; i++)
		{
			this->items[i] = new Item(*other.items[i]);
		}
	}
}

Item& Inventory::operator[](const unsigned index)
{
	if (index < 0 || index >= nrOfItems)
	{
		throw("OUT OF BOUNDS!");
	}

	return *this->items[index];
}

const unsigned& Inventory::size() const
{
	return this->nrOfItems;

}

const unsigned& Inventory::capacity() const
{
	return this->cap;
}

Item& Inventory::at(const unsigned index)
{
	return *this->items[0];
}

void Inventory::addItem(Item& item)
{
	if (this->nrOfItems >= this->cap)
		this->expand();
	this->items[this->nrOfItems++] = new Item(item);
}
void Inventory::removeItem(unsigned index)
{

}

std::string Inventory::toString() const
{
	std::stringstream ss;

	for (int i = 0; i < this->nrOfItems; i++)
	{
		ss << i << ":" << " " << "\n";
	}
	return ss.str();
}