#include "j1App.h"
#include "j1UIManager.h"
#include "j1Fonts.h"
#include "j1DialogSystem.h"
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

int j1DialogSystem::performdialogue(int treeid)
{
	if (dialogTrees.empty())
		return -1;

	else
	{
		LOG("Is not empty!");
	}

	DialogNode* currentNode = dialogTrees[treeid]->dialogNodes[0];
	
	std::string name = "PLAYERNAME";
	

	/*Put the player's name in a the lines of dialog*/
	for (int i = 0; i < currentNode->text.size(); i++)
	{
		size_t found = currentNode->text.find(name);
		if (found != std::string::npos)
			currentNode->text.replace(currentNode->text.find(name), 10, "Enrique");
	}
	
	App->ui_manager->AddLabel(180, 200, currentNode->text.c_str(), 200, App->ui_manager->screen, WHITE, "fonts/Munro.ttf", this);
	int space = 220;
	for (int i = 0; i < currentNode->dialogOptions.size(); i++)
	{

		GUI_Button* button = new GUI_Button();

		button = App->ui_manager->AddButton(180, space += 30, { 0,0,20,20 }, { 0,0,20,20 }, { 0,0,20,20 }, this, App->ui_manager->screen, false, false, false);
		App->ui_manager->AddLabel(0, 0, currentNode->dialogOptions[i].text.c_str(), 100, button, GREEN, "fonts/Munro.ttf", this);


		options_buttons.push_back(button);
	}
	
		//Check for tree tags
		/*dialogTrees[treeid]->CheckTags(dialogTrees[treeid]->karma);*/


		
	
		//cout << currentNode->text << "\n\n";
		//for (int i = 0; i < currentNode->dialogOptions.size(); i++)
		//	cout << i + 1 << ": " << currentNode->dialogOptions[i].text << endl;
		//
		//cout << endl;
		//int input;
		//cin >> input;
		//input--;

		//if (input < 0 || input >= currentNode->dialogOptions.size())
		//	cout << "Invalid input \n\n";
		//
		//else
		//{
		//	//Check for end of conversation
		//	if (currentNode->dialogOptions[input].id >= dialogTrees[treeid]->dialogNodes.size())
		//		return currentNode->dialogOptions[input].returnCode;
		//	
		//	for (int j = 0; j < dialogTrees[treeid]->dialogNodes.size(); j++)
		//	{
		//		if (currentNode->dialogOptions[input].id == dialogTrees[treeid]->dialogNodes[j]->id)
		//		{					
		//			currentNode = dialogTrees[treeid]->dialogNodes[j];
		//			break;
		//		}
		//	}
		//}
		//
		//cout << endl;
	
	

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
		DialogueOption* option = new DialogueOption;
		option->text.assign(op.attribute("line").as_string());
		option->id = op.attribute("id").as_int();
		npc->dialogOptions.push_back(*option);
	}
	return ret;
}

bool DialogTree::CheckTags(int tag)
{
	bool ret = true;







	return ret;
}