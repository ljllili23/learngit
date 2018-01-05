//binaryTree_20180104_.cpp
#include <stdio.h>
#include <string>

struct Node{
	Node *lchild;
	Node *rchild;
	char c;
}Tree[50];

int loc;

Node *creat(){									// means create a Tree node; namely choose one from Tree[50] array;
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

char str1[30],str2[30];

void postOrder(Node *T){   						//postorder traversal function;
	if(T->lchild!=NULL){
		postOrder(T->lchild);
	}
	if(T->rchild!=NULL){
		postOrder(T->rchild);
	}
	printf("%c",T->c);
}
												//build a binary tree according to preorder sequence and infix order 
												//sequence.
Node *build(int s1, int e1, int s2, int e2){  
	Node* ret=creat();
	ret->c=str1[s1];
	int rootIdx;								//find the index of the root node in infix order sequence;
	for(int i=s2;i<=e2;++i){
		if(str2[i]==str1[s1]){
			rootIdx=i;
			break;
		}
	}

	if(rootIdx!=s2){							//means the root node has its left subtree;
		ret->lchild=build(s1+1,s1+(rootIdx-s2),s2,rootIdx-1);
	}
	if(rootIdx!=e2){
		ret->rchild=build(s1+(rootIdx-s2)+1,e1,rootIdx+1,e2);
	}
	return ret;

}

int main(){
	while(scanf("%s",str1)!=EOF){
		scanf("%s", str2);
		loc=0;
		int L1=strlen(str1);
		int L2=strlen(str2);
		Node *T = build(0,L1-1,0,L2-1);
		postOrder(T);
		printf("\n");
	}
	return 0;
}