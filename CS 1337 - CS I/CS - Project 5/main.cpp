//Main.cpp for Project 5
//Liste faire: rein
//Last 3 changes: IT RUNS!, fixed out of bounds check, converted everything

#include <iostream>
#include <fstream>
#include "grid.h"
#include "gridnode.h"
using namespace std;


//pen movements. Take direction, how man, if it can write, if it's bold and the current pntr. (not grid. We cannot draw with grid, but pntr looks at grid and can draw)
void penNS(char nOrS, int intMove, bool &canWrite, bool &isBold, Gridnode* &ptr);
void penWE(char eOrW, int intMove, bool &canWrite, bool &isBold, Gridnode* &ptr);

//Out of Bounds checks
bool outOfBoundsNS(char direction, int movement, int &y);
bool outOfBoundsEW(char direction, int movement, int &x);

//Last function to run to draw grid to the file. Takes grid canvas. Considering changing to just canvas.display();
void drawGrid(grid &canvas, fstream &output);

int main()
{

	//dirMove is the direction is moving, selectSwitch determines the switch to follow, intMove is how far it moved.
	//isBold + writingPossible are both true false to if it's bold and you can write or not. False by default.
	char dirMove, selectSwitch;
	int intMove, x=1, y=1;
	bool isBold = false, writingPossible=false;

    //Opens the file streams for commands and paint. Allows reading commands and painting to paint.
	ifstream commandsFile;
	commandsFile.open("commands.txt");
    fstream paintFile;
	paintFile.open("paint.txt", ios::out);

    grid canvas;
    //required to look through canvas and draw.
    Gridnode *pntr = canvas.getHead();


    //executes while not at the end of the file in commands.
	while(!commandsFile.eof())
    {
        //Finds the command in the file. See switch below.
        selectSwitch = commandsFile.get();

        //After getting command, sends in correct command. When command is complete, loops back up to while.
		switch (selectSwitch)
        {
            //turns off writing.
			case '1': writingPossible = false;
                break;

            //turns on writing.
			case '2': writingPossible = true;
                break;

            //gets the other 2 commands following 3 and then tells the pen to move respectively, and possibly mark in that direction.
			case '3':

                        commandsFile.ignore();
                        if(commandsFile.peek()==' ')
                            commandsFile.ignore();

                        dirMove = commandsFile.get();

                        commandsFile.ignore();
                        if(commandsFile.peek()==' ')
                            commandsFile.ignore();

                        commandsFile >> intMove;

                        //moves north and south.
                        if(dirMove == 'N' || dirMove =='S')
                        {
                            if(outOfBoundsNS(dirMove, intMove, y) == false)
                                penNS(dirMove, intMove, writingPossible, isBold, pntr);
                        }

                        //moves east and west
                        if(dirMove == 'E'|| dirMove == 'W')
                        {
                            if(outOfBoundsEW(dirMove, intMove, x)==false)
                                penWE(dirMove, intMove, writingPossible, isBold, pntr);
                        }
                break;

            //shows what it looks like at the time it's commanded. Displays to console.
			case '4': canvas.display();
                break;

            //turns bold on.
			case 'B':isBold = true;
                break;

            //turns bold off
			case 'b': isBold = false;
                break;

        }
    }
    //one final what it looks like to the console. Got to make sure it looks right and this is easier than hunting down the file.
	drawGrid(canvas, paintFile);

	//Packs the files up, we're done with them.
	commandsFile.close();
	paintFile.close();


    return 0;
}

bool outOfBoundsNS(char direction, int movement, int &y)
{
    //negatives
    if(direction == 'N')
    {
        y = y - movement;
        if(y < 1)
        {
            y = y + movement;
            return true;
        }
        else
        {
            return false;
        }
    }
    //positives
    if(direction == 'S')
    {
        y= y+movement;
        if(y > 50)
        {
            y= y - movement;
            return true;
        }
        else
        {
            return false;
        }

    }
}

bool outOfBoundsEW(char direction, int movement, int &x)
{
        //negatives
    if(direction == 'W')
    {
        x = x - movement;
        if(x < 1)
        {
            x = x + movement;
            return true;
        }
        else
        {
            return false;
        }
    }
    //positives
    if(direction == 'E')
    {
        x= x+movement;
        if(x > 50)
        {
            x= x - movement;
            return true;
        }
        else
        {
            return false;
        }

    }
}

