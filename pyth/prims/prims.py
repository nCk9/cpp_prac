INT_MAX = 1000001

def min_key(key, final_set):   
    minn = INT_MAX
    min_idx = -1
    for i in range(1, ver+1):
        if(final_set[i] == 0 and key[i] < minn):
            minn = key[i]
            min_idx = i 
    return min_idx

ver, edgs = map(int, input().split())

graph = [[0]*(ver+1) for i in range(ver+1)]

for i in range(edgs):
    n1, n2, wt = map(int, input().split())
    graph[n1][n2] = wt
    graph[n2][n1] = wt
    
final_set = [0]*(ver+1)  #keeps track of vertices in final mst.
parent = [0]*(ver+1)
key = [INT_MAX]*(ver+1)
key[1] = 0          #mst starting with node no. 1
parent[1] = -1     
mst_weight=0

for ct in range(1, ver):
    u = min_key(key, final_set)
    
    final_set[u] = 1
    for v in range(1, ver+1):
        if graph[u][v]!=0 and final_set[v]==0 and graph[u][v]<key[v]:
            parent[v] = u
            key[v] = graph[u][v]
            
for i in range(2, ver+1):
    mst_weight += graph[i][parent[i]]
print (mst_weight)
                        
for  i in range(2, ver+1):
    print(parent[i], end =" ") 
    print(i)    
    