#include <stdio.h>
#include <stdlib.h>

struct Inputs{
    char alp;
    Inputs *next, *prev;
}*now = NULL, *head = NULL, *tail = NULL, *starts = NULL;

Inputs *newinput (char p){
    Inputs *temp = (Inputs*) malloc (sizeof(Inputs));

    temp->alp = p;
    temp->prev = NULL;
    temp->next = NULL;
}

void Push(char p){

    Inputs *t = newinput(p);
    if (!head){ //Kosong
        head = tail = t;
        now = head;
        starts->next = head;
        head->prev = starts;
    }

    else if (now == starts){
        Inputs *temp = head;
        starts->next = t;
        t->prev = starts;

        t->next = temp;
        temp->prev = t;
        head = t;
        now = t;
    }

    else if (now == tail){
        tail->next = t;
        t->prev = tail;
        tail = t;
        now = tail;
    }

    else {
        (now->next)->prev = t;
        t->next = now->next;
        t->prev = now;
        now->next = t;
        now = t; 
    }


} // !fdfgh

void Pop(){
    if (now == starts) return;
    else if (head == tail){
        head->prev = NULL;
        free(head);
        now = starts;
        starts->next = NULL;
        head = NULL;
        tail = NULL;
        
    }
    else if (now == head){
        head = now->next;
        head->prev = starts;
        now->next = NULL;
        starts->next = head;
        now->prev = NULL;
        now = NULL;
        free(now);
        now = starts;
    }
    else if (now == tail){
        tail = now->prev;
        tail->next = NULL;
        now->prev = NULL;
        free(now);
        now = tail;
    }
    else {
        (now->prev)->next = now->next;
        (now->next)->prev = now->prev;
        now->next = NULL;
        Inputs *temp = now->prev;
        now->prev = NULL;
        free(now);
        now = temp; 
    }
}

void PrintAll(){
    puts("\n");
    Inputs *ok = head;
    if (now == starts) printf ("|");
    while(ok){
        printf ("%c", ok->alp);
        if (ok == now) printf ("|");
        ok = ok->next;
    }
    puts("");
}

int main(){
    char l;

    starts = newinput('!');
    now = starts;

    puts("TEXT EDITOR!!!!!");
    puts("] for move the cursor forward and [ for the opposite");
    puts("~ to exit the program");
    
    while (1){
        printf (">>");
        scanf ("%c", &l); getchar();

        if (l == '~') break;

        else if (l == '\\'){ //Backspace
            Pop();
        }
        else if (l == ']' && tail != NULL){
            if (now != tail) now = now->next;
        }
        else if (l == '['){
            if (now != starts) now = now->prev;
        }
        else {
            Push(l);
        }
        PrintAll();
    }

    puts("Thanks for using this simple text editor :)");

}


