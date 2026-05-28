#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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

  bool startWith(string prefix)
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

  // void remove(string word)
  // {
  //   TrieNode *curr = root;
  //   for(const auto& c : word)
  //   {

  //   }
  // }
};

int main()
{
  Trie *trie = new Trie();
  trie->insert("cat");
  trie->insert("car");
  trie->insert("dog");

  cout << (trie->search("car") ? "YES" : "NO") << endl;
  cout << (trie->search("cat") ? "YES" : "NO") << endl;
  cout << (trie->search("cow") ? "YES" : "NO") << endl;

  cout << (trie->startWith("co") ? "YES" : "NO") << endl;
  cout << (trie->startWith("do") ? "YES" : "NO") << endl;
}