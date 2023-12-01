//
// Created by vicky on 12-11-2023.
//

#ifndef LAB_AVL_H
#define LAB_AVL_H

//TODO: Lot of scope of improvement in way balance factors as handled and updated.
//TODO: Properly Handle deleting node with 2 children.
//TODO: Scope of improvements in rotation code and how balance factor is updated after rotation.

#include "avl_node.h"

template <typename T>
class AVLTree{
    AVLNode<T>* root;

    bool isLeftChild(AVLNode<T>* n);
    void leftRotate(AVLNode<T>* n);
    void rightRotate(AVLNode<T>* n);
    AVLNode<T>* recalculateBalanceFactors(AVLNode<T>* n);
    AVLNode<T>* getSibling(AVLNode<T>* n);

public:
    AVLTree();
    AVLTree(AVLNode<T>* _root);

    void insert(T elem);
    void insert(T* elems, int num);

    AVLNode<T>* search(T elem);

    AVLNode<T>* findPredecessor(AVLNode<T>* );
    AVLNode<T>* findSuccessor(AVLNode<T>* );

    AVLNode<T>* min(AVLNode<T>* );
    AVLNode<T>* max(AVLNode<T>* );


    void deleteElement(T elem);
    void deleteElement(AVLNode<T>* n);

    void preOrder();
    void postOrder();
    void inOrder();

    void fixRotations(AVLNode<T> *n);
};

template <typename T>
AVLTree<T>::AVLTree() {
    root = NULL;
}
template <typename T>
AVLTree<T>::AVLTree(AVLNode<T>* _root) {
    root = _root;
}

template <typename T>
bool AVLTree<T>::isLeftChild(AVLNode<T> *n) {
    if(n -> getParent() == NULL)
        return  false;
    return n -> getParent() -> getLeftChild() == n;
}

template <typename T>
AVLNode<T>* AVLTree<T>::recalculateBalanceFactors(AVLNode<T> *n) {
    AVLNode<T>* parent = n -> getParent();

    n->setBalanceFactor(((n -> getRightChild() != NULL) ? n -> getRightChild() -> getHeight() : 0) - ((n -> getLeftChild() != NULL) ? n -> getLeftChild() -> getHeight() : 0));

    if(parent == NULL)
        return NULL;

    parent ->setBalanceFactor(
            ((parent -> getRightChild() == NULL) ? 0 : parent -> getRightChild() -> getHeight()) -
            ((parent -> getLeftChild() == NULL) ? 0 : parent -> getLeftChild() -> getHeight())
    );

    while(parent != root && std::abs(parent->getBalanceFactor()) <= 1){
        n = parent;
        parent = n -> getParent();
        if(n->getBalanceFactor() == 0){
            return NULL;
        }
        parent ->setBalanceFactor(
                ((parent -> getRightChild() == NULL) ? 0 : parent -> getRightChild() -> getHeight()) -
                        ((parent -> getLeftChild() == NULL) ? 0 : parent -> getLeftChild() -> getHeight())
                );
    }
    if(std::abs(parent->getBalanceFactor()) > 1){
        return parent;
    }
    return NULL;
}

template <typename T>
AVLNode<T>* AVLTree<T>::getSibling(AVLNode<T> *n) {
    AVLNode<T>* parent = n -> getParent();
    if(parent == NULL)
        return NULL;
    if(parent->getLeftChild() == n){
        return parent -> getRightChild();
    }

    return  parent -> getLeftChild();
}

template <typename T>
void AVLTree<T>::leftRotate(AVLNode<T> *node) {
    AVLNode<T>* right = node ->getRightChild();

    if(right == NULL){
        throw std::runtime_error("No right child while doing left rotate");
    }
    right ->setParent(node->getParent());

    node ->setRightChild(right ->getLeftChild());

    if(node == root){
        root = right;
    }

    right ->setLeftChild(node);
    //updateBalanceFactors(node);
}

