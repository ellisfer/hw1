#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"
using namespace std; 

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// implement push_back, push_front, pop_back, pop_front, back, front, getValAtLoc

void ULListStr::push_back(const string& val){
  // add size, change tail, if tail null set to tail, 
  //otherwise change tail pointer to val

  size_++;

  if(tail_==NULL){
    head_ = new Item();
    head_->val[0] = val;
    head_->last++;
    tail_ = head_;
    return;
  }
  // if room in back
  if(tail_->last < 10){
    tail_->val[tail_->last] = val;
    tail_->last++;
    return;
  }
  if(tail_->last == 10){
    tail_->next = new Item(); 
    tail_->next->prev = tail_;
    tail_ = tail_->next;
    tail_->val[0] = val;
    tail_->last++;
    return;
  }
}

void ULListStr::push_front(const string& val){


  size_++;
  if(head_==NULL){
    head_ = new Item();
    head_->val[0] = val;
    head_->last++;
    tail_ = head_;
    return;
  }
  // if room in front
  if(head_->first > 0){
    head_->val[head_->first-1] = val;
    head_->first--;
    return;
  }
  // if no room in front
  if(head_->first == 0){
    head_->prev = new Item();
    head_->prev->next = head_;
    head_ = head_->prev;
    head_->val[9] = val;
    head_->last = 10;
    head_->first = 9;
    return;
  }
}

// pop back, pop front
void ULListStr::pop_back(){
  size_--;
  // if only one item;
  if(head_==tail_ && (head_->last - head_->first == 1)){
    delete head_;
    head_= nullptr;
    tail_ = nullptr;
    return;
  }
  // if only one item in tail
  else if(tail_->last == 1){
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = nullptr;
    return;
  }
  // if elts before last item
  else{
    tail_->last--;
  }
}

// pop front
void ULListStr::pop_front(){
  size_--;
  // if only one item;
  if(head_==tail_ && (head_->last - head_->first == 1)){
    delete head_;
    head_=nullptr;
    tail_=nullptr;
    return;
  }
  // if only one item in head
  else if(head_->first == 9){
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
    head_->prev = nullptr;
    return;
  }
  
  else{
    head_->first ++;
    return;
  }
}

string const & ULListStr:: back() const{
  return (tail_->val[tail_->last-1]);
}

string const & ULListStr:: front() const{
  return (head_->val[head_->first]);
}

string* ULListStr::getValAtLoc(size_t loc) const{
  if(head_==tail_ && head_->last == 0){
    return NULL;
  }
  int items = (head_->first + (int)loc) / 10;
  int ind = (head_->first + (int)loc) % 10;
  Item* temp = head_;
  for(int i = 0; i < items; i++){
    if(temp->next == nullptr){
      return NULL;
    }
    temp = temp->next;
  }
  if(temp->last < ind){
    return NULL;
  }
  return &temp->val[ind];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
