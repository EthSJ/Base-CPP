//Project 4

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "Node.h"
#include "LinkedList.h"
using namespace std;

//takes the derivative of the node and prints in one move. Recursive.
void derivativePrint(Node* pntr, fstream &output);

int main()
{
    //We need to read in from somewhere and output by making a file if needed.
    ifstream input("functions.txt");
    //need a nice error if something goes wrong too!
    if(!(input.is_open()))
    {
        cout<<"Can't find the file to open. Did you name the file functions.txt?\n";
    }
    fstream output("derive.txt", ios::out);

    //the term to hold coefficient, exponent, and denominator.
    //The checks for if it's trig, if we need a negative, if there's no X, and if a ^ is there.
    //What'll save the trig.
    double rCoefficient, rExponent, downCo;
    bool triggi = false, negcheck=false, noX=true, noPow = false;
    char triggy[4];

    //loops making nodes then print/calculating then stops.
    while(!(input.eof()))
    {
    LinkedList LL;
    //while you don't see a new line next and we're not at the end of the file, make nodes.
    while(input.peek() !='\n' && !(input.eof()))
    {
        downCo=1;

        //Fills in triggy with blanks each time. If it's blank, no trig. If trig, it'll fill up again.
        for(int i=0; i<4; i++)
        {
            triggy[i] = ' ';
            if(i == 3)
                triggy[i] ='\0';
        }

        //check space. Ignore. Checks for first space in node (space) -+ (space) node
        if(input.peek()==' ')
            input.ignore();
        //Checks for negative. Flags that next will be negative.
        if(input.peek()=='-')
        {
            input.ignore();
            negcheck=true;
        }
        //checks for positive symbol. Just goes over.
        if(input.peek()=='+')
            input.ignore();

        //checks for second space in Node (space)-+ (space) node
        if(input.peek()==' ')
            input.ignore();

        //checks for the bonus.
        //peeks for it, then ignore (, grab numerator, ignore /, grab demoninator, ignore, assign and go
        if(input.peek()=='(')
        {
            input.ignore();
            input>>rCoefficient;
            input.ignore();
            input>>downCo;
            input.ignore();
        }

        //is it negative and a digit? read it in, flip it to negative for Coefficient.
        else if(negcheck==true && isdigit(input.peek()))
        {
            input>>rCoefficient;
            rCoefficient=rCoefficient*(-1);
        }
        //Is it positive and a digit? Read it into coefficient.
        else if(negcheck==false && isdigit(input.peek()))
            input>>rCoefficient;

        else if (isalpha(input.peek()) && negcheck==true)
            rCoefficient=-1;
        //nothing there? It's an assumed one for coefficient.
        else if (isalpha(input.peek()))
            rCoefficient=1;
        //Ignore the x that must come next. if it does this, there is not not an x.
        if(input.peek()=='x')
        {
            input.ignore();
            noX=false;
        }
        //ignore whatever this ^ symbol is called.
        if(input.peek() != '^')
        {
            noPow=true;
        }
        if(input.peek()=='^')
            input.ignore();
        //If we have no X, we can flip this back because there'll be no power ^ symbol. Seriously, what do you call it?
        if(noX==true)
            noPow=false;

        //If it starts with a trig term, flag it as trig and c-string it in.
        if(input.peek()=='c'||input.peek()=='s'||input.peek()=='t')
            {
                noX=false;
                triggi=true;
                triggy[0]=input.get();
                triggy[1]=input.get();
                triggy[2]=input.get();
                triggy[3]='\0';
                if(input.peek()==' ')
                    input.ignore();
            }
        //ignores a possible space
        if(input.peek()==' ' && noPow==false)
            input.ignore();

        //accounts for negative exponent
        if(input.peek()=='-' && noX==false && noPow==false)
        {
            input.ignore();
            input>>rExponent;
            rExponent=rExponent*(-1);

        }
        if(input.peek()==' ' && noX==false && noPow==false)
            input.ignore();
        //Is it a digit next? (post ^ or after trig term). Just read into exponent.
        else if(isdigit(input.peek()) && noX==false && noPow==false)
        {
            input>>rExponent;
        }
        //Is it just an x and still in triggi? There's no exponent.
        else if(input.peek()=='x' && triggi==true  && noPow==false)
            rExponent=1;
        //If it doesn't find an x to ignore, the exponent is 0
        else if(noX==true)
        {
            rExponent=0;
        }
        //Else we set it to one because it is implied: 2x^1 == 2x
        else if (noX== false && noPow==true)
            rExponent=1;
        else if(noX ==false)
            rExponent=1;

        //reset all the flags back to what they were to prepare for next node.
        if(noX==false)
        {
            noX=true;
        }
        if(negcheck==true)
        {
            negcheck=false;
        }
        if(noPow==true)
            noPow=false;

        //sets triggy back to false for the next term or just resets it to false.
        //maybe redundant.
        if(triggi==true)
        {
            triggi=false;
            input.ignore();
        }

        //debug code. Used to see each Coefficient and Exponent before it becomes a node.
        //cout<<"Coeffic "<<rCoefficient<<" and Expon " <<rExponent<<"\n";

        //if the node is trig related, it will add to end. Otherwise add normally.
        if(triggy[0] == 'c' || triggy[0] == 's'|| triggy[0] =='t')
        {
            Node* term = new Node(rCoefficient, downCo, rExponent, triggy);
            LL.addToEnd(term);
        }
        else
        {
            Node* term = new Node(rCoefficient, downCo, rExponent, triggy);
            LL.addNode(term);

        }
    }
    //Debug Code. Used for chars other than '\n';
    //input.seekg(1, ios::cur);

    //Skip the windows \r and default \n if they're there so we start on a nice new line
    if(input.peek()=='\r')
        input.ignore();
    if(input.peek()=='\n')
        input.ignore();

    //Gets the head, so long as it exists we start printing out.
    Node* temp = LL.getLead();
    if(temp !=NULL)
    {
        //Degun Code
       // LL.printList(temp);

        //output calc/print the nodes to the file then clean up and delete it all!
        derivativePrint(temp, output);
        LL.~LinkedList();
    }
   }

    return 0;
}

