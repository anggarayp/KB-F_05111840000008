#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <stack>
using namespace std;

class State{ 
public:
	int a[9];
	
	State(){
		for(int i=0; i<9; i++){
				a[i] = rand() % 9;
				while (found(i)) { a[i] = rand() % 9; } 
		}
	}
	
	void print(){
		cout << "-----------------" << endl;
		for(int i=0; i<9; i++){
			if (i>0 && i%3==0) cout << endl;
			cout << a[i] << "\t";
		}
		cout << endl << "-----------------" << endl;
	}
	
	int found(int i){
		for(int j=0; j<i; j++){
			if (a[i]==a[j]) return 1;
		}
		return 0;
	}
	
	int findzero(){
		for (int i=0; i<9; i++){
			if (a[i]==0) return i;
		}
	}
	
	State exch(int i, int j){
		State b;
		for (int k=0; k<9; k++)
			b.a[k]=a[k];
		int t=b.a[i];
		b.a[i]=b.a[j];
		b.a[j]=t;
		return b;
	}

	int equal(State s){
		for(int i=0; i<9; i++){
			if (a[i]!=s.a[i]) return 0;
		}
		return 1;
	}
	
	int goal(){
		int g[9] = {1,2,3,8,0,4,7,6,5};
		for (int i=0; i<9; i++){
			if (a[i]!=g[i]) return 0; 
		}
		return 1;
	}
	
};

class Node{
public:
	State s;
	Node *father;
	int action, cost, depth;
	
	Node(){
		State s();
		father=NULL;
		action=-1;
		cost=1;
		depth=0;
	}
	
	Node(State _s, Node *_father, int _action, int _depth){
		s=_s;
		father=_father;
		action=_action;
		depth=_depth;
	}
	
	Node copy(){
		Node b;
		for (int i=0; i<9; i++)
			b.s.a[i]=s.a[i];		
		b.father=father;
		b.action=action;
		b.depth=depth;
		
		return b;
	}
	
	void print(){
		cout << "Cost: \t" << cost << endl;
		cout << "Depth: \t" << depth << endl;
	}
	
	void expand(deque<Node> *deque){
		int p = s.findzero();
		//moveup	(0)
		if ((p!=0 && p!=1 && p!=2) && action!=1){
			Node n(s.exch(p,p-3), this, 0, depth+1);
			(*deque).push_back(n);
		}
		//movedown 	(1)
		if ((p!=6 && p!=7 && p!=8) && action!=0){
			Node n(s.exch(p,p+3), this, 1, depth+1);
			(*deque).push_back(n);
		}
		//moveright (2)
		if ((p!=2 && p!=5 && p!=8) && action!=3){
			Node n(s.exch(p,p+1), this, 2, depth+1);
			(*deque).push_back(n);
		}
		//moveleft 	(3)
		if ((p!=0 && p!=3 && p!=6) && action!=2){
			Node n(s.exch(p,p-1), this, 3, depth+1);
			(*deque).push_back(n);
		}
	}
	
	int expanded(deque<State> *deque){
		int max=(*deque).size()>depth?depth:(*deque).size();
		for (int i=0; i<max; i++){
			if ( s.equal( (*deque)[i] ) ){
				return 1;
			}
		}
		return 0;
	}

	int dfs(int idsdepth){
		deque<Node> toexpand;
		
		if (idsdepth==-1) idsdepth = sizeof(int);
		
		toexpand.push_back(*this);
		while ( !toexpand.empty() ){
				if (toexpand.back().depth < idsdepth){
					if ( toexpand.back().s.goal()==1 ){ 
						if (idsdepth != sizeof(int))  
							cout << "------|IDS|------" << endl;
						cout << "Solution found!" << endl;
						toexpand.back().print();
						toexpand.clear();
						return cost;
					}
					else{
						Node t;
						t= toexpand.back().copy();
						toexpand.pop_back();
						t.expand(&toexpand);
					}
				}
				else return 0;
		}
		if ( toexpand.empty() ) cout << endl << "Solution NOT found!" << endl;
		return 0;
	}
	
	int ids(){
		for(int i=0;;i++){
			int t = dfs(i);
			if (t!=0) return t; 
		}
	}
};

int main(int argc, char *argv[]){
	int num=1;
	int idscost=0;
	int idsfail=0;

	cout << "\nEnter number of problems to solve: ";
	cin >> num;
    cout << endl;
	
	if (argc == 2){
		cout << "-------DEMO------\n\n";
	}
	
	for(int i=0;i<num;i++){
		int _ids=0;		
		
		cout << "\n    Problem " << i+1 << endl;
		srand(argc==2?(2*i+1):time(NULL)+i);
        Node n;
		n.s.print();
		
		_ids=n.ids();
		
		if (_ids>0) 
			idscost+=_ids;
		else
			idsfail+=1;
	}
	if (num > 1){
		cout << "\n\n------|IDS|-------";
		cout << "\nAverage cost = " << idscost/(num-idsfail);
		cout << "\nSolved " << num-idsfail << "/" << num;
		cout << "\n------------------";
		cout << endl;
	}
	return 0;
}
