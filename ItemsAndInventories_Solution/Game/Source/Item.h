#ifndef __ITEM_H__
#define __ITEM_H__

#include "Entity.h"
#include "Point.h"
#include "SDL/include/SDL.h"


struct SDL_Texture;

class Item : public Entity
{
public:

	Item();
	virtual ~Item();

	bool Awake();

	bool Start();

	bool Update();

	bool CleanUp();

	void OnCollision(PhysBody* physA, PhysBody* physB);

public:
	bool isPicked = false;

	int id = 0;

	bool handledCollision = false;

private:

	SDL_Texture* texture;
	const char* texturePath;

	SDL_Rect rect;

	//DONE 4: Add a physics to an item
	PhysBody* pbody;
};

#endif // __ITEM_H__