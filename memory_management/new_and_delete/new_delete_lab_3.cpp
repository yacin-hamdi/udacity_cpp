

/*
1.  Create class called binary_tree
2.  Create structure called node
3.  Declare 4 attributes in structure: integer data, two pointers to the same
    type of structure, called left and right
4.  Declare main pointer to structure node type called root
5.  This pointer is attribute of class binary_tree
6.  This pointer is going to contain all data related to binary tree trought
    connecting nodes
7.  Declare two methods called add and search
8.  Add needs to have logic which will be dependent from data attribute and
    check for its place of creation on left or right side
9.  Search needs to be implemented as recursive function
10. Check for nullptr in search and call it again on fulfilled condition(< or >)
11. First function doesn't have return type
12. Second function indicates its success by sending boolean values
13. Both class methods are wrappers for two private class method which are going
    to be implemented recursively for easier usage.
14. Private functions are using another input parameter -> node pointer
15. This is designed like this for passage of pointers ( left, right)
16. Declare two constructors and destructors
17. One of the constructor - destructor pair is going to be part of node
    structure
18. Second pair is going to be of class
19. Constructors in structure is used to declare new node (Pointers are NULL,
    data is set)
20. Constructor in class is esentially wrapper for stucture constructor
21. Structure destructor deletes left and right pointers
22. Class destructor deletes root pointer
23. Test everything in main
*/

#include<iostream>

class BinaryTree{
    private:
        struct Node{
            int data_;
            Node* left_;
            Node* right_;
            Node(int data,Node* left, Node* right):data_(data), left_(left), right_(right){}
            ~Node(){
                if(left_)
                    delete left_;
                if(right_)
                    delete right_;
            }
            
        };

        Node* root;
        
        void add(int data, Node *ptr){
            if(data > ptr->data_){
                //add node to the left
                if(ptr->left_ != nullptr){
                    add(data, ptr->left_);
                }else{
                    ptr->left_ = new Node(data, nullptr, nullptr);
                }


            }else if (data <= ptr->data_){
                //add node to the right
                if(ptr->right_ != nullptr){
                    add(data, ptr->right_);
                }else{
                    ptr->right_ = new Node(data, nullptr, nullptr);
                }
            }
        }
    
        
        bool search(int item, Node*ptr){
            if(!ptr->left_ && !ptr->right_){
                if(ptr->data_ == item)
                    return true;
 
                return false;
            }

            if(ptr->data_ > item && ptr->right_){
                search(item, ptr->right_);
            }else if(ptr->data_ < item && ptr->left_){
                search(item, ptr->left_);
            }
        }

    public:

        BinaryTree(int data){
            root = new Node(data, nullptr, nullptr);
        }
        ~BinaryTree(){
            delete root;
        }

        void addData(int data){
            add(data, root);
        }

        bool searchItem(int item){
            return search(item, root);
        }

};


int main() {
  BinaryTree tree(2);
  tree.addData(10);
  tree.addData(1);
  tree.addData(20);
  tree.addData(0);

  std::cout << tree.searchItem(0) << std::endl;
//   std::cout << tree.searchItem(9) << std::endl;
  tree.addData(11);
  std::cout << tree.searchItem(11) << std::endl;
  std::cout << tree.searchItem(10) << std::endl;
  /* OUTPUT:
      1
      0
      1
  */
  return 0;
}


