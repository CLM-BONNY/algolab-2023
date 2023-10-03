#include <iostream>

struct node
{
  int data;
  struct node *leftSubTree;
  struct node *rightSubTree;
};

void insert(struct node **root, int data);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
int size(struct node *root);
int height(struct node *root);
int sumOfWeight(struct node *root);
int maxPathWeight(struct node *root);
void mirror(struct node **root);
void destruct(struct node **root);

using namespace std;

int main()
{
  int cases;

  cin >> cases;

  while (cases--)
  {
    int num, i;
    struct node *root = NULL;

    cin >> num;

    for (i = 0; i < num; i++)
    {
      int data;

      cin >> data;
      insert(&root, data);
    }
    cout << size(root) << endl;
    cout << height(root) << endl;
    cout << sumOfWeight(root) << endl;
    cout << maxPathWeight(root) << endl;
    mirror(&root);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    destruct(&root); // BST의 모든 노드의 동적 메모리 해제
    if (root == NULL)
      cout << "0" << endl;
    else
      cout << "1" << endl;
  }

  return 0;
}

// 데이터 삽입(recursion)
void insert(struct node **root, int data)
{
  if (*root == NULL)
  {
    struct node *newNode = new node();
    newNode->data = data;
    *root = newNode;
    return;
  }
  if (data > (*root)->data)
    insert(&(*root)->rightSubTree, data);
  else
    insert(&(*root)->leftSubTree, data);
}

// 전위(preorder)탐색(recursion)
void preOrder(struct node *root)
{
  if (root == NULL)
    return;
  else
  {
    cout << root->data << " ";
    preOrder(root->leftSubTree);
    preOrder(root->rightSubTree);
  }
}

// 중위(inorder)탐색(recursion)
void inOrder(struct node *root)
{
  if (root == NULL)
    return;
  else
  {
    inOrder(root->leftSubTree);
    cout << root->data << " ";
    inOrder(root->rightSubTree);
  }
}

// 후위(postorder)탐색(recursion)
void postOrder(struct node *root)
{
  if (root == NULL)
    return;
  else
  {
    postOrder(root->leftSubTree);
    postOrder(root->rightSubTree);
    cout << root->data << " ";
  }
}

// 노드의 개수(recursion)
int size(struct node *root)
{
  if (root == NULL)
    return 0;
  else
  {
    return size(root->leftSubTree) + size(root->rightSubTree) + 1;
  }
}

// 높이(recursion)
int height(struct node *root)
{
  if (root == NULL)
    return -1;
  else
  {
    return max(height(root->leftSubTree), height(root->rightSubTree)) + 1;
  }
}

// 미러 이미지로 변환하기(recursion)
void mirror(struct node **root)
{
  if (root == NULL)
    return;
  else
  {
    if ((*root)->leftSubTree)
      mirror(&(*root)->leftSubTree);
    if ((*root)->rightSubTree)
      mirror(&(*root)->rightSubTree);

    struct node *tmp = (*root)->leftSubTree;
    (*root)->leftSubTree = (*root)->rightSubTree;
    (*root)->rightSubTree = tmp;
  }
}

// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(struct node *root)
{
  if (root == NULL)
    return 0;
  else
  {
    return sumOfWeight(root->leftSubTree) + sumOfWeight(root->rightSubTree) + root->data;
  }
}

// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion)
int maxPathWeight(struct node *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int leftWeight = maxPathWeight(root->leftSubTree);
    int rightWeight = maxPathWeight(root->rightSubTree);
    return root->data + max(leftWeight, rightWeight);
  }
}

// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(struct node **root)
{
  *root = NULL;
}