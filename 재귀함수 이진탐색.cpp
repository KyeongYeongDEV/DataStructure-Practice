    #include<iostream>
    using namespace std;

    int Bsearch(int *ar,int first, int last, int target){
        int mid;
        if(first >last)
            return -1;
        mid = (first + last) /2;

        if(ar[mid] == target)
            return mid;
        else if(ar[mid] > target)
            return Bsearch(ar, first,mid-1,target);
        else 
            return Bsearch(ar, mid-1, last, target);   
        
        return 0;
    }

    int main(){
        int arr[5] = {1,3,5,7,9};
        int idx;

        idx = Bsearch(arr,0,sizeof(arr)/sizeof(int)-1, 7);
        if(idx ==-1){
            cout << "탐색 실패ㅜ\n";
        }
        else{
            cout<< "타깃 저장 인덱스: " <<idx <<"\n";
        }

        idx = Bsearch(arr,0,sizeof(arr)/sizeof(int)-1, 4);
        if(idx ==-1){
            cout << "탐색 실패ㅜ\n";
        }
        else{
            cout<< "타깃 저장 인덱스: " <<idx <<"\n";
        }

        return 0;
    }