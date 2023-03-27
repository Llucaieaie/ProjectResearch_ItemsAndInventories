#include "Inventory.h"
#include "Input.h"
#include "app.h"
#include "Log.h"
#include "Render.h"
#include "Player.h"
#include "Item.h"


Inventory::Inventory(unsigned cap) : Module()
{
	name.Create("Inventory");

	// TODO 1: initialize the inventory capacity, the number of items contained and the array of this items

}


// Destructor
Inventory::~Inventory()
{

}

bool Inventory::Start()
{
	// TODO 1: Add a null pointer to every position of the inventory array

	return true;
}


bool Inventory::PreUpdate()
{
	// TODO 3: Make the inventoryOn bool true when pressing a key

	// TODO 4: delete the last item picked when pressing a key


	return true;
}


// Called before quitting
bool Inventory::CleanUp()
{
	return true;
}

// TODO 2: Create functions to add and remove items from the inventory
