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

int main()
{






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
