#include "DialogTree.h"


DialogTree::DialogTree()
{
}
DialogTree::~DialogTree()
{
}

DialogNode::DialogNode(string t)
{
	text = t;
}

void DialogTree::init()
{
	DialogNode* node0 = new DialogNode("Hello brave warrior");
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
	dialogNodes.push_back(node4);
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

			if (currentNode->dialogOptions[input].nextNode == nullptr)
				return currentNode->dialogOptions[input].returnCode;

			currentNode = currentNode->dialogOptions[input].nextNode;
		
		}
		
		cout << endl;

		/*return 0;*/
	}
}

DialogueOption::DialogueOption(string t, DialogNode* n, int r)
{
	text = t;
	nextNode = n;
	returnCode = r;
}