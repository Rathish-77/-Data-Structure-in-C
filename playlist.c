//playlist using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
	char  data[100];
	struct Node* next;
};
struct Node *head=NULL;

struct Node *createNode(char data[]) {
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
	strcpy(newNode->data,data);
	newNode->next=NULL;
	return newNode;
}
struct Node *insert(char data[]) {
	struct Node* newNode=createNode(data);
	newNode->next=head;
	head=newNode;
	printf("%s added to playlist",data);

}

void display() {
	if(head==NULL) {
		printf("No Songs in the playlist..\n");
		return;
	}
	struct Node *temp=head;
	while(temp!=NULL) {
		printf("%s>>",temp->data);
		temp=temp->next;
	}
}
int main() {
	int  choice;
	char data[100];
	while(1) {
		printf("1.ADD\n2.DISPLAY\n3.Exit\nEnter u r choice:");
		scanf("%d",&choice);
		getchar();
		switch(choice) {
		case 1:
			printf("Enter song name:");
			fgets(data,sizeof(data),stdin);
			data[strcspn(data,"\n")]=0;
			insert(data);
			break;
		case 2:
			display();
			break;
		case 3:
			printf("Exiting");
			exit(0);
		default:
			printf("enter u r valid choice\n");
		}
	}
}
