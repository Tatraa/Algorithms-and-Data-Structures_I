#include <algorithm>
#include <iostream>

template <typename T>
void bubblesort(T* L, int left, int right){			//O(n^2)
	for(int i = left; i < right; ++i){
		for(int j = left; j < right; ++j){
			if(L[j+1] < L[j]){
				std::swap(L[j+1], L[j]);
			}
		}
	}
}

int main(int argc, char *argv[]){
	std::cout << "Przed sortowaniem...\n";
	int v[] = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	bubblesort(v, 0, (sizeof(v) / sizeof(*v)) - 1);

	std::cout << "Po sortowaniu...\n";

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	return 0;
}