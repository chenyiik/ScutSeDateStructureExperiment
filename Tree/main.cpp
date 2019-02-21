#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "HuffmanTree.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    BinaryTree<1000> BT0;
    int n = 0;

    cout << "n: ";
    cin >> n;
    BT0.build(n);
    BT0.preorder();
    cout << endl;
    BT0.inorder();
    cout << endl;
    BT0.postorder();
    cout << endl;

    cout << "n: ";
    cin >> n;
    BT0.build_by_preorder_inorder(n);
    BT0.postorder();
    cout << endl;

    BinarySearchTree<1000> BT1;
    cout << "n: ";
    cin >> n;
    BT1.build(n);
    int q = 0;
    while (cin >> q && q == 1)
    {
        cin >> q;
        cout << (BT1.find(q) ? "True" : "False") << endl;
    }

    HuffmanTree<1000> BT2;
    cout << "n: ";
    cin >> n;
    BT2.build(n);
    BT2.code();

    return 0;
}
