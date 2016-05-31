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
    while (first != last) {
      func(*first);
      ++first;
    }
    return func;
  }

  template <typename InputIterator, typename T>
  InputIterator find(InputIterator first, InputIterator last, const T& val) {
    while (first != last) {
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

  template <class InputIterator, class UnaryPredicate>
  typename iterator_traits<InputIterator>::difference_type
  count_if (InputIterator first, InputIterator last, UnaryPredicate pred) {
    typename iterator_traits<InputIterator>::difference_type res = 0;
    while (first != last) {
      if (pred(*first)) {
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

  template <class InputIterator1, class InputIterator2>
  pair<InputIterator1, InputIterator2>
  mismatch (InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2) {
    while (first1 != last1 && *first1 == *first2) {
      ++first1;
      ++first2;
    }
    return make_pair(*first1,*first2);
  };

  template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  pair<InputIterator1, InputIterator2>
  mismatch (InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, BinaryPredicate pred) {
    while (first1 != last1 && pred(*first1, *first2)) {
      ++first1;
      ++first2;
    }
    return make_pair(*first1,*first2);
  };

  template <class ForwardIterator>
  ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last) {
    ForwardIterator second = first+1;
    while (second != last) {
      if (*first == *second) {
        return second;
      }
      first = second++;
    }

    return last;
  }

  template <class InputIterator, class OutputIterator>
  OutputIterator copy (InputIterator first, InputIterator last,
                       OutputIterator result) {
    while (first != last) {
      *result++ = *first++;
    }

    return result;
  }

  template <class T>
  void swap (T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
  }

  template <class ForwardIterator1, class ForwardIterator2>
  ForwardIterator2 swap_ranges (ForwardIterator1 first1, ForwardIterator1 last1,
                                ForwardIterator2 first2) {
    while (first1 != last1) {
      swap(*first1,*first2);
      ++first1;
      ++first2;
    }

    return first2;
  }

  template <class ForwardIterator1, class ForwardIterator2>
  void iter_swap (ForwardIterator1 a, ForwardIterator2 b) {
    swap(*a,*b);
  };

  template <class InputIterator, class OutputIterator, class UnaryOperation>
  OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperation op) {
    while (first1 != last1) {
      *result = op(*first1);
      ++first1;
      ++result;
    }
  }

  template <class InputIterator1, class InputIterator2,
      class OutputIterator, class BinaryOperation>
  OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, OutputIterator result,
                            BinaryOperation binary_op) {
    while (first1 != first2) {
      *result = binary_op(*first1,*first2);
      ++first1;
      ++first2;
      ++result;
    }
  };

}//namespace

#endif //TINYSTL_ALGORITHM_H
