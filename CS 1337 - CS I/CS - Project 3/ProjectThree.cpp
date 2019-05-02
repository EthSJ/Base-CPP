

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//My node.
struct Node
{
    string sorter;
    string penInstructions;
    char command;
    char compass;
    int moveBy;
    Node* next;
};
//legacy functions. Edited slightly to account for grid
void penNS(char compass, int dist, bool &write, bool &bold, char grid[50][50], int& x, int &y);
void penEW(char compass, int dist, bool &write, bool &bold, char grid[50][50], int& x, int &y);

//adds a node.
void addNode(Node* &head, string alphasort);
void deleteNode(Node* &h, Node* &badptr);

//overrides the unsorted file with sorted.
//Also gets rid of characters for sorting, since unneeded.
void inputOverride(Node* head, fstream& commandsFile, int &x, int &y);

//if it's not out of bounds at all, this'll return a true;
bool notOut(char compass, int moveBy, int &x, int &y);

//Prints the current drawing, and prints the finished drawing.
void printCurrent(char grid[50][50]);
void displayFinished(char grid[50][50]);

int main()
{
    //variables
	char dirMove, selectSwitch;
    int totalX = 0, totalY =0, x=0, y=0, intMove;
	bool isBold = false, writingPossible=false;
	string alphasort;

    //Set up 2d array, give every value space.
    char grid[50][50] = {{}};
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            grid[i][j] = ' ';

    Node* head = nullptr;
    fstream commandsFile;
    commandsFile.open("commands.txt", ios::in | ios::out);
    fstream paintFile;
	paintFile.open("paint.txt", ios::out);


    while(!commandsFile.eof())
    {
        getline(commandsFile,alphasort);
        addNode(head, alphasort);
    }
    commandsFile.close();

    if(commandsFile.is_open())
    {
        cout<< "Woah stop! File is still open for some reason! \n";
    }

    fstream commandFile;
	commandFile.open("commands.txt", ios::in);
	if(!commandFile.is_open())
    {
        cout<< "Woah stop! File didn't open for some reason!"<<"\n";
    }
    Node* ptr = head;
    while(ptr != NULL)
    {
        if(notOut(char , int moveBy, int &x, int &y) == false)
        {
            deleteNode(head, ptr);
        }
        ptr=ptr->next;
    }

    /*
	while(!commandFile.eof())
    {
        selectSwitch = commandFile.get();
		switch (selectSwitch)
        {
            //turns off writing.
			case '1': writingPossible = false;

                break;

            //turns on writing.
			case '2': writingPossible = true;

                break;

            //gets the other 2 commands following 3 and then tells the pen to move respectively, and possibly mark in that direction.
			case '3':{

                        //moves north and south.
                        if(dirMove == 'N' || dirMove =='S')
                        {
                            penNS(dirMove, intMove, writingPossible, isBold, grid, x, y);
                        }
                        //moves east and west
                        if( dirMove == 'E'|| dirMove == 'W')
                        {
                            penNS(dirMove, intMove, writingPossible, isBold, grid, x, y);
                        }
                    }
                break;

            //shows what it looks like at the time it's commanded. Displays to console.
			case '4': printCurrent(grid);

                break;

            //turns bold on.
			case 'B':isBold = true;

                break;

            //turns bold off
			case 'b': isBold = false;

                break;
            default:
                break;

        }
    }
    //draws the finished thing to file
    displayFinished(grid);
    commandFile.close();
    commandsFile.open("commands.txt", ios::out | ios::trunc);
    if (commandsFile.is_open())
    {
        inputOverride(head, commandsFile, totalX, totalY);
    }*/


	return 0;
}
//Gets a string, finds space breaks it down into an easy to grid sorter (ex: AAA) and the command as a whole.
//gets command from first part of command whole, then looks for spaces. if it finds one, find compass and distance. If not, account for.
//One all above is done, it will sort the node based off of sorter. Also plugs values into node.
//Head is the null pointer that's the start of our linked list. Alphasort it the whole line with all info.
void addNode(Node* &head, string alphasort)
{
    char penCommand, compass;
    int distance;
    string distanceInString;

    //Finds first space and splits into Sorter section and instruction section
    int endSort = alphasort.find(" ");
    string alpha = alphasort.substr(0,endSort);
    string instructions = alphasort.substr(endSort+1, alphasort.size());

    //assigns command to what the pen will do. Always should be first.
    penCommand = instructions[0];

    //Has a command of three in it.
    if(penCommand == '3')
    {
        //accounts for spaces in commands.
        int spacewithin = alphasort.find(" ");
        if(spacewithin > 0)
        {
            compass = instructions[3];
            distanceInString = instructions.substr(5, instructions.size());
            distance= atoi(distanceInString.c_str());
        }
       // No spaces(ex: 3,2,1) in command.
        else
        {
            compass = instructions[2];
            distanceInString = instructions.substr(4, instructions.size());
            distance= atoi(distanceInString.c_str());
        }

    }
    //has command that's not three. Just fills in 0s. 0s are harmless here.
    else
    {
        compass = '0';
        distance = 0;
    }
    //start of creation of sorting on the new node.
    Node* i = new Node;
    i->sorter = alpha;
    i->penInstructions= instructions;
    i->command= penCommand;
    i->compass =compass;
    i->moveBy=distance;
    i->next = nullptr;

    if (!head)
        head = i;
    else if ((i->sorter) < (head->sorter))
    {
        i->next = head;
        head = i;
    }
    else
    {
        Node* p1 = head;
        while (p1->next)
        {
            if ((p1->next->sorter) > (i->sorter))
            {
                i->next = p1->next;
                p1->next = i;
                return;
            }
            p1 = p1->next;
        }
        p1->next = i;
    }

}
void deleteNode(Node* &h, Node* &badptr)
{
    if (!h)
        cout << "Empty list!\n";
    else if (h == badptr)
    {
        node* hold = h;
        h = h->next;
        badptr = head;
        delete hold;
    }
    else
    {
        node* p1 = h;
        while (p1->next)
        {
            if (p1->next == badptr)
            {
                node* hold = p1->next;
                p1->next = p1->next->next;
                delete hold;
                return;
            }
            p1 = p1->next;
            badptr =badptr->next;
        }
        cout << "Number not in list\n";
    }
}

