#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class List
{
	Node* START;
public:
	List();
	void addNode();
	bool search(int nim, Node** current, Node** previous);
	bool ListEmpty();
	bool delNode(int element);
	void traverse();
};

List::List()
{
	START = NULL;
}

void List::addNode()/*Menambah sebuah Node kedalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukkan Nomor Mahasiswa: ";
	cin >> nim;
	cout << "\Masukkan Nama: ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if ((START == NULL || nim <= START->noMhs))
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* previous, * current;

	current = START;
	previous = START;


	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDupikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;
		current = current ->next;

	}
	/*jika loop diatas dieksekusi, previous dan current akan menempati posisi dimana*/
	nodeBaru->next = current;
	previous->next = nodeBaru;
}
