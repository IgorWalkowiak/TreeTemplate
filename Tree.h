#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include<iostream>

template < typename KeyType, typename ValueType >

struct node
    {
        node(KeyType K,ValueType V):key(K),value(V),left(nullptr),right(nullptr){};

        KeyType key;
        ValueType value;

        node* left;
        node* right;


    };



template < typename KeyType, typename ValueType >

class Tree{

    node<KeyType,ValueType>* root;
    void addNode(node<KeyType,ValueType>*);
    void showNode(node<KeyType,ValueType>*);

    KeyType keyBuf;
    ValueType valueBuf;

public:
    Tree<KeyType,ValueType>(void):root(nullptr){};
    void add(KeyType, ValueType);
    void remove(KeyType);
    void show(void);

};


template <typename KeyType, typename ValueType>
void Tree<KeyType,ValueType>::add(KeyType keyIN, ValueType valueIN)
{
    if(root==nullptr)
        root=new node<KeyType,ValueType>(keyIN,valueIN);
    else
    {
        keyBuf=keyIN;
        valueBuf=valueIN;
         addNode(root);
    }
}

template <typename KeyType, typename ValueType>
void Tree<KeyType,ValueType>::remove(KeyType keyIN)
{

}



template <typename KeyType, typename ValueType>
void Tree<KeyType,ValueType>::show(void)
{
    if(root==nullptr)
    {
        std::cout<<"Tree is empty";
    }
    else showNode(root);
}



template <typename KeyType, typename ValueType>
void Tree<KeyType,ValueType>::addNode(node<KeyType,ValueType>* fatherNode)
{
    if(fatherNode->key>keyBuf) //left node
    {

        if(fatherNode->left==nullptr)
        {
            fatherNode->left=new node<KeyType,ValueType>(keyBuf,valueBuf);
        }
        else addNode(fatherNode->left);
    }
    else if(fatherNode->key<keyBuf) //right node
    {
        if(fatherNode->right==nullptr)
        {
            fatherNode->right=new node<KeyType,ValueType>(keyBuf,valueBuf);
        }
        else addNode(fatherNode->right);
    }
    else    //equals of keys
    {
        fatherNode->value=valueBuf;
    }
}


template <typename KeyType, typename ValueType>
void Tree<KeyType,ValueType>::showNode(node<KeyType,ValueType>* fatherNode)
{
    if(fatherNode->left!=nullptr) showNode(fatherNode->left);
    if(fatherNode->right!=nullptr) showNode(fatherNode->right);

    std::cout<<fatherNode->key<<" "<<fatherNode->value<<std::endl;

}





#endif // TREE_H_INCLUDED