//recursively checks if head is null, else check move, if move ok write to file. Then move head, delete old head, test new head. Call self again.
//Head is linked List(sorted), commandsFile is our output to file, X and Y are "file pointers" to test bounds before writing in.
void inputOverride(Node* head, fstream& commandsFile, int &x, int &y)
{
    //ends if
    if(head == NULL)
    {
        return;
    }
    //check move -> move ok? output to file and newline -> then delete head and move to next part.
    else
    {
        if(notOut(head->compass,head->moveBy, x, y)==true)
        {
            commandsFile <<head->penInstructions;
        }
        else
        {
            commandsFile.seekg(-2, ios::cur);
        }
        Node* temp = head;
        delete head;
        head = temp->next;
        if(head != NULL)
        {
            commandsFile << "\n";
        }
        inputOverride(head, commandsFile, x, y);
    }
}

//calculates if the command would cause an out of bounds. If not, returns true.
//compass is cardinal direction, moveby is the distance, x and y are tester "file pointer"s.
bool notOut(char compass, int moveBy, int &x, int &y)
{
    //If north and command isn't bigger than 50 or moved we'd be smaller than 0 return false
    //It the move is between 0 and 50 (ok to be 0 as is 0-49) calculate the move and return true.
    if(compass == 'N')
    {
        if(moveBy > 50)
        {
            return false;
        }
        else if(y-moveBy < 0 )
        {
            return false;
        }
        else if(y-moveBy >= 0 && y-moveBy <50)
        {
            y= y-moveBy;
            return true;
        }
    }
    //If south and command isn't bigger than 50 or moved we'd be smaller than 0 return false
    //It the move is between 0 and 50 (ok to be 0 as is 0-49) calculate the move and return true.
    if(compass == 'S')
    {
        if(moveBy > 50)
        {
            return false;
        }
        else if(y+moveBy > 50 )
        {
            return false;
        }
        else if(y+moveBy >= 0 && y+moveBy <50)
        {
            y= y+moveBy;
            return true;
        }
    }
    //If east and command isn't bigger than 50 or moved we'd be smaller than 0 return false
    //It the move is between 0 and 50 (ok to be 0 as is 0-49) calculate the move and return true.
    if(compass == 'E')
    {
        if(moveBy > 50)
        {
            return false;
        }
        else if(x+moveBy > 50 )
        {
            return false;
        }
        else if(x+moveBy >= 0 && x+moveBy < 50)
        {
            x= x+moveBy;
            return true;
        }
    }
    //If west and command isn't bigger than 50 or moved we'd be smaller than 0 return false
    //It the move is between 0 and 50 (ok to be 0 as is 0-49) calculate the move and return true.
    if(compass == 'W')
    {
        if(moveBy > 50)
        {
            return false;
        }
        else if(x-moveBy < 0 )
        {
            return false;
        }
        else if(x-moveBy > 0 && x-moveBy < 50)
        {
            x= x-moveBy;
            return true;
        }
    }
}

