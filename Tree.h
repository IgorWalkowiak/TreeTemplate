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
    void removeNode(node<KeyType,ValueType>*);
    node<KeyType,ValueType>* lastLeftNode(node<KeyType,ValueType>*);

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
    keyBuf=keyIN;
    if(root==nullptr) std::cout<<"Something goes wrong";
    else if(root->key==keyBuf)
    {
            node<KeyType,ValueType>* leftNodeBuf=root->left;
            node<KeyType,ValueType>* rightNodeBuf=root->right;
            delete root;
            root=rightNodeBuf;
                if(root!=nullptr)
                {
                    lastLeftNode(root)->left=leftNodeBuf;
                }
                else root=leftNodeBuf;
    }
    else
    removeNode(root);
}



template <typename KeyType, typename ValueType>
void Tree<KeyType,ValueType>::removeNode(node<KeyType,ValueType>* fatherNode)
{
    if(fatherNode->key>keyBuf)//left
    {
        if(fatherNode->left!=nullptr)
        {
            if(fatherNode->left->key==keyBuf)
            {
                node<KeyType,ValueType>* leftNodeBuf=fatherNode->left->left;
                node<KeyType,ValueType>* rightNodeBuf=fatherNode->left->right;
                delete fatherNode->left;
                fatherNode->left=rightNodeBuf;
                if(fatherNode->left!=nullptr)
                {
                    lastLeftNode(fatherNode->left)->left=leftNodeBuf;
                }
                else fatherNode=leftNodeBuf;
            }
            else
            removeNode(fatherNode->left);
        }
        else
        std::cout<<"There is no key: "<<keyBuf;
    }
    else //right
    {
        if(fatherNode->right!=nullptr)
        {
            if(fatherNode->right->key==keyBuf)
            {
                node<KeyType,ValueType>* leftNodeBuf=fatherNode->right->left;
                node<KeyType,ValueType>* rightNodeBuf=fatherNode->right->right;
                delete fatherNode->right;
                fatherNode->right=rightNodeBuf;
                if(fatherNode->right!=nullptr)
                {
                    lastLeftNode(fatherNode->right)->left=leftNodeBuf;
                }
                else fatherNode=leftNodeBuf;
            }
            else
            removeNode(fatherNode->right);
        }
        else
        std::cout<<"There is no key: "<<keyBuf;
    }
}


template <typename KeyType, typename ValueType>
node<KeyType,ValueType>* Tree<KeyType,ValueType>::lastLeftNode(node<KeyType,ValueType>* fatherNode)
{
    if(fatherNode->left!=nullptr)
    lastLeftNode(fatherNode->left);
    else return fatherNode;
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
      std::cout<<"Key: "<<fatherNode->key<<" Value: "<<fatherNode->value<<std::endl;
    if(fatherNode->right!=nullptr) showNode(fatherNode->right);
}





#endif // TREE_H_INCLUDED
