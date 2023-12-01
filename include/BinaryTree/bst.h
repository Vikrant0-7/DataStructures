#ifndef BST_H
#define BST_H

#include "node.h"

template <typename T>
class BinarySearchTree{
    private:
        Node<T>* root;
    
    public:
        BinarySearchTree() : root(NULL){ }
        BinarySearchTree(Node<T>* r) : root(r){ }

        void addElement(T);
        void addElement(T*,int);
        Node<T>* getParent(Node<T>*);
        Node<T>* search(T);

        Node<T>* findSuccessor(Node<T>*);
        Node<T>* findPredecessor(Node<T>*);

        Node<T>* max(Node<T>*);
        Node<T>* min(Node<T>*);

        void deleteNode(T);
        void deleteNode(Node<T>*);

        void inOrder();
        void postOrder();
        void preOrder();
};

template <typename T>
void BinarySearchTree<T>::addElement(T elem){
    if(root == NULL){
        root = new Node<T>(elem);
    }
    else{
        Node<T>* tmp = root;
        while(true){
            if(elem > tmp -> getData()){
                if(tmp -> getRightChild() == NULL){
                    tmp -> setRightChild(new Node<T>(elem));
                    break;
                }
                else{
                    tmp = tmp -> getRightChild();
                }
            }
            else{
                if(tmp -> getLeftChild() == NULL){
                    tmp -> setLeftChild(new Node<T>(elem));
                    break;
                }
                else{
                    tmp = tmp -> getLeftChild();
                }
            }
        }
    }
}

template <typename T>
void BinarySearchTree<T>::addElement(T* elem,int s){
    for(int i = 0; i < s; ++i){
        this -> addElement(elem[i]);
    }
}


template <typename T>
Node<T>* BinarySearchTree<T>::getParent(Node<T> *child){
    
    if(root == NULL){
        throw std::runtime_error("Root is NULL");
    }

    if(child == root){
        return NULL;
    }

    Node<T>* tmp = root;
    while(tmp -> getLeftChild() != child && tmp -> getRightChild() != child){
        if(child -> getData() <= tmp -> getData()){
            tmp = tmp -> getLeftChild();
        }
        else if(child -> getData() > tmp -> getData()){
            tmp = tmp -> getRightChild();
        }
    }
    return tmp;
}

template <typename T>
Node<T>* BinarySearchTree<T>::search(T elem){
    
    if(root == NULL){
        throw std::runtime_error("Root is NULL");
    }
    Node<T>* tmp = root;
    while(tmp != NULL && tmp -> getData() != elem){
        if(elem <= tmp -> getData()){
            tmp = tmp -> getLeftChild();
        }
        else if(elem > tmp -> getData()){
            tmp = tmp -> getRightChild();
        }
    }
    return tmp;
}

template <typename T>
Node<T>* BinarySearchTree<T>::findSuccessor(Node<T> *node){
    if (node -> getRightChild() != NULL){ //if there is rightChild of current node
        return min(node -> getRightChild()); //find minimum, i.e. left most node of that subtree.
    }

    /*
     *                               100
     *                        50                 150
     *                 40           60      120        160
     *                    45     55     110    130
     *                         52                  135
     *
     * in above tree. 135 has no right child. And it's successor is 150
     * so we will travel above the tree till current node is right child of its parent
     * and when we stop, parent of current node will be predecessor
     */

    Node<T>* parent = getParent(node);
    Node<T>* current = node;

    while(parent != NULL && parent -> getRightChild() == current){ //we will loop till current is right child of parent
        current = parent; //if parent is right child of current. assign current as parent and repeat.
        parent = getParent(current);
    }

    return parent;
}

template <typename T>
Node<T>* BinarySearchTree<T>::findPredecessor(Node<T> *node){ //finds predecessor.
    if (node -> getLeftChild() != NULL){ //if node has left child find maximum of that subtree.
        return max(node -> getLeftChild());
    }

    /*
     *                               100
     *                        50                 150
     *                 40           60      120        160
     *                    45     55     110    130
     *                         52                  135
     *
     * in above tree. 52 has no left child. And it's predecessor is 50
     * so we will travel above the tree till current node is left child of its parent
     * and when we stop, parent of current node will be predecessor
     */


    Node<T>* parent = getParent(node);
    Node<T>* current = node;

    while(parent != NULL && parent -> getLeftChild() == current){ //we will loop till current is left child of parent
        current = parent; //if parent is left child of current. assign current as parent and repeat.
        parent = getParent(current);
    }

    return parent;
}

template <typename T>
Node<T>* BinarySearchTree<T>::max(Node<T> *node){ //returns node with maximum value of tree rooted at 'node'
    Node<T>* maxNode = node;
    while(maxNode -> getRightChild() != NULL){ //loops till maxNode has right child i.e. till rightmost most node.
        maxNode = maxNode -> getRightChild();
    }
    return maxNode;
}