//moves the pen up or down, despite pen being up or down, and draws depending on if it is up or down and bold is on or off.
//compass is direction, dist is how far, write is if it can, bold is if it can, grid is our canvas, X and Y aer the "file pointers"
void penNS(char compass, int dist, bool &write, bool &bold, char grid[50][50], int& x, int &y)
{
    //Just move, Y is our memory "file pointer". E is right, W is left. Dist is how far.
	if(write==false)
	{
        if(compass == 'N')
        {
            y=y-dist;
        }
        else if(compass == 'S')
        {
            y=y+dist;
        }
	}
    //Write. move up(N) and for each time it does, draw a mark. If it's not a bold, and drawing nonbold, draw unbold else don't.
	if(write==true)
    {
        if(compass == 'N')
        {
            for(int i=0; i< dist;i++)
            {
                if(bold == true)
                {
                    grid[x][y-i]= '#';
                }
                else
                {
                    if(grid[x][y-i] != '#')
                    {
                        grid[x][y-i]= '*';
                    }
                    else
                    {
                        grid[x-i][y]= '#';
                    }
                }
            }
        }
        //Write. move down(S) and for each time it does, draw a mark. If it's not a bold, and drawing nonbold, draw unbold else don't.
        if(compass == 'S')
            {
                for(int i=0; i< dist;i++)
                {
                    if(bold == true)
                    {
                        grid[x][y+i]= '#';
                    }
                    else
                    {
                        if(grid[x][y+i] != '#')
                        {
                            grid[x][y+i]= '*';
                        }
                        else
                        {
                            grid[x+i][y]= '#';
                        }
                    }
                }
            }
    }
}

//moves the pen right or left, despite pen being up or down, and draws depending on if it is up or down and bold is on or off.
//compass is direction, dist is how far, write is if it can, bold is if it can, grid is our canvas, X and Y are the "file pointers"
void penEW(char compass, int dist, bool &write, bool &bold, char grid[50][50], int& x, int &y)
{
    //Just move, Y is our memory "file pointer". E is right, W is left. Dist is how far.
	if(write==false)
	{
        if(compass == 'E')
        {
            y=y+dist;
        }
        else if(compass == 'W')
        {
            y=y-dist;
        }
	}
	//Write. move right(E) and for each time it does, draw a mark. If it's not a bold, and drawing nonbold, draw unbold else don't.
	if(write==true)
    {
        if(compass == 'E')
        {
            for(int i=0; i< dist;i++)
            {
                if(bold == true)
                {
                    grid[x][y+i]= '#';
                }
                else
                {
                    if(grid[x][y+i] != '#')
                    {
                        grid[x][y+i]= '*';
                    }
                    else
                    {
                        grid[x][y+i]= '#';
                    }
                }
            }
        }
        //Write. move left(w) and for each time it does, draw a mark. If it's not a bold, and drawing nonbold, draw unbold else don't.
        if(compass == 'W')
            {
                for(int i=0; i< dist;i++)
                {
                    if(bold == true)
                    {
                        grid[x][y-i]= '#';
                    }
                    else
                    {
                        if(grid[x][y-i] != '#')
                        {
                            grid[x][y-i]= '*';
                        }
                        else
                        {
                            grid[x][y-i]= '#';
                        }
                    }
                }
            }
    }
}

//Simply prints out the grid. It's stored in memory so it'll output if traded.
//grid is our memory storage for the paining.
void printCurrent(char grid[50][50])
{
    for(int i=0;i<50;i++)
    {
        for(int k=1;k<50;k++)
        {
            cout<<grid[i][k];
        }
        cout<<"\n";
    }
}

//Does the same as old one did but with a grid.
//Make a output file stream, link to paint.txt and draw every piece of the grid, with a lil extra return for proper design
//Grid is our memory storage for the painting.
void displayFinished(char grid[50][50])
{
    char tempChar;
    ofstream currentPaint;
    currentPaint.open("paint.txt");
    for(int i=0;i<50;i++)
    {
        for(int k=1;k<50;k++)
        {
            currentPaint<<grid[i][k];
        }
        currentPaint<<"\n";
    }
    currentPaint.close();
}
