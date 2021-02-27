#include <bits/stdc++.h>
using namespace std;

// Author:�����a B093040044
// Date:Oct.29.2020
// BST exercise

//�M��BST��,��Ʒ|��bVECTOR��
struct nodeLR {
    int node;
    int left;
    int right;
};
vector<nodeLR> nodeLR_VEC;

// Binary Search Tree���c
struct BST {
    int element = 0;
    BST* LC = NULL;
    BST* RC = NULL;

    // constructor
    BST(int data) { element = data; }

    //���ǹM���o�ʾ�
    void travel(BST* cur) {
        //���M�����l��
        if (cur->LC != NULL) {
            travel(cur->LC);
        }
        //�N�{�b���`�I��Ʃ�Jvector
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

        //�M���k�l��
        if (cur->RC != NULL) {
            travel(cur->RC);
        }
    }
};

//�ŧi�@�Ӯڸ`�I
BST* root;

//�R���`�I
void delNode(BST* node, BST* par) {
    // node���� �����R��
    if (node->RC == NULL && node->LC == NULL) {
        // node����
        if (par == NULL) {
            node->element = 0;
        }
        // node��parent�����l��
        else if (par->LC == node) {
            delete node;
            par->LC = NULL;
        }
        // node��parent���k�l��
        else {
            delete node;
            par->RC = NULL;
        }
    }
    // node�����l��O�Ū� �k�l�𦳸��
    else if (node->LC == NULL) {
        // node����,�N�k�l����w���s����
        if (par == NULL) {
            root = node->RC;
        }
        // node��parent�����l��,�Nnode���k�l����w��parent�����l��
        else if (par->LC == node) {
            par->LC = node->RC;
        }
        // node��parent���k�l��,�Nnode���k�l����w��parent���k�l��
        else {
            par->RC = node->RC;
        }
        delete node;
    }
    // node���k�l��O�Ū� ���l�𦳸��
    else if (node->RC == NULL) {
        // node����,�N���l����w���s����
        if (par == NULL) {
            root = node->LC;
        }
        // node��parent�����l��,�Nnode�����l����w��parent�����l��
        else if (par->LC == node) {
            par->LC = node->LC;
        }
        // node��parent���k�l��,�Nnode�����l����w��parent���k�l��
        else {
            par->RC = node->LC;
        }
        delete node;
    }
    // node�����k�l��Ҧ����
    else {
        //��M�k�l��inorder successor
        BST* RCleast = node->RC;
        while (RCleast->LC != NULL) {
            RCleast = RCleast->LC;
        }
        RCleast->LC = node->LC;

        // node����,�N�k�l����w���s����
        if (par == NULL) {
            root = node->RC;
        }
        // node��parent�����l��,�Nnode���k�l����w��parent�����l��
        else if (par->LC == node) {
            par->LC = node->RC;
        }
        // node��parent���k�l��,�Nnode���k�l����w��parent���k�l��
        else {
            par->RC = node->RC;
        }
        delete node;
    }
}
//�N��ưe�JBST
void Push(BST* cur, BST* par, int data) {
    //��Ƭ��� ������J���
    if (cur->element == 0) {
        cur->element = data;
        return;
    }
    //��Ƥ��e�`�I�p �V���l��M��
    else if (cur->element > data) {
        //���l�𬰪� ������J
        if (cur->LC == NULL) {
            cur->LC = new BST(data);
            return;
        } else {
            Push(cur->LC, cur, data);
        }
    }
    //��Ƥ��e�`�I�j �V�k�l��M��
    else if (cur->element < data) {
        //�k�l�𬰪� ������J
        if (cur->RC == NULL) {
            cur->RC = new BST(data);
            return;
        } else {
            Push(cur->RC, cur, data);
        }
    }
    //��ƻP��e�`�I�ۦP �����R��
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
        //��l��
        root = new BST(data);
        nodeLR_VEC.clear();

        while (cin >> data) {
            //Ū��-1,�M����BST
            if (data == -1) {
                //�ڪ���Ƭ���
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
            //���ƶǤJBST
            else {
                Push(root, NULL, data);
            }
        }
        printf("\n");
    }
    return 0;
}