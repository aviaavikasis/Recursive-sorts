/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Ester                                   *
 * 31/07/2022                                        *
 * Description : recursive sorts                     *
 *                                                   *
 *****************************************************/

#include <stdlib.h>  /*malloc, free */
#include <stddef.h> /*size_t*/

#ifndef __ILRD_OL127_128__REC_SORTS__H__
#define __ILRD_OL127_128__REC_SORTS__H__


typedef enum
{
	SUCCESS = 0,
	FAIL    = 1
}status_ty;

typedef int (*compar)(const void *, const void *);


/*
DESCRIPTION: sort array of int numbers.
PARAMETERS: ints array, size of array(size_t)
RETURN: SUCCESS status_ty in success, else FAIL
TIME COMPLEXITY: O(n * log(n))
SPACE COMPLEXITY: O(n)
*/
status_ty MergeSort(int arr[], size_t size);

/*
DESCRIPTION: sort array of vlues in each size.
PARAMETERS: pointer to array of elements,
num of elements, size of each element, compare 
function.
RETURN: void 
TIME COMPLEXITY: O(n * log(n))
SPACE COMPLEXITY: O(n)
*/
void Qsort(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *));


#endif /* __ILRD_OL127_128__REC_SORTS__H__ */
