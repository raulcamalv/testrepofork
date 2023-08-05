#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>
// akjsdf laskf la
typedef struct{
    //uint16_t channel: 10;
    uint8_t enable_bit: 1;
    uint8_t trigger_src: 4;
    uint8_t channel_op_mode: 2;
    uint8_t enable_trigger: 1;
    uint16_t channel: 10;
} RegisterConfig;

int a(){ printf("a"); return 0;}
int b(){ printf("b"); return 0;}

//typedef struct Node;

typedef struct Node{
    Node* Next;
    int Data;
} Node;


void insertNode(Node *start, int position)
{
    if (start==NULL)
    {
         return;
    }
    if (position==0)
    {
        Node *anew = (Node*)malloc(sizeof(Node));
        memcpy(anew, start, sizeof(Node));
        start->Next = anew;
    }
    else
    {
        int counter = 0;
        Node *ptr = start;
        Node *last;
        while (counter<position && ptr)
        {
            last = ptr;
            ptr = ptr->Next;
            counter++;
        }
        if (!ptr)
        {
            Node *anew = (Node *)malloc(sizeof(Node));
            last->Next = anew;  
        }
        else
        {
            Node *anew = (Node *)malloc(sizeof(Node));
            anew->Next = ptr; 
            last->Next = anew;              
        }
    }
}
uint16_t translateData(uint8_t data)
{
   uint16_t retval;
   if (data==0xFF) return 0;

   int num_ones=0;
   for (int i = 0 ;  i < 8 ; i++)
   {
        if (data & 1<<i) num_ones++;
   }
   retval = (data<<8) + num_ones;
   return retval;
}

void f(int x)
{
    x=0;
    while (!x);
    printf("asdf");
}

int is_prime(int n)
{
    int x = 3;
    while(x<=n/2){
        if (n%x==0) return 0;
        x+=2;
    }
    return 1;
}

void func(char *str, char c)
{
    char *ptr;
    char buf[100];
    while (1)
    {
        ptr = strchr(str, c);
        if (!ptr) return;
        memcpy(ptr, ptr+1, strlen(ptr+1)+1);
    } 
}

int main(int argc, char *argv[])
{
    char source[] = "Hello, World!";
    int source_len = strlen(source);

    // Copy the first 5 characters of source to the position of index 0
    // The destination overlaps with the source
    memcpy(source, source + 5, 5);

    printf("Result: %s\n", source);
    return 0;
}







