/*
 * 简易通讯录
 * 记录一个错误：企图用char* name;来获取字符串，实则没有指定大小，导致指针异常
 * 2020.2.26
 */
#include <stdio.h>
#include "cJSON.h"
void welcome();
void input(cJSON* cjson_test);
void show(cJSON* cjson_test);

int main(void) {
    int command;
    cJSON* cjson_test = cJSON_CreateObject();

    for (;;) {

	welcome();
	scanf("%d", &command);
	
	if (command == 1) {
	    input(cjson_test);
	} else if (command == 2) {
	    show(cjson_test);
	} else if (command == 0) {
	    return 0;
	}

    }
    
    return 0;
}

void welcome() {
    printf("command:0 -- quit --\n");
    printf("command:1 -- input --\n");
    printf("command:2 -- show -- \n");
}

void input(cJSON* cjson_test) {
    printf("-- input --\n");

    char* name[50];
    // 错误：没有指定大小，所以只能输入一个字符，导致Segmentation fault (core dumped)
    int number;
    printf("name[enter]number\n");
    scanf("%s", name);
    scanf("%d", &number);

    cJSON_AddNumberToObject(cjson_test, name, number);
}

void show(cJSON* cjson_test) {
    printf("-- show --\n");

    for (int i = 0; i < cJSON_GetArraySize(cjson_test); i++) {
	cJSON* item = cJSON_GetArrayItem(cjson_test, i);
	char* name = item->string;
	char* number = cJSON_Print(item);
	printf("name:%s --- number:%s\n", name, number);
    }

}
