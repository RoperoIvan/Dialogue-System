#ifndef _J1DIALOGSYSTEM_H
#define _J1DIALOGSYSTEM_H

#include "j1Module.h"
#include <string>
#include <vector>
#include "j1App.h"
#include "p2Log.h"


class GUI_Label;
class GUI_Button;

struct DialogNode;

struct DialogueOption
{
public:
	std::string text;
	DialogNode* nextNode;
	int id;
	int karma;
};

struct DialogNode
{
public:
	std::string text;
	std::vector <DialogueOption> dialogOptions;
	int id, karma;
};
class DialogTree
{
public:
	DialogTree() {};
	~DialogTree() {};


public:
	std::vector <DialogNode*> dialogNodes;
	int treeid, karma;
};

class j1DialogSystem : public j1Module
{
public:
	j1DialogSystem();

	bool Awake(pugi::xml_node&);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

	void PerformDialogue();
	bool LoadDialogue(const char*);
	bool LoadTreeData(pugi::xml_node& trees, DialogTree* oak);
	bool LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc);
	void BlitDialog();
	bool CompareKarma();
	void CheckForKarma(DialogNode* karmaNode);
private:
	std::vector <DialogTree*> dialogTrees;
	std::list <GUI_Button*> options_buttons;
	GUI_Label* npctext;
	GUI_Label* playertext;
	DialogNode* currentNode;
	int input = 7, treeid = 0;
public:
	pugi::xml_document	tree_file;
	pugi::xml_node		tree;
	
};

#endif