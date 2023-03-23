#include <string.h>
#include <threads.h>
#include <stdio.h>
#include <stdlib.h>

struct Connection {
    int id;
    int socket;
    char name[20];
    struct Connection *next;
    struct Connection *prev;
};

void insert_to_llist(struct Connection **head_ref, int new_id, int new_socket, char name[20]) {
    // allocate memory for new connection
    struct Connection *new_connection = (struct Connection *) malloc(sizeof(struct Connection));
    // assign data to new connection
    new_connection->id = new_id;
    new_connection->socket = new_socket;
    strcpy(new_connection->name, name);
    // make new connection as head and previous as NULL
    new_connection->next = (*head_ref);
    new_connection->prev = NULL;
    // change prev of head connection to new connection
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_connection;
    // move the head to point to the new connection
    (*head_ref) = new_connection;
}

// append a connection at the end of the list
void append_to_llist(struct Connection **head_ref, int new_id, int new_socket, char name[20]) {
    // allocate memory for new connection
    struct Connection *new_connection = (struct Connection *) malloc(sizeof(struct Connection));
    // assign data to new connection
    new_connection->id = new_id;
    new_connection->socket = new_socket;
    strcpy(new_connection->name, name);
    // make next of new connection as NULL and prev as last connection
    new_connection->next = NULL;
    struct Connection *last = *head_ref;
    if (last != NULL) {
        while (last->next != NULL)
            last = last->next;
        last->next = new_connection;
        new_connection->prev = last;
    } else {
        // if the list is empty, make new connection as head and prev as NULL
        (*head_ref) = new_connection;
        new_connection->prev = NULL;
    }
}

// search a connection by id and return its socket file descriptor or -1 if not found
int search_on_llist_by_id(struct Connection *head, int target_id) {
    struct Connection *current = head;
    while (current != NULL) {
        if (current->id == target_id)
            return current->socket; // found the connection
        current = current->next; // move to next connection
    }
    return -1; // not found
}

// search a connection by name and return its socket file descriptor or -1 if not found
int search_on_llist_by_name(struct Connection *head, char name[20]) {
    struct Connection *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current->socket; // found the connection
        current = current->next; // move to next connection
    }
    return -1; // not found
}

int remove_connection_from_llist_by_id(struct Connection **head_ref, int target_id) {
    struct Connection *current = *head_ref;
    while (current != NULL) {
        if (current->id == target_id) {
            // found the connection to be deleted
            int socket = current->socket; // store the socket file descriptor
            // unlink the connection from the list
            if (current == *head_ref) {
                // deleting the head connection
                *head_ref = current->next;
                if (*head_ref != NULL)
                    (*head_ref)->prev = NULL;
            } else {
                // deleting an intermediate or tail connection
                if (current->next != NULL)
                    current->next->prev = current->prev;
                if (current->prev != NULL)
                    current->prev->next = current->next;
            }
            free(current); // free the memory of the connection
            return socket; // return the socket file descriptor of deleted connection
        }
        current = current->next; // move to next connection
    }
    return -1; // not found
}

int remove_connection_from_llist_by_name(struct Connection **head_ref, char name[20]) {
    struct Connection *current = *head_ref;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // found the connection to be deleted
            int socket = current->socket; // store the socket file descriptor
            // unlink the connection from the list
            if (current == *head_ref) {
                // deleting the head connection
                *head_ref = current->next;
                if (*head_ref != NULL)
                    (*head_ref)->prev = NULL;
            } else {
                // deleting an intermediate or tail connection
                if (current->next != NULL)
                    current->next->prev = current->prev;
                if (current->prev != NULL)
                    current->prev->next = current->next;
            }
            free(current); // free the memory of the connection
            return socket; // return the socket file descriptor of deleted connection
        }
        current = current->next; // move to next connection
    }
    return -1; // not found
}

int to_string(struct Connection *head, char res[20000]) {
    int count = 0;
    struct Connection *current = head;
    char temp[10000];
    while (current != NULL) {
        sprintf(temp, "%s%s,", temp, current->name);
        current = current->next; // move to next connection
        count++;
    }
    temp[strlen(temp) - 1] = '\0';
    sprintf(res, "%d/%s", count, temp);
    return count;
}

int get_sockets(struct Connection *head, char names[20000], char res[20000]) {
    char temp[18000];
    char *p = strtok(names, (const char *) ',');
    int count = 0;
    while (p != NULL) {
        sprintf(temp, "%s%d,", temp, search_on_llist_by_name(head, p));
        p = strtok(NULL, ',');
        count++;
    }
    temp[strlen(temp) - 1] = '\0';
    sprintf(res, "%d/%s", count, temp);
    return count;
}

int main() {
    struct Connection *head = NULL;
    insert_to_llist(&head, 1, 100, "Alice");
    insert_to_llist(&head, 2, 200, "Bob");
    insert_to_llist(&head, 3, 300, "Charlie");
    insert_to_llist(&head, 4, 400, "David");
    insert_to_llist(&head, 5, 500, "Eve");
    insert_to_llist(&head, 6, 600, "Frank");
    insert_to_llist(&head, 7, 700, "Grace");
    insert_to_llist(&head, 8, 800, "Hank");
    insert_to_llist(&head, 9, 900, "Ivy");
    append_to_llist(&head, 10, 1000, "John");
    int id = 3;
    int socket = search_on_llist_by_id(head, id);
    if (socket == -1) {
        printf("Connection with id %d not found\n", id);
    } else {
        printf("Socket for connection with id %d: %d\n", id, socket);
    }
    char name[20] = "Eve";
    socket = search_on_llist_by_name(head, name);
    if (socket == -1) {
        printf("Connection with name %s not found\n", name);
    } else {
        printf("Socket for connection with name %s: %d\n", name, socket);
    }
    id = 5;
    int result = remove_connection_from_llist_by_id(&head, id);
    if (result == -1) {
        printf("Connection with id %d not found\n", id);
    } else {
        printf("Connection with id %d removed\n", id);
    }
    char name_to_remove[20] = "Charlie";
    result = remove_connection_from_llist_by_name(&head, name_to_remove);
    if (result == -1) {
        printf("Connection with name %s not found\n", name_to_remove);
    } else {
        printf("Connection with name %s removed\n", name_to_remove);
    }
    char names[20000] = "Alice,Bob,Charlie,David,Eve,Frank,Grace,Hank,Ivy,John";
    char res[20000];
    printf("HELLO");
    int count = get_sockets(head, names, res);
    printf("Found %d sockets: %s\n", count, res);
    return 0;
}