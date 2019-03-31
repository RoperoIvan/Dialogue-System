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

bool j1DialogSystem::Awake(pugi::xml_node& node)
{
	bool ret = true;

	return ret;
}

bool j1DialogSystem::Start()
{
	bool ret = true;
	LoadDialogue("Tree.xml");
	currentNode = dialogTrees[0]->dialogNodes[0];
	PerformDialogue();

	return ret;
}

bool j1DialogSystem::PreUpdate()
{
	bool ret = true;

	return ret;
}

bool j1DialogSystem::Update(float dt)
{
	bool ret = true;

	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
	{
		treeid = 0;
		App->ui_manager->DeleteAllUIElements();
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		input = 7;
		PerformDialogue();
	}
		



	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
	{
		treeid = 1;
		App->ui_manager->DeleteAllUIElements();
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		input = 7;
		PerformDialogue();
	}



	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN)
	{
		treeid = 2;
		App->ui_manager->DeleteAllUIElements();
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		input = 7;
		PerformDialogue();
	}

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		input = 0;
		PerformDialogue();
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		input = 1;
		PerformDialogue();
	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		input = 2;
		PerformDialogue();
	}
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		App->ui_manager->DeleteAllUIElements();
		currentNode = dialogTrees[treeid]->dialogNodes[0];
		dialogTrees[treeid]->karma = 0;
		input = 7;
		PerformDialogue();
	}
		
	return ret;
}

bool j1DialogSystem::PostUpdate()
{
	bool ret = true;
	
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

void j1DialogSystem::PerformDialogue()
{
	if (dialogTrees.empty())
		LOG("TreeEmpty");

	if (CompareKarma()) //Check if the player said something bad to this npc
	{
		//Find the next node 
		if (input >= 0 && input < currentNode->dialogOptions.size()) //Only if the input is valid
		{
			for (int j = 0; j < dialogTrees[treeid]->dialogNodes.size(); j++)
			{
				if (currentNode->dialogOptions[input].nextnode == dialogTrees[treeid]->dialogNodes[j]->id) //If the option id is the same as one of the nodes ids in the tree
				{
					CheckForKarma(currentNode); // We update the player karma based in what option he/she choosed and
					currentNode = dialogTrees[treeid]->dialogNodes[j]; // we assign our node pointer to the next node in the tree				
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < dialogTrees[treeid]->dialogNodes.size(); i++)
		{
			// We search the mood of the bad response -1 = bad response 0 = neutral 1 = good response
			if (dialogTrees[treeid]->karma == dialogTrees[treeid]->dialogNodes[i]->karma) 
			{
				currentNode = dialogTrees[treeid]->dialogNodes[i]; //This node is the bad response from the npc
			}
		}
	}	
	//Put the player's name in the lines of the npc dialog
	for (int i = 0; i < currentNode->text.size(); i++)
	{
		size_t found = currentNode->text.find("PLAYERNAME");
		if (found != std::string::npos)
			currentNode->text.replace(currentNode->text.find("PLAYERNAME"), 10, "Enrique");
	}
	BlitDialog();
}

void j1DialogSystem::BlitDialog()
{
	App->ui_manager->AddLabel(180, 200, currentNode->text.c_str(), 50, App->ui_manager->screen, WHITE, "fonts/Final_Fantasy_font.ttf", this);
	int space = 220;
	for (int i = 0; i < currentNode->dialogOptions.size(); i++)
		App->ui_manager->AddLabel(180, space += 30, currentNode->dialogOptions[i].text.c_str(), 45, App->ui_manager->screen, GREEN, "fonts/Final_Fantasy_font.ttf", this);

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
	//int newkarma = dialogTrees[treeid]->karma += karmaNode->dialogOptions[input].karma;
	//tree = tree_file.child("dialogtree");
	//tree.append_attribute("karma") = newkarma;

	dialogTrees[treeid]->karma += karmaNode->dialogOptions[input].karma;
}

bool j1DialogSystem::LoadDialogue(const char* file)
{
	bool ret = true;

	pugi::xml_parse_result result = tree_file.load_file(file);

	if (result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file, result.description());
		ret = false;
	}
	else
		LOG("XML was loaded succesfully!");

	for (pugi::xml_node t = tree_file.child("dialogue").child("dialogtree"); t != NULL; t = t.next_sibling("dialogtree"))
	{
		DialogTree* tr = new DialogTree;
		tr->treeid = t.attribute("treeid").as_int();
		tr->karma = t.attribute("karma").as_int();
		LoadTreeData(t, tr);
		dialogTrees.push_back(tr);	
	}
	return ret;
}

bool j1DialogSystem::LoadTreeData(pugi::xml_node& trees, DialogTree* oak)
{
	bool ret = true;

	//Filling the dialogue tree information
	for (pugi::xml_node n = trees.child("node");n != NULL; n = n.next_sibling("node"))
	{
		DialogNode* node = new DialogNode;
		node->text.assign(n.attribute("line").as_string());
		node->id = n.attribute("id").as_int();
		node->karma = n.attribute("karma").as_int();
		LoadNodesDetails(n, node);
		oak->dialogNodes.push_back(node);
		
	}
	return ret;
}

bool j1DialogSystem::LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc)
{
	bool ret = true;
	for (pugi::xml_node op = text_node.child("option"); op != NULL; op = op.next_sibling("option"))
	{
		DialogOption* option = new DialogOption;
		option->text.assign(op.attribute("line").as_string());
		option->nextnode = op.attribute("nextnode").as_int();
		option->karma = op.attribute("karma").as_int();
		npc->dialogOptions.push_back(*option);
	}
	return ret;
}