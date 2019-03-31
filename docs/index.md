# Dialogue System

[Link to repository](https://github.com/RoperoIvan/Dialogue-System)

[Link to both projects](https://github.com/RoperoIvan/Dialogue-System/releases/tag/Both)

[Link to the exercises](https://github.com/RoperoIvan/Dialogue-System/releases/tag/TODOs)

[Link to the solution](https://github.com/RoperoIvan/Dialogue-System/releases/tag/Solution)

[Link to the presentation]()

# Dialogue Systems importance

A few years before video games emerged, exactly in 1966 a professor of computer science at MIT, Joseph Weizenbaum, developed a program that allowed emulating a conversation with a therapist. That program would be called ELIZA and would be the first attempt to try to emulate a conversation between humans and machines. 

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/eliza_4.png?raw=true"/>

It did not take too long for videogames to start using dialogues in some way to use them as support to tell stories. Games like Adventure by William Crowther in 1972 credited as the first RPG used a text interface to transmit to the player what was happening around him.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/giphy.gif?raw=true"/>

A few years later, Monkey Island in 1990 will revolutionize the market with its new system of choice of dialogue that allowed the player to give the feeling of freedom to choose what he wanted to say to other NPCs. Games like the Fallout saga depend tremendously on the dialogue, on how the player interacts with the NPCs and influences them to forge their story within the game.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/giphy%20(2).gif?raw=true"/>


But the dialogues not only depend in how good the lines between interactions are, the different kinds of systems that each videogame uses to make the interaction between the player and the game are important too.

# Different Dialog Systems in videogames

## Non-branching Dialog

This type of dialogue is the typical interaction between the player and an NPC, where the player can not choose what to say, and is simply limited to normally pressing a button for the dialogue to continue, in this case the game itself will be chosen by the player what his character will say. The conversation may change if the player talks to the NPC again but has no control over what his character says.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/giphy%20(1).gif?raw=true"/>

## Branching Dialog

In this type of dialog the player has more control about what he/she wants to say. The player can access different paths that form end up forming a dialogue tree by which player navigates, where the path he travels will depend on the decisions made by the player.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/dt_sample.png?raw=true " height="433" width="380" />

Normally, the decisions that the player makes during the dialogue will not only give information to the player, but may also end up influencing the NPC, such as making him angry due to an option chosen by the player. Or the NPC can offer you a mission after having gained confidence with the player. The possibilities with this dialog system are quite broad, so it ends up being a very versatile and useful system. It is also easier to control what the player can do or say if the options he has to interact are already pre-written. For this reason it is one of the most used, if not the most widely used in the industry.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/ConsideratePaleDromaeosaur.gif?raw=true"/>

## Hub Dialog

This system could be considered a variant of the previous one since the only difference between the two is that in a Hub system the player can go back to the options of dialogue at the beginning to be able to know each and every one of the possible answers of the NPC giving the possibility to the player to know all possible information. The level of freedom of decision is greater in this type of dialogue. One of its negative points is that it is not too immersive since having total control over the conversation is not too realistic. Many RPGs use this type of system, games mentioned above as Fallout or Elder Scrolls of the same company make use of the system.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Vxnmct.gif?raw=true"/>

## Parser Driven Dialog

Before ELIZA was mentioned as the first RPG, it would also have in this case the achievement of being also the first programs they use in their input text parser. The complexity of this system is so large and complicated that it is rarely seen in video games. One of the few examples is the game Façade. A negative point that has this type of esque systems often misinterpret what the player has written, which usually unravels in that the NPC does not know how to react or have totally different reactions to what the player expected from the NPC.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/BraveGargantuanEskimodog-small.gif?raw=true"/>

In this type of dialog the player writes directly what he wants to say to the NPC. Through a database the syntactic composition of the phrase formed by the player is analyzed, the game interprets the phrase and forms a response for the NPC.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/1-s2.0-S2468232216301081-gr2.jpg?raw=true"/>

## Other remarkable Dialog Systems

This system doesn't use dialog to interact with the other NPCs. Instead the player can choose the action that he/she wants to do with his Sim and the other NPCs will react with symbols depending of the personality and mood of each of the Sims.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/GiddyForcefulIberianmidwifetoad.gif?raw=true"/>

## Which we will use

As mentioned previously, the most used system is the Branching dialog. It is also the one that will be most useful in our project because if we want we can choose between non branching and branching with very little effort. The complexity of the code is not high either, so implementing it in our project will be simple and we should not have any problem.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Untitled%20Diagram.jpg?raw=true"/>

We will use a tree as structure of a dialogue with, for example, an NPC. Each tree has nodes, that are each of the different possible interactions between the player and the NPC. Finally within these nodes are the options, that will be as the name says the possibilities of choice that the player will have.

# Ways to define de data

You could really make a branching system dialog directly from the code, but putting each and every one of the lines of dialogue in different strings is expensive and hardcode the code is not a good habit of programming. That's why we will use XML as a container for all our lines of game dialogues. 

The choice in addition to XML is justified by easy use and little complexity when reading the file format. In this way both programmers and designers or artists can quickly access the dialogues to make possible changes of NPCs, add new conversations and in general make changes in the narrative of the game.

The structure that we will follow to make our dialogue tree is the following:

Our dialog XML will be able to contain multiple dialogue trees, these being each one of the interactions with the NPCs of our game. Within the trees, we will have different dialog nodes, making the role of the different lines of dialogue of the NPC and each of these nodes will contain the different options that the player can choose and that will take him to other nodes within the tree of dialogue.

```
 <dialogtree treeid="0" karma="0">
    <node line="PLAYERNAME how are you PLAYERNAME" id="0">
      <option  line="Supp Noob" nextnode="1" karma="-1"/>
      <option line="Hello strange voice" nextnode="2"/>
    </node>
    <node  line="PLAYERNAME , I don't want to talk to you" id="1">
      <option  line="Aww" nextnode="6"/>
    </node>
    <node  line="I have a quest for you" id="2">
      <option  line="K bye" nextnode="6"/>
      <option line="What is it" nextnode="4"/>
      <option  line="Whats the pay" nextnode="3"/>
    </node>
    <node line="Yes, you will get gold you greedy swine" id="3">
      <option line="Ok what is it" nextnode="4"/>
      <option   line="That sucks im out" nextnode="6"/>
    </node>
    <node   line="Collect ten Dandillions" id="4">
      <option line="Lets do it" nextnode="6"/>
      <option  line="No way" nextnode="6"/>
    </node>
    <node line="I won't talk to you, you insulted me!" id="5" karma="-1">
      <option line="Ok then..." nextnode="6"/>
    </node>
  </dialogtree>
```

# Code Structure

## Classes

The code is made up of 4 classes: 
The first would be the options, which carry 2 int, the next node to which the conversation will go and a modifier of the state of the npc and 1 string that will be the line of dialogue that will form the option that the player will choose.

```
class DialogOption
{
public:
	DialogOption() {};
	~DialogOption() {};
public:
	std::string text;
	int nextnode;
	int karma;
};
```

The next class is the nodes that you will have as well as the options, 2 int, your node id and the karma of that NPC dialog. A string that would be the line of dialogue of the NPC and a vector of DialogOptions.

```
class DialogNode
{
public:
	DialogNode() {};
public:
	std::string text;
	std::vector <DialogOption> dialogOptions;
	int id, karma;
};
```

The third class is the trees that in this case will only have 2 int, their tree id so that we can have different dialog trees and the other int that will work as a karma comparator between the player and the NPC and a vector variable of DialogNodes.

```
class DialogTree
{
public:
	DialogTree() {};
	~DialogTree() {};

public:
	std::vector <DialogNode*> dialogNodes;
	int treeid, karma;
};
```

And finally the dialog class that will be the one that manages the whole system and that mainly will do three important functions. Load the tree data, find the correct node and paint the dialog.

```
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
	DialogNode* currentNode;
	int input = 0, treeid = 0;
public:
	pugi::xml_document	tree_file;
};
```

## How it works

- First we will have to load the data from the XML, which will be our container of dialogs. 

- With the three load functions of the dialog class you will first enter the first tree, inside the first tree will load its attributes and call the second function that is responsible for loading the nodes. 

- In the same way that the other function will load attributes the attributes of the first node and activate the last function that will load the attributes of each one of the options of that node. Looping the 3 functions we will load the whole tree and we will have it ready.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Webp.net-gifmaker%20(4).gif?raw=true"/>

- The next thing would be to choose which is the conversation node that we want to show. What we will do is to have a DialogNodes pointer that will take care of going from one node to another as a guide to the dialogue that the player will follow. 

- We choose which option the player chooses and we would look for a node that had the same id that that option marks as the next node. When we find it, we will assign that node to our DialogNodes pointer.

- Finally we just need to paint the node on the screen with your options, with a couple of labels and looped the label of the options and everything would be ready to work.


<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Webp.net-gifmaker%20(3).gif?raw=true"/>


# TODO's and solutions

## TODO 1: Load the data from the XML

### What do you have to do
In this TODO you have to load all the XML information in the game. To do this and following the structure of the previous XML you will have to fill in the three loading functions of the code.
- Create a new DialogTree

- Load the variables that it has in the XML

- Call the function that loads the nodes

- Add the DialogTree to the DialogTrees vector


### What you should see

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/TODO1.JPG?raw=true"/>


## TODO 2: Change the PLAYERNAME tag to the player name in the dialog

### What do you have to do
Now we want to replace the word that came out in the previous TODO (PLAYERNAME) by the name we want our character to have in the game. For this I have already left a loop that runs through the whole phrase that the NPC says in a node.

- Create a new variable size_t (a variable capable of representing the size of any object), this variable will be equal to the value obtained from looking for the PLAYERNAME in the line of dialogue.

- Put a condition that will only be fulfilled if you find the word PLAYERNAME.

- Now substitute the word for the name we want to put our character.

- Remember to use the find and replace functions to complete this TODO.

### What you should see

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/TODO2.JPG?raw=true"/>

## TODO 3:  Put your own dialog options 

### What do you have to do
Now complete the first node with your own options. The TODO is in the Dialog.xml file.

### What you should see

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/TODO3.JPG?raw=true"/>

## TODO 4:  Search which will be the next node in the tree

### What do you have to do
Now we have to find what the next node will be when the player chooses one of the options we created earlier.

- Search among all the nodes and compare which node has the option taken with the nodes of the tree.

- Finally assign that node to our currentNode.

### What you should see

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Webp.net-gifmaker%20(5).gif?raw=true"/>


## TODO 5:  Write a bad option to say and a node with the NPCs's angry response

### What do you have to do
The TODO is in the Dialog.xml file.
Now write something bad to tell our NPC. You will also have to write the angry NPC response.
Remember to tell him that karma has our conversation tree with this NPC.
Assign a negative value to the bad option and put a negative value also on the angry response of our NPC.

Karma values:
0 neutral karma
-1 bad karma

### What you should see
This TODO you can't check if did it right but in the next TODO you will be able.

## TODO 6:  Check the karma of the player

### What do you have to do
In this ALL we will have to check how is the state of karma in the tree of dialogue. And act according to the result. If it is negative, the NPC will not want to talk to us.

For that we will use two methods: CompareKarma and CheckForKarma.

- The first is responsible for looking if the Karma with the npc is neutral or negative.

- The second happens that the value of karma has the option chosen by the player and will update the karma value of the tree.

- If CompareKarma is not fulfilled we must assign our currentNode pointer to the node that has a negative karma. That way the NPC will not let us talk with him unless we reset the dialogue with R.

### What you should see
If we choose the option with bad karma if we talk again with the NPC giving the F1 key, the NPC will not want to talk to us unless we restart the conversation with the R key.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Webp.net-gifmaker%20(6).gif?raw=true"/>


## Solution TODO 1
```
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

```

```
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
```

```
bool j1DialogSystem::LoadNodesDetails(pugi::xml_node& text_node, DialogNode* npc)
{
	bool ret = true;
	for (pugi::xml_node op = text_node.child("option"); op != NULL; op = op.next_sibling("option"))
	{
		DialogOption* option = new DialogOption;
		option->text.assign(op.attribute("line").as_string());
		option->nextnode = op.attribute("nextnode").as_int();
		option->karma = op.attribute("karma").as_int();
		npc->dialogOptions.push_back(option);
	}
	return ret;
}
```

## Solution TODO 2

```
for (int i = 0; i < currentNode->text.size(); i++)
	{
		size_t found = currentNode->text.find("PLAYERNAME");
		if (found != std::string::npos)
			currentNode->text.replace(currentNode->text.find("PLAYERNAME"), 10, "Ivan");
	}
```


## Solution TODO 3

```
<dialogtree treeid="0" karma="0">
    <node line="Hello PLAYERNAME, how are you?" id="0">
      <option  line="You smell bad" nextnode="1" karma="-1"/>
      <option line="Hello strange voice" nextnode="2"/>
    </node>
```

## Solution TODO 4

```
for (int j = 0; j < dialogTrees[treeid]->dialogNodes.size(); j++)
{
	if (currentNode->dialogOptions[input]->nextnode == dialogTrees[treeid]->dialogNodes[j]->id)
	{
		currentNode = dialogTrees[treeid]->dialogNodes[j]; 			
		break;
	}
}
```

## Solution TODO 5

```
<dialogtree treeid="0" karma="0">
    <node line="Hello PLAYERNAME, how are you?" id="0">
      <option  line="You smell bad" nextnode="1" karma="-1"/>
      <option line="Hello strange voice" nextnode="2"/>
    </node>
```
```
 <node line="I won't talk to you, you insulted me!" id="5" karma="-1">
      <option line="Ok then..." nextnode="6"/>
    </node>
```


## Solution TODO 6

```
if (CompareKarma() == true)
	{
		//Find the next node 
		if (input >= 0 && input < currentNode->dialogOptions.size()) //Only if the input is valid
		{
			for (int j = 0; j < dialogTrees[treeid]->dialogNodes.size(); j++)
			{
				if (currentNode->dialogOptions[input]->nextnode == dialogTrees[treeid]->dialogNodes[j]->id) //If the option id is the same as one of the nodes ids in the tree
				{
					CheckForKarma(currentNode);
					currentNode = dialogTrees[treeid]->dialogNodes[j]; // we assign our node pointer to the next node in the tree				
					break;
				}
			}
		}
	}
	else if(CompareKarma() == false)
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
```


# What we could improve

- The input is very limited, you would have to implement some kind of method to choose the different options.

- If you want to assign more diversity to the actions that can unleash the options, such as karma, you should implement a state machine that will handle all the possible variables according to their type. For example: That the npc you of some object, money, that you can only access certain options if you have a high enough level, etc ...

- It could also be implemented to our system a function that will calculate the size of each node of dialogue and assign the UI of corresponding size.


# Links to documentation

- [Discussion on how to do a dialog system](https://www.gamedev.net/forums/topic/636921-rpg-dialog-system/)

- [How to do a simple dialog tree](https://www.youtube.com/watch?v=W4TV-_-Wcw4)

- [How a studio did their dialog system](https://thegamekitchen.com/blog/designing-a-dialog-system-for-chapter-two/)

- [Different solutions about how to do a dialogue structure](https://stackoverflow.com/questions/1840154/rpg-dialogue-engine-structure)

- [Article about different kinds of dialog systems](http://www.gamasutra.com/view/feature/132116/defining_dialogue_systems.php?page=4)

- [Another article about kinds of dialog systems](https://web.archive.org/web/20100324114601/http://www.gamedev.net/reference/articles/article247.asp)

- [Conversational AI in videogames](https://www.researchgate.net/publication/328215976_Spoken_Conversational_AI_in_Video_Games-Emotional_Dialogue_Management_Increases_User_Engagement)

- [Designing an intelligent dialog system](https://www.academia.edu/2841712/Designing_an_intelligent_dialogue_system_for_serious_games)

- [New approach to dialog systems](https://timhengeveld.com/files/SupNar_TimH_Crafting_ConFlo.pdf)

- [Article about the future of dialogs](https://www.pcgamer.com/the-future-of-dialogue-in-games/)

# Author

This research project has been done by Ivan Ropero García. Contact me in:

Github: [Link](https://github.com/RoperoIvan)

Mail: ivan_ropero98@hotmail.com
