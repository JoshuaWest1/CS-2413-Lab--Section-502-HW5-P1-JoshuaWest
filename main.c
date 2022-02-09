/*
AUTHOR: Joshua Wade West
HW #: HW5 Problem 1
FOR: CS 2413 Lab- Section 502
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TREEstruct//struct decleration of Treestruct
{
int data;//varaibel to store data
struct TREEstruct *left;//used to move left
struct TREEstruct *right;//used to move right
};
typedef struct TREEstruct Node;
Node *node;//name node


int loop,jump,mess;//used for output

Node* Add_Nodes(Node *node, int data);//prototype function call for Add_Nodes

Node* Search(Node *node, int data);//prototype function call for Search

Node* Lowest(Node *node);//prototype function call for Lowest

Node* Delete(Node *node, int data);//prototype function call for Delete

int Height(Node* root);//prototype function call for Height

void LOTravel(Node* root, int branch);//prototype function call for LOTravel

void print(Node* root);//prototype function call for print

void randomizer(int *arr,int n);//prototype function call for randomizer



int main(void){
int data, Choice, i, n, is=0,arr[999];//varibale for menu, while, and random

Node *root=NULL;//set root to null

while (is==0)//while loop for menu
{
printf("\n\nEnter the number to select the option: ");
printf("\n1.Create Tree");
printf("\n2.Search Item");
printf("\n3.Delete Item");
printf("\n4.Print Tree");
printf("\n0.END\n");

scanf("%d", &Choice);//get users choice

switch (Choice)
{

case 1: printf("\nEnter the Number of Nodes you want: " );//if 1, enter the numbr of nodes
scanf("%d", &n);//store users node number

for(i=0; i<n; i++){arr[i]=i;}//for length of nodes, input a value into array

randomizer(arr,n);//randomizr values in array

for(i=0; i<n; i++)//for lenth of nodes
{
data = arr[i];//store array value sinto data
root=Add_Nodes(root, data);//get size of tree and store as root
}
break;


case 2: printf("\nEnter Node Number to search: ");
scanf("%d", &data);//store value of wanted search node
root=Search(root, data);//function call to search
break;


case 3: printf("\nEnter Node Number to delete: ");
scanf("%d", &data);//store value of wanted delete node
root=Delete(root, data);//function call to delete
break;


case 4: printf("\nPrint tree: \n");
loop = 7;//reset to loop to 7
jump=1;//reset jump to 1
mess=7;//reset mess to 7

print(root);//function call to print tree
break;


case 0: is++;//end the while loop
break;
default:printf("\nERROR! Choose again");//if enter worng, error

break;
}}

return 0;
}//END OF MAIN






Node* Add_Nodes(Node *node, int data){//Add function

if (node == NULL)//if the node is NULL
{
Node *temp;//temp is a pointer

temp= (Node*)malloc(sizeof(Node));//temp ia the size of node

temp->data = data;//store temp into data

temp->left = temp->right = NULL;//branches equal null

return temp;
}//END OF IF

if (data < (node->data)){node->left = Add_Nodes(node->left, data);}//if next data is larger, add left node

else if (data > node->data){node -> right = Add_Nodes(node->right, data);}//if former data is larger, add right node

return node;
}//END OF ADD NODES


Node* Search(Node *node, int data){//search function

if(node == NULL){printf("\nThe item is not found.");}//if Null, warn user

else if(data < node->data){node->left=Search(node->left, data);}//if next is greater, search left

else if(data > node->data){node->right=Search(node->right, data);}//if former is greater, search right

else{printf("\nThe item %d has been found.", node->data);}//when ==, out put

return node;
}//END OF SEARCH



Node* Lowest(Node *node){//Lowest function

if(node==NULL){return NULL;}//if null, return null

if(node->left){return Lowest(node->left);}//if left, go left

else//else return node
return node;
}//END OF LOWEST



Node* Delete(Node *node, int data){//delete function
Node *temp;//pointer temp

if(node == NULL){printf("\nThe Item Is Not Found.");}//if null, output 

else if(data < node->data){node->left = Delete(node->left, data);}//if next is greater, delete left

else if(data > node->data){node->right = Delete(node->right, data);}//if former is greater, delete right

//the node can now be deleted
else
{ if(node->right && node->left)//if values in left and right sub-trees
{ 
temp = Lowest(node->right);//store the lowest value in the right subtree
node -> data = temp->data;//replace the value
node -> right = Delete(node->right,temp->data);//delete old node
}

else
{
temp = node;//temp storage
if(node->left == NULL)//if null in left subtree
node = node->right;//pull from right

else if(node->right == NULL)//if null in right subtree
node = node->left;//pull from left
free(temp);//empty temp
}}

return node;
}//END OF DELETE




int Height(Node* root){

if (root == NULL){return 0;}//if null, height is zero

int LeftST = Height(root->left);//leftST is height of all left nodes

int RightST = Height(root->right);//rightST is height of all right nodes

if (LeftST> RightST){return(LeftST + 1);}//if left is greater than right, return left+1

return(RightST+ 1);//else return right+1

}//END OF HEIGHT


void LOTravel(Node* root, int branch){

if (root == NULL) {return;}//if Null, end

if (branch == 1) {printf("%d ",root->data );//if first root, input root into data and output

if(jump == 1){printf("\n");}//end for 1

if(jump == 3){printf("\n");}//end for 3

if(jump==loop)//if loop is the same as jump
{
if(loop == mess){loop=(loop*2)+1;mess=mess*2+1;}//is loop is the same as mess, mulitply loop by 2 and add 1, multiply mess by 2 and add one

else{loop=loop*2;};  //else double loop and end line
printf("\n");
}

jump++;//increase jump by one
}


else if (branch > 1)//if to high of a branch
{  
LOTravel(root->left, branch-1);//move down left
    
LOTravel(root->right, branch-1);//move down right
}

}//END OF LOTRAVEL


void print(Node* root){

for (int i = 1; i <= Height(root); i++){//for the height of the tree
   LOTravel(root, i);//travel through tree
   }
}//END OF PRINT

void randomizer(int *arr,int n){

for (int i = 0; i < n; i++) {//for the number of nodes
    int temp = arr[i];//store array temp

    int randomIndex = rand() % n;//fill with numbers below node count

    arr[i]= arr[randomIndex];//re insert into array

    arr[randomIndex] = temp;//store temp
}
}//END OF RANDOMIZER