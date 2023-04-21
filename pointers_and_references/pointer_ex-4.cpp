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
                node *prev;
                node *next;
                t value;
                node(t value_, node*prev_, node*next_):value(value_), prev(prev_), next(next_){}
            };

            node* head;
            node* tail;


        public:
            list():head(NULL),tail(NULL){}
            ~list();
            void push_back(t);
            void push_front(t);
            t pop_front();
            t pop_back();
            void print();
            bool empty()const{return !head | !tail;};

    };

     template<typename t> void list<t>::push_front(t element){
        node * front_node = new node(element, nullptr, head);
        if(head == nullptr and tail == nullptr){
            head = front_node;
            tail = front_node;
        }else{
            head->prev = front_node;
            head = front_node;
        }
    }

    template<typename t> void list<t>::push_back(t element){
        node* back_node = new node(element, tail, nullptr);
        if(head == nullptr and tail == nullptr){
            head = back_node;
            tail = back_node;
        }else{
            tail->next= back_node;
            tail = back_node;
        }
    }

    template<typename t> t list<t>::pop_front(){
        if(list<t>::empty()){
            throw("list is empty");
        }
        node* temp(head);
        t value = head->value;
        head = head->next;
        if(head){
            head->prev = nullptr;
        }else{
            tail = nullptr;
        }

        delete temp;
        return value;

    }

    template<typename t> t list<t>::pop_back(){
        if(list<t>::empty()){
            throw("list is empty");
        }

        node* temp(tail);
        t value = tail->value;
        tail = tail->prev;
        if(tail)
            tail->next = nullptr;
        else   
            head = nullptr;

        delete temp;
        return value; 

    }

    template<typename t> void list<t>::print(){
        node* ptr = list<t>::head;
        while(ptr != nullptr){
            std::cout << ptr->value<< std::endl;
            ptr = ptr->next;
        }
    }

    template<typename t> list<t>::~list(){
        while(head){
            node* temp(head);
            head = head->next;
            delete(temp);
        }
    }
}

int main(){
    custom::list<int>ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_front(3);
    ls.print();
    std::cout << ";;;;;;;;"<< std::endl;
    ls.pop_back();
    ls.pop_front();
    ls.pop_front();
    ls.print();

    return 0;
}