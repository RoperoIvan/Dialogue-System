#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1UIManager.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "j1DialogSystem.h"
#include <string>
#include "GUI.h"
#include "GUI_Button.h"
#include "GUI_Label.h"
#include "GUI_Image.h"

j1Scene::j1Scene() : j1Module()
{
	name.assign("scene");

}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{


	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	LOG("HOLA");
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		App->dialog->performdialogue(0);	

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		App->dialog->performdialogue(1);

	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
		App->dialog->performdialogue(2);


	
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{


	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	iPoint mouse;
	App->input->GetMousePosition(mouse.x, mouse.y);

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
