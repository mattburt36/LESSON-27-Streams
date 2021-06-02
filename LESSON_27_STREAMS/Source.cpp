/*STREAMS_1_DISPLAYING_INTEGER_IN_DECIMAL_OCTAL_HEXADECIMAL_FORMATS*/
/*#include <iostream> 
#include <iomanip> 
using namespace std; 

int main()
{
	cout << "Enter an integer: ";
	int input = 0;
	cin >> input; 

	cout << "Integer in octal: " << oct << input << "\n";
	cout << "Integer in hexadecimal: " << hex << input << "\n"; 

	cout << "Integer in hex using base notation: "; 
	cout << setiosflags(ios_base::hex | ios_base::showbase | ios_base::uppercase);
	cout << input << "\n"; 

	cout << "Integer after resetting I/O flags: "; 
	cout << resetiosflags(ios_base::hex | ios_base::showbase | ios_base::uppercase);
	cout << input << "\n"; 

	return 0; 
}*/

/*STREAMS_2_FIXED-POINT_SCIENTIFIC_NOTATIONS*/
/*#include <iostream>
#include <iomanip> 
using namespace std; 

int main()
{
	const double Pi = (double)22.0 / 7;
	cout << "Pi = " << Pi << "\n";

	cout << "\n" << "Setting precision to 7: " << "\n"; 
	cout << setprecision(7);
	cout << "Pi = " << Pi << "\n"; 
	cout << fixed << "Fixed Pi = " << Pi << "\n"; 

	cout << "\n" << "Setting precision to 10: " << "\n"; 
	cout << setprecision(10);
	cout << "Pi = " << Pi << "\n"; 
	cout << fixed << "Fixed Pi + " << Pi << "\n";
	cout << scientific << "Scientific Pi = " << Pi << "\n"; 

	cout << "\n" << "Enter a radius: ";
	double radius = 0.0;
	cin >> radius;
	cout << "Area of circle: " << 2 * Pi * radius * radius << "\n"; 

	return 0; 
}*/

/*STREAMS_3_SET_WIDTH_SET_FILL_MANIPULATORS*/
/*#include <iostream>
#include <iomanip>
using namespace std; 

int main()
{
	cout << "Hey - default!" << "\n";

	cout << setw(35); // set field width to 25 columns
	cout << "Hey - right aligned!" << "\n"; 

	cout << setw(35) << setfill('*');
	cout << "Hey - right aligned!" << "\n";

	cout << "Hey - back to default!" << "\n"; 

	return 0;
}*/

/*STREAMS_4_CIN_TO_INT_FLOATING-POINT_TO_DOUBLE_THREE_LETTERS_TO_CHAR*/
/*#include <iostream> 
using namespace std; 

int main()
{
	cout << "Enter an integer: ";
	int inputNum = 0; 
	cin >> inputNum;

	cout << "Enter the value of Pi: ";
	double Pi = 0.0;
	cin >> Pi;

	cout << "Enter three characters seperated by space: " << "\n"; 
	char char1 = '\0', char2 = '\0', char3 = '\0';
	cin >> char1 >> char2 >> char3;

	cout << "The recorded variable values are: " << "\n"; 
	cout << "inputNum: " << inputNum << "\n"; 
	cout << "Pi: " << Pi << "\n"; 
	cout << "The three character : " << char1 << char2 << char3 << "\n"; 

	return 0; 
}*/

/*STREAMS_5_CHAR_BUFFER_BOUNDS*/
/*#include <iostream>
#include <string> 
using namespace std; 

int main()
{
	cout << "Enter a line: " << "\n"; 
	char charBuf[10] = { 0 }; 
	cin.get(charBuf, 9);
	cout << "charBuf: " << charBuf << "\n"; 

	return 0; 
}*/

/*STREAMS_6_TEXT_TO_STRING_USING_CIN*/
/*#include <iostream> 
#include <string> 
using namespace std; 

int main()
{
	cout << "Enter your name: "; 
	string name;
	cin >> name;
	cout << "Hi " << name << "\n"; 

	return 0; 
}*/
/*if you wish to include a whole name with spaces included (first and last) replace "cin >> name;" with "getline(cin, name);*/

/*STREAMS_7_NEW_FILE_WRITING_TEXT_TO_FILE_OPEN_OPERATOR<<_OFSTREAM*/
/*#include <fstream> 
#include <iostream>
using namespace std; 

int main()
{
	ofstream myFile;
	myFile.open("HelloFile.txt", ios_base::out);

	if (myFile.is_open())
	{
		cout << "File open successful" << "\n";

		myFile << "My first text file!" << "\n";
		myFile << "Hello file!";

		cout << "Finished writing to file, will close now" << "\n";
		myFile.close();
	}

	return 0;
}*/

/*STREAMS_8_FILE_READING_TEXT_FILE_OPEN_OPERATOR>>_OFSTREAM*/
/*#include <fstream> 
#include <iostream> 
#include <string> 
using namespace std; 

int main()
{
	ifstream myFile;
	myFile.open("HelloFile.txt", ios_base::in);

	if (myFile.is_open())
	{
		cout << "File open successful. It contains: " << "\n";
		string fileContents;

		while (myFile.good())
		{
			getline(myFile, fileContents);
			cout << fileContents << "\n";
		}

		cout << "Finished reading file, will close now" << "\n";
		myFile.close();
	}
	else
		cout << "open() failed: check if file is in right folder" << "\n";

	return 0;
}*/

/*STREAMS_9_STRUCT_TO_BINARY_THEN_RECONSTRUCTING*/
/*#include <fstream>
#include <iomanip> 
#include <string> 
#include <iostream>
using namespace std; 

struct Human
{
	Human() {};
	Human(const char* inName, int inAge, const char* inDOB) : age(inAge)
	{
		strcpy(name, inName);
		strcpy(DOB, inDOB);
	}

	char name[30];
	int age;
	char DOB[20];
};

int main()
{
	Human Input("Matthew Burton", 23, "April 1997");

	ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);

	if (fsOut.is_open())
	{
		cout << "Writing one object of human to a binary file" << "\n";
		fsOut.write(reinterpret_cast<const char*>(&Input), sizeof(Input));
		fsOut.close();
	}

	ifstream fsIn("MyBinary.bin", ios_base::in | ios_base::binary);

	if (fsIn.is_open())
	{
		Human somePerson;
		fsIn.read((char*)&somePerson, sizeof(somePerson));

		cout << "Reading information from binary file: " << "\n";
		cout << "Name = " << somePerson.name << "\n";
		cout << "Age = " << somePerson.age << "\n";
		cout << "Date of birth = " << somePerson.DOB << "\n";
	}

	return 0;
}*/

/*STREAMS_10_INT_TO_STRING_STRING_TO_INT*/
/*#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter an integer: ";
	int input = 0;
	cin >> input;

	stringstream converterStream;
	converterStream << input; 
	string inputAsStr;
	converterStream >> inputAsStr;

	cout << "Integer Input = " << input << "\n"; 
	cout << "String gained from integer = " << inputAsStr << "\n"; 

	stringstream anotherStream; 
	anotherStream << inputAsStr;
	int Copy = 0;
	anotherStream >> Copy; 

	cout << "Integer gained from string, Copy = " << Copy << "\n"; 

	return 0; 
}*/

