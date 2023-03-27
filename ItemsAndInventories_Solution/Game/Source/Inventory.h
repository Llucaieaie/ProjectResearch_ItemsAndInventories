#pragma once
#include "Module.h"
#include "Entity.h"
#include "Item.h"

#include "Box2D/Box2D/Box2D.h"

// Module --------------------------------------
class Inventory : public Module
{
public:

	// Constructors & Destructors
	Inventory(unsigned cap = 10);
	~Inventory();

	// Main module steps
	bool Start();
	bool PreUpdate();
	bool CleanUp();

	void addItem(Item& item);
	void removeItem();

public:
	SDL_Texture* texture;
	const char* texturePath;
	SDL_Rect rect;

	bool inventoryOn = false;

	Item** items;
	//capacity and number of items
	unsigned cap;
	unsigned nrOfItems;

};