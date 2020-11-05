#include<iostream>
#include<cassert>

using namespace std;

class Node{
private:

public:
  int Key;
  Node* right;
  Node* left;
    Node(){
      right = nullptr;
      left = nullptr;
    }
    Node(int Key){
      right = nullptr;
      left = nullptr;
        this->Key = Key;
    }
};


class BST{

public:
    Node* root;
  BST()
  {
    root = nullptr;
  }
  void inorderBST(Node* r){
    if(r != nullptr){
      inorderBST(r->left);
      cout << r->Key << " ";
      inorderBST(r->right);
    }
  }
  int noNodes(Node* r){
    if (r == nullptr){
     return 0;
    }
     return 1 + noNodes(r->left) + noNodes(r->right);
   }
   int getHeight(Node* r){
     if(!r){
       return 0;
     }
     else{
       int left_h = getHeight(r->left);
       int right_h = getHeight(r->right);
       return 1 + (left_h > right_h ? left_h : right_h);
     }
   }
   Node* maxNode(Node* leftmax){
     while(leftmax->right != nullptr){
       leftmax = leftmax->right;
     }
     return leftmax;
   }
   Node* minNode(Node* rightmin){
     while(rightmin->left != nullptr){
       rightmin = rightmin->left;
     }
     return rightmin;
   }
  void deleteBST(int delkey){
    if(root == nullptr){
      return;
    }
    Node* p = root;
    Node* q = nullptr;
    bool isleft = true;
    while(p->Key != delkey){
      q = p;
      if(delkey < p->Key){
        isleft = true;
        p = q->left;
      }
      else{
        isleft = false;
        p = q->right;
      }
      if(p == nullptr){
        return;
      }
    }
    Node* replace;
    if((p->left == nullptr) && (p->right == nullptr)){
      if(p == root){
        root = nullptr;
      }
      else if(isleft){
        q->left = nullptr;
      }
      else{
        q->right = nullptr;
      }
    }

    else if(p->left == nullptr){
      replace = p->right;
      if(p == root){
        root = replace;
      }
      else if(isleft){
        q->left = replace;
      }
      else {
        q->right = replace;
      }
    }

    else if(p->right == nullptr){
      replace = p->left;
      if(p == root){
        root = replace;
      }
      else if(isleft){
        q->left = replace;
      }
      else{
        q->right = replace;
      }
    }

    else{
      int lefth = getHeight(p->left);
      int righth = getHeight(p->right);
      int noleft = noNodes(p->left);
      int noright = noNodes(p->right);
      Node* rightmin = minNode(p->right);
      Node* leftmax = maxNode(p->left);
      if(lefth > righth){
        replace = leftmax;
      }
      else if(lefth < righth){
        replace = rightmin;
      }
      else if(lefth == righth){
        if(noleft < noright){
          replace = rightmin;
        }
        else {
          replace = leftmax;
        }
      }
      int replacekey = replace->Key;
      if(p == root){
        deleteBST(replace->Key);
        root->Key = replacekey;
      }
      else if(isleft){
        deleteBST(replace->Key);
        q->left->Key = replacekey;
      }
      else{
        deleteBST(replace->Key);
        q->right->Key = replacekey;
      }
    }
  }
  void insertBST(int newkey){
    Node* node = new Node(newkey); // 최종적으로 추가되는 노드
    Node* tmproot = nullptr;

    if(root == nullptr){ // 노드가 없으면 그냥 생
      root = node;
    }
    else {
      Node* p = root;

      while(p != nullptr){
        tmproot = p; // 추가하려는 노드의 부모노드가 됨
        if(node->Key < p->Key){ // 추가 하려는 값이 현재 노드보다 작으면
          p = p->left; // 왼쪽으로 이동
        }
        else{
          p = p->right; // 오른쪽으로 이동
        }
      }
      if(node->Key < tmproot->Key){
        tmproot->left = node;
      }
      else{
        tmproot->right = node;
      }
    }
  }
};
int main() {
  BST n;
  n.insertBST(25);
  n.insertBST(9);
  n.insertBST(37);
  n.insertBST(45);
  n.insertBST(56);
  n.insertBST(18);
  n.insertBST(4);
  n.insertBST(40);
  n.insertBST(38);
  n.insertBST(55);
  n.insertBST(39);
  n.deleteBST(25);
  n.deleteBST(37);
  n.deleteBST(45);
  n.deleteBST(38);
  n.deleteBST(39);
  n.deleteBST(40);
  n.deleteBST(18);
  n.inorderBST(n.root);
  cout << endl;

  return 0;
}
