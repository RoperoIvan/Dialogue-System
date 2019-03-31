#include "j1App.h"
#include "j1UIManager.h"
#include "j1Fonts.h"
#include "j1DialogSystem.h"
#include "j1Input.h"
#include "GUI_Label.h"
#include "GUI_Button.h"

j1DialogSystem::j1DialogSystem()
{
}

j1DialogSystem::~j1DialogSystem()
{
}

bool j1DialogSystem::Start()
{
	bool ret = true;
	LoadDialogue("Dialog.xml");
	currentNode = dialogTrees[treeid]->dialogNodes[0];
	PerformDialogue(treeid);

	return ret;
}

bool j1DialogSystem::Update(float dt)
{
	bool ret = true;

	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		treeid = 0;
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		input = 7;
		PerformDialogue(treeid);
	}
		



	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		treeid = 1;
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		input = 7;
		PerformDialogue(treeid);
	}



	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		treeid = 2;
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		input = 7;
		PerformDialogue(treeid);
	}

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		input = 0;
		PerformDialogue(treeid);
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		input = 1;
		PerformDialogue(treeid);
	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		input = 2;
		PerformDialogue(treeid);
	}
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		dialogTrees[treeid]->karma = 0;
		currentNode = dialogTrees[treeid]->dialogNodes[0];		
		input = 7;
		PerformDialogue(treeid);
	}
		
	return ret;
}

bool j1DialogSystem::CleanUp()
{
	bool ret = true;

	for (int j = 0; j < dialogTrees.size(); j++)
	{
		for (int i = 0; i < dialogTrees[j]->dialogNodes.size(); i++)
			delete dialogTrees[j]->dialogNodes[i];

		dialogTrees[j]->dialogNodes.clear();
		delete dialogTrees[j];
	}
	dialogTrees.clear();
	return ret;
}

void j1DialogSystem::PerformDialogue(int trId)
{
	if (dialogTrees.empty())
		LOG("TreeEmpty");

	//TODO 6 : Check the karma of the player

		if (input >= 0 && input < currentNode->dialogOptions.size()) //Only if the input is valid
		{
			//TODO 4 : Search which will be the next node in the tree

		}

		

	//TODO 2 : Change the PLAYERNAME tag to the player name in the dialog
	for (int i = 0; i < currentNode->text.size(); i++)
	{
		
	}
	BlitDialog();
}

void j1DialogSystem::BlitDialog()
{
	App->ui_manager->AddLabel(150, 200, currentNode->text.c_str(), 50, App->ui_manager->screen, WHITE, "fonts/Final_Fantasy_font.ttf", this);
	int space = 220;
	for (int i = 0; i < currentNode->dialogOptions.size(); i++)
		App->ui_manager->AddLabel(150, space += 30, currentNode->dialogOptions[i]->text.c_str(), 45, App->ui_manager->screen, GREEN, "fonts/Final_Fantasy_font.ttf", this);

}

bool j1DialogSystem::CompareKarma()
{
	bool ret = true;

	if (dialogTrees[treeid]->karma < 0)
		ret = false;

	return ret;
}

void j1DialogSystem::CheckForKarma(DialogNode* karmaNode)
{
	dialogTrees[treeid]->karma += karmaNode->dialogOptions[input]->karma;
}

bool j1DialogSystem::LoadDialogue(const char* file)
{
	bool ret = true;

	pugi::xml_parse_result result = tree_file.load_file(file);

	if (result == NULL)
	{
		LOG("Could not load xml file %s. pugi error: %s", file, result.description());
		ret = false;
	}
	else
		LOG("XML was loaded succesfully!");

	//TODO 1 : Load the data from the XML
	for (pugi::xml_node t = tree_file.child("dialogue").child("dialogtree"); t != NULL; t = t.next_sibling("dialogtree"))
	{

	}
	return ret;
}

bool j1DialogSystem::LoadTreeData(pugi::xml_node& trees, DialogTree* oak)
{
	bool ret = true;

	//TODO 1 : Load the data from the XML
	for (pugi::xml_node n = trees.child("node");n != NULL; n = n.next_sibling("node"))
	{

	}
	return ret;
}

bool j1DialogSystem::LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc)
{
	//TODO 1 : Load the data from the XML
	bool ret = true;
	for (pugi::xml_node op = text_node.child("option"); op != NULL; op = op.next_sibling("option"))
	{

	}

	return ret;
}