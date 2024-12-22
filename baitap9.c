#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Students{
	int id;
	char fullName[50];
	int age;
	char phoneNumber[12];
};
void addStudents(struct Students *sv, int *sizePtr){
	printf("\nNhap ID: ");
	scanf("%d", &sv[(*sizePtr) - 1].id);
	fflush(stdin);
	printf("Nhap ten: ");
	fgets(sv[(*sizePtr) - 1].fullName, 50, stdin);
	sv[(*sizePtr) -1].fullName[strlen(sv[(*sizePtr) -1].fullName) - 1] = '\0';
	printf("Nhap tuoi: ");
	scanf("%d", &sv[(*sizePtr) - 1].age);
	fflush(stdin);
	printf("Nhap so dien thoai: ");
	fgets(sv[(*sizePtr) - 1].phoneNumber, 12, stdin);
	sv[(*sizePtr) - 1].phoneNumber[strlen(sv[(*sizePtr) - 1].phoneNumber) - 1] = '\0';
	printf("\n");
}
void printStudents(struct Students *sv, int *sizePtr){
	printf("\nThong tinh sinh vien\n");
	printf("--------------------\n");
		for(int i = 0; i < *sizePtr; i++){
			printf("ID: %d", sv[i].id);
			printf("\nHo ten: %s", sv[i].fullName);
			printf("\nTuoi: %d", sv[i].age);
			printf("\nSo dien thoai: %s", sv[i].phoneNumber);
			printf("\n--------------------\n");
		}
	printf("\n");
}
void editStudents(struct Students *sv, int *sizePtr){
	int id, found = 0;
	printf("\nNhap ID sinh vien: ");
	scanf("%d", &id);
	fflush(stdin);
	for(int i = 0; i < *sizePtr; i++){
		if(id == sv[i].id){
			found = 1;
			printf("\nNhap ten: ");
			fgets(sv[i].fullName, 50, stdin);
			sv[i].fullName[strlen(sv[i].fullName) - 1] = '\0';
			printf("\nNhap tuoi: ");
			scanf("%d", &sv[i].age);
			fflush(stdin);
			printf("\nNhap so dien thoai: ");
			fgets(sv[i].phoneNumber, 12, stdin);
			sv[i].phoneNumber[strlen(sv[i].phoneNumber) - 1] = '\0';
		}
	}
	if(found == 0){
		printf("\nID sinh vien khong ton tai\n\n");
	}
}
void deleteStudents(struct Students *sv, int *sizePtr){
	int id, found = 0;
	printf("\nNhap ID sinh vien muon xoa: ");
	scanf("%d", &id);
	for(int i = 0; i < *sizePtr; i++){
		if(id == sv[i].id){
			found = 1;
			for(int j = i; j < *sizePtr; j++){
				sv[j] = sv[j+1];
			}
		}
	}
	if(found == 0){
		printf("\nID khong ton tai\n\n");
	}
	else{
		(*sizePtr)--;
		sv = realloc(sv, *sizePtr * sizeof(struct Students));
		printf("\nXoa thanh cong\n\n");
	}
}
void searchByName(struct Students *sv, int *sizePtr){
	char *name;
	int found = 0;
	name = (char *)calloc(50, sizeof(char));
	printf("\nNhap ten sinh vien: ");
	fflush(stdin);
	fgets(name, 50, stdin);
	name[strlen(name) - 1] = '\0';
	for(int i = 0; i < *sizePtr; i++){
		if(strstr(sv[i].fullName, name) != NULL){
			printf("\nID: %d", sv[i].id);
			printf("\nHo ten: %s", sv[i].fullName);
			printf("\nTuoi: %d", sv[i].age);
			printf("\nSo dien thoai: %s", sv[i].phoneNumber);
			printf("\n\n");
			found = 1;
		}
	}
	if(found == 0){
		printf("\nTen sinh vien hoac ID khong hop le \n\n");
	}
	free(name);
}
void SortByName(struct Students *sv, int *sizePtr){
	for(int i = 0; i < *sizePtr - 1; i++){
		for(int j = 0; j < *sizePtr - i - 1; j++){
			if(strcmp(sv[j].fullName, sv[j+1].fullName) > 0){
				struct Students temp = sv[j];
				sv[j] = sv[j+1];
				sv[j+1] = temp;
			}
		}
	}
	printf("\nSap xep thanh cong\n\n");
}
void checkStudents(struct Students *sv, int *sizePtr, int choice){
	if((*sizePtr) == 0){
		printf("\nChua them sinh vien\n\n");
	}
	else{
		switch(choice){
			case 1:
				printStudents(sv, sizePtr);
				break;
			case 3:
				editStudents(sv, sizePtr);
				break;
			case 4:
				deleteStudents(sv, sizePtr);
				break;
			case 5:
				searchByName(sv, sizePtr);
				break;
			case 6:
				SortByName(sv, sizePtr);
				break;
		}
	}
}
int main(){
	int size = 0, choice;
	int *sizePtr = &size;
	struct Students *sv = ( struct Students *)calloc(size, sizeof(struct Students));
	do{
		printf("1. Hien thi thong tin\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Tim kiem sinh vien\n");
		printf("6. Sap xep danh sach sinh vien\n");
		printf("7. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 2:
				(*sizePtr)++;
				sv = realloc(sv, *sizePtr * sizeof(struct Students));
				addStudents(sv, sizePtr);
				break;
			case 1:
			case 3:
			case 4:
			case 5:
			case 6:
				checkStudents(sv, sizePtr, choice);
				break;
			case 7:
				printf("\nThoat thanh cong\n");
				break;
		}
	}
	while(choice != 7);
	free(sv);
	return 0;
}

