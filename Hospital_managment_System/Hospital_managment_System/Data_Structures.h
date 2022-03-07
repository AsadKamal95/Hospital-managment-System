#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<time.h>
#include<cstdlib>
#include<iomanip>
#define size 26
using namespace std;

class node {
public:
	string data;
	string disease;
	string medicine;
	node* next;

	node() :next(NULL) {}
};

class Node {
public:
	Node* child[size];
	bool wordEnd;
	Node() {
		for (int i = 0; i < size; i++) {
			child[i] = NULL;
		}
		wordEnd = false;
	}
};

class tries {
	Node* root;

public:
	tries() {
		root = createNode();
	}
	Node* createNode() {
		Node* newNode;
		newNode = new Node;
		return newNode;
	}

	void add_medicine() {
		string yourtext;
		ifstream ReadFile("search2.0.txt");
		while (getline(ReadFile, yourtext)) {
			insert(yourtext);
		}
	}

	void insert(string word) {

		word = to_Lower(word);
		int len = word.length();
		int index = 0;;
		Node* temp = root;
		if (temp == NULL) {
			return;
		}
		for (int i = 0; i < len; i++) {
			index = word[i] - (int)'a';
			if (!(temp->child[index])) {
				temp->child[index] = createNode();
			}
			temp = temp->child[index];
		}
		temp->wordEnd = true;
	}

	string to_Lower(string word) {
		for (int i = 0; i < word.length(); i++) {
			word[i] = tolower(word[i]);
		}
		return word;
	}

	bool search(string word) {
		word = to_Lower(word);
		int len = word.length();
		int index;
		Node* temp = root;
		for (int i = 0; i < len; i++) {
			index = word[i] - 'a';
			if (!temp->child[index])
				return false;

			temp = temp->child[index];
		}
		if (temp->wordEnd)
			return true;
		else
			return false;
	}

};

class linked_list {
public:
	void push(node** head_ref, string new_data, string new_disease = "", string new_medicine = "") {
		node* new_node = new node();
		new_node->data = new_data;
		new_node->disease = new_disease;
		new_node->medicine = new_medicine;
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	void pop(node** head_ref) {
		node* current = *head_ref;
		node* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			delete(current);
			current = next;
		}
		*head_ref = NULL;
	}
	void append(node** head_ref, string new_data, string new_disease, string new_medicine) {
		node* new_node = *head_ref;
		node* temp = *head_ref;
		new_node->next = NULL;
		new_node->data = new_data;
		new_node->medicine = new_medicine;
		new_node->disease = new_disease;

		if (*head_ref == NULL) {
			*head_ref = new_node;
			return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}

	int count(node** head, string search_for)
	{
		node* current = *head;
		int count = 0;
		while (current != NULL) {
			if (current->data == search_for)
				count++;
			current = current->next;
		}
		return count;
	}

	void print_viral(node* x, int j) {
		cout << "\n" << x->data << " is viral this month!" << endl;
	}

	void print(node* n) {
		cout << "NAME\t" << "\t    DISEASE\t" << "\t\t  MEDICINE\t\n" << endl;
		while (n != NULL) {
			cout << left;
			cout << setw(20) << n->data << setw(30) << n->disease << setw(25) << n->medicine << "\n";
			n = n->next;

		}
	}

	void find_medicine(node* head) {
		tries obj;
		obj.add_medicine();
		bool found;
		while (head != NULL) {
			//cout << <<endl;
			found = obj.search(head->medicine);
			if (found == true) {
				cout << head->medicine << " found" << endl;
			}
			else {
				cout << head->medicine << " NOT FOUND" << endl;
			}
			head = head->next;
		}
	}
};

class queue {
public:
	int count = 0;
	void clear(node** head_ref) {

		(*head_ref) = NULL;
	}
	void enqueue(node** head_ref, string new_data) {

		node* new_node = new node();
		new_node->data = new_data;
		if (*head_ref == NULL) {
			*head_ref = new_node;
			new_node->next = NULL;
			return;
		}
		new_node->next = *head_ref;
		*head_ref = new_node;
	}

	string dequeue(node** head_ref) {
		string temp_data;
		node* temp = *head_ref;
		node* prev = *head_ref;
		if (temp == NULL) {
			return "";
		}
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == (*head_ref)) {
			*(head_ref) = NULL;
			return temp->data;
		}
		prev->next = NULL;
		temp_data = temp->data;

		delete(temp);
		return temp_data;
	}

	void print(node* n) {
		while (n != NULL) {
			cout << " " << n->data << "  " << endl;
			n = n->next;
		}
	}
};