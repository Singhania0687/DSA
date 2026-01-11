// covered all conecpts of trie 
# include<iostream>
# include<vector>
using namespace std;

// Declaring a class for constructing Trie
class Trie{
    public:
    Trie* children[26];
    bool isEnd;
    Trie(){
        for(int i=0;i<26;++i)
        {
            children[i]=NULL;
        }
        isEnd=false;
    }
};

// Now initializing the trie to compose a class to handle different tasks
class TrieOperation{
    public:
    Trie* root;
    TrieOperation(){
        root=new Trie();
    }
    // Insert an element in the Trie 
    void insert(string st){
       
    }
    // Serach an element in the trie
    bool search(string st){

    }
    // delete an element from the trie
    void deleteElement(string st){

    }
    // count # of prefixes that start with the given string
    int countPrefix(string st){

    }

    // longest prefix
    string longestPrefix(string st){
        
    }
};

int main(){

}