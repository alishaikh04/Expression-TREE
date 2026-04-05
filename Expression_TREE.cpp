#include <iostream>
using namespace std;


struct ETNode
{
    char data;
    ETNode* left;
    ETNode* right;
};

ETNode* root = NULL;

int precedence (char ch)
{
    switch (ch)
    {
    case '*':
    case '/':
    case '%':
     return 5;

    case '+':
    case '-':
     return 4;

    case '=':
    case '<':
    case '>':
     return 3; 

    case '&':
     return 2;
    
    case '|':
     return 1; 
    
    default:
     return 0;
    }
}

bool isOperator (char exp)
{
    return (exp == '*' || exp == '%' || exp == '/' || exp == '+' || exp == '-' ||
            exp == '>' || exp == '<' || exp == '=' || exp == '&' || exp == '|' );
}

ETNode* insertData (ETNode* current, char data)
{

    if (current == NULL)
    {
    ETNode* temp = new ETNode();    
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (current == NULL)
    {
        current = temp;
    }
    return temp;
    }
     if (isOperator(data) && isOperator(current->data))
    {
        if (precedence(data) <= precedence(current->data))
        {
            current->left = insertData (current->left, data);
        }
        else 
        {
            current->right = insertData (current->right, data);
        }
    }
    else if (data < current->data)
    {
      current->left = insertData (current->left, data);   
    }
    else 
    {
        current->right = insertData (current->right, data);
    }
    
    return current;
}

ETNode* searchData (ETNode* current, char data)
{
    if (current == NULL)
    {
        cout << "Value Not Found in Tree. " << endl;
        return NULL;
    }

    if (current->data == data)
    {
        cout << "Value Found..." << endl;
        return current;
    }
    else if (current->data > data)
    {
        return searchData (current->left, data);
    }
    else 
    {
        return searchData (current->right, data);
    }
}

ETNode* deleteData (ETNode* current, char data)
{
    if (current == NULL)
    {
        cout << "Tree is Empty. " << endl;
        return NULL;
    }

    if (current->data == data)
    {
        if (current->left == NULL && current->right == NULL)
        {
            delete current;
            cout << "Deleted Successfully. " << endl;
            return NULL;
        }
        if (current->left == NULL)
        {
            ETNode* temp = current->right;
            delete current;
            cout << "Deleted Successfully. " << endl;
            return temp;
        }
        if (current->right == NULL)
        {
            ETNode* temp = current->left;
            delete current;
            cout << "Deleted Successfully. " << endl;
            return temp;
        }
        if (current->left != NULL && current->right != NULL)
        {
            ETNode* temp = current->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            current->data = temp->data;
            current->right = deleteData (current->right, temp->data);
        }
    }

    else if (current->data > data)
    {
        current->left = deleteData (current->left, data);
    }
    else
    {
        current->right = deleteData (current->right, data);
    }

    return current;
}


void preorder (ETNode* current)
{
   if (current != NULL)
   {
     cout << current->data << " ";
     preorder (current->left);
     preorder (current->right);
   }
}

void postOrder (ETNode* current)
{
    if (current != NULL)
    {
        postOrder (current->left);
        postOrder (current->right);
        cout << current->data << " ";
    }
}

void inorder (ETNode* current)
{
    if (current != NULL)
    {
        inorder (current->left);
        cout << current->data << " ";
        inorder (current->right);
    }
}

int main () 
{
    int choice;
    char data;
    
    while (true)
    {
        cout << endl;
        cout <<  "1. Insert." << endl;
        cout <<  "2. Search." << endl;
        cout <<  "3. Delete.. " << endl;
        cout <<  "4  PreOrder." << endl;
        cout <<  "5. PostOrder." << endl;
        cout <<  "6. Inorder. " << endl;
        cout <<  "7. Exit." << endl << endl;
      
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Data : ";
            cin >> data;
           root = insertData (root, data); 
        }
        else if (choice == 2)
        {
         cout << "Enter Data : ";
            cin >> data;
            searchData (root, data);
        }
        else if (choice == 3)
        {
             cout << "Enter Data : ";
            cin >> data;
         root = deleteData (root, data);
        }
        else if (choice == 4)
        {
           preorder (root);
        }
        else if (choice == 5)
        {
            postOrder (root);
        }
        else if (choice == 6)
        {
            inorder (root);
        }
        else if (choice == 7)
        {
            cout << "Exit Successfully." << endl;
            break;
        }
        else 
        {
            cout << "Enter Correct Choice ! " << endl;  
        }
    }
    return 0;
}



