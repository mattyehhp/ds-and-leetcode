#include <iostream>
#include <queue>
using namespace std;

struct BstNode {
  int data;
  BstNode *left;
  BstNode *right;
};

BstNode* GetNewNode(int data) {
  BstNode *newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}



BstNode* Inset(BstNode* root, int data) {
  if (root == NULL) {
    root = GetNewNode(data);
  } else if (data <= root->data) {
    root->left = Inset(root->left, data);
  } else if (data > root->data) {
    root->right = Inset(root->right, data);
  }
  return root;
}

// Another way to implement inserting a node

// void Insert(BstNode** root, int data) {
//   if (*root == NULL) {
//     *root = GetNewNode(data);
//   } else if (data <= (*root)->data) {
//     Insert(&((*root)->left), data);
//   } else if (data > (*root)->data) {
//     Insert(&((*root)->right), data);
//   }
// }

bool Search(BstNode* root, int data) {
  if (root == NULL) {
    return false;
  } else if (data == root->data) {
    return true;
  } else if (data < root->data) {
    return Search(root->left, data);
  } else if (data > root->data) {
    return Search(root->right, data);
  }
}

void LevelbyLevelPrinting(BstNode* root) {
  if (root == NULL) {
    return;
  }
  int levelCount = 1;
  int currentCount = 0;
  BstNode* currentNode;
  queue<BstNode*> nodeQueue;
  nodeQueue.push(root);
  
  while (!nodeQueue.empty()) {
    currentNode = nodeQueue.front();
    if (currentNode->left) {
      nodeQueue.push(currentNode->left);
      currentCount++;
    }
    if (currentNode->right) {
      nodeQueue.push(currentNode->right);
      currentCount++;
    }
    cout << currentNode->data;
    cout << " ";
    nodeQueue.pop();
    levelCount--;
    if (levelCount == 0) {
      cout << "\n";
      levelCount = currentCount;
      currentCount = 0;
    }
  }
  return;
}


int main() {
  BstNode *root = NULL;
  // Insert(&root, 15);
  // Insert(&root, 20);
  // Insert(&root, 25);
  // Insert(&root, 30);
  
  // Insert(&root, 5);
  root = Inset(root, 8);
  
  root = Inset(root, 5);

  root = Inset(root, 11);
  
  root = Inset(root, 3);
 
  root = Inset(root, 20);
  
  LevelbyLevelPrinting(root);
  return 0;
}