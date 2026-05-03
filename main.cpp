// Project 7 - Requirements & Solution :
#include <iostream>
#include "clsMyString.h"
using namespace std;


int main() {

	cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

	clsMyString S1;

	cout << "\nS1 = " << S1.Value << endl;
	
	S1.Value = "Mohammed";
	cout << "S1 = " << S1.Value << endl;

	S1.Value = "Mohammed2";
	cout << "S1 = " << S1.Value << endl;

	S1.Value = "Mohammed3";
	cout << "S1 = " << S1.Value << endl;

	cout << "\n\nUndo : ";
	cout << "\n------------------------\n";

	S1.Undo();
	cout << "\nS1 After Undo = " << S1.Value << endl;

	S1.Undo();
	cout << "\nS1 After Undo = " << S1.Value << endl;

	S1.Undo();
	cout << "\nS1 After Undo = " << S1.Value << endl;

	cout << "\n\nRedo : ";
	cout << "\n------------------------\n";

	S1.Redo();
	cout << "\nS1 After Redo = " << S1.Value << endl;

	S1.Redo();
	cout << "\nS1 After Redo = " << S1.Value << endl;

	S1.Redo();
	cout << "\nS1 After Redo = " << S1.Value << endl;




	system("pause>0");
	return 0;
}
