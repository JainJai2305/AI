

from collections import defaultdict 
  

class Graph: 
  
    def __init__(self,vertices): 
  
        
        self.V = vertices 
  
         
        self.graph = defaultdict(list) 
  
    
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
  
    
    def DLS(self,src,target,maxDepth): 
  
        if src == target : return True
  
        if maxDepth <= 0 : return False
  
        for i in self.graph[src]: 
                if(self.DLS(i,target,maxDepth-1)): 
                    return True
        return False
  
     
    def IDDFS(self,src, target, maxDepth): 
  
        
        for i in range(maxDepth): 
            if (self.DLS(src, target, i)): 
                return True
        return False
  

print("enter the number of vertices") 
ver = int(input())
g = Graph (ver)
print("enter the edges")
ch=0
while(ch!=-1) :
    ver1 = int(input())
    ver2 = int(input())
    g.addEdge(ver1, ver2) 
    print("entert the choice")
    ch = int(input())
 

print("enter the target ")
target = int(input())
print("enter the max depth ")
maxDepth = int(input())
print("enter the source ")
src = int(input())
  
if g.IDDFS(src, target, maxDepth) == True: 
    print ("Target is reachable from source " +
        "within max depth") 
else : 
    print ("Target is NOT reachable from source " +
        "within max depth")

