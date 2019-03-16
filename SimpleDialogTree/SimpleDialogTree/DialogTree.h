#ifndef _DIALOGTREE_H
#define _DIALOGTREE_H

#include <string>
#include <iostream>
#include <vector>
#include "PugiXml/src/pugixml.hpp"
#include "p2Log.h"

using namespace std;

class DialogNode;

class DialogueOption
{
public:
	DialogueOption();
	DialogueOption(string t, DialogNode* n, int r);
	string text;
	DialogNode* nextNode;
	int id;
	int returnCode;
};

class DialogNode
{
public:
	DialogNode::DialogNode();
	string text;
	vector <DialogueOption> dialogOptions;
	int id;
};
class DialogTree
{
public:
	DialogTree();
	~DialogTree();

	void init();
	void destroytree();

	int performdialogue();

	bool LoadTreeData(const char*);
	bool LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc);
private:
	vector <DialogNode*> dialogNodes;
	int nodes = 5;

public:

	pugi::xml_document	tree_file;
	pugi::xml_node		tree;
};

#endif