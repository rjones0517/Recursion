// Robert Jones
// 03/03/2023
// instcutor : Ghadeer Alabandi


/*
 * project2.cpp
 * 
 * The implementation file where you will implement your code for Project 2.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file. You may add helper functions for 
 * any function other than Sum in Question 1. 
 */

#include "recursive_list.h"
#include "project2.h"

/** QUESTION 1: SUM AND PRODUCT **/

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// Your implementation of Sum should NOT be tail recursive and should NOT
// use a helper function. 
//
// PSEUDOCODE:
// algorithm Sum
//   base case: if list is empty return;
//      if the list isnt empty:
//      remove first and add it to sum(rest of the list)
//
// COMMENTS:

int Sum(RecursiveList list) {
  // Implement this function.
    if (ListIsEmpty(list))
        return 0;
    else{
        return Sum(ListRest(list)) + ListFirst(list);
    }
}

// EFFECTS: returns the product of each element in list, or one if the list is
//          empty
//
// PSEUDOCODE:
//
//  algorithm ProductHelper
//      when list is empty: return final product
//      until then:
//          return (product tracker *= first element, rest of the list)
// COMMENTS:
// I used a helper function to hold the value of the product

int ProductHelper(RecursiveList list, int product_so_far){
    if (ListIsEmpty(list)){
        return product_so_far;
    }
    else {
        return ProductHelper(ListRest(list), product_so_far * ListFirst(list));
    }
}

// EFFECTS: returns product of each element in list,or one if list is empty
//
// PSUEDOCODE:
//Algorithim Product
//      return ProductHelper(list, 1)

int Product(RecursiveList list) {
  // Implement this function.
    return ProductHelper(list, 1); //Product has to start at 1 not 0
}



/** QUESTION 2: TAIL RECURSIVE SUM **/

// EFFECTS: adds the next element in the list to the sum so far
// Your implementation of TailRecursiveSumHelper MUST be tail recursive.
//
// PSEUDOCODE:
// algorithm TailRecursiveSumHelper(RecursiveList, Sum tracker):
//      when list is empty: return final sum
//      until then:
//          return (sum tracker += first element, rest of the list)
//
// COMMENTS:
// The helper function will hold the sum to be adeed to eachtime
// Making it tail recursive

int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
  // Implement this function.
    if (ListIsEmpty(list)){
        return sum_so_far;
    }
    else{
        return TailRecursiveSumHelper(ListRest(list), sum_so_far + ListFirst(list));
    }
}

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
// DO NOT MODIFY THIS FUNCTION.
// 
// PSEUDOCODE:
// algorithm TailRecursiveSum
//   return TailRecursiveSumHelper(list, 0)

int TailRecursiveSum(RecursiveList list) {
  return TailRecursiveSumHelper(list, 0);
}

/** QUESTION 4: REVERSE **/

// EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
//
// PSEUDOCODE:
// algorithm ReverseHelper(original list, reversed list)
//      if list is empty return the final reversed list
//      else:
//          return ReverseHelper(rest of list, makeList(first element, reverse)
//
//
//
// COMMENTS:
// This helper function will allow us to create a new list during our call
// Allowing us to reverse the first list without changing it

RecursiveList ReverseHelper(RecursiveList list, RecursiveList reverse){
    if (ListIsEmpty(list)){
        return reverse;
    }
    else{
        return ReverseHelper(ListRest(list), MakeList(ListFirst(list), reverse));
    }
}

// algorithm Reverse
//      return ReverseHelper(list, new list)
RecursiveList Reverse(RecursiveList list) {
  // Implement this function.
  return ReverseHelper(list, MakeList());
}



/** QUESTION 3: FILTER ODD AND FILTER EVEN **/

// EFFECTS: returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
//
// PSEUDOCODE:
// algorithm FilterOddHelper
//   if list is empty:
//      return newlist
//   else:
//      if not odd
//          return filteroddhelper (rest of list, new list)
//      else
//          return filteroddhelper (rest of list, make new list adding odds as
//          encountered
//
// COMMENTS:
//  Since elements are taken from the from of the list then put into the new
//  list, they will be pushed back as other elements are added to the new list
//  essentially reversing the list, so I reversed the return

RecursiveList FilterOddHelper(RecursiveList list, RecursiveList new_list){
    if(ListIsEmpty(list)){
        return Reverse(new_list);
    }
    else {
        if (!(ListFirst(list)%2)){ // odd#%2 = 1
            return FilterOddHelper(ListRest(list), new_list);
        }
        else{
            return FilterOddHelper(ListRest(list), MakeList(ListFirst(list), new_list));
        }
    }
}

// PSEUDOCODE:
// algorithm FilterOdd
//   return FilterOddHelper(list, newList)

RecursiveList FilterOdd(RecursiveList list) {
  // Implement this function.
    return FilterOddHelper(list, MakeList());
}



// EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
//
// PSEUDOCODE:
// algorithm FilterEvenHelper
//    if list is empty:
//      return newlist
//   else:
//      if not even
//          return filterevenhelper (rest of list, new list)
//      else
//          return filterevenhelper (rest of list, make new list adding evens as
//          encountered)
//
// COMMENTS:
// Will need to be reversed like FilterOdd

