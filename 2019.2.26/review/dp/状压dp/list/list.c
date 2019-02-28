#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node
{
	int id,age;
	node* next;
};
void insertList(node* first,int index,node value);
void printfList(node* first);

int main()
{

	node* data;
	data->next = NULL;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		int a,b;
		scanf("%d %d",&a, &b);
		node temp ;
		temp.id = a;
		temp.age = b;
		insertList(data,i,temp);
	}
	printfList(data);





	return 0;
}
void insertList(node* first,int index,node value)
{
	node* key = first;
	int i = 1;
	while(i <= index)
	{
		key = key->next;
	}
	node* temp = new node();
	temp->id = value.id;
	temp->age = value.age;
	temp->next = key->next;
	key->next = temp->next;
}
void printfList(node* first)
{
	node* temp = first->next;
	while(temp != NULL)
	{
		printf("%d %d\n",temp->id,temp->age);
		temp = temp->next;
	}
}
