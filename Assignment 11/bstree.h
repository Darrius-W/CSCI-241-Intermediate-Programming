#ifndef BSTREE_H
 #define BSTREE_H

#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;
using std::queue;

template <class K, class V>
struct node
{
  K keyStore;//key field
  V keyValue;
  node<K, V>* leftChild;
  node<K, V>* rightChild;

  node (const K& keyStore = K(), const V& keyValue = V(),
        node<K, V>* leftChild = nullptr, node<K, V>* rightChild = nullptr){
    this->keyStore = keyStore;
    this->keyValue = keyValue;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
};

template <class K, class V>
class bstree
{
  private:
        node<K, V>* root;
        size_t numNodes;
        void pvtClear(node<K, V>*);
        size_t pvtHeight(node<K, V>*) const;
        void pvtPreorder(node<K, V>*) const;
        void pvtInorder(node<K, V>*) const;
        void pvtPostorder(node<K, V>*) const;
        node<K, V>* clone(node<K, V>*) const;

  public:
        bstree();
        void clear();
        ~bstree();
        size_t height() const;
        size_t size() const;
        bool empty() const;
        const node<K, V>* find(const K&) const;
        void preorder() const;
        void inorder() const;
        void postorder() const;
        void level_order() const;
        bool insert(const K&, const V&);
        const K& min() const;
        const K& max() const;
        bstree(const bstree<K, V>&);
        bstree<K, V>& operator=(const bstree<K, V>&);
        bool remove(const K&);
};

//constructor
//initialize data members
template <class K, class V>
bstree<K, V>::bstree(){
  root = nullptr;
  numNodes = 0;
}

//public clear method
//calls private clear method and sets tree to empty state
template <class K, class V>
void bstree<K, V>::clear(){
  pvtClear(root);
  root = nullptr;
  numNodes = 0;
}

//private clear method
//deleting nodes
template <class K, class V>
void bstree<K, V>::pvtClear(node<K, V>* root){
  if (root != nullptr){
    pvtClear(root->leftChild);
    pvtClear(root->rightChild);

    delete root;
  }
}

//deconstructor
//calls clear method
template <class K, class V>
bstree<K, V>::~bstree(){
  clear();
}

//height method
//returns height from pvtHeight method
template <class K, class V>
size_t bstree<K, V>::height() const{
  return pvtHeight(root);
}

//private height method
//finds the height
template <class K, class V>
size_t bstree<K, V>::pvtHeight(node<K, V>* root) const{
  if (root == nullptr)
    return 0;

  size_t leftSubTree =  pvtHeight(root->leftChild);//assigns height of left sub tree
  size_t rightSubTree = pvtHeight(root->rightChild);//assign height of right sub tree

  if (leftSubTree > rightSubTree)
    return leftSubTree + 1;

  else
    return rightSubTree + 1;
}

//size method
//returns size_t
template <class K, class V>
size_t bstree<K, V>::size() const{
  return numNodes;
}

//empty method
//returns true/false depending if the number of nodes is 0 or greater
template <class K, class V>
bool bstree<K, V>::empty() const{
  if (numNodes == 0)
    return true;

  else
    return false;
}

//find method
//tries to find specified key in binary search tree
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const{
  node<K, V>* ptr = root;

  while (ptr != nullptr && key != ptr->keyStore){
    if (key < ptr->keyStore)
      ptr = ptr->leftChild;

    else
      ptr = ptr->rightChild;
  }
  return ptr;
}

//preorder method
//calls the private preorder method
template <class K, class V>
void bstree<K, V>::preorder() const{
  pvtPreorder(root);
}

//private preorder method
//performs preorder traversal of the tree from left to right
template <class K, class V>
void bstree<K, V>::pvtPreorder(node<K, V>* root) const{
  if (root != nullptr){
    cout << root->keyStore << ": " << root->keyValue << endl;

    pvtPreorder(root->leftChild);
    pvtPreorder(root->rightChild);
  }
}

//inorder method
//calls private inorder method
template <class K, class V>
void bstree<K, V>::inorder() const{
  pvtInorder(root);
}

//private inorder method
//performs inorder traversal of tree from left to right
template <class K, class V>
void bstree<K, V>::pvtInorder(node<K, V>* root) const{
  if (root != nullptr){
    pvtInorder(root->leftChild);

    cout << root->keyStore << ": " << root->keyValue << endl;

    pvtInorder(root->rightChild);
  }
}

//postorder method
//calls private postorder method
template <class K, class V>
void bstree<K, V>::postorder() const{
  pvtPostorder(root);
}

//private postorder method
//performs a postorder traversal of the tree from left to right
template <class K, class V>
void bstree<K, V>::pvtPostorder(node<K, V>* root) const{
  if (root != nullptr){
    pvtPostorder(root->leftChild);
    pvtPostorder(root->rightChild);

    cout << root->keyStore << ": " << root->keyValue << endl;
  }
}

//level order method
//performs level order transversal of tree from left to right
template <class K, class V>
void bstree<K, V>::level_order() const{
  queue<node<K, V>*> q;
  node<K, V>* item;

  if (root == nullptr)
    return;

  q.push(root);

  while (!q.empty()){

    item = q.front();
    cout << item->keyStore << ": " << item->keyValue << endl;

    if (item->leftChild != nullptr)
      q.push(item->leftChild);

    if (item->rightChild != nullptr)
      q.push(item->rightChild);

    q.pop();
  }
}

//insert method
//inserts a key value into binary search tree
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value){
  node<K, V>* p = root;
  node<K, V>* parent = nullptr;

  while (p != nullptr && key != p->keyStore){
    parent = p;

    if (key < p->keyStore)
      p = p->leftChild;

    else
      p = p->rightChild;
  }

  if (p != nullptr)
    return false;

  node<K, V>* newNode = new node<K, V>(key, value);

  if (parent == nullptr)
    root = newNode;

  else{
    if (newNode->keyStore < parent->keyStore)
      parent->leftChild = newNode;

    else
      parent->rightChild = newNode;
  }

  numNodes++;

  return true;
}

