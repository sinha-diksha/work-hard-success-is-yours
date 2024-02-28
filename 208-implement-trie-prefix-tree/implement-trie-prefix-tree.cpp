class Node{
    public:
    Node* links[26];
    bool isEnd;

    Node(){
        isEnd=false;
        for(int i=0; i<26; i++){
            links[i]=NULL;
        }
    }
    bool isContains(char ch){
        return links[ch-'a']!=NULL;
    }

    void isSet(char ch, Node* newNode){
        links[ch-'a']=newNode;
    }

    Node* nextVal(char ch){
        return links[ch-'a'];
    }

};

class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        int n=word.size();
        for(int i=0; i<n; i++){
            if(!node->isContains(word[i])){
                Node* newNode=new Node();
                node->isSet(word[i],newNode);
            }
            node=node->nextVal(word[i]);
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Node* node=root;
        int n=word.size();
        for(int i=0; i<n; i++){
            if(!node->isContains(word[i])){
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        if(node->isEnd==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        int n=prefix.size();
        for(int i=0; i<n; i++){
            if(!node->isContains(prefix[i])){
                return false;
            }
            node=node->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */