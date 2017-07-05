#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;
#define uInt unsigned int

int  main( int, char** );
void tryRow( string, uInt );
void testPasswd ( string );


char g_cPossibleCharacters [] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                  'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
                                  'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                  'Y', 'Z', '!', '"', '$', '%', '&', '/', '(', '=',
                                  '?', '.', ':', ',', ';'
                                };

int main ( int argc, char* argv[] )
{
    string  phantomPasswd;
    uInt    maxCharters   = 1;
    double time1         = 0.0;
    double tstart		  = 0.0;

	cout<< "Please enter the maximum of characters:" << endl;
	cin>> maxCharters;

    tstart = clock();

    phantomPasswd.resize( maxCharters, 32 );

    for( uInt pos = 0; pos < maxCharters; pos++ )
    {
       tryRow( phantomPasswd, pos ); // startet Rekursion
    }
    // zur berechnung der dauer
    time1 += clock() - tstart;
    time1 = time1 / CLOCKS_PER_SEC;
    cout<< "Time needed "  << time1 << endl;

    return 0;
}

void tryRow( string sPhantomPassword, uInt nPosition )
{
    for( uInt nIdx = 0 ; nIdx < sizeof( g_cPossibleCharacters ); nIdx++ )
    {
        sPhantomPassword[ nPosition ] = g_cPossibleCharacters[ nIdx ];

        testPasswd( sPhantomPassword ); // testet das Passwort

        if( nPosition > 0 )
		{
			tryRow( sPhantomPassword, nPosition - 1 );
		}
    }
}

void testPasswd( string sPasswd )
{
    /*=================================================================
     * Das Testpasswort
     *===============================================================*/
    string testString = "test";

    if (sPasswd == testString)
    {
		cout<< "Password found! " + sPasswd << endl;
		exit( 0 );
    }

    /*=================================================================
     * folgende Zeile auskommentieren um fortschritt anzuzeigen
     * geht jedoch zu lasten der Performance
     *===============================================================*/

    //cout<< sPasswd << endl;
}

