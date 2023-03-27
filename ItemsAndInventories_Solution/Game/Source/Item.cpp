#include "Item.h"
#include "App.h"
#include "Textures.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Scene.h"
#include "Log.h"
#include "Point.h"
#include "Physics.h"
#include "Inventory.h"

Item::Item() : Entity(EntityType::ITEM)
{
}

Item::~Item() {}

bool Item::Awake() {

	position.x = parameters.attribute("x").as_int();
	position.y = parameters.attribute("y").as_int();
	texturePath = parameters.attribute("texturepath").as_string();

	return true;
}

bool Item::Start() {

	//initilize textures
	texture = app->tex->Load(texturePath);
		
	// Replace the collision of items with a sensor and add a listener
	
	//pbody = app->physics->CreateCircle(position.x + 16, position.y + 16, 16, bodyType::DYNAMIC);
	pbody = app->physics->CreateRectangleSensor(position.x + 16, position.y + 16, 16, 16, bodyType::STATIC);
	pbody->listener = this;


	// L07 DONE 7: Assign collider type
	pbody->ctype = ColliderType::ITEM;

	this->id = this->parameters.attribute("id").as_int();
	return true;
}

bool Item::Update()
{
	// L07 DONE 4: Add a physics to an item - update the position of the object from the physics.  
	position.x = METERS_TO_PIXELS(pbody->body->GetTransform().p.x) - 16;
	position.y = METERS_TO_PIXELS(pbody->body->GetTransform().p.y) - 16;

	// TODO Draw the items only if they have not been picked
	if (!isPicked)
		app->render->DrawTexture(texture, position.x, position.y);


	// TODO : Show the items on the inventory
	if (app->inventory->inventoryOn)
	{
		rect = { 150, 100, 1280 - 300, 720 - 200 };
		app->render->DrawRectangle(rect, 0, 0, 0, 50);
		for (int i = 0; i < app->inventory->nrOfItems; i++)
		{
			app->render->DrawTexture(texture, 182 + 32 * i, 132);
		}
	}

	return true;
}

bool Item::CleanUp()
{
	return true;
}

// TODO Add item to the inventory when picked
void Item::OnCollision(PhysBody* physA, PhysBody* physB)
{
	// Detect the collision with the player
	switch (physB->ctype)
	{
	case ColliderType::PLAYER:
		LOG("ITEM Collision PLAYER");
		isPicked = true;
		physA->body->DestroyFixture(physA->body->GetFixtureList());
		if(!handledCollision)
			app->inventory->addItem(*this);

		//LOG("nritems: %d", app->inventory->nrOfItems);

		break;
	case ColliderType::UNKNOWN:
		LOG("Collision UNKNOWN");
		break;
	}
	handledCollision = true; // Set flag to indicate collision has been handled to avoid adding the item more than once
}