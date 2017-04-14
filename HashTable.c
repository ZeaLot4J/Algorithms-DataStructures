#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 8192
/*
使用times33哈希函数构造hashTable
使用链地址法解决地址冲突
*/

struct Entry{
    char* key;          //键为字符串
    void* value;        //值为任意类型
    struct Entry* next; //下一个结点
};
struct HashTable{
    struct Entry** entryList;
};

/* times33哈希函数 */
int getHashCode(char* key){
    int hashCode = 0;
    while(*key != '\0')
        hashCode = (hashCode << 5) + hashCode + *key++; //+优先级高于<<
    return hashCode;
}

/* 初始化一个哈希表 */
struct HashTable* createHashTable(){
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    if(hashTable == NULL)
        return NULL;
    hashTable->entryList = (struct Entry**)calloc(TABLE_SIZE, sizeof(struct Entry*));
    if(hashTable->entryList == NULL)
        return NULL;
    return hashTable;
}

/* 生成一个链表结点 */
struct Entry* createEntry(){
    struct Entry* entry = (struct Entry*)malloc(sizeof(struct Entry));
    if(entry == NULL)
        return NULL;
    entry->key = NULL;
    entry->value = NULL;
    entry->next = NULL;
    return entry;
}

/* 向哈希表中加入键值对 */
void putEntry(struct HashTable* hashTable, char* key, void* value){
    int hashCode = getHashCode(key) % TABLE_SIZE;
    struct Entry* head = hashTable->entryList[hashCode];
    struct Entry* newEntry = NULL;
    char* k = (char*)malloc(sizeof(char) * (strlen(key)+1));//给\0留个位子
    strcpy(k, key);
    if(head == NULL){//如果此地址还没有键值对使用，则直接添加
        newEntry = createEntry();
        newEntry->key = k;
        newEntry->value = value;
        head = newEntry;
        hashTable->entryList[hashCode] = head;
    }else{          //如果是因为哈希地址冲突
        while(head != NULL){
            if(strcmp(head->key, key) == 0){//先判断有没有键名相同的，如果有则把值覆盖过去
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

/* 根据键名取值 */
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

/* 根据键名删除键值对 */
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

/* 销毁整个hashTable */
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
/* 打印所有键值对 暂时以字符串作为值*/
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
