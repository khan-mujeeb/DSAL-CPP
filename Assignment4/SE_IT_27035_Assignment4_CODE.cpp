/*   ASSIGNMENT 4
    name : Mujeeb ur rahman khan
      Roll no: 27035
      Class : SE IT B 
    
Problem Statement:- Construct an Expression Tree from postfix and prefix expression. Perform recursive and non- recursive In-order, pre-order and post-order traversals
*/


#include <iostream>
#include <stack>
#include <string.h>
using namespace std;


struct node
{
    char data;
    node *leftchild;
    node *rightchild;
}*root;

    node *store_root_address;
    
    node *construct_prefix_tree(char prefix[]);
    node *construct_postfix_tree(char posfix[]);
    void recursive_nonrecursive_choice();
    void expression_choice();


    void recursive_inorder(node*root);
    void recursive_preorder(node*root);
    void recursive_postorder(node*root);
    
    void nonrecursive_inorder(node *root);
    void nonrecursive_preorder(node *root);
    void nonrecursive_postorder(node *root);



 
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }

    return false;
}
 

 
node* newNode(char v)
{
    node *temp = new node;
    temp->leftchild = NULL;
    temp->rightchild = NULL;
    temp->data = v;
    return temp;
};
 

node* construct_postfix_tree(char postfix[])
{
    stack<node *> s;
    node *root, *t1, *t2;

    for (int i=0; i<strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            root=newNode(postfix[i]);
            s.push(root);
        }

        else 
        {
            root= newNode(postfix[i]);
 
            t1 = s.top(); 
            s.pop();
            t2 = s.top();
            s.pop();
 
            root->rightchild = t1;
            root->leftchild = t2;
 
            s.push(root);
        }
    }
 
    root= s.top();
    s.pop();
 
    return root;
}


node* construct_prefix_tree(char prefix[])
{
    stack<node *> s;
    node *root, *t1, *t2;

    for (int i=0; i<strlen(prefix); i++)
    {
        if (!isOperator(prefix[i]))
        {
            root= newNode(prefix[i]);
            s.push(root);
        }

        else 
        {
            root= newNode(prefix[i]);
 
            t1 = s.top(); 
            s.pop(); 
            t2 = s.top();
            s.pop();
 
            root->leftchild = t1;
            root->rightchild = t2;
 
            s.push(root);
        }
    }

    root = s.top();
    s.pop();
 
    return root;
}




void recursive_inorder(node*root)
{
    node*temp;
    temp=root;
    if(temp!=NULL)
    {
        recursive_inorder(temp->leftchild);
        cout<<" "<<temp->data;
        recursive_inorder(temp->rightchild);
    }
    
}


void recursive_preorder(node*root)
{
    node*temp;
    temp=root;
    if(temp!=NULL)
    {
        cout<<" "<<temp->data;
        recursive_preorder(temp->leftchild);
        recursive_preorder(temp->rightchild);
    }
    
}


void recursive_postorder(node*root)
{
    node*temp;
    temp=root;
    if(temp!=NULL)
    {
        recursive_postorder(temp->leftchild);
        recursive_postorder(temp->rightchild);
        cout<<" "<<temp->data;
    }
    
   
}


void nonrecursive_inorder(node *root) 
{ 

    stack<node *> s; 

    node *current_node = root; 

  

    while (current_node != NULL || s.empty() == false) 

    { 

        while (current_node!= NULL) 

        { 
            s.push(current_node); 

            current_node=current_node->leftchild; 

        } 

        current_node= s.top(); 

        s.pop(); 
        cout<<current_node->data;
         
        current_node=current_node->rightchild; 
    }
}



void nonrecursive_preorder(node *root)
{
    stack<node *>s;
    s.push(root);
    if (root == NULL)
    {
        return;
    }
 
    while (s.empty()==false)
    {
        node *temp=s.top();
        s.pop();
        cout<<" "<<temp->data;

        if (temp->rightchild)
        {
            s.push(temp->rightchild);
        }

        if (temp->leftchild)
        {
        
            s.push(temp->leftchild);
        }
    }

}

