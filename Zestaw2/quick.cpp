#include <algorithm>
#include <iostream>

template <typename T>
void quicksort(T* L, int left, int right){			//O(n*logn)
	if(right <= left) return;

	int i = left - 1;
	int j = right + 1;
	T pivot = L[(left + right) / 2];

	while(1){
		while(pivot > L[++i]);
		while(pivot < L[--j]);

		if(i <= j){
			std::swap(L[i], L[j]);
		}else{
			break;
		}
	}

	if(j > left){
		quicksort(L, left, j);
	}

	if(i < right){
		quicksort(L, i, right);
	}
}

int main(int argc, char *argv[]){
	std::cout << "Przed sortowaniem...\n";
	int v[] = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	quicksort(v, 0, (sizeof(v) / sizeof(*v)) - 1);

	std::cout << "\nPo sortowaniu...\n";

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	return 0;
}