template <typename T>
void AVLTree<T>::rightRotate(AVLNode<T> *node) {
    AVLNode<T>* left = node -> getLeftChild();

    if(left == NULL){
        throw std::runtime_error("No left child while doing right rotate");
    }
    left ->setParent(node->getParent());
    node ->setLeftChild(left ->getRightChild());

    if(node == root){
        root = left;
    }

    left ->setRightChild(node);
    //updateBalanceFactors(node);
}

template <typename T>
void AVLTree<T>::insert(T elem) {
    AVLNode<T>* n;
    if(root == NULL){
        n = new AVLNode<T>(elem,NULL);
        root = n;
        return;
    }
    else{
        AVLNode<T>* tmp = root;
        while(true){
            if(elem <= tmp ->getData()){
                if(tmp -> getLeftChild() == NULL) {
                    n = new AVLNode<T>(elem, NULL);
                    tmp->setLeftChild(n);
                    break;
                }
                else {
                    tmp = tmp->getLeftChild();
                }
            }
            else {
                if (tmp->getRightChild() == NULL) {
                    n = new AVLNode<T>(elem, NULL);
                    tmp->setRightChild(n);
                    break;
                } else {
                    tmp = tmp->getRightChild();
                }
            }
        }
    }
    AVLNode<T>* parent = n -> getParent();

    n->setBalanceFactor(0);
    if(parent == NULL)
        return;

    if (isLeftChild(n)){
        parent -> dec();
    }
    else{
        parent -> inc();
    }
    while(parent != root && std::abs(parent->getBalanceFactor()) <= 1){
        n = parent;
        parent = n -> getParent();
        if(n->getBalanceFactor() == 0){
            return;
        }
        if (isLeftChild(n)){
            parent -> dec();
        }
        else{
            parent -> inc();
        }
    }
    if(std::abs(parent->getBalanceFactor()) > 1){
        fixRotations(n);

    }
}

template<typename T>
void AVLTree<T>::fixRotations(AVLNode<T> *n) {
    AVLNode<T>* parent = n -> getParent();
    int p_bf = parent->getBalanceFactor();
    int c_bf = n->getBalanceFactor();

    if(p_bf < 0 && c_bf < 0){
        rightRotate(parent);
        recalculateBalanceFactors(parent);
        recalculateBalanceFactors(n);

    }
    else if(p_bf > 0 && c_bf > 0){
        leftRotate(parent);
        recalculateBalanceFactors(parent);
        recalculateBalanceFactors(n);

    }
    else if(p_bf < 0 && c_bf > 0){
        leftRotate(n);
        rightRotate(parent);
        recalculateBalanceFactors(n);
        recalculateBalanceFactors(parent);
    }
    else{
        rightRotate(n);
        leftRotate(parent);
        recalculateBalanceFactors(n);
        recalculateBalanceFactors(parent);

    }
}

template <typename T>
void AVLTree<T>::insert(T *elems, int num) {
    for(int i = 0; i < num; ++i){
        insert(elems[i]);
    }
}

template<typename T>
AVLNode<T>* AVLTree<T>::search(T elem){
    if(root == NULL){
        throw  std::runtime_error("Root is NULL");
    }
    else{
        AVLNode<T>* tmp = root;
        while(tmp != NULL && tmp -> getData() != elem){
            if(elem <= tmp->getData()){
                tmp = tmp -> getLeftChild();
            }
            else{
                tmp = tmp -> getRightChild();
            }
        }
        return tmp;
    }
}

template<typename T>
void AVLTree<T>::deleteElement(T elem) {
    deleteElement(search(elem));
}

