#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node ()
    {

    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        cout<<"deleted for value "<<data<<" !"<<endl;
    }
};

void athead(node *&head, int d)
{
    if (head == NULL)
    {
        node *newnode = new node(d);
        head = newnode;
    }
    else
    {
        node *newnode = new node(d);
        newnode->next = head;
        head = newnode;
    }
}

void attail(node *&head, int d)
{
    if (head == NULL)
    {
        athead(head, d);
    }

    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *newnode = new node(d);
        temp->next = newnode;
    }
}

void print(node *head)
{
    if (head == NULL)
        cout << "List is Empty!" << endl;
    else
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

void length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    cout << "Length = " << cnt << endl;
}

void atx(node *&head, int d, int pos)
{
    if (pos == 1)
    {
        athead(head, d);
    }
    else
    {
        int i = 1;
        node *temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        node *newnode = new node(d);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deletehead(node *&head)
{
    node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
void deletetail(node *&head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* nodedel=temp->next;
    temp->next=NULL;
    delete nodedel;
}

int main()
{
    node *head = NULL;
    print(head);

    athead(head, 3);
    athead(head, 2);
    athead(head, 1);
    print(head);
    attail(head, 4);
    attail(head, 5);
    attail(head, 6);
    print(head);
    length(head);
    atx(head, 8, 7);
    print(head);
    
    deletehead(head);
    print(head);
    deletetail(head);
    print(head);

    return 0;
}