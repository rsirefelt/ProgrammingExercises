#include <queue>

void Search(Node* root)
{
  std::queue<Node*>;
  root->visited = true;
  visit(root);
  
  queue->push(root);
  
  while (queue.empty()) {
    Node* r = queue.back();
    for (Node* n : r->adjacent) {
      if (n->visited == false) {
        visit(n);
        n->visited = true;
        queue.push(n);
      }
    }
  
  }
  

}
