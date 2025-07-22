#include <iostream>

#ifndef BST_H
#define BST_H

/**
 * \brief A Node structure for the Binary Search Tree (BST).
 * \param T The type of data stored in the node.
 */
template <class T>
struct Node{
  /**
   * \brief The left child of the node.
   */
  Node<T>* left;

  /**
   * \brief The right child of the node.
   */
  Node<T>* right;

  /**
   * \brief The value stored in the node.
   */
  T value;

  /**
   * \brief The height of the node.
   */
  int height;

  /**
   * \brief Constructor to initialize a node with a value.
   * \param data The value to store in the node.
   */
  Node(const T& data): value(data), left(nullptr), right(nullptr), height(0){}
};

/**
 * \brief A Binary Search Tree (BST) implementation.
 * \param T The type of data stored in the BST.
 */
template <class T>
class BST{
  private:
  /**
   * \brief The root node of the BST.
   */
  Node<T>* root;

  /**
   * \brief Search for a node with the given data.
   * \param node The current node to search in.
   * \param data The value to search for.
   * \return True if the node is found, false otherwise.
   */
  bool Search(Node<T>* node, const T& data);

  /**
   * \brief Perform an in-order traversal of the BST.
   * \param node The current node to traverse.
   * \param fn The function to apply to each node's data.
   */
  void InOrder(Node<T>* node, void(*fn)(const T& data)) const;

  /**
   * \brief Perform a post-order traversal of the BST.
   * \param node The current node to traverse.
   * \param fn The function to apply to each node's data.
   */
  void PostOrder(Node<T>* node, void(*fn)(const T& data)) const;

  /**
   * \brief Perform a pre-order traversal of the BST.
   * \param node The current node to traverse.
   * \param fn The function to apply to each node's data.
   */
  void PreOrder(Node<T>* node, void (*fn)(const T& data)) const;

  /**
   * \brief Destroy the entire tree and free memory.
   * \param node The node to start destroying from.
   */
  void DestroyTree(Node<T>* node);

  protected:
  /**
   * \brief Copy a node from another tree.
   * \param other_node The node to copy from.
   * \return A new node or the updated subtree after copying.
   */
  virtual Node<T>* Copy(const Node<T>* other_node);

  /**
   * \brief Insert a node into the BST.
   * \param node The current node to insert into.
   * \param data The value to insert.
   * \return The new node or the updated subtree after insertion.
   */
  virtual Node<T>* Insert(Node<T>* node, const T& data);

  /**
   * \brief Delete a node from the BST.
   * \param node The current node to delete from.
   * \param data The value to delete.
   * \return The new node or the updated subtree after deletion.
   */
  virtual Node<T>* DeleteNode(Node<T>* node, const T& data);

  public:
  /**
   * \brief Constructor to initialize an empty BST.
   */
  BST() : root(nullptr){}

  /**
   * \brief Copy constructor to create a new BST from another.
   * \param other The BST to copy from.
   */
  BST(const BST<T>& other);

  /**
   * \brief Destructor to clean up the BST.
   */
  virtual ~BST();

  /**
   * \brief Insert a value into the BST.
   * \param data The value to insert.
   */
  void Insert(const T& data);

  /**
   * \brief Search for a value in the BST.
   * \param data The value to search for.
   * \return True if the value is found, false otherwise.
   */
  bool Search(const T& data);

  /**
   * \brief Delete a value from the BST.
   * \param data The value to delete.
   */
  void DeleteNode(const T& data);

  /**
   * \brief Perform an in-order traversal of the BST.
   * \param fn The function to apply to each node's data.
   */
  void InOrder(void (*fn)(const T& data)) const;

  /**
   * \brief Perform a post-order traversal of the BST.
   * \param fn The function to apply to each node's data.
   */
  void PostOrder(void (*fn)(const T& data)) const;

  /**
   * \brief Perform a pre-order traversal of the BST.
   * \param fn The function to apply to each node's data.
   */
  void PreOrder(void (*fn)(const T& data)) const;

