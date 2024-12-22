#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
void deleteStudents(struct Students sv[], int id){
	int found = 0;
	for(int i = 0; i < 5; i++){
		if(sv[i].id == id){
			found = 1;
			for(int j = i; j < 5; j++){
				sv[i] = sv[i+1];
			}
		}
	}
	if(found == 0){
		printf("\nID khong ton tai\n\n");
	}
	else{
		printf("\nThong tin sinh vien sau khi xoa\n\n");
		for(int i = 0; i < 4; i++){
		printf("%d, %s, %d, %s\n\n", sv[i].id, sv[i].fullName, sv[i].age, sv[i].phoneNumber);
		}
	}
}
int main(){
	struct Students sv[5] = {
		{1, "Son", 18, "032"},
		{2, "Non", 17, "132"},
		{3, "Mon", 18, "932"},
		{4, "Kon", 20, "072"},
		{5, "Yon", 21, "099"}
	};
	printf("Thong tin sinh vien truoc khi xoa\n\n");
	for(int i = 0; i < 5; i++){
		printf("%d, %s, %d, %s\n\n", sv[i].id, sv[i].fullName, sv[i].age, sv[i].phoneNumber);
	}
	int id;
	printf("Nhap ID xoa: ");
	scanf("%d", &id);
	deleteStudents(sv, id);
	return 0;
}

