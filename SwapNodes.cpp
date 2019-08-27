
struct node
{    int data;         
    struct node *next;
} * head;
void create(int n);
int  count(struct node *list);
int  swap(struct node *list, int pos1, int pos2);
void display();
int main()
{
    int n, pos1, pos2;
    cout<<"Enter number of node to create: ";
    cin>>n;
    create(n);
    cout<<"\n\nData in list before swapping: \n";
    displayList();
    cout<<"\nEnter first node position to swap: ";
    cin>>pos1;
    cout<<"\nEnter second node position to swap: ";
    cin>>pos2;

    if (swap(head, pos1, pos2) == 1)
    {
        cout<<"\nData swapped successfully.\n";
        cout<<”Data in list after swapping”<<pos1<<”node with”<<pos2<<”: \n”;
        displayList();
    }
    else 
    {
        cout<<"Invalid position, please enter position greater than 0 and less than nodes in list.\n";
    }

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = malloc(sizeof(struct node))
    if (head == NULL)
    {
        cout<<"Unable to allocate memory. Exiting from app.";
        exit(0);
    }
    cout<<"Enter data of node 1: ";
    cin>>data;
    head->data = data;
    head->next = NULL;
    temp = head;
    for (i = 2; i <= n; i++)
{
        newNode = malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            cout<<"Unable to allocate memory.";
            exit(0);
        }

        cout<<"Enter data of node”<<i;
        cin>>data;

        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode; 
        temp = temp->next;
int count(struct node *list)
{
    int nodes = 0;

    while (list != NULL) 
    {
        nodes++;
        list = list->next;
    }

    return nodes;
}

int swap(struct node *list, int pos1, int pos2)
{
    struct node *node1, *node2, *prev1, *prev2, *temp;
    int i;
    const int maxPos = (pos1 > pos2) ? pos1 : pos2;
    const int totalNodes = count(list);
    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
    {
        return -1;
    }
     if (pos1 == pos2)
    {
        return 1;
    }
    i = 1;
    temp  = list;
    prev1 = NULL;
    prev2 = NULL;
    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;
        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }
    if (node1 != NULL && node2 != NULL)
    {
        if (prev1 != NULL)
            prev1->next = node2;
        if (prev2 != NULL)
            prev2->next = node1;
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

   return 1;
}

