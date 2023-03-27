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

	// Draw the items only if they have not been picked
	if (!isPicked)
		app->render->DrawTexture(texture, position.x, position.y);


	// TODO 3: Some interface for the inventory


	//	TODO 4: Show the items' sprites in the inventory


	return true;
}

bool Item::CleanUp()
{
	return true;
}

// TODO 4: Add item to the inventory when picked
void Item::OnCollision(PhysBody* physA, PhysBody* physB)
{
	// Detect the collision with the player
	switch (physB->ctype)
	{
	case ColliderType::PLAYER:
		LOG("ITEM Collision PLAYER");
		physA->body->DestroyFixture(physA->body->GetFixtureList());
		isPicked = true;

		break;
	case ColliderType::UNKNOWN:
		LOG("Collision UNKNOWN");
		break;
	}
}