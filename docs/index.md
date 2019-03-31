# Dialogue System


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

## Which we will use

As mentioned previously, the most used system is the Branching dialog. It is also the one that will be most useful in our project because if we want we can choose between non branching and branching with very little effort. The complexity of the code is not high either, so implementing it in our project will be simple and we should not have any problem.

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Untitled%20Diagram.jpg?raw=true"/>

We will use a tree as structure of a dialogue with, for example, an NPC. Each tree has nodes, that are each of the different possible interactions between the player and the NPC. Finally within these nodes are the options, that will be as the name says the possibilities of choice that the player will have.

## Code Structure

The code is made up of 4 classes: 
The first would be the options, which carry 2 int, the next node to which the conversation will go and a modifier of the state of the npc and 1 string that will be the line of dialogue that will form the option that the player will choose.
```class DialogOption
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
The next class is the nodes that you will have as well as the options, 2 int, your node id and the karma of that NPC dialog. And finally the string that would be the line of dialogue of the NPC.
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
The third class is the trees that in this case will only have 2 int, their tree id so that we can have different dialog trees and the other int that will work as a karma comparator between the player and the NPC.
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
	std::list <GUI_Button*> options_buttons;
	DialogNode* currentNode;
	int input = 0, treeid = 0;
public:
	pugi::xml_document	tree_file;
};
```
<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/Tree.png?raw=true"  height="100" width="100"/>

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/node.png?raw=true"  height="100" width="100"/>

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/option.png?raw=true"  height="100" width="100"/>

<img src="https://github.com/RoperoIvan/Dialogue-System/blob/master/docs/Webpage%20images/currentNode.png?raw=true"  height="84" width="168"/>

## Ways to define de data


## TODO's and solutions

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
