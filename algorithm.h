//
// Created by bxd on 16-5-27.
//

#ifndef TINYSTL_ALGORITHM_H
#define TINYSTL_ALGORITHM_H
namespace tinySTL {

  //min/max
  template <typename T>
  const T& min(T& a, T&b) {
    return !(b < a) ? a : b;
  }

  template <typename T, typename Compare>
  const T& min(T& a, T& b, Compare comp) {
    return !comp(b,a) ? a : b;
  }

  template <typename T>
  const T& max(T& a, T&b) {
    return a < b ? b : a;
  }


  template <typename T, typename Compare>
  const T& max(T& a, T& b, Compare comp) {
    return comp(a,b) ? b : a;
  }


  template <typename ForwardIterator>
  ForwardIterator min_element(ForwardIterator first, ForwardIterator last) {
    if (first == last) {
      return last;
    }
    ForwardIterator smallest  = first;
    while(++first != last) {
      if (*first < *smallest) {
        smallest = first;
      }
    }
    return smallest;
  }

  template <typename ForwardIterator, typename Compare>
  ForwardIterator min_element(ForwardIterator first, ForwardIterator last,
                              Compare Comp) {
    if (first == last) {
      return last;
    }
    ForwardIterator smallest  = first;
    while(++first != last) {
      if (Comp(*first, *smallest)) {
        smallest = first;
      }
    }
    return smallest;
  }

  template <typename ForwardIterator>
  ForwardIterator max_element(ForwardIterator first, ForwardIterator last) {
    if (first == last) {
      return last;
    }
    ForwardIterator largest  = first;
    while(++first != last) {
      if (*first > *largest) {
        largest = first;
      }
    }
    return largest;
  }

  template <typename ForwardIterator, typename Compare>
  ForwardIterator max_element(ForwardIterator first, ForwardIterator last,
                              Compare Comp) {
    if (first == last) {
      return last;
    }
    ForwardIterator largest  = first;
    while(++first != last) {
      if (Comp(*largest, *first)) {
        largest = first;
      }
    }
    return largest;
  }

  // Non-modifying sequence operations
  template <typename InputIterator, typename Function>
  Function for_each (InputIterator first, InputIterator last, Function func) {
    while (first < last) {
      func(*first);
      ++first;
    }
    return func;
  }

  template <typename InputIterator, typename T>
  InputIterator find(InputIterator first, InputIterator last, const T& val) {
    while (first < last) {
      if (*first == val) {
        return first;
      }
      ++first;
    }
    return last;
  }

  template <class InputIterator, class UnaryPredicate>
  InputIterator find_if (InputIterator first, InputIterator last,
                         UnaryPredicate pred) {
    while (first < last) {
      if (pred(*first)) {
        return first;
      }
    }
    return last;
  }


  template <class InputIterator, class T>
  typename iterator_traits<InputIterator>::difference_type
    count (InputIterator first, InputIterator last, const T& val) {
    typename iterator_traits<InputIterator>::difference_type res = 0;
    while (first != last) {
      if (*first == val) {
        ++res;
      }
    }
    return res;
  }

  template <class InputIterator1, class InputIterator2>
  bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2) {
    while(*first1++ == *last1++);
    if (first1 == first2) {
      return true;
    }else {
      return false;
    }
  }

}//namespace

#endif //TINYSTL_ALGORITHM_H
