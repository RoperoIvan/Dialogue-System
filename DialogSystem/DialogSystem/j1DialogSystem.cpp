#include "j1App.h"
#include "j1UIManager.h"
#include "j1DialogSystem.h"

j1Dialogue::j1Dialogue()
{
}

bool j1Dialogue::Awake(pugi::xml_node&)
{
	bool ret = true;

	return ret;
}

bool j1Dialogue::Start()
{
	bool ret = true;
	LoadDialogue("Tree.xml");
	return ret;
}

bool j1Dialogue::PreUpdate()
{
	bool ret = true;

	return ret;
}

bool j1Dialogue::Update(float dt)
{
	bool ret = true;

	return ret;
}

bool j1Dialogue::PostUpdate()
{
	bool ret = true;

	return ret;
}

bool j1Dialogue::CleanUp()
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

int j1Dialogue::performdialogue(int treeid)
{
	if (dialogTrees.empty())
		return -1;

	else
	{
		LOG("Is not empty!");
	}

	DialogNode* currentNode = dialogTrees[treeid]->dialogNodes[0];
	
	string name = "PLAYERNAME";
	
	
	

	//while (true)
	//{
	//	//Check for tree tags
	//	/*dialogTrees[treeid]->CheckTags(dialogTrees[treeid]->karma);*/


	//	//Put the player's name in a the lines of dialog
	//	for (int i = 0; i < currentNode->text.size(); i++)
	//	{
	//		size_t found = currentNode->text.find(name);
	//		if (found != string::npos)
	//			currentNode->text.replace(currentNode->text.find(name), 10, "Oscar");
	//	}
	//
	//	cout << currentNode->text << "\n\n";
	//	for (int i = 0; i < currentNode->dialogOptions.size(); i++)
	//		cout << i + 1 << ": " << currentNode->dialogOptions[i].text << endl;
	//	
	//	cout << endl;
	//	int input;
	//	cin >> input;
	//	input--;

	//	if (input < 0 || input >= currentNode->dialogOptions.size())
	//		cout << "Invalid input \n\n";
	//	
	//	else
	//	{
	//		//Check for end of conversation
	//		if (currentNode->dialogOptions[input].id >= dialogTrees[treeid]->dialogNodes.size())
	//			return currentNode->dialogOptions[input].returnCode;
	//		
	//		for (int j = 0; j < dialogTrees[treeid]->dialogNodes.size(); j++)
	//		{
	//			if (currentNode->dialogOptions[input].id == dialogTrees[treeid]->dialogNodes[j]->id)
	//			{					
	//				currentNode = dialogTrees[treeid]->dialogNodes[j];
	//				break;
	//			}
	//		}
	//	}
	//	
	//	cout << endl;
	//}
	

}

bool j1Dialogue::LoadDialogue(const char* file)
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

bool j1Dialogue::LoadTreeData(pugi::xml_node& trees, DialogTree* oak)
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

bool j1Dialogue::LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc)
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