//prints out the linked list recursively to the file AND does the derivative calculations
//requires the head node pointer and a reference of the output.
void derivativePrint(Node* pntr, fstream &output)
{
    //stop condition. Newlines for next set.
    if(pntr==NULL)
    {
        output<<"\n";
        return;
    }
    //while there's a next node, get the required info and print to file with a + sign.
    if(pntr->next)
    {
        //The work for cos
        if(*(pntr->getTrig())=='c')
        {
            if(pntr->getExpon()==1)
                output<<(-1)*pntr->getCoeff()*pntr->getExpon()<<"sin ("<<"x)" <<" + ";
            else
                output<<(-1)*pntr->getCoeff()*pntr->getExpon()<<"sin ("<<pntr->getExpon()<<"x)" <<" + ";
        }
        //does it start with an s? It's a sin(x).
        else if(*(pntr->getTrig())=='s')
        {
            if(pntr->getExpon()==1)
                output<<pntr->getCoeff()*pntr->getExpon()<<"cos ("<<"x)" <<" + ";
            else
                output<<pntr->getCoeff()*pntr->getExpon()<<"cos ("<<pntr->getExpon()<<"x)" <<" + ";
        }
        //Does it start with a t? It's a tan(x)
        else if(*(pntr->getTrig())=='t')
        {
            if(pntr->getExpon()==1)
                output<<pntr->getCoeff()*pntr->getExpon()<<"sec ("<<"x)^2" <<" + ";
            else
                output<<pntr->getCoeff()*pntr->getExpon()<<"sec ("<<pntr->getExpon()<<"x)^2" <<" + ";
        }
        //does the exponent minus one get to be one? Don't bother including exponent.
        else if(pntr->getExpon()-1 ==1)
            output<<pntr->getCoeff()*pntr->getExpon()<<"x" <<" + ";
        //Is exponent 0(not added)? Then it's just a number and therefore nothing!
        else if(pntr->getExpon() ==0)
            output<<"0 + ";
        //If it goes to 0, the absence of X, just tell the coefficient.
        else if(pntr->getExpon()-1 ==0)
            output<<pntr->getCoeff()<<" + ";
        //if all else fails, just do a normal derivative.
        else
            output<<pntr->getCoeff()*pntr->getExpon()<<"x^"<< pntr->getExpon()-1 <<" + ";
    }
    //if there's not a next, just end it there.
    else if (pntr)
    {
        //The work for cos
        if(*(pntr->getTrig())=='c')
        {
            if(pntr->getExpon()==1)
                output<<(-1)*pntr->getCoeff()*pntr->getExpon()<<"sin ("<<"x)";
            else
                output<<(-1)*pntr->getCoeff()*pntr->getExpon()<<"sin ("<<pntr->getExpon()<<"x)";
        }
        //does it start with an s? It's a sin(x).
        else if(*(pntr->getTrig())=='s')
        {
            if(pntr->getExpon()==1)
                output<<pntr->getCoeff()*pntr->getExpon()<<"cos ("<<"x)";
            else
                output<<pntr->getCoeff()*pntr->getExpon()<<"cos ("<<pntr->getExpon()<<"x)";
        }
        //Does it start with a t? It's a tan(x)
        else if(*(pntr->getTrig())=='t')
        {
            if(pntr->getExpon()==1)
                output<<pntr->getCoeff()*pntr->getExpon()<<"sec ("<<"x)^2";
            else
                output<<pntr->getCoeff()*pntr->getExpon()<<"sec ("<<pntr->getExpon()<<"x)^2";
        }
        //does the exponent minus one get to be one? Don't bother including exponent.
        else if(pntr->getExpon()-1 ==1)
            output<<pntr->getCoeff()*pntr->getExpon()<<"x";
        //Is exponent 0(not added)? Then it's just a number and therefore nothing!
        else if(pntr->getExpon() ==0)
            output<<"0";
        //If it goes to 0, the absence of X, just tell the coefficient.
        else if(pntr->getExpon()-1 ==0)
            output<<pntr->getCoeff();
        //if all else fails, just do a normal derivative.
        else
            output<<pntr->getCoeff()*pntr->getExpon()<<"x^"<< pntr->getExpon()-1;
        }
    //calls self again, because it's recursive.
    derivativePrint(pntr->next, output);
}

