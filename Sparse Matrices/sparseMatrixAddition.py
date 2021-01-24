'''

Time Complexity: O(R*C), R -> No. of rows, C -> No. of columns 
Space Complexity: O(R*C), R -> No. of rows, C -> No. of columns

'''

class Node:
       def __init__(self,row,col,val):
              # Node takes row number column number and value
              self.r=row
              self.c=col
              self.v=val
              # next row and next col is initialized to None
              self.nr=None
              self.nc=None
              
class Sparse:     
       def __init__(self,m,n):
              #initializing the header node for each row
              self.rh=[0]
              #initializing the header node for each column
              self.ch=[0]
              for i in range(1,m+1):
                     #creating elements for each row and assigning no value
                     self.rh.append(Node(i,0,0))
                     #next of the last element points to first element
                     self.rh[i].nr=self.rh[i]
              for i in range(1,n+1):
                     #creating elements for each column and assigning no value
                     self.ch.append(Node(0,i,0))
                     #next of the last element points to first element
                     self.ch[i].nc=self.ch[i]
       def insert(self,row,col,val):
              #Node is created with inputted row,column and value
              #new is the node that is going to be inserted
              new=Node(row,col,val)
              #if value is 0, the node should not be inserted
              if val==0:
                     return
              #row header
              #prev is first initialized to the given row in the row header
              prev=self.rh[row]
              temp=prev.nr
              #While loop to traverse and find the position at where to be inserted
              #till temp's column number is less than entered column number
              while (temp!=self.rh[row]) and (temp.c < col):
                     prev=temp
                     temp=temp.nr
              #Checking if the same row number and column number is entered again, its value must be changed
              if(temp.c==col and temp.r==row):
                     temp.v=val
                     return
              #Insertion takes place between prev and temp
              prev.nr=new
              new.nr=temp
              #column header
              prev=self.ch[col]
              temp=prev.nc
              #While loop to traverse and find the position at where to be inserted
              while (temp!=self.ch[col]) and (temp.r < row):
                     prev=temp
                     temp=temp.nc
              #Checking if the same row number and column number is entered again, its value must be changed
              if(temp.c==col and temp.r==row):
                     temp.v=val
                     return
              #Insertion takes place between prev and temp
              prev.nc=new
              new.nc=temp
       def summatrix(self,self1,self2,m,n):
              for i in range(1,m+1):
                     #iterating through row headers
                     temp1=self1.rh[i].nr
                     temp2=self2.rh[i].nr
                     #looping through to traverse row headers
                     while temp1 is not self1.rh[i] and temp2 is not self2.rh[i]:
                            #when the row and column of the two sparse matrices matches the value get added and inserted to sum matrix
                            if temp1.r ==temp2.r and temp1.c==temp2.c:
                                   va=temp1.v+temp2.v
                                   self.insert(temp1.r,temp1.c,va)
                                   temp1=temp1.nr
                                   temp2=temp2.nr
                            #when column of matrix 1 is less than column of matrix 2
                            elif temp1.r==temp2.r and temp1.c<temp2.c:
                                   self.insert(temp1.r,temp1.c,temp1.v)
                                   temp1=temp1.nr
                            #when column of matrix 2 is less than column of matrix 1
                            elif temp1.r==temp2.r and temp1.c>temp2.c:
                                   self.insert(temp2.r,temp2.c,temp2.v)
                                   temp2=temp2.nr
                     #checking whether which matrix gets emptied
                     if temp1==self1.rh[i]:
                            # inserting the remaining elements in matrix 2 to sum matrix
                            while temp2 is not self2.rh[i]:
                                   self.insert(temp2.r,temp2.c,temp2.v)
                                   temp2=temp2.nr
                     else:
                            # inserting the remaining elements in matrix 1 to sum matrix
                            while temp1 is not self1.rh[i]:
                                   self.insert(temp1.r,temp1.c,temp1.v)
                                   temp1=temp1.nr                                  
       def printmatrix(self,m,n):
              #for loop to traverse different row headers
              print("(Row,Column)-->Value")
              for i in range(1,m+1):
                     curr=self.rh[i].nr
                     while curr!=self.rh[i]:
                            #printing the value row and column
                            print("(",curr.r,",",curr.c,")-->",curr.v)
                            curr=curr.nr
if __name__=="__main__":
       #getting input number of rows and columns
       m1=int(input("Enter no.of rows:"))
       n1=int(input("Enter no.of cols:"))
       # two sparse matrices are created
       s1=Sparse(m1,n1)
       s2=Sparse(m1,n1)
       s3=Sparse(m1,n1)
       ch='y'
       print("Matrix 1")
       # getting input till the user enters Y
       while ch.upper()=='Y':
              #getting input as row col value
              row=int(input("Enter row:"))
              if row <=m1:    
                     col=int(input("Enter column:"))
              else:
                     print("Invalid row no.")
                     exit(0)
              if col<=n1:
                     item=int(input("Enter value:"))
              else:
                     print("Invalid column no.")
                     exit(0)
              #insertion function is called 
              s1.insert(row,col,item)
              #if choice is entered as Y , then the loop runs again and inputted
              ch=input("Enter y to add more elements:")
       #printing the elements of sparse matrix 1
       print("Sparse Matrix 1 elements:")
       s1.printmatrix(m1,n1)
       print("Matrix 2")
       ch='y'
       # getting input till the user enter Y
       while ch.upper()=='Y':
              #getting input as row column value
              row=int(input("Enter row:"))
              if row<=m1:
                     col=int(input("Enter column:"))
              else:
                     print("Invalid row no.")
                     exit(0)
              if col<=n1:
                     item=int(input("Enter value:"))
              else:
                     print("Invalid column no.")
                     exit(0)
              #insert function is called
              s2.insert(row,col,item)
              #if choice is entered as Y , then the loop runs again and inputted
              ch=input("Enter y to add more elements:")
       #printing sparse matrix 2 elements
       print("Sparse Matrix 2 elements:")
       s2.printmatrix(m1,n1)
       #function to add Sparse matrices is called
       s3.summatrix(s1,s2,m1,n1)
       print("Sum Sparse matrix")
       #printing the sum sparse matrix
       s3.printmatrix(m1,n1)
       
      
              
