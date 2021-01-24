import sys
input=sys.stdin.readline

'''

Time Complexity: O(R*C), R -> No. of rows, C -> No. of columns 
Space Complexity: O(R*C), R -> No. of rows, C -> No. of columns

'''

def lin(): #input array in single line
    return list(map(int,input().split()))

class Node:
    def __init__(self,r,c,value): #constructor 
        self.row=r
        self.col=c
        self.data=value
        self.next_column=None
        self.next_row=None

class SparseMatrix:
    def __init__(self,n,m):
        self.row_head=[0]  #initialising row and column heads
        self.col_head=[0]
        for i in range(1,n+1):
            new_node=Node(i,0,0)
            self.row_head.append(new_node)
            self.row_head[i].next_column=self.row_head[i]
        for i in range(1,m+1):
            new_node=Node(0,i,0)
            self.col_head.append(new_node)
            self.col_head[i].next_row=self.col_head[i]
    
    def insert(self,r,c,value):
        new_node=Node(r,c,value)
        #insertion in row headers
        previous_node=self.row_head[r]
        last=self.row_head[r].next_column
        rhead=self.row_head[r]
        while last!=rhead:
            if last.col>c:
                break
            previous_node=last
            last=last.next_column
        new_node.next_column=last
        previous_node.next_column=new_node
        
        #insertion in column headers
        previous_node=self.col_head[c]
        last=self.col_head[c].next_row
        chead=self.col_head[c]
        while last!=chead:
            if last.row>r:
                break
            previous_node=last
            last=last.next_row
        new_node.next_row=last
        previous_node.next_row=new_node
        
    def printSparseMatrix(self): #printing a Sparse Matrix
        n=len(self.row_head)
        for i in range(1,n):
            rhead=self.row_head[i]
            node=rhead.next_column
            while node!=rhead:
                print(node.row,node.col,node.data)
                node=node.next_column
                
    def subtract(self,matrix1,matrix2,n,m): #Row-wise subtraction
        for i in range(1,n+1):
            p=matrix1.row_head[i].next_column
            q=matrix2.row_head[i].next_column
            phead=matrix1.row_head[i]
            qhead=matrix2.row_head[i]
            while p!=phead and q!=qhead:
                if p.col==q.col:
                    value=p.data-q.data
                    if value:
                        self.insert(i,p.col,value)
                    p=p.next_column
                    q=q.next_column
                elif p.col<q.col:
                    self.insert(i,p.col,p,data)
                    p=p.next_column
                else:
                    self.insert(i,q.col,-1*q.data)
                    q=q.next_column
            while p!=phead:
                self.insert(i,p.col,p.data)
                p=p.next_column
            while q!=qhead:
                self.insert(i,q.col,-1*q.data)
                q=q.next_column
                
    
if __name__ == "__main__": #input matrices, invoke subtraction function and print the result
    n,m=lin()
    Matrix1=SparseMatrix(n,m)
    Matrix2=SparseMatrix(n,m)
    Result=SparseMatrix(n,m)
    mat=[]
    for i in range(n):
        rows=lin()
        mat.append(rows)
    for i in range(n):
        for j in range(m):
            if(mat[i][j]):
                Matrix1.insert(i+1,j+1,mat[i][j])
    mat=[]
    for i in range(n):
        rows=lin()
        mat.append(rows)
    for i in range(n):
        for j in range(m):
            if(mat[i][j]):
                Matrix2.insert(i+1,j+1,mat[i][j])
    print("Matrix 1")
    Matrix1.printSparseMatrix()
    print("Matrix 2")
    Matrix2.printSparseMatrix()
    Result.subtract(Matrix1,Matrix2,n,m)
    print("Result Matrix : Matrix1 - Matrix 2")
    Result.printSparseMatrix()
    