//simply draws a grid to work on
void drawGrid(grid &canvas, fstream &output)
{
    //Create two temps. One points to head, the other to nothing.
    Gridnode *temp = canvas.getHead();
    Gridnode *temp2;
    //Change i<50 to number of nodes up/down or WILL crash!
    //loops setting temp2 to temp doing loop, adding break and then moving down one.
    for(int i=0;i<50;i++)
    {
        temp2 = temp;
        //Prints going right below.
        for(int w=0;w<50;w++)
        {
            output<<temp2->getText();
            temp2 = temp2->getRight();
        }
        output<<"\n";
        temp=temp->getDown();
    }
}

//moves the pen up or down, despite pen being up or down, and draws depending on if it is up or down and bold is on or off.
void penNS(char nOrS, int intMove, bool &canWrite, bool &isBold, Gridnode* &ptr)
{
    // No writing
	if(canWrite==false)
	{
	    //moves up by intMove number of rows (52 units per)
        if(nOrS == 'N')
        {
            for(int i=0; i < intMove; i++)
            {
                if(ptr->getUp() != NULL)
                    ptr=ptr->getUp();
            }
        }
        //moves down by intMove number of rows (52 units per)
        else if(nOrS == 'S')
        {
            for(int i=0; i < intMove; i++)
            {
                if(ptr->getDown() != NULL)
                    ptr=ptr->getDown();
            }
        }
	}//end of no writing.

	//writing
	if(canWrite==true)
    {
        //Moves seek one row up (52 units), prints the character (if possible), then backs up one so next move is accurate
        if(nOrS == 'N')
            {
                for(int i=0; i < intMove; i++)
                    {
                        if(ptr->getUp() != NULL)
                            ptr=ptr->getUp();
                        //bold version of drawing
                        if(isBold == true)
                        {
                            ptr->setText('#');
                        }

                        else
                        {
                            if(ptr->getText() != '#')
                            {
                                 ptr->setText('*');
                            }
                        }
                    }
            }

        //Moves seek one row down (52 units), prints the character (if possible), then backs up one so next move is accurate.
        if(nOrS == 'S')
            {
                for(int i=0; i < intMove; i++)
                    {
                        if(ptr->getDown() != NULL)
                            ptr=ptr->getDown();
                        //bold mark on paint file
                        if(isBold == true)
                        {
                            ptr->setText('#');
                        }
                        //unbold version of drawing.
                        //BUG FIX here. Tells position, peeks at next character, then returns to position and places a *. Zero net movement, just peeking at next character.
                        else
                        {
                            if(ptr->getText() != '#')
                            {
                                ptr->setText('*');
                            }
                        }
                    }
            }
    }//end of writing.

}

//moves the pen left or right, despite pen being up or down, and draws depending on if it is up or down and bold is on or off.
void penWE(char eOrW, int intMove, bool &canWrite, bool &isBold, Gridnode* &ptr)
{

    //Just moving;no writing.
	if(canWrite== false)
    {
        //move west
        if(eOrW == 'W')
        {
            for(int i=0; i < intMove; i++)
            {
                if(ptr->getLeft() != NULL)
                    ptr=ptr->getLeft();
            }
        }

        //move east
        if(eOrW == 'E')
        {
            for(int i=0; i < intMove; i++)
            {
                if(ptr->getRight() != NULL)
                    ptr=ptr->getRight();
            }
        }
    }
    //the pen is down and can write
    if(canWrite == true)
    {
        //Moves west. Moves back full distance, then draws, and goes back to full distance.
        if(eOrW == 'W')
        {
            for(int i=0; i < intMove; i++)
            {
                if(ptr->getLeft() != NULL)
                    ptr=ptr->getLeft();
                for(int k=0; k < intMove; k++)
                {
                    //bold mark on paint file
                    if(isBold == true)
                    {
                        ptr->setText('#');
                    }
                    else
                    {
                        if(ptr->getText() != '#')
                        {
                            ptr->setText('*');
                        }
                    }
                }
            }
        }

        //pen's still writing.
        else if(canWrite == true)
        {
            //Moves east, by intMove spaces
            if(eOrW == 'E')
            {
                for(int i=0; i < intMove; i++)
                {
                    if(ptr->getRight() != NULL)
                        ptr=ptr->getRight();
                    for(int k=0; k < intMove; k++)
                    {
                        //bold mark on paint file
                        if(isBold == true)
                        {
                            ptr->setText('#');
                        }
                        else
                        {
                            if(ptr->getText() != '#')
                            {
                                ptr->setText('*');
                            }
                        }
                    }
                }
            }

        }
    }

}
