#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

void merge(unsigned int arr[],int l,int m,int h){
	int first_sub_array_ind,second_sub_array_ind,whole_array_ind;
	int first_piece = m - l + 1;
	int second_piece = h - m;
	
	int L[first_piece], R[second_piece];
	//printf("first_piece = %d, second_piece = %d, middle = %d\n",first_piece,second_piece,m);
	
	for (first_sub_array_ind = 0; first_sub_array_ind < first_piece; first_sub_array_ind++){
		L[first_sub_array_ind] = arr[l + first_sub_array_ind];
		//printf("L[%d] = %d <-- arr[%d] = %d\n",first_sub_array_ind,L[first_sub_array_ind], l + first_sub_array_ind,arr[l + first_sub_array_ind]);
	}
	for (second_sub_array_ind = 0; second_sub_array_ind < second_piece; second_sub_array_ind++){
		R[second_sub_array_ind] = arr[m + 1+ second_sub_array_ind];		
		//printf("R[%d] = %d <-- arr[%d] = %d\n",second_sub_array_ind,R[second_sub_array_ind], m+1 + second_sub_array_ind,arr[m + 1+ second_sub_array_ind]);
	}
	first_sub_array_ind = 0;
	second_sub_array_ind = 0;
	whole_array_ind = l;
	while (first_sub_array_ind < first_piece && second_sub_array_ind < second_piece)
	{
		if (L[first_sub_array_ind] <= R[second_sub_array_ind])
		{
		    arr[whole_array_ind] = L[first_sub_array_ind];
		    first_sub_array_ind++;
		}
		else
		{
		    arr[whole_array_ind] = R[second_sub_array_ind];
		    second_sub_array_ind++;
		}
		whole_array_ind++;
        }

	while (first_sub_array_ind < first_piece)
	{
		arr[whole_array_ind] = L[first_sub_array_ind];
		first_sub_array_ind++;
		whole_array_ind++;
	}

	while (second_sub_array_ind < second_piece)
	{
		arr[whole_array_ind] = R[second_sub_array_ind];
		second_sub_array_ind++;
		whole_array_ind++;
	}
	
}
void mergeSort(unsigned int arr[],int low_bound,int high_bound){
	
	if(low_bound<high_bound){
		int middle = low_bound + ((high_bound - low_bound) / 2) ;//avoids overflow
		mergeSort(arr,low_bound,middle);
		mergeSort(arr,middle+1,high_bound);

		merge(arr,low_bound,middle,high_bound);
	}

}

#endif
