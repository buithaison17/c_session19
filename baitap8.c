#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
void sortByName(struct Students sv[]){
	for(int i = 0; i < 5; i++){
		int index = i;
		for(int j = i; j < 5; j++){
			if(sv[index].fullName[0] < sv[j].fullName[0]){
				index = j;
			}
		}
		struct Students temp = sv[i];
		sv[i] = sv[index];
		sv[index] = temp;
	}
	printf("Thong tin sinh vien truoc sau sap xep\n\n");
	for(int i = 0; i < 5; i++){
		printf("%d, %s, %d, %s\n\n", sv[i].id, sv[i].fullName, sv[i].age, sv[i].phoneNumber);
	}
}
int main(){
	struct Students sv[5] = {
		{1, "Aon", 18, "032"},
		{2, "Bon", 17, "132"},
		{3, "Con", 18, "932"},
		{4, "Don", 20, "072"},
		{5, "Eon", 21, "099"}
	};
	printf("Thong tin sinh vien truoc khi sap xep\n\n");
	for(int i = 0; i < 5; i++){
		printf("%d, %s, %d, %s\n\n", sv[i].id, sv[i].fullName, sv[i].age, sv[i].phoneNumber);
	}
	sortByName(sv);
	return 0;
}

