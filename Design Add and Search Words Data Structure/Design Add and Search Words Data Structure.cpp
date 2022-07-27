#define SIZE 26
class Trie{
    struct trie{
        char ch;
        bool found;
        trie* child[SIZE];
        trie(char c){
            ch=c;
            for(int i=0;i<SIZE;i++)child[i]=NULL;
            found = false;
        }
    };
    trie * root;
    public:
    
    Trie(){
        root= new trie('/');
    }
    void insert(string word){
        trie* curr=root;
        int idx;
        for(int i=0;i<word.size();i++){
            idx=word[i]-'a';
            if(curr->child[idx]==NULL){
                curr->child[idx]=new trie(word[i]);
            }
            curr=curr->child[idx];
        }
        curr->found=true;
    }  
    bool helper(int idx,string word,trie* curr){
        
        if(curr==NULL)return false;
        if(idx==word.size())return curr->found;
        if(word[idx]!='.'){
            int index=word[idx]-'a';
            if(curr->child[index]==NULL)return false;
            return helper(idx+1,word,curr->child[index]);
        }
        for(int i=0;i<SIZE;i++){
            if(helper(idx+1,word,curr->child[i]))return true;
        }
        return false;
    }
    bool search(string word){
        trie* curr = root;
        return helper(0,word,curr);
    }
};
class WordDictionary {
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
