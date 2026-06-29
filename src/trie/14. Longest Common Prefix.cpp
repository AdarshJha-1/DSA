class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *curr = root;
        for (const auto &c : word)
        {
            if (curr->children.count(c) == 0)
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        Trie *trie = new Trie();
        for (auto &word : strs)
        {
            if (word == "")
            {
                return "";
            }
            trie->insert(word);
        }

        string prefix;

        TrieNode *curr = trie->root;
        for (auto &c : strs[0])
        {

            if (curr->children.size() == 1 && !curr->isEnd)
            {
                prefix += c;
                curr = curr->children[c];
            }
            else
            {
                break;
            }
        }

        return prefix;
    }
};