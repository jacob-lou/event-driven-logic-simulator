#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator())
    :m_(m),comp_(c){}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){}
  
  
  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item){
    data_.push_back(item);
    heapifyUp(data_.size()-1);
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const{
    if (empty()){
      throw std:: underflow_error("Heap is empty");
    }
    return data_[0];
  }

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop(){
    if (empty()){
      throw std::underflow_error("Heap is empty");
    }
    data_[0] = data_.back();
    data_.pop_back();
    if(!empty()){
      heapifyDown(0);
    }
  }


  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
    return data_.empty();
  }

  /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{
    return data_.size();
  }

//private:
  /// Add whatever helper functions and data members you need below
private:
  std::vector<T> data_;
  int m_;
  PComparator comp_;

  void heapifyUp(int idx){
    while (idx > 0){
      int parent = (idx-1)/m_;
      if(comp_(data_[idx], data_[parent])){
        std::swap(data_[idx], data_[parent]);
        idx = parent;
      }else{
        break;
      }
    }
  }

  void heapifyDown(int idx){
    int size = data_.size();
    while (true){
      int best = idx;
      int first_child = m_ * idx +1;

      for (int i = 0; i < m_; i++) {
        int child = first_child + i;
        if (child < size && comp_(data_[child], data_[best])) {
          best = child;
        }
      }

      if(best != idx){
        std::swap(data_[idx], data_[best]);
        idx = best;
      }else{
        break;
      }
    }
  }



};

// Add implementation of member functions here

/*
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  data_[0] = data_.back();
  data_.pop_back();

  if(!empty()){
    heapifyDown(0);
  }


}
*/


#endif

