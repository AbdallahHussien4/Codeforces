#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This code is used for guidance (you can change it if you want).

struct Node
{
    int index;
    int rating;
    Node* parent; // this is optional
    vector<Node*> children;
};


long long maximumSum(Node* root, vector<long long>& memo){// TODO: add the vector 'memo' here) {
  // TODO: enter your code here
    if (root == NULL)
        return 0;
    if (memo[root->index]!=0)
        return memo[root->index];
    //vector<int>temp;
    long long Odd = root->rating;
    for (int i = 0;i < root->children.size();i++)
        for (int j = 0;j < root->children[i]->children.size();j++)
            Odd += maximumSum(root->children[i]->children[j],memo);
    long long Even = 0;
    for (int i = 0;i < root->children.size();i++)
            Even += maximumSum(root->children[i],memo);
    memo[root->index]= max(Odd, Even);

    return memo[root->index];
}


int main() {

    // Number of nodes in the tree
    int N;
    cin >> N;

    vector<Node*> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i] = new Node;
        nodes[i]->index = i;
        cin >> nodes[i]->rating;
    }

    // Iterating over all edges
    int parent, child;
    for (int i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        nodes[child]->parent = nodes[parent];
        nodes[parent]->children.push_back(nodes[child]);
    }

    // TODO: Create a vector called 'memo' used for memoization (What is the dimensions of that vector?)
    vector<long long> memo (N);
    // then uncomment the following line.
    cout << maximumSum(nodes[0], memo);

    return 0;
}