template <typename T>
Node<T>* BinarySearchTree<T>::min(Node<T> *node){ //returns node with minimum value of tree rooted at 'node'
    Node<T>* minNode = node;
    while(minNode -> getLeftChild() != NULL){ //loops till minNode has left child i.e. till left most node.
        minNode = minNode -> getLeftChild();
    }
    return minNode;
}

template <typename T>
void BinarySearchTree<T>::inOrder(){ // visits nodes in tree in order left-parent-right
    if(root == NULL)
        throw std::runtime_error("No root exists");
    root -> inOrder();
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::postOrder(){ // visits nodes in tree in order left-right-parent
    if(root == NULL)
        throw std::runtime_error("No root exists");
    root -> postOrder();
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::preOrder(){ // visits nodes in tree in order parent-left-right
    if(root == NULL)
        throw std::runtime_error("No root exists");
    root -> preOrder();
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::deleteNode(T val){ //searches and delete node with given value.
    Node<T>* toBeDeleted = search(val);
    if(toBeDeleted != NULL)
        deleteNode(search(val)); //calls deleteNode function after finding node via search function
    else //raise exception if supplied node to not exists in binary search tree.
        throw std::runtime_error(val + " does not exists in binary search tree");
}

template <typename T>
void BinarySearchTree<T>::deleteNode(Node<T>* node){ //deletes node pointed by given pointer
    int childs = ((node -> getLeftChild() != NULL) ? 1 : 0) + ((node -> getRightChild() != NULL) ? 1 : 0);

    if(childs == 0){ //if node to be deleted has no child, i.e. node is leaf
        Node<T> * parent = getParent(node); //Gets Parent, to update pointers and remove address of deleted node

        if(parent -> getLeftChild() == node) //if node to be deleted is left child of parent then update parent's left child's pointer
            parent ->setLeftChild(NULL);
        else //if not, update right child's pointer
            parent ->setRightChild(NULL);
    }
    else if(childs == 1){ //if node be deleted has exactly 1 child
        Node<T> * parent = getParent(node); //Gets Parent of Node, to promote it's grandchild to child

        /*
         * this code works on fact that node has exactly one child. If it is not in right side then it
         * must be in left hand side.
         * Moreover all node in left subtree of a node must be smaller than the
         * node itself. So naturally any node in left subtree can be assigned as left child of that node
         * Similarly, all nodes in right subtree can be assigned as right child of that node.
        */

        if(parent -> getLeftChild() == node){ // if node to be deleted is left child of its parent then
            if(node->getRightChild() != NULL) //if node has right child, then assign it as left child of parent
                parent ->setLeftChild(node->getRightChild());
            else //if note than make left child of node as parent's left child.
                parent ->setLeftChild(node ->getLeftChild());

        }
        else{ //if node to be deleted is right child of its parent then
            if(node->getRightChild() != NULL) //if node has right child, then assign it as right child of parent
                parent ->setRightChild(node->getRightChild());
            else//if note than make left child of node as parent's right child.
                parent ->setRightChild(node ->getLeftChild());
        }
    }
    else{ //if parent has 2 child

        /*
         * This works on logic that get predecessor i.e. node just before node to be deleted while traversing
         * three inorder traversal.
         * Predecessor is node with atmost 1 child. and even that child (if node has one) will always be left child.
         * Copy predecessor's value to current node and delete predecessor.
         * if predecessor has child, apply the same logic as deleting node with 1 child.
         */


        /* here node is replaced by predecessor, which is rightmost node
         * of left subtree.
         */
        Node<T>* predecessor = node -> getLeftChild(), *predecessorParent = node;

        /*
         * while loop will run till predecessor has no right child
         */
        while(predecessor->getRightChild() != NULL){ //gets rightmost node
            predecessorParent = predecessor;
            predecessor = predecessor->getRightChild(); //predecessor parent is necessary for updating few pointers
        }

        /*
         * if predecessor is not left child of node. Now, if we delete predecessor, that means that predecessor's parent
         * has to adopt predecessor's child (if any). And as all node on right subtree can be right child of a node.
         */
        if(predecessorParent != node) {
            predecessorParent->setRightChild(predecessor -> getLeftChild());
        }
        /*
         * if predecessor is left child of node to be deleted. Now, if we delete predecessor, that means that
         * predecessor's parent i.e. current node has to adopt predecessor's child (if any). And as all node on left
         * subtree can be left child of a node. Predecessor is in left subtree that means it will be left child of node.
         */
        else{
            predecessorParent->setLeftChild(predecessor -> getLeftChild());
        }

        node->setData(predecessor->getData()); //copy data of predecessor.
        node = predecessor;
    }
    delete node;
}
#endif