RecursiveList FilterEvenHelper(RecursiveList list, RecursiveList new_list){
    if(ListIsEmpty(list)){
        return Reverse(new_list);
    }
    else {
        if (ListFirst(list)%2){
            return FilterEvenHelper(ListRest(list), new_list);
        }
        else{
            return FilterEvenHelper(ListRest(list), MakeList(ListFirst(list), new_list));
        }
    }
}

// PSEUDOCODE:
// algorithm FilterEven
//      return FilterEvenHelper(list, newList)

RecursiveList FilterEven(RecursiveList list) {
  // Implement this function.
    return FilterEvenHelper(list, MakeList());
}

/** QUESTION 5: APPEND **/

// EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
//
// PSEUDOCODE:
// algorithm AppendHelper
//      if both list are empty: return empty list
//      if first list is empty: return second
//      if second list is empty: return first
//      else
//          if reversed list is empty: return final list
//          else: return appendHelper(first, second, reversed, final)
//
// COMMENTS:
// A reversed list must be used to add the first list in order to avoid the
// same problem as the FilterOdd function.

RecursiveList AppendHelper(RecursiveList first, RecursiveList second,
                           RecursiveList reverse_first, RecursiveList final_list){
    
    if(ListIsEmpty(first) && ListIsEmpty(second)){
        return MakeList();
    }
    else if(ListIsEmpty(first)) return second;
    else if(ListIsEmpty(second)) return first;
    else{
        if(ListIsEmpty(reverse_first)){
            return final_list;
        }
        else{
            return AppendHelper(first, second, ListRest(reverse_first), MakeList(ListFirst(reverse_first), final_list));
        }
    }
}

// PSEUDOCODE:
// algorithm Append
//      return AppendHelper(first,second, reversed, second

RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
  // Implement this function.
    return AppendHelper(first_list, second_list, Reverse(first_list), second_list);
}


/** QUESTION 6: CHOP **/

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//
// PSEUDOCODE:
// algorithm ChopHelper
//   if list is empty or n hits 0:
//      return list
//   else
//      return ChopHelper(rest of list, n-1)
//
// COMMENTS:

RecursiveList ChopHelper(RecursiveList list, unsigned int n){
    if(ListIsEmpty(list) || n==0)
    {
        return list;
    }
    else {
        return ChopHelper(ListRest(list), n-1); // will run until n "chopping"
    }
}

// PSEUDOCODE:
// algorithm Chop
//      return ChopHelper(list, n)

// COMMENTS: list will need to be reversed

RecursiveList Chop(RecursiveList list, unsigned int n) {
  // Implement this function.
  return Reverse(ChopHelper(Reverse(list), n));
}


/** QUESTION 7: ROTATE **/

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
// algorithm Rotate
//      If list is empty or n hits 0: return final list
//      else: return(new list(first element, rest of list), n-1)
//
// COMMENTS:
// The lists must be reversed while manipulating

RecursiveList RotateHelper(RecursiveList final_list, unsigned int n){
    if (n==0 || ListIsEmpty(final_list)){
        return final_list;
    }
    else {
        return RotateHelper(Reverse(MakeList(ListFirst(final_list), Reverse(ListRest(final_list)))), n-1);
    }
}

RecursiveList Rotate(RecursiveList list, unsigned int n) {
  // Implement this function.
    return RotateHelper(list, n);
}


/** QUESTION 8: INSERT LIST **/

// REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
//
// PSEUDOCODE:
// algorithm InsertListHelper
//      origianl chacks or parameters
//
//      if unchanged list is empty or second is empty or n == 0:
//          if n = 0: return append (second, first)
//          else: return append(first, second)
//      else:
//          if n > 0 : return insertlisthelper(first, rest of first, new list
//                                             with first element, first half of
//                                             first list, rest of first,
//                                             second, n, n-1)
//          else return append(first half, append(second, left over))
//
// COMMENTS:
//
RecursiveList InsertListHelper(RecursiveList unchanged_first,
                               RecursiveList first,
                               RecursiveList fl_keep,
                               RecursiveList fl_left_over,
                               RecursiveList second,
                               unsigned int unchanged_n,
                               unsigned int n){
    if (ListIsEmpty(unchanged_first) || ListIsEmpty(second) || unchanged_n == 0){
        if(unchanged_n==0){
            return Append(second, unchanged_first);
        }
        else{
            return Append(unchanged_first, second);
        }
    }
    else {
        if (n > 0){
            return InsertListHelper(unchanged_first, ListRest(first), MakeList(ListFirst(first), fl_keep), ListRest(first), second, unchanged_n, n-1);
        }
        else return Append(Reverse(fl_keep), Append(second, fl_left_over));
    }
}

// PSEUDOCODE:
// algorithm InsertList
//      return InsertListHelper(first, first, newlist for first half, new list
//                              for second half, second, n, n)

RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n) {
  // Implement this function.
    return InsertListHelper(first_list, first_list, MakeList(), MakeList(), second_list, n, n);
}
