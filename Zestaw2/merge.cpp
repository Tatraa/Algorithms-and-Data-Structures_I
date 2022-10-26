#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
template <typename T>
void merge(T* L, int left, int right){
	int mid = (left + right) / 2;
	int z = 0;
	int x = left;
	int y = mid + 1;
    vector<T> temp(right - left + 1);

    while(x <= mid && y <= right)
    {
        if(L[x] < L[y])
        {
            temp[z] = L[x];
            ++x, ++z;
        }else{
            temp[z] = L[y];
            ++y, ++z;
        }
    }

    while(x <= mid)
    {
        temp[z] = L[x];
        ++x, ++z;
    }

    while(y <= right)
    {
        temp[z] = L[y];
        ++y, ++z;
    }

    for(int i = left; i <= right; ++i)
    {
        L[i] = temp[i - left];
    }
}
template <typename T>
void mergesort(T* L, int left, int right){
	if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(L, left, mid);
        mergesort(L, mid + 1, right);
        merge(L, left, right);
    }
} 

int main(int argc, char *argv[]){
	std::cout << "Przed sortowaniem...\n";
	int v[] = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	mergesort(v, 0, (sizeof(v) / sizeof(*v)) - 1);

	std::cout << "\nPo sortowaniu...\n";

	for(auto item : v){
		std::cout << item << " ";
	}
	std::cout <<"\n";

	return 0;
} 