#include "chain.h"
#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain(){
  /* your code here */
}

/**
 * Inserts a new node at the end of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block & ndata){
  Node* new_node = new Node(ndata);
  Node* tail = head_->prev;
  new_node->next = head_;
  new_node->prev = tail;
  tail->next = new_node;
  head_->prev = new_node;
  length_ = length_ + 1;
  height_ = ndata.height();
  width_ = ndata.width();
}

/**
 * Modifies the Chain by moving the subchain of len Nodes,
 * starting at position startPos, dist positions toward the
 * end of the chain.  If startPos + len - 1 + dist > length
 * then dist = length - startPos - len + 1 (to prevent gaps
 * in the new chain).
 * The subchain occupies positions (startPos + dist) through
 * (startPos + dist + len - 1) of the resulting chain.
 * The order of subchain nodes is not changed in the move.
 * You may assume that: 1 <= startPos <= length - len + 1,
 * 0 <= dist <= length, and 0 <= len <= length. 
 */
void Chain::moveBack(int startPos, int len, int dist){
  /* your code here */
  // FIXME:for now consider startPos <= length
  if (startPos + len - 1 + dist > length_){
    dist = length_ - startPos - len + 1;
  }
  if (length_ == 0 || len == 0 || dist <= 0){
    return;
  }
  else{
    Node* startNode = head_;
    for (int i=0; i<startPos; i++){
      startNode = startNode->next;
    }
    Node* endNode = startNode;
    for (int i=startPos; i<startPos+len-1; i++){
      endNode = endNode->next;
    }
    Node* a = startNode->prev;
    Node* b = endNode->next;
    Node* c = endNode->next->next;
    a->next = b;
    b->prev = a;
    b->next = startNode;
    startNode->prev = b;
    endNode->next = c;
    c->prev = endNode;
    moveBack(startPos+1, len, dist-1);
  }
}

/**
 * Rolls the current Chain by k nodes: reorders the current list
 * so that the first k nodes are the (n-k+1)th, (n-k+2)th, ... , nth
 * nodes of the original list followed by the 1st, 2nd, ..., (n-k)th
 * nodes of the original list where n is the length.
 */
void Chain::roll(int k){
  /* your code here */
  // TODO: need to do this!!!
}

/**
 * Modifies the current chain by reversing the sequence
 * of nodes from pos1 up to and including pos2. You may
 * assume that pos1 and pos2 exist in the given chain,
 * and pos1 <= pos2.
 * The positions are 1-based.
 */
void Chain::reverseSub(int pos1, int pos2){
  /* your code here */
  if (pos1 == pos2){
    return;
  }
  else if (pos1 == (pos2 - 1)){
    swap_node(pos1, pos2);
    return;
  }
  else{
    swap_node(pos1, pos2);
    reverseSub(pos1+1, pos2-1);
  }
}

void Chain::swap_node(int pos1, int pos2){
  int cnt;
  Node* pos1_node = head_;
  Node* pos2_node = head_;

  for(cnt=0; cnt<pos1; cnt++){
    pos1_node = pos1_node->next;
  }

  for(cnt=0; cnt<pos2; cnt++){
    pos2_node = pos2_node->next;
  }

  Node* pos1_node_prev = pos1_node->prev;
  Node* pos1_node_next = pos1_node->next;
  Node* pos2_node_prev = pos2_node->prev;
  Node* pos2_node_next = pos2_node->next;

  if(pos1 == pos2 - 1){
    pos1_node_prev->next = pos2_node;
    pos2_node_next->prev = pos1_node;
    pos1_node->prev = pos2_node;
    pos1_node->next = pos2_node_next;
    pos2_node->prev = pos1_node_prev;
    pos2_node->next = pos1_node;
  }
  else{
    pos1_node_prev->next = pos2_node;
    pos1_node_next->prev = pos2_node;
    pos1_node->prev = pos2_node_prev;
    pos1_node->next = pos2_node_next;
    pos2_node_prev->next = pos1_node;
    pos2_node_next->prev = pos1_node;
    pos2_node->prev = pos1_node_prev;
    pos2_node->next = pos1_node_next;
  }
}

/*
* Modifies both the current chain and the "other" chain by removing
* nodes from the other chain and adding them between the nodes
* of the current chain -- one "other" node between two current nodes --
* until one of the two chains is exhausted.  Then the rest of the
* nodes in the non-empty chain follow.
* The length of the resulting chain should be the sum of the lengths
* of current and other. The other chain should have only
* the head_ sentinel at the end of the operation.
* The weave fails and the original
* chains should be unchanged if block sizes are different.
* In that case, the result of the function should be:
* cout << "Block sizes differ." << endl;
*/
void Chain::weave(Chain & other) { // leaves other empty.
  /* your code here */
}


/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class except for the sentinel head_. Sets length_
 * to zero.  After clear() the chain represents an empty chain.
 */
void Chain::clear() {
  /* your code here */
}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const& other) {
  /* your code here */
}
