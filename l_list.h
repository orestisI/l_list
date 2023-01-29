#ifndef L_LIST_H
#define L_LIST_H

struct l_list_node_s{
	void *data;
	struct l_list_node_s *next;
};

struct l_list_s{
	struct l_list_node_s *head;
	struct l_list_node_s *tail;
	struct l_list_node_s *c_node;
};

void l_list_init(struct l_list_s *l_list);
int l_list_append(struct l_list_s *l_list,void *data);
void l_list_begin(struct l_list_s *l_list);
void *l_list_get_next(struct l_list_s *l_list);
int l_list_eol(struct l_list_s *l_list);
int l_list_is_empty(struct l_list_s *l_list);
void l_list_free(struct l_list_s *l_list);
void l_list_freee(struct l_list_s *l_list,void (*free_data)(void *));

#endif
