// #include<bits/stdc++.h>
// using namespace std;
// class Trie;
// class Node{
//     bool end;
//     Node* next[26];
// public:
//     friend int main();
//     friend class Trie;
//     Node(){
//         end = false;
//         for(int i=0;i<26;i++)
//             next[i] = NULL;
//     }
// };

// class Trie{
//     Node* trie;
// public:
//     Trie(){
//         trie = new Node;
//     }

//     void insert(string word){
//         Node* it = trie;
//         for(int i=0; i < word.size(); i++){
//             if(it->next[word[i]-'a'] == NULL)
//                 it->next[word[i]-'a'] = new Node;
//             it = it->next[word[i]-'a'];
//         }
//         it->end = true;
//     }

//     bool search(string word){
//         Node* it = trie;
//         for(int i=0; i < word.size(); i++){
//             if(it->next[word[i]-'a'] == NULL)
//                 return false;
//             it = it->next[word[i]-'a'];
//         }
//         return it->end;
//     }
// };

// int main(){
//     Trie myTrie;
//     vector<string> words = {"chintan","suthar"};
//     for(auto w : words)
//         myTrie.insert(w);
//     cout << myTrie.search("krunal");
//     cout << myTrie.search("chintan");
//     return 0;
// }



struct Node {
    Node* next[26] = {NULL};
    int endWith = 0;
    int countPrefix = 0;
};
Node* trie = new Node;
void insert(string &word) {
    auto it = trie;
    for(int i = 0; i < word.size(); ++i) {
        if(it->next[word[i] - 'a'] == NULL) {
            it->next[word[i] - 'a'] = new Node;
        }
        it->next[word[i] - 'a']->countPrefix++;
        it = it->next[word[i] - 'a'];
    }
    it->endWith++;
}