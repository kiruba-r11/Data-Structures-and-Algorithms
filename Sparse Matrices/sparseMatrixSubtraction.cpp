#include<bits/stdc++.h>

using namespace std;

/*

Time Complexity: O(R*C), R -> No. of rows, C -> No. of columns 
Space Complexity: O(R*C), R -> No. of rows, C -> No. of columns

*/

//Class definition of Each Node
class Node
{
public:
	int data;
	int column_no;
	int row_no;
	Node* nextr;
	Node* nextc;
};

//Method to create a Node with given data
Node* createNode(int r,int c,int value)
{
	Node* node=new Node();
	node->data=value;
	node->column_no=c;
	node->row_no=r;
	node->nextr=NULL;
	node->nextc=NULL;
	return node;
}

//Method to initialize the head Nodes
void prepend(Node** head,Node* node)
{
	if(*head==NULL)
	{
		*head=node;
		return;
	}
	return;
}

//Method to print a single row
void printr(Node* head)
{
	Node *node=head->nextr;
	while(node!=NULL)
	{
		printf("%d %d %d|",node->data,node->row_no,node->column_no);
		node=node->nextr;
	}
	printf("\n");
}

//Method to print a single column
void printc(Node* head)
{
	Node *node=head->nextc;
	while(node!=NULL)
	{
		printf("%d %d %d|",node->data,node->row_no,node->column_no);
		node=node->nextc;
	}
	printf("\n");
}

//Method to insert an element in a given Row_Head
void Rowinsert(Node** head,Node* node)
{
	Node *last=(*head)->nextr;
	Node *prev=*head;
	while(last!=NULL)
	{
		if(last->column_no > node->column_no)
		{
			node->nextr=last;
			prev->nextr=node;
			return;
		}
		prev=last;
		last=last->nextr;
	}
	prev->nextr=node;
	return;
}

//Method to insert an element in a given Column_Head
void Colinsert(Node** head,Node* node)
{
	Node *last=(*head)->nextc;
	Node *prev=*head;
	while(last!=NULL)
	{
		if(last->row_no > node->row_no)
		{
			node->nextc=last;
			prev->nextc=node;
			return;
		}
		prev=last;
		last=last->nextc;
	}
	prev->nextc=node;
	return;
}

//Method to subtract elements in a similar rows of two sparse matrix
//And to also link with column headers
void subtractrow(Node** sumr,vector<Node*> &sumc,Node* a,Node* b)
{
	Node* p=a->nextr;
	Node* q=b->nextr;
	Node* r=*sumr;
	while(p!=NULL && q!=NULL)
	{
		if(p->column_no==q->column_no)
		{
			Node* temp = createNode(p->row_no,p->column_no,p->data-q->data);
			if(temp->data!=0)
			{
				r->nextr=temp;
				r=r->nextr;
				Colinsert(&sumc[p->column_no-1],temp);
			}
			p=p->nextr;
			q=q->nextr;
		}
		else if(p->column_no>q->column_no)
		{
			Node* temp = createNode(p->row_no,q->column_no,-1*q->data);
			r->nextr=temp;
			r=r->nextr;
			Colinsert(&sumc[q->column_no-1],temp);
			q=q->nextr;
		}
		else
		{
			Node* temp = createNode(p->row_no,p->column_no,p->data);
			r->nextr=temp;
			Colinsert(&sumc[p->column_no-1],temp);
			r=r->nextr;
			p=p->nextr;
		}
	}
	if(p==NULL&&q!=NULL)
	{
		while(q!=NULL)
		{
			Node* temp = createNode(q->row_no,q->column_no,-1*q->data);
			r->nextr=temp;
			Colinsert(&sumc[q->column_no-1],temp);
			q=q->nextr;
			r=temp;
		}
	}
	else if(q==NULL&&p!=NULL)
	{
		while(p!=NULL)
		{
			Node* temp = createNode(p->row_no,p->column_no,p->data);
			r->nextr=temp;
			Colinsert(&sumc[p->column_no-1],temp);
			p=p->nextr;
			r=temp;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int r,c;
	cin>>r>>c;

	//Declaring Headers of all Sparse Matrix
	vector<Node*> Arow_head(r,NULL);
	vector<Node*> Acol_head(c,NULL);
	vector<Node*> Brow_head(r,NULL);
	vector<Node*> Bcol_head(c,NULL);
	vector<Node*> Srow_head(r,NULL);
	vector<Node*> Scol_head(c,NULL);

	//Initializing Row Headers of all Sparse Matrix
	for(int i=0;i<r;i++)
	{
		Node *node = createNode(i+1,0,0);
		prepend(&Arow_head[i],node);
		Node *nodx = createNode(i+1,0,0);
		prepend(&Brow_head[i],nodx);
		Node *nody = createNode(i+1,0,0);
		prepend(&Srow_head[i],nody);
	}
	//Initializing Column Headers of all Sparse Matrix
	for(int i=0;i<c;i++)
	{
		Node *node = createNode(i+1,0,0);
		prepend(&Acol_head[i],node);
		Node *nodx = createNode(i+1,0,0);
		prepend(&Bcol_head[i],nodx);
		Node *nody = createNode(i+1,0,0);
		prepend(&Scol_head[i],nody);
	}

	//Input Matrix 1
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int num;
			cin>>num;
			if(num!=0)
			{
				Node *node = createNode(i+1,j+1,num);
				Rowinsert(&Arow_head[i],node);
				Colinsert(&Acol_head[j],node);
			}
		}
	}
	/*for(int i=0;i<r;i++)
	{
		printr(Arow_head[i]);
	}
	for(int i=0;i<c;i++)
	{
		printc(Acol_head[i]);
	}*/

	//Input Matrix 2
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int num;
			cin>>num;
			if(num!=0)
			{
				Node *node = createNode(i+1,j+1,num);
				Rowinsert(&Brow_head[i],node);
				Colinsert(&Bcol_head[j],node);
			}
		}
	}

	//Subtract with respect to Rows
	for(int i=0;i<r;i++)
	{
		subtractrow(&Srow_head[i],Scol_head,Arow_head[i],Brow_head[i]);
	}
	/*for(int i=0;i<r;i++)
	{
		printr(Brow_head[i]);
	}
	for(int i=0;i<c;i++)
	{
		printc(Bcol_head[i]);
	}*/

	//Printing the subtracted Sparse Matrices
	for(int i=0;i<r;i++)
	{
		printr(Srow_head[i]);
	}
	for(int i=0;i<c;i++)
	{
		printc(Scol_head[i]);
	}
	return 0;
}
