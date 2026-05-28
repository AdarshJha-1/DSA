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

    void insert(string word)
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

    bool search(string word)
    {
        TrieNode *curr = root;
        for (const auto &c : word)
        {
            if (curr->children.count(c) == 0)
            {
                return false;
            }
            curr = curr->children[c];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (const auto &c : prefix)
        {
            if (curr->children.count(c) == 0)
            {
                return false;
            }
            curr = curr->children[c];
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