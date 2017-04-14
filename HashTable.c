#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 8192
/*
ʹ��times33��ϣ��������hashTable
ʹ������ַ�������ַ��ͻ
*/

struct Entry{
    char* key;          //��Ϊ�ַ���
    void* value;        //ֵΪ��������
    struct Entry* next; //��һ�����
};
struct HashTable{
    struct Entry** entryList;
};

/* times33��ϣ���� */
int getHashCode(char* key){
    int hashCode = 0;
    while(*key != '\0')
        hashCode = (hashCode << 5) + hashCode + *key++; //+���ȼ�����<<
    return hashCode;
}

/* ��ʼ��һ����ϣ�� */
struct HashTable* createHashTable(){
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    if(hashTable == NULL)
        return NULL;
    hashTable->entryList = (struct Entry**)calloc(TABLE_SIZE, sizeof(struct Entry*));
    if(hashTable->entryList == NULL)
        return NULL;
    return hashTable;
}

/* ����һ�������� */
struct Entry* createEntry(){
    struct Entry* entry = (struct Entry*)malloc(sizeof(struct Entry));
    if(entry == NULL)
        return NULL;
    entry->key = NULL;
    entry->value = NULL;
    entry->next = NULL;
    return entry;
}

/* ���ϣ���м����ֵ�� */
void putEntry(struct HashTable* hashTable, char* key, void* value){
    int hashCode = getHashCode(key) % TABLE_SIZE;
    struct Entry* head = hashTable->entryList[hashCode];
    struct Entry* newEntry = NULL;
    char* k = (char*)malloc(sizeof(char) * (strlen(key)+1));//��\0����λ��
    strcpy(k, key);
    if(head == NULL){//����˵�ַ��û�м�ֵ��ʹ�ã���ֱ�����
        newEntry = createEntry();
        newEntry->key = k;
        newEntry->value = value;
        head = newEntry;
        hashTable->entryList[hashCode] = head;
    }else{          //�������Ϊ��ϣ��ַ��ͻ
        while(head != NULL){
            if(strcmp(head->key, key) == 0){//���ж���û�м�����ͬ�ģ���������ֵ���ǹ�ȥ
                head->value = value;
                return;
            }
            head = head->next;
        }
        newEntry = createEntry();
        newEntry->key = k;
        newEntry->value = value;
        head->next = newEntry;
    }
}

/* ���ݼ���ȡֵ */
void* getValue(struct HashTable* hashTable, char* key){
    int hashCode = getHashCode(key) % TABLE_SIZE;
    struct Entry* head = hashTable->entryList[hashCode];
    while(head!=NULL){
        if(strcmp(head->key, key) == 0){
            return head->value;
        }
        head = head->next;
    }
    return NULL;
}

/* ���ݼ���ɾ����ֵ�� */
void removeEntry(struct HashTable* hashTable, char* key){
    int hashCode = getHashCode(key) % TABLE_SIZE;
    struct Entry* head = hashTable->entryList[hashCode];
    struct Entry* tp = NULL;
    while(head != NULL){
        if(strcmp(head->key, key) == 0){
            tp = head;
            head = head->next;
            free(tp);
            tp = NULL;
            break;
        }
        head = head->next;
    }
}

/* ��������hashTable */
void destroyHashTable(struct HashTable* hashTable){
    int i;
    struct Entry* head = NULL;
    struct Entry* tp = NULL;
    for(i=0; i<TABLE_SIZE; i++){
        head = hashTable->entryList[i];
        hashTable->entryList[i] = NULL;
        while(head != NULL){
            tp = head;
            head = head->next;
            free(tp);
            tp = NULL;
        }
    }
}
/* ��ӡ���м�ֵ�� ��ʱ���ַ�����Ϊֵ*/
void printHashTable(struct HashTable* hashTable){
    int i;
    struct Entry* head = NULL;
    for(i=0; i<TABLE_SIZE; i++){
        head = hashTable->entryList[i];
        while(head != NULL){
            printf("%s = %s\n", head->key, head->value);
            head = head->next;
        }
    }
}
int main(){
    struct HashTable* hashTable = createHashTable();
    putEntry(hashTable, "name", "ZeaLot");
    putEntry(hashTable, "age", "22");
    printf("%s\n", getValue(hashTable, "name"));
    printf("%s\n", getValue(hashTable, "age"));
    printHashTable(hashTable);
    destroyHashTable(hashTable);
    printHashTable(hashTable);
    return 0;
}
