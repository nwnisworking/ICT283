#ifndef AVL_H
#define AVL_H

#include <iostream>

using std::cout;
using std::endl;
#include "bst.h"

/**
 * \brief An AVL implementation of a Binary Search Tree (BST).
 */
template <class T>
class AVL : public BST<T>{
  private:
  /**
   * \brief Insert a node into the AVL tree and balances it. This overrides the insert method from BST as it requires balancing after insertion.
   * \param node The node to insert into.
   * \param data The value to insert.
   * \return A new node or the updated subtree after insertion and balancing.
   */
  Node<T>* Insert(Node<T>* node, const T& data) override;

  /**
   * \brief Delete a node from the AVL tree and balances it. This overrides the deleteNode method from BST as it requires balancing after deletion.
   * \param node The node to delete from.
   * \param data The value to delete.
   * \return A new node or the updated subtree after deletion and balancing.
   */
  Node<T>* DeleteNode(Node<T>* node, const T& data) override;

  /**
   * \brief Copy a node from another tree and balances it. This overrides the copy method from BST as it requires balancing after copying.
   * \param other_node The node to copy from.
   * \return A new node or the updated subtree after copying and balancing.
   */
  Node<T>* Copy(const Node<T>* other_node) override;

  /**
   * \brief Rotate a subtree to the left.
   * \param node The node to rotate.
   * \return The new successor after rotation.
   */
  Node<T>* RotateLeft(Node<T>* node);

  /**
   * \brief Rotate a subtree to the right.
   * \param node The node to rotate.
   * \return The new successor after rotation.
   */
  Node<T>* RotateRight(Node<T>* node);

  /**
   * \brief Balance the AVL tree.
   * \param node The node to balance.
   * \return The new root of the balanced subtree.
   */
  Node<T>* Balance(Node<T>* node);

  /**
   * \brief Get the balance factor of a node.
   * \param node The node to check.
   * \return The balance factor (height of left subtree - height of right subtree).
   */
  int GetFactor(const Node<T>* node) const;

  static int GetHeight(const Node<T>* node);
  public:
  // Due to name hiding, we need to explicitly use the base class methods to access them.
  // The implementation of these methods are valid, except, after insert, delete, and copy operations,
  // the tree must be balanced.
  using BST<T>::Insert;
  using BST<T>::DeleteNode;
  using BST<T>::Copy;
};

template <class T>
Node<T>* AVL<T>::Insert(Node<T>* node, const T& data){
  return Balance(BST<T>::Insert(node, data));
}

template <class T>
Node<T>* AVL<T>::Copy(const Node<T>* other_node){
  return Balance(BST<T>::Copy(other_node));
}

template <class T>
Node<T>* AVL<T>::DeleteNode(Node<T>* node, const T& data){
  return Balance(BST<T>::DeleteNode(node, data));
}

template <class T>
Node<T>* AVL<T>::RotateLeft(Node<T>* node){
  Node<T>* successor = node->right;
  Node<T>* child = successor->left;

  successor->left = node;
  node->right = child;

  successor->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
  node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

  return successor;
}

template <class T>
Node<T>* AVL<T>::RotateRight(Node<T>* node){
  Node<T>* successor = node->left;
  Node<T>* child = successor->right;

  successor->right = node;
  node->left = child;

  successor->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
  node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

  return successor;
}

template <class T>
Node<T>* AVL<T>::Balance(Node<T>* node){
  if(node == nullptr) return nullptr;

  node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

  int factor = GetFactor(node);

  if(factor < -1){
    if(node->right && GetFactor(node->right) > 0){
      node->right = RotateRight(node->right);
    }

    node = RotateLeft(node);
  }
  else if(factor > 1){
    if(node->left && GetFactor(node->left) < 0){
      node->left = RotateLeft(node->left);
    }

    node = RotateRight(node);
  }

  return node;
}

template <class T>
int AVL<T>::GetFactor(const Node<T>* node) const{
  return GetHeight(node->left) - GetHeight(node->right);
}

template <class T>
int AVL<T>::GetHeight(const Node<T>* node){
  return node == nullptr ? -1 : node->height;
}

#endif
