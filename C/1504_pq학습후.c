#include <stdio.h>
#include <stdlib.h>

typedef struct _adj_list_node{
    int destination;
    int weight;
    struct _adj_list_node *next;
}adj_list_node;

typedef adj_list_node* adj_list_pointer;

typedef struct _adj_list{
    adj_list_pointer *head;
    int* visitInfo;
    int num_node;
}adj_list;

adj_list* init_adj_list(int num_node){
    adj_list* new_adj_list = (adj_list*)malloc(sizeof(adj_list));

    new_adj_list->head = (adj_list_pointer*)malloc(sizeof(adj_list_pointer)*(num_node+1));
    new_adj_list->visitInfo = (int*)malloc(sizeof(int)*(num_node+1));
    new_adj_list->num_node = num_node;

    return new_adj_list;
}

adj_list_pointer init_adj_list_node(int dt, int wt){
    adj_list_pointer new = (adj_list_pointer)malloc(sizeof(adj_list_node));
    new->destination = dt;
    new->weight = wt;
    new->next = NULL;

    return new;
}

void add_edge(adj_list* al, int st, int dt, int wt){
    adj_list_pointer new_start_node = init_adj_list_node(dt,wt);
    new_start_node->next = al->head[st]->next;
    al->head[st]->next = new_start_node;

    adj_list_pointer new_dest_node = init_adj_list_node(st,wt);
    new_dest_node->next = al->head[dt]->next;
    al->head[dt]->next = new_dest_node;
}




int main(){
    int num_vertex, num_edges;

    scanf("%d %d",&num_vertex, &num_edges);

    adj_list* adj_list = init_adj_list(num_vertex);

    for(int i = 0 ; i < num_edges ; i++){
        int st, dt, wt;

        scanf("%d %d %d", &st, &dt, &wt);

        add_edge(adj_list, st, dt, wt);
    }
}