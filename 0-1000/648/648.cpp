#include <bits/stdc++.h>

using namespace std;

class Trie
{

private:
    bool is_valiable = false;
    Trie *next[26] = {nullptr};

public:
    Trie() {}

    void insert(string input)
    {
        Trie *it = this;
        for (char &c : input)
        {
            if (it->next[c - 'a'] == nullptr)
            {
                it->next[c - 'a'] = new Trie();
            }
            it = it->next[c - 'a'];
        }
        it->is_valiable = true;
    }

    string find_root(string input){
        string prefix;
        Trie * cur = this;
        for(char & c:input){
            if(cur->next[c-'a']){
                prefix += c;
                cur=cur->next[c-'a'];
                if(cur->is_valiable){
                    return prefix;
                }
            }else{
                return input;
            }
        }
        return input;
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // 如何合并root最短的前缀 1. map 2. 字典数：节点为字母，每个节点最多26个子节点
        // c++拆分 string
        Trie *tree = new Trie();
        for(auto &word:dictionary){
            tree->insert(word);
        }
        stringstream w(sentence);
        string word,result;
        while(w >> word){
            result += tree->find_root(word)+" ";
        }
        delete tree;
        return result.substr(0,result.size()-1);
    }
};