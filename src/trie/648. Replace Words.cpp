class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    string word;

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
        curr->word = word;
    }

    string replacement(string word)
    {
        TrieNode *curr = root;
        for (const auto &c : word)
        {
            if (curr->children.count(c) == 0)
            {
                return word;
            }
            curr = curr->children[c];

            if (curr->isEnd)
            {
                return curr->word;
            }
        }
        return word;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *t = new Trie();

        for (int i = 0; i < dictionary.size(); i++)
        {
            t->insert(dictionary[i]);
        }

        stringstream ss(sentence);
        string word;

        string ans = "";

        while (ss >> word)
        {
            ans += t->replacement(word);
            if (ss.peek() != EOF)
            {
                ans.push_back(' ');
            }
        }

        return ans;
    }
};