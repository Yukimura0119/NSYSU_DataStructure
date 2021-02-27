#include <bits/stdc++.h>
using namespace std;

// Author:蔡明軒 B093040044
// Date:Oct.29.2020
// BST exercise

//遍歷BST時,資料會放在VECTOR中
struct nodeLR {
    int node;
    int left;
    int right;
};
vector<nodeLR> nodeLR_VEC;

// Binary Search Tree結構
struct BST {
    int element = 0;
    BST* LC = NULL;
    BST* RC = NULL;

    // constructor
    BST(int data) { element = data; }

    //中序遍歷這棵樹
    void travel(BST* cur) {
        //先遍歷左子樹
        if (cur->LC != NULL) {
            travel(cur->LC);
        }
        //將現在的節點資料放入vector
        nodeLR tmp;
        tmp.node = cur->element;
        if (cur->LC == NULL) {
            tmp.left = 0;
        } else {
            tmp.left = cur->LC->element;
        }
        if (cur->RC == NULL) {
            tmp.right = 0;
        } else {
            tmp.right = cur->RC->element;
        }
        nodeLR_VEC.push_back(tmp);

        //遍歷右子樹
        if (cur->RC != NULL) {
            travel(cur->RC);
        }
    }
};

//宣告一個根節點
BST* root;

//刪除節點
void delNode(BST* node, BST* par) {
    // node為樹葉 直接刪除
    if (node->RC == NULL && node->LC == NULL) {
        // node為根
        if (par == NULL) {
            node->element = 0;
        }
        // node為parent的左子樹
        else if (par->LC == node) {
            delete node;
            par->LC = NULL;
        }
        // node為parent的右子樹
        else {
            delete node;
            par->RC = NULL;
        }
    }
    // node的左子樹是空的 右子樹有資料
    else if (node->LC == NULL) {
        // node為根,將右子樹指定為新的根
        if (par == NULL) {
            root = node->RC;
        }
        // node為parent的左子樹,將node的右子樹指定為parent的左子樹
        else if (par->LC == node) {
            par->LC = node->RC;
        }
        // node為parent的右子樹,將node的右子樹指定為parent的右子樹
        else {
            par->RC = node->RC;
        }
        delete node;
    }
    // node的右子樹是空的 左子樹有資料
    else if (node->RC == NULL) {
        // node為根,將左子樹指定為新的根
        if (par == NULL) {
            root = node->LC;
        }
        // node為parent的左子樹,將node的左子樹指定為parent的左子樹
        else if (par->LC == node) {
            par->LC = node->LC;
        }
        // node為parent的右子樹,將node的左子樹指定為parent的右子樹
        else {
            par->RC = node->LC;
        }
        delete node;
    }
    // node的左右子樹皆有資料
    else {
        //找尋右子樹的inorder successor
        BST* RCleast = node->RC;
        while (RCleast->LC != NULL) {
            RCleast = RCleast->LC;
        }
        RCleast->LC = node->LC;

        // node為根,將右子樹指定為新的根
        if (par == NULL) {
            root = node->RC;
        }
        // node為parent的左子樹,將node的右子樹指定為parent的左子樹
        else if (par->LC == node) {
            par->LC = node->RC;
        }
        // node為parent的右子樹,將node的右子樹指定為parent的右子樹
        else {
            par->RC = node->RC;
        }
        delete node;
    }
}
//將資料送入BST
void Push(BST* cur, BST* par, int data) {
    //資料為空 直接放入資料
    if (cur->element == 0) {
        cur->element = data;
        return;
    }
    //資料比當前節點小 向左子樹遍歷
    else if (cur->element > data) {
        //左子樹為空 直接放入
        if (cur->LC == NULL) {
            cur->LC = new BST(data);
            return;
        } else {
            Push(cur->LC, cur, data);
        }
    }
    //資料比當前節點大 向右子樹遍歷
    else if (cur->element < data) {
        //右子樹為空 直接放入
        if (cur->RC == NULL) {
            cur->RC = new BST(data);
            return;
        } else {
            Push(cur->RC, cur, data);
        }
    }
    //資料與當前節點相同 直接刪除
    else {
        delNode(cur, par);
        return;
    }
}

int main() {
    int data;
    while (cin >> data) {
        if (data == EOF) {
            break;
        }
        //初始化
        root = new BST(data);
        nodeLR_VEC.clear();

        while (cin >> data) {
            //讀到-1,遍歷此BST
            if (data == -1) {
                //根的資料為空
                if (root->element == 0) {
                    printf("node: 0\nleft: 0\nright: 0\n");
                } else {
                    root->travel(root);
                    printf("node:");
                    for (int i = 0; i < nodeLR_VEC.size(); i++) {
                        printf(" %d", nodeLR_VEC[i].node);
                    }
                    printf("\nleft:");
                    for (int i = 0; i < nodeLR_VEC.size(); i++) {
                        printf(" %d", nodeLR_VEC[i].left);
                    }
                    printf("\nright:");
                    for (int i = 0; i < nodeLR_VEC.size(); i++) {
                        printf(" %d", nodeLR_VEC[i].right);
                    }
                    printf("\n");
                }
                break;
            }
            //把資料傳入BST
            else {
                Push(root, NULL, data);
            }
        }
        printf("\n");
    }
    return 0;
}