#include<iostream>
#include<stack>
#include<cstdio>
#include<list>
#include<string>
#include<malloc.h>
#include<limits>
using namespace std;

/* reference links
	http://codereview.stackexchange.com/questions/33195/stack-implementation-using-linked-list
	
	https://www.youtube.com/watch?v=5_6nsViVM00
	http://stackoverflow.com/questions/6947653/problem-understanding-how-recursion-applies-to-towers-of-hanoi
	
    move n−1 discs from A to B. This leaves disc n alone on peg A
    move disc n from A to C
    move n−1 discs from B to C so they sit on disc n

*/

class Node {
	public:
		int data;
		Node *next;
};


class MyStack {
	protected:
		string varName;
		int size;
		Node *top=NULL;

	public:
		MyStack(string s) {varName=s; size=0;} /* constructor, dibantu oleh teman kami Evans */
		~MyStack();
		string getName() {return varName;}
		int getVal() {return top->data;}
		int getSize() {return size;}
		void push(int);
		void pop();
		void removeAll();
};

MyStack::~MyStack() {

}

void MyStack::push(int n) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = n;

	if(top==NULL) newNode->next = NULL;
	else newNode->next = top;

	top = newNode;
	size = size+1;

}

void MyStack::pop() {
	if(top!=NULL) {
		Node *temp = (Node*) malloc(sizeof(Node));
		temp = top;
		top = temp->next;
		free(temp);
		size = size-1;

	}

}

void MyStack::removeAll() {
	if(size>0) {
		for(int i=MyStack::size;i>0;i--) {
			MyStack::pop();
		}
	}
}

void teamHeader() {
	cout << "Tugas 1 ALGORITMA DAN STRUKTUR DATA" << endl
		 << "Oleh:" << endl
		 << "- Ervina Wijaya    1400910005" << endl
		 << "- Fajar Febriyan   1400910001" << endl
		 << "- Handy Tantyo     1400910037" << endl
		 << "-------------------------------------------" << endl;

}

void hanoiHeader() {
	cout << "Selamat datang di program Tower of Hanoi" << endl
		 << "-------------------------------------------" << endl;
}

void hanoi(int n, MyStack *beg, MyStack *aux, MyStack *end) {
	if(n>0) {
		hanoi(n-1,beg,end,aux);
		
		cout << "Move " << beg->getVal() << " from " << beg->getName() << " to " << end->getName() << endl;
		end->push(beg->getVal());
		beg->pop();

		hanoi(n-1,aux,beg,end);

	}
}


int main() {
	MyStack A("A"), B("B"), C("C");
	int t;
	char c;
	
	teamHeader();
	hanoiHeader();
	
	
	while(true) {

		for(;;){

			while (cout << "Masukkan berapa disk untuk tumpukan?\n" && !(cin >> t))
			{
				cout << "Input Error. Try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if(cin.good() && t>2){
				break;

			} else{
				cout << "Input Error. Try again." << endl;

			}


		}

		for(int i=t;i>0;i--) {
			A.push(i);

		}

		hanoi(t,&A,&B,&C);

	//	C.removeAll();
	
		for(int i=C.getSize();i>1;i--) {
			C.pop();
			
		}
		
		cout << C.getVal() << endl << C.getSize();
		
		cout << "\nCoba lagi? Tekan X untuk keluar dari program" << endl;
		cin >> c;
		if(toupper(c)=='X') break;	
	//	if(toupper(getch())=='X') break;
	
	}

	return 0;
}
