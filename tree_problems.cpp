#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
//------------------------------------------------------------------------------------------//
typedef struct node* Node;
int identical(Node root1,Node root2){
	if(root1==NULL && root2 == NULL)
		return 1;
	if((root1 && root2)&& (root1->data==root2->data) && identical(root1->left,root2->left) && identical(root1->right,root2->right)){
		return 1;
	}else{
		return 0;
	}
}

//------------------------------------------------------------------------------------------//
int identical_iterative(Node root1,Node root2){
	if(root1==NULL && root2=NULL)
		return 1;
	if(root1==NULL)
		return 0;
	if(root2==NULL)
		return 0;
	stack<pair<Node,Node> > s;
	s.push(make_pair(root1,root2));
	while(s.empty()){
		Node x = s.top().first;
		Node y = s.top().second;
		s.pop();
		if(x->data!=y->data)
			return 0;
		if(x->left && y->left)
			s.push(make_pair(x->left,y->left));
		else if(x->left || y->left)
			return 0;
		if(x->right && y->right)
			s.push(x->right,y->right);
		else if(x->right || y->right)
			return 0;
	}
	return 1;
}

//------------------------------------------------------------------------------------------//
int height(Node root){
 	if(root==NULL)
 		return 0;
 	int h1 = height(root->left)+1;
 	int h2 = height(root->right)+1;
 	if(h1>h2)
 		return h1;
 	return h2;
}

//------------------------------------------------------------------------------------------//
int height_iterative(Node root){
	if(root==NULL)
		return 0;
	queue<Node> q;
	q.push(root);
	int height = 0;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			Node front = q.front();
			q.pop_front();
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
		}
		height+=1;
	}
	return height;
}

//------------------------------------------------------------------------------------------//
void deletebt(Node root){
	if(root==NULL)
		return;
	deletebt(root->left);
	deletebt(root ->right);
	delete root;
}
//iterative is almost same as height function

//------------------------------------------------------------------------------------------//
void deletebt_iterative(Node root){
	if(root==NULL)
		return;
	stack<Node> s;
	s.push(root);
	while(!s.empty()){
		root = s.top();
		s.pop();
		if(root->left)
			s.push(root->left);
		if(root->right)
			s.push(root->right);
		delete root;
	}
	root = NULL;
}

//------------------------------------------------------------------------------------------//
void inorder(Node root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data; // can be a visit() function
	inorder(root->right);
} 

//------------------------------------------------------------------------------------------//
void inorder_iterative(Node root){
	if(root==NULL)
		return;
	stack<Node> s;
	s.push(root);
	while(!s.empty() || root!=NULL){
		if(root!=NULL){
			s.push(root);
			root = root->left;
		}
		else{
			root = s.top();
			cout<<root->data;
			root = root->right;
		}

	}
}

//------------------------------------------------------------------------------------------//
void preorder(Node root){
	if(root==NULL)
		return;
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}

//------------------------------------------------------------------------------------------//
void preorder_iterative(Node root){
	if(root==NULL)
		return;
	stack<Node> s;
	s.push(root);
	while(!s.empty()){
		root = s.top();
		s.pop();
		cout<<root->data;
		if(root->left)
			s.push(root->left);
		if(root->right)
			s.push(root->right);
	}
}

//------------------------------------------------------------------------------------------//
void postorder(Node root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data; 
}
// this can be easily implemented with two stacks

//------------------------------------------------------------------------------------------//
void postorder_iterative_2stack(Node root){
	if(root==NULL)
		return;
	stack<Node> s;
	stack<int> data;
	s.push(root);
	while(!s.empty()){
		root = s.top();
		s.pop();
		data.push(root->data);
		if(root->left)
			s.push(root->left);
		if(root->right)
			s.push(root->right);
	}
	while(!data.empty()){
		cout<<data.top();
		data.pop();
	}
}

//------------------------------------------------------------------------------------------//
void level_order(Node root){
	if(root==NULL)
		return;
	queue<Node> q;
	q.push(root);
	while(!q.empty()){
		size = q.size();
		root = q.front();
		cout<<root->data;
		q.pop();
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	} 
}

//------------------------------------------------------------------------------------------//
int spiral(Node root,int level){
	if(root==NULL)
		return 0;
	if(level==1)
		cout<<root->data;
		return 1;
	if(level%2==0){
		int a = spiral(root->left,level-1);
		int b = spiral(root->right,level-1);
		return a||b;
	}
	else{
		int a = spiral(root->right,level-1);
		int b = spiral(root->left,level-1);
		return a||b;
	}
}
void print_spiral(Node root){
	if(root==NULL)
		return;
	int level = 1;
	while(spiral(root,level)){
		level++;
	}
}


//------------------------------------------------------------------------------------------//
void spiral_iterative(Node root){
	if(root==NULL)
		return;
	queue<int> q;
	q.push(root);
	int dir = 0;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			if(dir==0){
				root = q.front();
				q.pop_front();
				cout<<root->data;
				if(root->left)
					q.push_back(root->left);
				if(root->right)
					q.push_back(root->right);
			}else{
				root = q.back();
				q.pop_back();
				cout<<root->data;
				if(root->left)
					q.push_front(root->right);
				if(root->right)
					q.push_front(root->left);
			}
		}
		dir = !dir;
	}
}
//------------------------------------------------------------------------------------------//
void reverselevel_order(Node tree){
	if(root==NULL)
		return;
	queue<Node> q;
	stack<int> out;
	q.push(root);
	while(!q.empty()){
		root = q.front();
		q.pop();
		out.push(root->data);
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	while(!out.empty()){
		cout<<out.top();
		out.pop();
	}
}