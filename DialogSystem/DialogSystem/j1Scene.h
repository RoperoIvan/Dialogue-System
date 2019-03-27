#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "j1DialogSystem.h"

struct SDL_Texture;
struct SDL_Rect;
struct DialogNode;
struct DialogOption;
class GUI;
class GUI_Image;
class GUI_Label;
class GUI_Button;
class DialogTree;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

public:


private:
	j1DialogSystem* d;
};

#endif // __j1SCENE_H__