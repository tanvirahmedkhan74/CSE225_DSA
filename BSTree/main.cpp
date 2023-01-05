#include <iostream>
#include "binarysearchtree.cpp"

/**
Given a sequence of integers, determine the best ordering of
the integers to insert them into a binary search tree. The best
order is the one that will allow the binary search tree to have
the minimum height.

Hint: Sort the sequence (use the inorder traversal). The middle
element is the root. Insert it into an empty tree. Now in the
same way, recursively build the left subtree and then the right
subtree.
**/

void get_balanced(TreeType<int> &tree, int arr[], int l, int r){
    if(l > r){
        return;
    }

    int mid = (l + r) / 2;

    tree.InsertItem(arr[mid]);

    get_balanced(tree, arr, l, mid - 1);

    get_balanced(tree, arr, mid+1, r);
}

int main()
{
    // 11  9  4  2  7  3  17  0  5  1
    TreeType<int> tree = TreeType<int>();

    tree.InsertItem(11);
    tree.InsertItem(9);
    tree.InsertItem(4);
    tree.InsertItem(2);
    tree.InsertItem(7);
    tree.InsertItem(3);
    tree.InsertItem(17);
    tree.InsertItem(0);
    tree.InsertItem(5);
    tree.InsertItem(1);

    tree.ResetTree(IN_ORDER);

    int arr[10];

    int idx = 0;

    bool finish = false;
    while(!finish){
        tree.GetNextItem(arr[idx++], IN_ORDER, finish);
    }

    tree.MakeEmpty();

    get_balanced(tree, arr, 0, 9);

    tree.ResetTree(PRE_ORDER);

    int temp;

    finish = false;
    while(!finish){
        tree.GetNextItem(temp, PRE_ORDER, finish);
        std::cout << temp << " ";
    }

    return 0;

}
