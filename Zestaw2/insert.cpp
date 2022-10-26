#include <algorithm>
#include <iostream>

template <typename T>
void insertsort(T* L, int left, int right){
	T temp;

	for(int i = left; i < 10; ++i){
		temp = L[i];
		right = i - 1;

		while(right >= 0 && L[right] > temp){
			L[right + 1] = L[right];
			right = right - 1;
		}
		L[right + 1] = temp;
	}

}

int main(int argc, char *argv[]){
	std::cout << "Przed sortowaniem...\n";
	int v[] = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	insertsort(v, 0, (sizeof(v) / sizeof(*v)) - 1);
	std::cout << "Po sortowaniu...\n";

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	return 0;
}