//min method
//finds the minimum key field in the binary search tree
template <class K, class V>
const K& bstree<K, V>::min() const{
  node<K, V>* ptr = root;

  while (ptr->leftChild != nullptr)
    ptr = ptr->leftChild;

  return (ptr->keyStore);
}

//max method
//finds the maximum key field in the binary search tree
template <class K, class V>
const K& bstree<K, V>::max() const{
  node<K, V>* ptr = root;

  while (ptr->rightChild != nullptr)
    ptr = ptr->rightChild;

  return ptr->keyStore;
}

//clone method
//clones binary tree
template <class K, class V>
node<K, V>* bstree<K, V>::clone(node<K, V>* ptr) const{
  if (ptr != nullptr){
    node<K, V>* newNode = new node<K, V>(ptr->keyStore, ptr->keyValue);

    newNode->keyStore = ptr->keyStore;
    newNode->keyValue = ptr->keyValue;

    newNode->leftChild = clone(ptr->leftChild);
    newNode->rightChild = clone(ptr->rightChild);

    return newNode;
  }
  else
    return nullptr;
}

//copy constructor
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x){
  numNodes = x.numNodes;

  root = clone(x.root);
}

//assignment operator method
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x){
  if (this != &x){
    clear();

    numNodes = x.numNodes;
    root = clone(x.root);
  }
  return *this;
}

//remove method
//removes specified key from binary search tree
template <class K, class V>
bool bstree<K, V>::remove(const K& key){
  node<K, V>* ptr = root;
  node<K, V>* parent = nullptr;
  node<K, V>* temp;
  node<K, V>* tempParent;


  while (ptr != nullptr && key != ptr->keyStore){
    parent = ptr;

    if (key < ptr->keyStore)
      ptr = ptr->leftChild;

    else
      ptr = ptr->rightChild;
  }

  if (ptr == nullptr)
    return false;

  if (ptr->leftChild == nullptr)
    temp = ptr->rightChild;

  else if (ptr->rightChild == nullptr)
    temp = ptr->leftChild;


  else{
    tempParent = ptr;
    temp = ptr->leftChild;

    while (temp->rightChild != nullptr){
      tempParent = temp;
      temp = temp->rightChild;
    }

    if (tempParent != ptr){
      tempParent->rightChild = temp->leftChild;
      temp->leftChild = ptr->leftChild;
    }

    temp->rightChild = ptr->rightChild;
  }


  if (parent == nullptr)
    root = temp;

  else{
    if (ptr->keyStore < parent->keyStore)
      parent->leftChild = temp;

    else
      parent->rightChild = temp;
  }
  numNodes--;

  return true;
}
#endif