void nonrecursive_postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }

    stack<node *>s1;
    stack<node *> s2;
    s1.push(root);
    node *temp;

    while(s1.empty()==false)
    {
        temp=s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->leftchild)
        {
            s1.push(temp->leftchild);
        }

        if(temp->rightchild)
        {
            s1.push(temp->rightchild);
        }
    }

    
    while(!s2.empty())
    {
        temp=s2.top();
        s2.pop();
        cout<<" "<<temp->data;

    }
    
}
 
 
int main()
{
    int k =0;
    int choice, choice_R, choice_NR;
    node *root_address;
    char reverse[100],prefix[100],postfix[100];
    
    node *construct_prefix_tree(char prefix[]);
    node *construct_postfix_tree(char posfix[]);
    void recursive_non_recursive_choice();
    void expression_choice();

    void recursive_inorder(node*root);
    void recursive_preorder(node*root);
    void recursive_postorder(node*root);
    
    void nonrecursive_inorder(node *root);
    void nonrecursive_preorder(node *root);
    void nonrecursive_postorder(node *root);
        
        do
        {
        cout<<"\n";
        cout<<"**********************************************";
        cout<<"\n From which expression you want to construct binary expression tree?\n";
        cout<<"\n 1) Prefix Expression. \n 2) Postfix Expression. \n 3) Exit.";
        cout<<"\n**********************************************";
        cout<<"\n Enter Your Choice: ";
        cin>>choice;
        cout<<"...............................................";
            switch(choice)
            {
                case 1:
                   //ACCEPTING PREFIX EXPRESSION
                    cout<<"\nEnter Prefix Expression: ";
                    cin>>prefix;
                    
                    for(int j=strlen(prefix)-1;j>=0;j--)
                    reverse[k++]=prefix[j];
                    reverse[k]='\0';
                    //cout<<reverse;
                    root_address=construct_prefix_tree(reverse);
                    
                    cout<<"\nIn which manner you want to traverse the binary expression tree?";
                    cout<<"\n1) Recursively. \n2) Non-Recursively. \n3) Exit.";
                    cout<<"\nEnter Your Choice:  ";
                    cin>>choice_R;
                    switch(choice_R)
                    {
                        case 1:
                                //RECURSIVE FUNCTIONS ON PREFIX    
                                cout<<"\nRecursive preorder is: ";
                                recursive_preorder(root_address);
                               
                                cout<<"\nRecursive inorder is: ";
                                recursive_inorder(root_address);
                                
                                cout<<"\nRecursive postorder is: ";
                                recursive_postorder(root_address);
                                
                                break;
                            
                            
                        case 2:
                                //NON RECURSIVE FUNCTIONS ON PREFIX
                    
                                cout<<"\n\nNon-Recursive preorder is: ";
                                nonrecursive_preorder(root_address);
                                
                                cout<<"\nNon-Recursive inorder is: ";
                                nonrecursive_inorder(root_address);        
                                
                                cout<<"\nNon-Recursive postorder is: ";
                                nonrecursive_postorder(root_address);
                                break;
                                
                        case 3:
                                cout<<"You Have Successfully Exitted.....";
                                break;
                            
                        default:
                                cout<<"INVALID CHOICE.....";
                        
                    }
                        break;
    
                case 2:
                    cout<<"\nEnter Postfix Expression: ";
                    cin>>postfix;
                    root_address=construct_postfix_tree(postfix);
                                       cout<<"\nIn which manner you want to traverse the binary expression tree?";
                    cout<<"1) Recursively. \n2) Non-Recursively. \n3) Exit.";
                    cout<<"\nEnter Your Choice:  ";
                    cin>>choice_R;
                    switch(choice_R)
                    {
                        case 1:
                                //RECURSIVE FUNCTIONS ON PREFIX    
                                cout<<"\nRecursive preorder is: ";
                                recursive_preorder(root_address);
                               
                                cout<<"\nRecursive inorder is: ";
                                recursive_inorder(root_address);
                                
                                cout<<"\nRecursive postorder is: ";
                                recursive_postorder(root_address);
                                
                                break;
                            
                            
                        case 2:
                                //NON RECURSIVE FUNCTIONS ON PREFIX
                    
                                cout<<"\n\nNon-Recursive preorder is: ";
                                nonrecursive_preorder(root_address);
                                
                                cout<<"\nNon-Recursive inorder is: ";
                                nonrecursive_inorder(root_address);        
                                
                                cout<<"\nNon-Recursive postorder is: ";
                                nonrecursive_postorder(root_address);
                                break;
                                
                        case 3:
                                cout<<"You Have Successfully Exitted.....";
                                break;
                            
                        default:
                                cout<<"INVALID CHOICE.....";
                        
                    }
            }
        }
        while(choice!=3);
    return 0;       
}
