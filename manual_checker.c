#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_stack;

void init_stack(t_stack *s) {
    s->head = NULL;
    s->tail = NULL;
    s->size = 0;
}

void push_front(t_stack *s, int value) {
    t_node *n = malloc(sizeof(t_node));
    n->value = value;
    n->prev = NULL;
    n->next = s->head;
    if (s->head)
        s->head->prev = n;
    s->head = n;
    if (!s->tail)
        s->tail = n;
    s->size++;
}

int pop_front(t_stack *s) {
    if (!s->head) return 0;
    t_node *n = s->head;
    int val = n->value;
    s->head = n->next;
    if (s->head)
        s->head->prev = NULL;
    else
        s->tail = NULL;
    s->size--;
    free(n);
    return val;
}

void sa(t_stack *a) {
    if (a->size < 2) return;
    int v1 = pop_front(a);
    int v2 = pop_front(a);
    push_front(a, v1);
    push_front(a, v2);
}

void pa(t_stack *a, t_stack *b) {
    if (b->size == 0) return;
    push_front(a, pop_front(b));
}

void pb(t_stack *a, t_stack *b) {
    if (a->size == 0) return;
    push_front(b, pop_front(a));
}

void ra(t_stack *a) {
    if (a->size < 2) return;
    int val = pop_front(a);
    // Add to end
    t_node *n = malloc(sizeof(t_node));
    n->value = val;
    n->next = NULL;
    n->prev = a->tail;
    if (a->tail)
        a->tail->next = n;
    a->tail = n;
    if (!a->head)
        a->head = n;
    a->size++;
}

void rb(t_stack *b) {
    if (b->size < 2) return;
    int val = pop_front(b);
    t_node *n = malloc(sizeof(t_node));
    n->value = val;
    n->next = NULL;
    n->prev = b->tail;
    if (b->tail)
        b->tail->next = n;
    b->tail = n;
    if (!b->head)
        b->head = n;
    b->size++;
}

void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
}

void rra(t_stack *a) {
    if (a->size < 2) return;
    t_node *n = a->tail;
    a->tail = n->prev;
    if (a->tail)
        a->tail->next = NULL;
    else
        a->head = NULL;
    n->prev = NULL;
    n->next = a->head;
    if (a->head)
        a->head->prev = n;
    a->head = n;
    if (!a->tail)
        a->tail = n;
}

void rrb(t_stack *b) {
    if (b->size < 2) return;
    t_node *n = b->tail;
    b->tail = n->prev;
    if (b->tail)
        b->tail->next = NULL;
    else
        b->head = NULL;
    n->prev = NULL;
    n->next = b->head;
    if (b->head)
        b->head->prev = n;
    b->head = n;
    if (!b->tail)
        b->tail = n;
}

void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
}

void print_stack(const char *name, t_stack *s) {
    printf("%s (%d): ", name, s->size);
    t_node *cur = s->head;
    while (cur) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int is_sorted(t_stack *s) {
    t_node *cur = s->head;
    while (cur && cur->next) {
        if (cur->value > cur->next->value)
            return 0;
        cur = cur->next;
    }
    return 1;
}

int main() {
    t_stack a, b;
    init_stack(&a);
    init_stack(&b);
    
    int numbers[] = {42743061, 1077244982, -1955910293, -839496484, -966455884, 
                     -1135920830, 41591695, 1185385102, 601365101, -1347539130, 
                     1918449505, -1988458351, -1000704046, -1394742176, 927630853, 
                     -1374499909, 1863534462, -2139813184, -1688577619, -67883618};
    
    // Push in reverse order to maintain order
    for (int i = 19; i >= 0; i--) {
        push_front(&a, numbers[i]);
    }
    
    printf("Initial:\n");
    print_stack("A", &a);
    print_stack("B", &b);
    
    FILE *f = fopen("ops.txt", "r");
    if (!f) {
        printf("Can't open ops.txt\n");
        return 1;
    }
    
    char line[100];
    int op_count = 0;
    while (fgets(line, sizeof(line), f)) {
        // Remove newline
        line[strcspn(line, "\r\n")] = 0;
        op_count++;
        
        if (strcmp(line, "pa") == 0) pa(&a, &b);
        else if (strcmp(line, "pb") == 0) pb(&a, &b);
        else if (strcmp(line, "sa") == 0) sa(&a);
        else if (strcmp(line, "ra") == 0) ra(&a);
        else if (strcmp(line, "rb") == 0) rb(&b);
        else if (strcmp(line, "rr") == 0) rr(&a, &b);
        else if (strcmp(line, "rra") == 0) rra(&a);
        else if (strcmp(line, "rrb") == 0) rrb(&b);
        else if (strcmp(line, "rrr") == 0) rrr(&a, &b);
        else printf("Unknown op: '%s'\n", line);
    }
    fclose(f);
    
    printf("\nAfter %d operations:\n", op_count);
    print_stack("A", &a);
    print_stack("B", &b);
    
    if (is_sorted(&a) && b.size == 0) {
        printf("\nRESULT: OK\n");
    } else {
        printf("\nRESULT: KO\n");
        if (!is_sorted(&a))
            printf("  - Stack A is NOT sorted\n");
        if (b.size != 0)
            printf("  - Stack B is NOT empty (size=%d)\n", b.size);
    }
    
    return 0;
}
