#ifndef _J1DIALOGSYSTEM_H
#define _J1DIALOGSYSTEM_H

#include "j1Module.h"
#include <string>
#include <vector>
#include "j1App.h"
#include "p2Log.h"

using namespace std;

struct DialogNode;

struct DialogueOption
{
public:
	string text;
	DialogNode* nextNode;
	int id;
	int returnCode;
};

struct DialogNode
{
public:
	string text;
	vector <DialogueOption> dialogOptions;
	int id;
};
class DialogTree
{
public:
	DialogTree() {};
	~DialogTree() {};


public:
	vector <DialogNode*> dialogNodes;
	int treeid, karma;
	bool CheckTags(int tag);
};

class j1Dialogue : public j1Module
{
public:
	j1Dialogue();

	bool Awake(pugi::xml_node&);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

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