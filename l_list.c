#include"l_list.h"
#include<stdlib.h>

void l_list_init(struct l_list_s *l_list){
	l_list->head = NULL;
	l_list->tail = NULL;
	l_list->c_node = NULL;
}

int l_list_append(struct l_list_s *l_list,void *data){
	struct l_list_node_s *n_node = (struct l_list_node_s *)
		malloc(sizeof(struct l_list_node_s));
	if (n_node == NULL) return 0;
	n_node->data = data;
	n_node->next = NULL;
	if (l_list->head == NULL){
		l_list->head = n_node;
		l_list->tail = n_node;
		return 1;
	}
	(l_list->tail)->next = n_node;
	l_list->tail = n_node;
	return 1;
}

void l_list_begin(struct l_list_s *l_list){
	l_list->c_node = l_list->head;
}

void *l_list_get_next(struct l_list_s *l_list){
	if (l_list->c_node == NULL) return NULL;
	void *data = (l_list->c_node)->data;
	l_list->c_node = (l_list->c_node)->next;
	return data;
}

int l_list_eol(struct l_list_s *l_list){
	return l_list->c_node == NULL;
}

int l_list_is_empty(struct l_list_s *l_list){
	return l_list->head == NULL;
}

void l_list_free(struct l_list_s *l_list){
	struct l_list_node_s *temp;
	l_list->c_node = l_list->head;
	while(l_list->c_node != NULL){
		temp = (l_list->c_node)->next;
		free(l_list->c_node);
		l_list->c_node = temp;
	}
	l_list->head = NULL;
	l_list->tail = NULL;
}

void l_list_freee(struct l_list_s *l_list,void (*free_data)(void *)){
	struct l_list_node_s *temp;
	l_list->c_node = l_list->head;
	while(l_list->c_node != NULL){
		temp = (l_list->c_node)->next;
		free_data((l_list->c_node)->data);
		free(l_list->c_node);
		l_list->c_node = temp;
	}
	l_list->head = NULL;
	l_list->tail = NULL;
}
