

#include <iostream>
#include <fstream>
using namespace std;

//void prototypes. Take a direction, a number to move that direction, a true/false if they can write, a true/false if the writing is bolded, and gets passed the paintfile to draw to.
void penNS(char nOrS, int intMove, bool &canWrite, bool &isBold, fstream& outFile);
void penWE(char eOrW, int intMove, bool &canWrite, bool &isBold, fstream& outFile);
//Void prototypes. Takes the paintfile to draw to.  First is grid building, second is see progress.
void drawGrid(fstream &beforeGrid);
void displayCurrent(fstream &paintFile);

int main()
{

	//dirMove is the direction is moving, selectSwitch determines the switch to follow, intMove is how far it moved.
	//isBold + writingPossible are both true false to if it's bold and you can write or not. False by default.
	char dirMove, selectSwitch;
	int intMove;
	bool isBold = false, writingPossible=false;

    //Opens the file streams for commands and paint. Allows reading commands and painting to paint.
	ifstream commandsFile;
	commandsFile.open("commands.txt");
    fstream paintFile;
	paintFile.open("paint.txt", ios::out);

    //draws grid. seeks beginning of file so as to not start at the end
	drawGrid(paintFile);
	paintFile.seekp(0, ios::beg);

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
                        dirMove = commandsFile.get();
                        commandsFile.ignore();
                        commandsFile >> intMove;

                        //moves north and south.
                        if(dirMove == 'N' || dirMove =='S')
                        {
                            penNS(dirMove, intMove, writingPossible, isBold, paintFile);
                        }

                        //moves east and west
                        if(dirMove == 'E'|| dirMove == 'W')
                        {
                            penWE(dirMove, intMove, writingPossible, isBold, paintFile);
                        }
                break;

            //shows what it looks like at the time it's commanded. Displays to console.
			case '4': displayCurrent(paintFile);
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
	displayCurrent(paintFile);

	//Packs the files up, we're done with them.
	commandsFile.close();
	paintFile.close();


    return 0;
}

//simply draws a grid to work on
void drawGrid(fstream &beforeGrid)
{
    //draws expanding down
    for(int k=0; k <50; k++)
    {
        //draws expanding row
        for(int i=0;i<50;i++)
        {

            beforeGrid << " ";
            //if it's 49, finishes the row. since start at 0, this is technically the 50th item there.
            if(i==49)
            {
                beforeGrid<< "\n";
            }
        }
    }
}

//moves the pen up or down, despite pen being up or down, and draws depending on if it is up or down and bold is on or off.
void penNS(char nOrS, int intMove, bool &canWrite, bool &isBold, fstream &outFile)
{
    // No writing
	if(canWrite==false)
	{
	    //moves up by intMove number of rows (52 units per)
        if(nOrS == 'N')
        {
            for(int i=0; i < intMove; i++)
            {
                outFile.seekp(-52,ios::cur);
            }
        }
        //moves down by intMove number of rows (52 units per)
        else if(nOrS == 'S')
        {
            for(int i=0; i < intMove; i++)
            {
                outFile.seekp(52,ios::cur);
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
                        outFile.seekp(-52,ios::cur);
                        //bold version of drawing
                        if(isBold == true)
                        {
                            outFile << '#';
                            outFile.seekp(-1,ios::cur);
                        }
                        //unbold version of drawing.
                        //BUG FIX here. Tells position, peeks at next character, then returns to position and places a *. Zero net movement, just peeking at next character.
                        else
                        {
                            int pos = outFile.tellg();
                            if(outFile.peek() != '#')
                            {
                                outFile.seekg(pos,ios::beg);
                                outFile << '*';
                                outFile.seekp(-1,ios::cur);
                            }
                        }
                    }
            }

        //Moves seek one row down (52 units), prints the character (if possible), then backs up one so next move is accurate.
        if(nOrS == 'S')
            {
                for(int i=0; i < intMove; i++)
                    {
                        outFile.seekp(52,ios::cur);
                        //bold mark on paint file
                        if(isBold == true)
                        {
                            outFile << '#';
                            outFile.seekp(-1,ios::cur);
                        }
                        //unbold version of drawing.
                        //BUG FIX here. Tells position, peeks at next character, then returns to position and places a *. Zero net movement, just peeking at next character.
                        else
                        {
                            int pos = outFile.tellg();
                            if(outFile.peek() != '#')
                            {
                                outFile.seekg(pos,ios::beg);
                                outFile << '*';
                                outFile.seekp(-1,ios::cur);
                            }
                        }
                    }
            }
    }//end of writing.

}

//moves the pen left or right, despite pen being up or down, and draws depending on if it is up or down and bold is on or off.
void penWE(char eOrW, int intMove, bool &canWrite, bool &isBold, fstream &outFile)
{

    //Just moving;no writing.
	if(canWrite== false)
    {
        //move west
        if(eOrW == 'W')
        {
            outFile.seekp((-1*intMove), ios::cur);
        }

        //move east
        if(eOrW == 'E')
        {
            outFile.seekp(intMove, ios::cur);
        }
    }
    //the pen is down and can write
    if(canWrite == true)
    {
        //Moves west. Moves back full distance, then draws, and goes back to full distance.
        if(eOrW == 'W')
        {
            outFile.seekp((-1*intMove), ios::cur);
            for(int i=0; i < intMove; i++)
            {
                //bold mark on paint file
                if(isBold == true)
                {
                    outFile << '#';
                }
                //unbold version of drawing.
                //BUG FIX here. Tells position, peeks at next character, then returns to position and places a *. Zero net movement, just peeking at next character.
                else
                {
                    int pos = outFile.tellg();
                    if(outFile.peek() != '#')
                    {
                        outFile.seekg(pos,ios::beg);
                        outFile << '*';

                    }
                }
            }
            outFile.seekp((-1*intMove), ios::cur);
        }

        //pen's still writing.
        else if(canWrite == true)
        {
            //Moves east, by intMove spaces
            if(eOrW == 'E')
            {
                for(int i=0; i<intMove; i++)
                    {
                        //bold mark on paint file
                        if(isBold == (true))
                        {
                            outFile << '#';
                        }
                        //unbold version of drawing.
                        //BUG FIX here. Tells position, peeks at next character, then returns to position and places a *. Zero net movement, just peeking at next character.
                        else
                        {
                            int pos = outFile.tellg();
                            if(outFile.peek() != '#')
                            {
                                outFile.seekg(pos,ios::beg);
                                outFile << '*';

                            }
                        }
                    }
            }

        }
    }//ends writing

}


//creates an way to copy and show what's made in paintFile. Can show unfinished or finished version
void displayCurrent(fstream &paintFile)
{
    //opens a new input stream and gives it a temporary char to work with.
    char tempChar;
    ifstream currentPaint;
    currentPaint.open("paint.txt");

    //Goes through the current painting and copies it until it hits the end. Will show in console.
	while(!currentPaint.eof())
    {
        tempChar= currentPaint.get();
        cout <<tempChar;
    }
    //Adds a nice break afterwards. Usability.
	cout << "\n";
	cout << "\n";
}


