#ifndef _DIALOGTREE_H
#define _DIALOGTREE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class DialogNode;

class DialogueOption
{
public:
	DialogueOption(string t, DialogNode* n, int r);
	string text;
	DialogNode* nextNode;
	int returnCode;
};

class DialogNode
{
public:
	DialogNode(string t);
	string text;
	vector <DialogueOption> dialogOptions;
};
class DialogTree
{
public:
	DialogTree();
	~DialogTree();

	void init();
	void destroytree();

	int performdialogue();

private:
	vector <DialogNode*> dialogNodes;
};

#endif