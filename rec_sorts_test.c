#include <stddef.h>	/* size_t */
#include <assert.h> /* assert */
#include "rec_sorts.h" /* recursive sorts api */


void MergeSortTest(void);
void QsortTest(void);

int CmpInt(const void *element1, const void *element2);

int main(void)
{
	MergeSortTest();
	QsortTest();

	return 0;
}


void MergeSortTest(void)
{
	int arr[100] = {0};
	int i = 0;         
	
	for(; i < 100 ; ++i)
	{
		arr[i] = i % 8;
	}
	                      
	MergeSort(arr, 100);                              
	                   
	for(i = 0 ; i < 99; ++i)                             
	{
		assert(arr[i] <= arr[i + 1]);
	}

}

void QsortTest(void)
{
	int arr[100] = {0};
	int i = 0;         
	
	for(; i < 100 ; ++i)
	{
		arr[i] = i % 8;
	}
	                      
	MergeSort(arr, 100);                              
	                   
	for(i = 0 ; i < 99; ++i)                             
	{
		assert(arr[i] <= arr[i + 1]);
	}
}






int CmpInt(const void *element1, const void *element2)
{
	assert(NULL != element1);
	assert(NULL != element2);
	
	return (*(int*)element1 - *(int*)element2);
}












