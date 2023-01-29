# l_list
Linked list

## API
```C
//Initialize the linked list.
void l_list_init(struct l_list_s *l_list);
//Append data
int l_list_append(struct l_list_s *l_list,void *data);
//Begin iteration of the list
void l_list_begin(struct l_list_s *l_list);
//Get next element
void *l_list_get_next(struct l_list_s *l_list);
//End of list?
int l_list_eol(struct l_list_s *l_list);
//Is empty?
int l_list_is_empty(struct l_list_s *l_list);
//Free linked list
void l_list_free(struct l_list_s *l_list)
//Free linked list and data
void l_list_freee(struct l_list_s *l_list,void (*free_data)(void *));

```
