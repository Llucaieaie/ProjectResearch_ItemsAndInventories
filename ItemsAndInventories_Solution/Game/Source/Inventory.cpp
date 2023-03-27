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

	this->cap = cap;
	this->nrOfItems = 0;
	this->items = new Item * [cap];
}


// Destructor
Inventory::~Inventory()
{
	//Delete the whole array
	for (int i = 0; i < this->nrOfItems; i++)
	{
		delete[] this->items;
	}
}

bool Inventory::Start()
{
	//LOG("cap: %d",cap);
	for (int i = 0; i < this->cap; i++)
	{
		this->items[i] = nullptr;
	}
	return true;
}


bool Inventory::PreUpdate()
{
	if (app->input->GetKey(SDL_SCANCODE_TAB) == KEY_DOWN)
	{
		inventoryOn = !inventoryOn;
	}
	if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		removeItem();
	}

	return true;
}


// Called before quitting
bool Inventory::CleanUp()
{
	return true;
}


void Inventory::addItem(Item& item)
{
	this->items[this->nrOfItems++] = new Item(item);
}


void Inventory::removeItem()
{
	delete items[nrOfItems--];
}