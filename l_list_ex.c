#include"l_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ex_s{
	int id;
	char *name;
};

struct ex_s *ex_s_init(int id,const char *name){
	struct ex_s *ex = (struct ex_s *)malloc(sizeof(struct ex_s));
	ex->id = id;
	ex->name = (char *)malloc(strlen(name) + 1);
	strcpy(ex->name,name);
	return ex;
}

void ex_s_free(void *ex_v){
	struct ex_s *ex = (struct ex_s *)ex_v;
	free(ex->name);
}

void ex_s_print(void *ex_v){
	struct ex_s *ex = (struct ex_s *)ex_v;
	printf("Id = %d\n",ex->id);
	printf("Name = %s\n",ex->name);
	printf("------\n");
}

int main(){
	struct l_list_s l_list;
	l_list_init(&l_list);
	//
	struct ex_s *ex1 = ex_s_init(0,"george");
	struct ex_s *ex2 = ex_s_init(1,"maria");
	struct ex_s *ex3 = ex_s_init(2,"john");
	struct ex_s *ex4 = ex_s_init(3,"antrea");
	//
	l_list_append(&l_list,ex1);
	l_list_append(&l_list,ex2);
	l_list_append(&l_list,ex3);
	l_list_append(&l_list,ex4);
	//
	l_list_begin(&l_list);
	void *ex_v;
	while(!l_list_eol(&l_list)){
		ex_v = l_list_get_next(&l_list);
		ex_s_print(ex_v);
	}
	//
	l_list_freee(&l_list,ex_s_free);
	//
	return 1;
}

