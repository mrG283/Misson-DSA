class Trie {
public:
    struct trienode{
        bool isendofword;
        trienode * children[26];
    };
    trienode * getnode(){
        trienode * newh=new trienode();
        newh->isendofword=false;
        for(int i=0;i<26;i++){
            newh->children[i]=NULL;
        }
        return newh;
        
    }
    trienode * root;
    Trie() {
        root=getnode();
        
    }
    
    void insert(string word) {
        trienode * crawler=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            int idx=c-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getnode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isendofword=true;
        
    }
    
    bool search(string word) {
        trienode * crawler=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            int idx=c-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(crawler!=NULL&&crawler->isendofword==true){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
        trienode * crawler=root;
        int i;
        for(i=0;i<prefix.size();i++){
            char c=prefix[i];
            int idx=c-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(i==prefix.size()){
            return true;
        }
        return false;
        
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */