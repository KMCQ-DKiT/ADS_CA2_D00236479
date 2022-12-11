// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Car.h"
#include "Date.h"
#include "TNode.h"
#include "BinaryTree.h"
#include "Utilities.h"
#include "Data.h"
#include "KeyData.h"
using namespace std;

void PrintData();
void PrintDataKey();
void HashMethod();

//void Input();

int main()
{
	cout << endl << "PrintKey()..........." << endl;
	PrintDataKey();
    cout << endl << "PrintData()..........." << endl;
    PrintData();
    cout << endl << "HashMethod()..........." << endl;
    HashMethod();


    //Printing Subtree of Binary Tree
    BinaryTree<int, int> tree;
    TNode<int, int>* root = new TNode<int, int>(5, 5);
    root->setLeft(new TNode<int, int>(4, 4));
    root->setRight(new TNode<int, int>(10, 10));
    root->getLeft()->setLeft(new TNode<int, int>(3, 3));
    root->getLeft()->setRight(new TNode<int, int>(7, 7));
    root->getLeft()->getLeft()->setLeft(new TNode<int, int>(2, 2));
    root->getLeft()->getRight()->setRight(new TNode<int, int>(15, 15));

    cout << "before: " << endl;
    printBT(root);
    TNode<int, int>* new_root = tree.SubTree(root, 7);
    cout << "after: " << endl;
    printBT(new_root);

	//return 0;
}

template<typename K, typename E>
void Input()
{
	
	BinaryTree<KeyData, Data> tree;
	string fileName = "data/data_1000.csv";
	vector<vector<string>> allData = readDelimitedRows(fileName);


	for (vector<string> row : allData)
	{
		for (int i = 0; i <= 5; i++) {

			/*KeyData SKey = new KeyData(row[0], row[2], row[6]);
			Data SData = new Data(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14]);*/
		
			tree.add(Car(row[0],[1]));


			/*tree.printInOrder(KeyData(row[0], row[2], row[6]), Data(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14]));*/
			cout << "Hello" << endl;
		}
	}
}

void PrintDataKey()
{
	string fileName = "data/data_1000.csv";

	vector<vector<string>> allData = readDelimitedRows(fileName);

	for (vector<string> row : allData)
	{
		string user_id = row[0];
		string first_name = row[2];
		string email = row[6];

		for (int i = 0; i <= 0; i++) {


			cout << row[0] << ", " << row[2] << ", " << row[6] << endl;

			
		}
	}
}

void PrintData()
{
    string fileName = "data/data_1000.csv";

    vector<vector<string>> allData = readDelimitedRows(fileName);

    for (vector<string> row : allData)
    {

        for (int i = 0; i <= 0; i++) {


            cout << row[0] << ", " << row[1] << ", " << row[2] << row[3] << ", " << row[4] << ", " << row[5] << ", " << row[6] << ", " << row[7] << ", " << row[8]
                << ", " << row[9] << ", " << row[10] << ", " << row[11] << ", " << row[12] << ", " << row[13] << ", " << row[14] << ", " << endl;

           
        }
    }
}
void HashMethod()
{
    string fileName = "data/data_1000.csv";

    vector<vector<string>> allData = readDelimitedRows(fileName);

    for (vector<string> row : allData) {

        hash<string> hasherStr;
        string user_id_hash = row[0];
        cout << "IDhash [" << user_id_hash << "] " << endl;

        string first_name_hash = row[2];
        cout << "Namehash [" << first_name_hash << "] " << endl;

        string email_hash = row[6];
        cout << "Emailhash [" << email_hash << "] " << endl;

        size_t GamerHash = hasherStr(user_id_hash + first_name_hash + email_hash);
        cout << "Unique Key [" << GamerHash << "] " << endl << endl;
    }
}