
count=0
def merge(arr, low, mid, high):
    global count
    n1 = mid-low+1
    n2 = high-mid
    aux_1 = []
    aux_2 = []
    
    for i in range(0, n1):
        aux_1.append(arr[i+low])
        
    for i in range(0, n2):
        aux_2.append(arr[mid+i+1])
    
    i=0
    j=0
    k=low
    g=low
    while i<n1 and j<n2:      #counting inversions...
        if aux_1[i] > aux_2[j]:
            arr[k] = aux_2[j]
            count += mid-g+1
            j += 1
            k += 1
        else:
            arr[k] = aux_1[i]
            i += 1
            k += 1
            g += 1

    while i<n1:
        arr[k] = aux_1[i]
        i += 1
        k += 1
    while j<n2:
        arr[k] = aux_2[j]
        j += 1
        k += 1
        
def merge_sort(arr, low, high):
    if low<high:
        mid = (low+high)//2
        merge_sort(arr, low, mid)
        merge_sort(arr, mid+1, high)
        merge(arr, low, mid, high)



sz = int(input())  
arr = []
# arr = list(map(int, input().strip()))
i=0
while i<sz:
    arr.append(input())
    i += 1

merge_sort(arr, 0, sz-1)
    
print(count)
    
    