
struct Node {

  bool visited = false;
  std::list<Node*> adjacent;

}

void DFS(Node* root)
{
  if (root == NULL) return;
  visit(root);
  root->visited = true;
  
  std::list<Node*>::const_iterator iterator
  
  for (iterator = root->adjacent.begin(); 
    iterator != root->adjacent.end(); ++iterator) {
    if (iterator->visited == false) {
      search(iterator);
    }
  }
  /*
  for(Node &n : root->adjacent) 
  {
    if (n->visited == false) {
      search(n);
    }
  }
  */
}
