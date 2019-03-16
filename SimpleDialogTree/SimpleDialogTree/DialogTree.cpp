#include "DialogTree.h"


DialogTree::DialogTree()
{
}
DialogTree::~DialogTree()
{
}

DialogNode::DialogNode()
{

}

DialogueOption::DialogueOption()
{

}

DialogNode::DialogNode(string t)
{
	text = t;

}

void DialogTree::init()
{
	LoadTreeData("Tree.xml");

	/*for (int i = 0; i < nodes; i++)
	{
		DialogNode * nodes = new DialogNode("Hello brave warrior");
	}*/
	/*DialogNode* node0 = new DialogNode("Hello brave warrior");
	DialogNode* node1 = new DialogNode("I don't want to talk to you");
	DialogNode* node2 = new DialogNode(" I have a quest for you");
	DialogNode* node3 = new DialogNode("Yes, you will get gold you greedy swine");
	DialogNode* node4 = new DialogNode("Collect ten Dandillions");

	
	node0->dialogOptions.push_back(DialogueOption("Supp Noob", node1, 0));
	node0->dialogOptions.push_back(DialogueOption("Hello strange voice", node2, 0));
	dialogNodes.push_back(node0);

	node1->dialogOptions.push_back(DialogueOption("Aww", nullptr, 0));
	dialogNodes.push_back(node1);

	node2->dialogOptions.push_back(DialogueOption("K bye", nullptr, 0));
	node2->dialogOptions.push_back(DialogueOption("What is it", node4, 0));
	node2->dialogOptions.push_back(DialogueOption("Whats the pay", node3, 0));
	dialogNodes.push_back(node2);

	node3->dialogOptions.push_back(DialogueOption("Ok what is it", node4, 0));
	node3->dialogOptions.push_back(DialogueOption("That sucks im out", nullptr, 0));
	dialogNodes.push_back(node3);

	node4->dialogOptions.push_back(DialogueOption("Lets do it", nullptr, 1));
	node4->dialogOptions.push_back(DialogueOption("No way", nullptr, 0));
	dialogNodes.push_back(node4);*/
}

void DialogTree::destroytree()
{
	for (int i = 0; i < dialogNodes.size(); i++)
	{
		delete dialogNodes[i];
		
	}
	dialogNodes.clear();
}

int DialogTree::performdialogue()
{
	if (dialogNodes.empty())
	{
		return -1;
	}
	else
	{
		LOG("Is not empty!");
	}
	DialogNode* currentNode = dialogNodes[0];

	while (true)
	{
		cout << currentNode->text << "\n\n";
		for (int i = 0; i < currentNode->dialogOptions.size(); i++)
		{
			cout << i + 1 << ": " << currentNode->dialogOptions[i].text << endl;
		}
		cout << endl;
		int input;
		cin >> input;
		input--;
		if (input < 0 || input > currentNode->dialogOptions.size())
		{
			cout << "Invalid input \n\n";
		}
		else
		{
			//Check for end of conversation
			LOG("holita");
			/*if (currentNode->dialogOptions[input].nextNode == nullptr)
				return currentNode->dialogOptions[input].returnCode;*/
			if (currentNode->dialogOptions[input].id == 0)
			{
				return currentNode->dialogOptions[input].returnCode;
			}
			for (int j = 0; j < dialogNodes.size(); j++)
			{
				if (currentNode->dialogOptions[input].id == dialogNodes[j]->id)
				{
					
					currentNode = dialogNodes[j];
					break;
				}
			}
			
			/*currentNode = currentNode->dialogOptions[input].nextNode;*/
		
		}
		
		cout << endl;
	}
}

DialogueOption::DialogueOption(string t, DialogNode* n, int r)
{
	text = t;
	nextNode = n;
	returnCode = r;
}

bool DialogTree::LoadTreeData(const char* file)
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

	
	int t = 0;
	
	//Filling the dialogue tree information
	for (pugi::xml_node n = tree_file.child("dialogtree").child("node");n != NULL; n = n.next_sibling("node"))
	{
		DialogNode* node = new DialogNode;
		node->text.assign(n.attribute("line").as_string());
		node->id = n.attribute("id").as_int();
		LoadNodesDetails(n, node);
		dialogNodes.push_back(node);	
	}
	

	return ret;
}

bool DialogTree::LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc)
{
	bool ret = true;
	for (pugi::xml_node op = text_node.child("option"); op != NULL; op = op.next_sibling("option"))
	{
		DialogueOption* option = new DialogueOption;
		option->text.assign(op.attribute("line").as_string());
		option->id = op.attribute("id").as_int();
		
		LOG("HOLA");
		/*option->nextNode = dialogNodes[option->id];*/
		LOG("HOLA");
		npc->dialogOptions.push_back(*option);
		LOG("HOLA");
	}
	return ret;
}
