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

	// TODO 2: Create functions to add and remove items from the inventory


public:
	SDL_Texture* texture;
	const char* texturePath;
	SDL_Rect rect;

	// TODO 3: Create a bool to check if inventory is being shown

	// TODO 1: Create the array Item class, and the variables for the capacity and the number of items contained

};