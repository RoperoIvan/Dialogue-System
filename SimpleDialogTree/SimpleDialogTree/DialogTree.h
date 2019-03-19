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

public:
	vector <DialogNode*> dialogNodes;
	int treeid;
public:

	
};

class Dialogue
{
public:
	Dialogue();

	void init();
	void destroytree();

	int performdialogue(int treeid);
	bool LoadDialogue(const char*);
	bool LoadTreeData(pugi::xml_node& trees, DialogTree* oak);
	bool LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc);
private:
	vector <DialogTree*> dialogTrees;

public:
	pugi::xml_document	tree_file;
	pugi::xml_node		tree;
};

#endif