  /**
   * \brief Destroy the entire tree and free memory.
   */
  void DestroyTree();

  /**
   * \brief Destroy the tree starting from a specific node.
   * \param node The node to start destroying from.
   */
  BST<T>& operator =(const BST<T>& other);
};

template <class T>
BST<T>::BST(const BST<T>& other){
  root = Copy(other.root);
}

template <class T>
BST<T>::~BST(){
  DestroyTree();
}

template <class T>
Node<T>* BST<T>::Insert(Node<T>* node, const T& data){
  if(node == nullptr) return new Node<T>(data);

  if(data > node->value){
    node->right = Insert(node->right, data);
  }
  else if(data < node->value){
    node->left = Insert(node->left, data);
  }

  return node;
}

template <class T>
bool BST<T>::Search(Node<T>* node, const T& data){
  if(node == nullptr) return false;

  if(data > node->value){
    return Search(node->right, data);
  }
  else if(data < node->value){
    return Search(node->left, data);
  }

  return true;
}

template <class T>
Node<T>* BST<T>::DeleteNode(Node<T>* node, const T& data){
  if(node == nullptr) return nullptr;

  if(data > node->value){
    node->right = DeleteNode(node->right, data);
  }
  else if(data < node->value){
    node->left = DeleteNode(node->left, data);
  }
  else{
    if(!node->left && !node->right){
      delete node;
      node = nullptr;
    }
    else if(!node->left){
      Node<T>* temp = node->right;
      delete node;
      node = temp;
    }
    else if(!node->right){
      Node<T>* temp = node->left;
      delete node;
      node = temp;
    }
    else{
      Node<T>* successor = node->right;

      while(successor->left)
        successor = successor->left;

      node->value = successor->value;
      node->right = DeleteNode(node->right, node->value);
    }
  }

  return node;
}

template <class T>
void BST<T>::InOrder(Node<T>* node, void (*fn)(const T& data)) const{
  if(node == nullptr) return;

  InOrder(node->left, fn);
  fn(node->value);
  InOrder(node->right, fn);
}

template <class T>
void BST<T>::PostOrder(Node<T>* node, void (*fn)(const T& data)) const{
  if(node == nullptr) return;
  PostOrder(node->left, fn);
  PostOrder(node->right, fn);
  fn(node->value);
}

template <class T>
void BST<T>::PreOrder(Node<T>* node, void (*fn)(const T& data)) const{
  if(node == nullptr) return;

  fn(node->value);
  PreOrder(node->left, fn);
  PreOrder(node->right, fn);
}

template <class T>
void BST<T>::DestroyTree(Node<T>* node){
  if(node == nullptr) return;
  DestroyTree(node->left);
  DestroyTree(node->right);

  delete node;
}

template <class T>
void BST<T>::Insert(const T& data){
  root = Insert(root, data);
}

template <class T>
bool BST<T>::Search(const T& data){
  return Search(root, data);
}

template <class T>
void BST<T>::DeleteNode(const T& data){
  root = DeleteNode(root, data);
}

template <class T>
void BST<T>::InOrder(void (*fn)(const T& data)) const{
  InOrder(root, fn);
}

template <class T>
void BST<T>::PostOrder(void (*fn)(const T& data)) const{
  PostOrder(root, fn);
}

template <class T>
void BST<T>::PreOrder(void (*fn)(const T& data)) const{
  PreOrder(root, fn);
}

template <class T>
void BST<T>::DestroyTree(){
  DestroyTree(root);
  root = nullptr;
}

template <class T>
Node<T>* BST<T>::Copy(const Node<T>* other_node){
  if(other_node == nullptr) return nullptr;

  Node<T>* node = new Node<T>(other_node->value);

  node->left = Copy(other_node->left);
  node->right = Copy(other_node->right);

  return node;
}

template <class T>
BST<T>& BST<T>::operator =(const BST<T>& other){
  if(this != &other){
    DestroyTree();
    root = Copy(other.root);
  }

  return *this;
}

#endif