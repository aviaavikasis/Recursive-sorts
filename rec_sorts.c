/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Ester                                   *
 * 31/07/2022                                        *
 * Description : recursive sorts                     *
 *                                                   *
 *****************************************************/
#include <stddef.h> /* size_t */
#include <stdlib.h> /* calloc, free */
#include <string.h> /* memcpy */
#include <assert.h> /* assert */

#include "rec_sorts.h" /* recursion sorts api */

typedef struct help_arrays
{
	int *left_arr;
	int *right_arr;
}help_arrays_ty;

static void Merge(int *arr, int *arr1, int *arr2, int left, size_t size1, size_t size2)
{
	int i = left;
	size_t arr1_index = 0;
	size_t arr2_index = 0;
	
	while(arr1_index < size1 && arr2_index < size2)
	{
		if(arr1[arr1_index] <= arr2[arr2_index])
		{
			arr[i] = arr1[arr1_index];
			++arr1_index;
		}
		else
		{
			arr[i] = arr2[arr2_index];
			++arr2_index;
		}
		++i;
	
	}
	
	while(arr1_index < size1)
	{
		arr[i] = arr1[arr1_index];
		++arr1_index;
		++i;
	}
	
	while(arr2_index < size2)
	{
		arr[i] = arr2[arr2_index];
		++arr2_index;
		++i;
	}
	
}


static void MergeArr(int *arr, int left, int mid, int right, 
											help_arrays_ty help_arrays)
{
	size_t left_arr_len = mid - left + 1;
	size_t right_arr_len = right - mid;
	int *left_arr = help_arrays.left_arr;
	int *right_arr = help_arrays.right_arr;
	
	assert(NULL != arr);
	
	memcpy(left_arr, arr + left, left_arr_len * sizeof(int));
	memcpy(right_arr, arr + mid + 1, right_arr_len * sizeof(int));
	
	Merge(arr, left_arr, right_arr, left, left_arr_len, right_arr_len);

}


static void RecursiveMergeSort(int *arr, int left, int right,
											 help_arrays_ty help_arrays)
{
	if(left < right)
	{
		int mid_index = left + (right - left) / 2;
		
		RecursiveMergeSort(arr, left, mid_index, help_arrays);
		RecursiveMergeSort(arr, mid_index + 1, right, help_arrays);
		MergeArr(arr, left, mid_index, right, help_arrays);
	}

}

static status_ty InitHelpArrays(help_arrays_ty *help_arrays, size_t size)
{

	assert(NULL != help_arrays);
	
	help_arrays->left_arr = (int*)calloc(size / 2, sizeof(int));
	if(NULL == help_arrays->left_arr)
	{
		return FAIL;
	}
	
	help_arrays->right_arr = (int*)calloc(size / 2 + 1, sizeof(int));
	if(NULL == help_arrays->right_arr)
	{
		free(help_arrays->left_arr);
		help_arrays->left_arr = NULL;
		
		return FAIL;
	}
	
	return SUCCESS;
}

static void FreeHelpArrays(help_arrays_ty *help_arrays)
{
	assert(NULL != help_arrays);
	
	free(help_arrays->left_arr);
	help_arrays->left_arr = NULL;

	free(help_arrays->right_arr);
	help_arrays->right_arr = NULL;
}


status_ty MergeSort(int arr[], size_t size)
{
	
	help_arrays_ty help_arrays = {0};
	status_ty status = 0;
	assert(NULL != arr);
	
	status = InitHelpArrays(&help_arrays, size);
	if(FAIL == status)
	{
		FreeHelpArrays(&help_arrays);
		return FAIL;
	}
	
	RecursiveMergeSort(arr, 0, size - 1, help_arrays);
	
	FreeHelpArrays(&help_arrays);
	
	return SUCCESS;
}


static void Swap(void *arr, size_t size, int i, int j)
{
	char *temp = NULL;
	assert(NULL != arr);
	
	temp = (char *)calloc(size , sizeof(char));
	if(NULL == temp)
	{
		return;
	}
	memcpy(temp, (char*)arr + i * size, size);
	memcpy((char*)arr + i * size, (char*)arr + j * size, size);
	memcpy((char*)arr + j * size, temp, size);
	
	free(temp);
	temp = NULL;
}


static int Partition(void *arr, size_t size, int start, int end, compar cmp)
{
	int pivot = end;
	int first_index = start - 1;
	int second_index = start;
	
	assert(NULL != arr);
	assert(NULL != cmp);
	
	for(; second_index < end ; ++second_index)
	{
		if(0 > cmp((char*)arr + second_index * size, (char*)arr + pivot * size))
		{
			++first_index;
			Swap(arr, size, first_index, second_index);
		}
	}
	++first_index;
	Swap(arr, size, first_index, pivot);
	
	return first_index; 

}


static void RecursiveQuickSort(void *base, size_t size, int left,
														 int right, compar cmp)
{
	int pivot = 0;
	assert(NULL != base);
	assert(NULL != cmp);
	
	if(left < right)
	{
		pivot = Partition(base, size, left, right, cmp);
		
		RecursiveQuickSort(base, size, left, pivot - 1, cmp);
		RecursiveQuickSort(base, size, pivot + 1, right, cmp);
	}
}

void Qsort(void *base, size_t nmemb, size_t size, compar cmp)
{
	int left = 0;
	int right = nmemb - 1;
	
	assert(NULL != base);
	assert(NULL != cmp);
	
	RecursiveQuickSort(base, size, left, right, cmp);	
}
           


















