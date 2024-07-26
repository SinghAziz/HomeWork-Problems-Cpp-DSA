    i=0;
    while (i<k){
        while (arr[i]!=2){
            i++;
        }
        while (arr[k]!=2){
            j--;
        }
        j++;
        swap(arr[i],arr[k]);
        i++;
        j--;
    }