template<typename T>
void AVLTree<T>::deleteElement(AVLNode<T> *node) {
    if(root == NULL)
        throw std::runtime_error("Root do not exists while deleting element");
    int childs = ((node -> getLeftChild() != NULL) ? 1 : 0) + ((node -> getRightChild() != NULL) ? 1 : 0);

    if(childs == 0){
        AVLNode<T>* sibiling = getSibling(node);

        AVLNode<T>* parent = node -> getParent();

        if(sibiling == NULL){
            if(isLeftChild(node)){
                parent ->setLeftChild(NULL);
            }
            else{
                parent ->setRightChild(NULL);
            }
        }
        else{
            recalculateBalanceFactors(sibiling);
            if(isLeftChild(node)){
                parent ->setLeftChild(NULL);
                parent ->dec();

                if(std::abs(parent->getBalanceFactor()) > 1) {

                    if (sibiling->getBalanceFactor() < 0) {
                        rightRotate(sibiling);
                        leftRotate(parent);
                    } else {
                        if (sibiling->getBalanceFactor() == 0 && sibiling->getLeftChild() == NULL) {
                            delete node;
                            return;
                        }
                        leftRotate(parent);
                    }
                }
            }
            else{
                parent ->setRightChild(NULL);
                if(sibiling -> getBalanceFactor() > 0){
                    leftRotate(sibiling);
                    rightRotate(parent);
                }
                else{
                    if(sibiling -> getBalanceFactor() == 0 && sibiling -> getRightChild() == NULL) {
                        delete node;
                        return;
                    }
                    rightRotate(parent);
                }

            }
        }
    }
    else if(childs == 1) {
        AVLNode<T> *parent = node->getParent();

        if (isLeftChild(node)) {
            parent->setLeftChild((node->getRightChild() == NULL) ? node->getLeftChild() : node->getRightChild());
        } else {
            parent->setRightChild((node->getRightChild() == NULL) ? node->getLeftChild() : node->getRightChild());
        }
    }
    else{
        AVLNode<T>* predecessor = findPredecessor(node);
        AVLNode<T>* parent = predecessor -> getParent();

        node ->setData(predecessor -> getData());
        deleteElement(predecessor);

    }

    delete node;
}


template <typename T>
AVLNode<T>* AVLTree<T>::findSuccessor(AVLNode<T> *node){
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

    AVLNode<T>* parent = node -> getParent();
    AVLNode<T>* current = node;

    while(parent != NULL && parent -> getRightChild() == current){ //we will loop till current is right child of parent
        current = parent; //if parent is right child of current. assign current as parent and repeat.
        parent = node -> getParent();
    }

    return parent;
}

template <typename T>
AVLNode<T>* AVLTree<T>::findPredecessor(AVLNode<T> *node){ //finds predecessor.
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


    AVLNode<T>* parent = node -> getParent();
    AVLNode<T>* current = node;

    while(parent != NULL && parent -> getLeftChild() == current){ //we will loop till current is left child of parent
        current = parent; //if parent is left child of current. assign current as parent and repeat.
        parent = node -> getParent();
    }

    return parent;
}

template <typename T>
AVLNode<T>* AVLTree<T>::max(AVLNode<T> *node){ //returns node with maximum value of tree rooted at 'node'
    AVLNode<T>* maxNode = node;
    while(maxNode -> getRightChild() != NULL){ //loops till maxNode has right child i.e. till rightmost most node.
        maxNode = maxNode -> getRightChild();
    }
    return maxNode;
}

template <typename T>
AVLNode<T>* AVLTree<T>::min(AVLNode<T> *node){ //returns node with minimum value of tree rooted at 'node'
    AVLNode<T>* minNode = node;
    while(minNode -> getLeftChild() != NULL){ //loops till minNode has left child i.e. till left most node.
        minNode = minNode -> getLeftChild();
    }
    return minNode;
}


template <typename T>
void AVLTree<T>::preOrder() {
    if(root == NULL)
        throw std::runtime_error("Root is NULL while doing pre order traversal");
    root -> preOrder();
    std::cout << std::endl;
}

template <typename T>
void AVLTree<T>::postOrder() {
    if(root == NULL)
        throw std::runtime_error("Root is NULL while doing post order traversal");
    root -> postOrder();
    std::cout << std::endl;
}

template <typename T>
void AVLTree<T>::inOrder() {
    if(root == NULL)
        throw std::runtime_error("Root is NULL while doing inorder traversal");
    root -> inOrder();
    std::cout << std::endl;
}

#endif //LAB_AVL_H
