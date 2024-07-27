#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct node {
  long long weight = 0;
  char ch;
  node *left = nullptr;
  node *right = nullptr;
  node *parent = nullptr;
};

bool compareNodes(const node &a, const node &b) { return a.weight < b.weight; }

node *buildTree(std::vector<node> &nodes) {
  while (nodes.size() > 1) {
    std::sort(nodes.begin(), nodes.end(), compareNodes);

    node *newNode = new node;
    newNode->left = new node(nodes[0]);
    newNode->right = new node(nodes[1]);
    newNode->weight = newNode->left->weight + newNode->right->weight;

    newNode->left->parent = newNode;
    newNode->right->parent = newNode;

    nodes.erase(nodes.begin());
    nodes.erase(nodes.begin());
    nodes.push_back(*newNode);
  }

  return &nodes[0];
}

void generateCode(node *root, std::unordered_map<char, std::string> &codes,
                  std::string currentCodes) {
  if (root) {
    if (root->left == nullptr && root->right == nullptr) {
      codes[root->ch] = currentCodes;
    } else {
      generateCode(root->left, codes, currentCodes + "0");
      generateCode(root->right, codes, currentCodes + "1");
    }
  }
}

void writeHuffmanTable(const std::unordered_map<char, std::string> &codes) {
  std::ofstream tableFile("huffman.table", std::ios::out);

  for (const auto &code : codes) {
    tableFile << code.first << " " << code.second << std::endl;
  }

  tableFile.close();
}

void writeFile(const std::unordered_map<char, std::string> &codes,
               const std::string inputFile) {
  std::ifstream inputFileStream(inputFile, std::ios::in | std::ios::binary);
  std::ofstream outputFile("output.huffman", std::ios::out | std::ios::binary);

  char buf;
  std::string encodedString;

  while ((buf = inputFileStream.get()) != EOF) {
    encodedString += codes.at(buf);
  }

  inputFileStream.close();

  int padding = 8 - (encodedString.length() % 8);

  encodedString += std::bitset<8>(padding).to_string().substr(0, padding);

  for (size_t i = 0; i < encodedString.length(); i += 8) {
    std::string byteStr = encodedString.substr(i, 8);
    std::bitset<8> byte(byteStr);
    outputFile.put(static_cast<char>(byte.to_ulong()));
  }

  outputFile.close();
}

int main(/*int argc, char* argv[]*/) {
  std::string argv[2] = {};
  argv[1] = "text.txt";
  //    if (argc != 2) {
  //        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
  //        std::cin.get();
  //        return -1;
  //    }
  std::ifstream fp(argv[1], std::ios::in);
  std::vector<node> nodes;
  if (!fp.is_open()) {
    std::cout << "File open error" << std::endl;
    std::cin.get();
    return -1;
  }
  char buf;
  int num;
  while ((buf = fp.get()) != EOF) {
    bool flag = false;
    num = nodes.size();
    for (int i = 0; i < num; i++) {
      if (nodes[i].ch == buf) {
        flag = true;
        nodes[i].weight++;
        break;
      }
    }
    if (!flag) {
      node newNode;
      newNode.ch = buf;
      newNode.weight++;
      nodes.push_back(newNode);
    }
  }
  fp.close();
  node *root = buildTree(nodes);

  std::unordered_map<char, std::string> codes;
  generateCode(root, codes, " ");
  writeHuffmanTable(codes);
  writeFile(codes, argv[1]);

  std::cin.get();
  return 0;
}
