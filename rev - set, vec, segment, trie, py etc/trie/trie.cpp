// concept: neetcode
// code: apna college

#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"

class node
{
public:
    bool end;
    node *next[26]; // this is like visited array... 0 - a, 25 - z
    // can use map to make memory efficient
    node()
    {
        end = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL; 
        }
        
    }
};


class Trie
{
public:
    node *trie;
    Trie(){
        trie = new node(); // this will be the root node
    }

    void insert(string word){
        node *it = trie;
        for(int i = 0; i < word.size(); i++)
        {
            if(it->next[word[i] - 'a'] == NULL) it->next[word[i] - 'a'] = new node(); // if no match at current node, make a new node
            it = it->next[word[i] - 'a'];

        }
        it->end = true;
    }
    
    bool search(string word)
    {
        node *it = trie;
        for (int i = 0; i < word.size(); i++) // logic: just keeptraversing while the character matches...
        {
            if(it -> next[word[i] - 'a'] == NULL) return false;
            it = it->next[word[i] - 'a'];
        }
        return it->end; // end needs to be true...
    }


};

int main()
{
    Trie *myTrie = new Trie();
    vector<string> words = {"helo", "hello"};
    for (int i = 0; i < words.size(); i++)
    {
        myTrie->insert(words[i]);
    }

    if(myTrie->search("heloo")) cout << "YES" << endl;
    else cout << "No" << endl;

    // EXTRA:
    // cout << 'c' - 'a' << endl;
    // TODO: learn about ascii n characters properly

    // vector<string> arr = {"acd", "acb", "zabcdef", "ac", "adbc"};
    // sort(arr.begin(), arr.end());
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // OP: ac acb acd adbc zabcdef
    

}

/*
TC according to me
search:
O(n), n is size of word
for brute force its gonna be O(n * k), k is number of words in dictionary

insert 1 word:
O(n)

SC:
O(n*k), n - total nodes, k - 26 here...

*/