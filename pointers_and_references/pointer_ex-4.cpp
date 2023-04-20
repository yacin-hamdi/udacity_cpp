/*
1.  Create namespace custom
2.  In this namespace design class list
3.  This class needs to have node structure which will represent elemental object
    of list
4.  In this structure we are going to implement: value store attribute, pointer
    to same structure type which we will use to store data about previous and next
    element.
5.  Besides that, implementation of constructor which will handle initializations
    of attriute is required
6.  Second attribute of class list is going to be structure type pointer called
    head, which is representing pointer to the beginning of the list
7.  Third attribute is tail pointer, which is in charge of showing to the end of
    the list
8.  Implement default constructor for initial declaration of new lists
9.  Define and implement destructor to prevent memory leakage of our class
    instances
10. Destructor needs to remove every object in a list
11. Use head pointer to delete every linked list member
12. Implement push_front for adding new nodes on the beginning of the list
13. Implement push_back ( same principle)
14. Implement pop back and pop front which will we based on same logic as push
    method, but instead of adding elements, they will delete values
15. Implement print method logic which will use instance of list object to print
    stored values
16. Protect every method logic from empty lists
*/

#include<iostream>


namespace custom{

    template<typename t> class list{
        private:
            struct node{
                t value;
                node* prev;
                node* next;
                node(t value_, node* prev_, node* next_):value(value_), prev(prev_), next(next_){}
            };

            node* head;
            node* tail;


        public:

            list():head(NULL), tail(NULL){}
            ~list();
            void push_front(t);
            void push_back(t);
            t pop_front();
            t pop_back();
            void print();
            bool empty()const;
    };
}

int main(){
    return 0;
}