#pragma once
#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "Module.h"
#include "Point.h"
#include "SDL/include/SDL.h"
#include "Item.h"
#include <string>
#include<sstream>

struct SDL_Texture;

class Inventory
{
public:

	Inventory(unsigned cap = 10);
	Inventory(Inventory* other);
	virtual ~Inventory();

	bool Awake();

	bool Start();

	bool Update();

	bool CleanUp();

	void addItem(Item&item);
	void removeItem(unsigned index);
	std::string toString() const;

public:

	void operator = (const Inventory& other);
	Item& operator [] (const unsigned index);

	const unsigned& size() const;
	const unsigned& capacity() const;
	Item& at(const unsigned index);
private:

	SDL_Texture* texture;
	const char* texturePath;

	Item** items;
	//capacity and number of items
	unsigned cap;
	unsigned nrOfItems;

	void initialize(unsigned from = 0);
	void expand();
};

#endif // __ITEM_H__