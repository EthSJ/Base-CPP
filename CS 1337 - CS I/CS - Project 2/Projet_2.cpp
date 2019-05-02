

//input/output to console
#include <iostream>
//for the ifstream
#include <fstream>
//for converting the float into a real workable float
#include <cstdlib>
//checking for validations
#include <cctype>
//for absolute value
#include <cmath>
using namespace std;

//tests for correct to and froms, followed by adding functions to add time and cost to respective planets
bool floaty(char shipLine[]), correctCode(char shipLine), isSpace(char shipLine), correctSend(char shipLine);

//Gets and returns the cost per shipment and travel timer per shipment (respectively) to add to totals. setDist is a helper function for travelTime.
double shippingCost(char shippingCodeTo, char shippingCodeFrom, char serviceCode, float weight);
double travelTime(char shippingCodeTo, char shippingCodeFrom, char serviceCode);
double setDist(char planet);


int main()
{
    //The totals for cost and time (respectively). Set to 0 by default.
    double mercuryTotal = 0,
            venusTotal=0,
            earthTotal=0,
            marsTotal=0,
            jupiterTotal=0,
            saturnTotal=0,
            uranusTotal=0,
            neptuneTotal=0;

    double mercuryTime=0,
            venusTime=0,
            earthTime=0,
            marsTime=0,
            jupiterTime=0,
            saturnTime=0,
            uranusTime=0,
            neptuneTime=0;

    //ShipLine gets the line and stores it. weight will be just the item weight stored, which will be converted.
    char shipLine[50];

    //opens shipment instructions
    ifstream inFile;
    inFile.open("shipments.txt");

    //loops until end of file
    do
    {
        //get a line and assign to shipLine array
        inFile.getline(shipLine, 50);

        //Checks (in order): shipping code ok, is space, is a place you can send from, is space, is place you can send to not same as sent from, is space, is a float.
        //All must be true or the whole line is ignored. If ignored and not end of file, start at the top (^) of the loop again.
        if(correctCode(shipLine[0])==true &&
           isSpace(shipLine[1])==true &&
           correctSend(shipLine[2])==true &&
           isSpace(shipLine[3])==true &&
           (correctSend(shipLine[4])==true && (shipLine[2] != shipLine[4]))&&
           isSpace(shipLine[5])==true &&
           floaty(&shipLine[6])==true)

            {
                //turns the character array group of characters into a real, workable float named weighty.
                float weighty;
                weighty = atof(&shipLine[6]);

                //Common sense tells us, while a float can be negative, all objects must have mass.
                // If weighty turns out to be equal or less than zero, that's an error.
                if(weighty <= 0)
                    weighty = -1;

                //matches to a from planet code, and if weight is not errored, calculates the cost and time then adds to the total from that planet.
                //In order from closest to sun to farthest. All following ifs/else ifs do same above comment.
                if (shipLine[2] == 'Y' && !(weighty == -1))
                {
                    mercuryTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    mercuryTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'V'&& !(weighty == -1))
                {
                    venusTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    venusTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'E'&& !(weighty == -1))
                {
                    earthTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    earthTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'M'&& !(weighty == -1))
                {
                    marsTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    marsTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'J'&& !(weighty == -1))
                {
                    jupiterTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    jupiterTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'S'&& !(weighty == -1))
                {
                    saturnTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    saturnTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'U'&& !(weighty == -1))
                {
                    uranusTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    uranusTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
                else if (shipLine[2] == 'N'&& !(weighty == -1))
                {
                    neptuneTotal += shippingCost(shipLine[4], shipLine[2], shipLine[0], weighty);
                    neptuneTime +=travelTime(shipLine[4], shipLine[2], shipLine[0]);
                }
            }
    }
    while(!(inFile.eof()));

    //Close up the file and output tabbed table. Nothing fancy, but it aligns.
	inFile.close();
	cout<<"Planet:\t\t" << "Cost shipping from:\t" << "Total Time for deliveries from:" <<"\n";
    cout<<"Mercury\t\t" << mercuryTotal <<"\t\t\t" << mercuryTime <<"\n";
    cout<<"Venus\t\t" << venusTotal <<"\t\t\t" << venusTime <<"\n";
    cout<<"Earth\t\t" << earthTotal <<"\t\t\t" << earthTime <<"\n";
    cout<<"Mars\t\t" << marsTotal <<"\t\t\t" << marsTime <<"\n";
    cout<<"Jupiter\t\t" << jupiterTotal <<"\t\t\t" << jupiterTime <<"\n";
    cout<<"Saturn\t\t" << saturnTotal <<"\t\t\t" << saturnTime <<"\n";
    cout<<"Uranus\t\t" << uranusTotal <<"\t\t\t" << uranusTime <<"\n";
    cout<<"Neptune\t\t"  << neptuneTotal <<"\t\t\t" << neptuneTime <<"\n";

    return 0;
}
//Checks service code to make sure is uppercase and it's an existing code. Returns true if so.
bool correctCode(char shipLine)
{
    if(isupper(shipLine)&& (shipLine == 'F'||shipLine=='P'||shipLine=='E'))
        return true;
    else
        return false;
}

//checks to find if it is a space, not any other whitespace character. Returns true if so.
bool isSpace(char shipLine)
{
    if(isspace(shipLine) && !(shipLine == '\v' || shipLine == '\n' || shipLine == '\t'))
        return true;
    else
        return false;
}
//checks both ingoing and outgoing code to make sure they're a match for real codes. Returns true if so.
bool correctSend(char shipLine)
{
    if(isupper(shipLine)&& (shipLine == 'Y'||shipLine=='V'||shipLine=='E'||shipLine=='M'||shipLine=='J'||shipLine=='S'||shipLine=='U'||shipLine=='N'))
        return true;
    else
        return false;
}

//checks if the number supplied to it is good. Returns true if so.
bool floaty(char shipLine[])
{
    //flag, incrementer in loop, and counter.
    bool hasDecimal = false;
    int i = 0, c=0;

    //checks to see if it starts with a negative sign, if so, that's fine. If it starts with something else, not float.
    if (shipLine[0] != '-' && !(isdigit(shipLine[0])))
            return false;

    //Goes through float looking for decimals, if it finds one, increases the counter.
    while (shipLine[i] != '\0')
    {
        if(!(isdigit(shipLine[i])))
            if(shipLine[i] =='.')
            {
                hasDecimal = true;
                c++;
            }
        i++;
    }
    //If it has a decimal and there's only one, it's a float (return true). If not, it's something else (return false).
    if(hasDecimal ==true && c == 1)
        return true;
    else
        return false;
}

//calculates the shipping cost when the package arrives on the planet based off weight and service code.
double shippingCost(char shippingCodeTo, char shippingCodeFrom, char serviceCode, float weight)
{
    //the gravities of the planets.
    double meGrav= .27, veGrav = .86, eaGrav =1, maGrav = .37, juGrav =1.64, saGrav = 1.17, urGrav =.92, neGrav = 1.44;
    double cost;
        //set service code costs
		if (serviceCode == 'F')
			cost = .25;
		else if (serviceCode =='P')
			cost = .75;
		else if (serviceCode =='E')
			cost = 1.50;

	//Set cost when arriving based on (weigh * planet gravity) * cost of service. Returns arrival (final) cost. Should it somehow fail, returns 0.
		switch(shippingCodeTo)
		{
		case 'Y':
			    return ((weight* meGrav)* cost);
			    break;
		case 'V':
			    return ((weight*veGrav)* cost);
			    break;
		case 'E':
			    return ((weight*eaGrav)* cost);
			    break;
		case 'M':
			    return ((weight*maGrav)* cost);
			    break;
		case 'J':
			    return ((weight*juGrav)* cost);
			    break;
		case 'S':
			    return ((weight*saGrav)* cost);
			    break;
		case 'U':
			    return ((weight*urGrav)* cost);
			    break;
		case 'N':
			    return ((weight*neGrav)* cost);
			    break;
        default:
                return 0;
                break;
        }

}

//adds the total time it took to get there at the speed which it was ordered by.
double travelTime(char shippingCodeTo, char shippingCodeFrom, char serviceCode)
{
	int speed;
    //Sets the speed based on the code.
	switch(serviceCode)
        {
            case 'F':
                speed = 45000;
                break;
            case 'P':
                speed = 95000;
                break;
            case'E':
                speed = 175000;
                break;
            default:
                return 0;
                break;
        }
        //returns absolute value of (distance from - distance to) / speed. This will be time (hrs) to arrive.
        return abs((setDist(shippingCodeFrom)-setDist(shippingCodeTo))/speed);
}

//just returns the distance of the planet from the sun.
double setDist(char planet)
{
        //Selects the planet and returns distance from sun. Should it fail somehow, returns 0.
		switch(planet)
		{
		case 'Y':
			    return 36000000;
			    break;
		case 'V':
			    return 67000000;
			    break;
		case 'E':
			    return 93000000;
			    break;
		case 'M':
			    return 141000000;
			    break;
		case 'J':
			    return 483000000;
			    break;
		case 'S':
			    return 886000000;
			    break;
		case 'U':
			    return 1782000000;
			    break;
		case 'N':
			    return 2793000000;
			    break;
        default:
            return 0;
            break;
        }
}
