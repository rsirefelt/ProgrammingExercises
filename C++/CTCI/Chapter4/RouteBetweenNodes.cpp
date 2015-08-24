
enum State { Unvisited, Visited, Visiting };

public static bool search(Graph g, Node* start, Node* end)
{
  std::list<Node*> q; 
  
  for(Node* u : g->GetNodes()) {
    u->state = State.Unvisited;
  }
  start->state = State.Visiting;
  q.push_back(start);
  
  Node* u;
  while (!q.empty()) {
    u = q.front(); 
    q.pop_front();
    
    if (u != NULL) {
      for (Node* v : u->GetAdjacent()) {
        if (v->state == State.Unvisited) {
          if (v == end) {
            return true;
          } else {
            q.push_back(v);
            v->state = State.Visiting;
          }
        }
      }
    }
    u->state = State.Visited;
  }
  
  return false;
}
