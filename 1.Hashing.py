"""
Functions:
constructor __init__(self) - size,hashtable(list 0 for i in range self.size),totalElements,comparisons
isFull - totalElements==size TRUE
HashFunction - return element%size
InsertLinear - call isFull,InsertionStatus=False, position=self.HashFunction[Element], if pos==0 hashtable[position]=element,
               else call LinearProbing and insert at new position, return status
LinearProbing - while position!=0 increment postion, if position>size position=0, return position
InsertQuadratic - call isFull, Status=False, call hashFunction, if position==0 insert, else call QuadratingProbing, insert elemenet at new position, return status
QuadraticProbing - limit=50,i=1, while i<limit newposition=position+(i**2), newposition=newposition%size, if newposition==0 break else i+=1 return newposition
display - for i in range(self.size) : "\t"+str(i)+"====>"+str(self.HashTable[i])+"\n"
search - isFound=False, limit=50, calculate position of key to find, if element present at HashTable[position] return index comparisons+=1 Found=True,
         else: while (position+1)<size,if element not at positon position+=1 comaprison+=1, if present return index and found=True
               while(position-1)>=0, if element not present position-=1 comparison+=1 else return index Found=True
Creation of object - objectName=className()
create separate objects of linear and quadratic probing.

"""

class HashingDemo:
    #hashtable initialised here
    
    def __init__(self):
        self.size = int(input("Enter size of Hashtable to store telephone numbers: "))
        self.HashTable = list(0 for i in range(self.size)) #assign 0 to all index of list
        self.totalElements = 0
        self.comparisons = 0

    def isFull(self):   #returns boolean
        if self.totalElements == self.size :  # ':' after if else statement
            return True
        else :
            return False  #Write true false in capital

    def HashFunction(self,element):   #returns index(int)
        return element % self.size

    def InsertLinear(self,element):
        if self.isFull() :
            print("Hash Table is Full.")
            return False

        InsertionStatus = False

        position = self.HashFunction(element)

        if self.HashTable[position]==0 : 
            self.HashTable[position] = element
            print("Telephone number "+str(element)+" is inserted at index "+str(position))
            InsertionStatus = True
            self.totalElements += 1
        else: #Collision handled using linear probing
            print("Collision occurred for "+str(element)+" at index "+str(position))
            position=self.LinearProbing(element,position)
            self.HashTable[position]=element
            print(str(element)+" is inserted at new position "+str(position))
            InsertionStatus = True
            self.totalElements +=1
        return InsertionStatus

    def LinearProbing(self,element,position):  #returns new index of element(int)
        while self.HashTable[position] != 0 :  #':' after while statement
            position += 1
            if position>=self.size :
                position=0
        return position

    def InsertQuadratic(self,element):
        if self.isFull():
            print("Hashtable is Full.")
            return False

        InsertionStatus : False

        position=self.HashFunction(element)

        if self.HashTable[position] == 0:
            self.HashTable[position]=element
            print("Telephone number "+str(element)+" is inserted at position "+str(position))
            self.totalElements +=1
            InsertionStatus=True
        else:
            print("Collision occurred for "+str(element)+" at index "+str(position))
            position = self.QuadraticProbing(element,position)
            self.HashTable[position]=element
            print(str(element)+" is inserted at new position "+str(position))
            InsertionStatus=True
            self.totalElements+=1
        return InsertionStatus

    def QuadraticProbing(self,element,position):  #returns new index
        limit=50
        i=1
        while i<=limit:
            newPosition=position+(i**2)
            newPosition=newPosition%self.size
            if self.HashTable[newPosition]==0:
                break                
            else:
                i +=1
        return newPosition

    def display(self):
        print("\n")
        print("---------------------------------")
        print("\n Position \t Telephone Number")
        print("\n---------------------------------\n")
        for i in range(self.size):
            print("\t"+str(i)+"====>"+str(self.HashTable[i]))

    def search(self,element):
        isFound=False
        position=self.HashFunction(element)  #calculate position of key to be searched
        self.comparisons +=1
        if(self.HashTable[position]==element): #first comparison
            isFound=True
            return position
        else:
            #search from position+1 to end
            while (position+1)<self.size: 
                if self.HashTable[position]!=element:
                    position+=1  #move to next position in hashtable
                    self.comparisons +=1  #increment comparison at every stepahead in hashtable
                else:
                    isFound=True
                    return position #element found
            #search from position-1 till zero
            while (position-1)>=0:
                if self.HashTable[position]!=element:
                    position -=1
                    self.comparisons +=1
                else:
                    isFound=True
                    return position
        if isFound==False:
            print("Element not found.")
            return False
                
        

# main function
hash_object1 = HashingDemo()
print("\nInserting Telephone numbers in hashtable...\n")
print("To solve collision Linear Probing is used...\n")
hash_object1.InsertLinear(1111111112)
hash_object1.InsertLinear(3333333331)
hash_object1.InsertLinear(4444444417)
hash_object1.InsertLinear(5555555590)
hash_object1.InsertLinear(6666666621)
hash_object1.InsertLinear(7777777788)
hash_object1.InsertLinear(8888888840)
hash_object1.InsertLinear(9999999977)
hash_object1.display()
print("\nPosition of 8888888840 : "+str(hash_object1.search(8888888840)))
print("\nPosition of 6666666621 : "+str(hash_object1.search(6666666621)))
print("\n---------------------------------")
print("\nTotal comparisons done for searching = "+str(hash_object1.comparisons))
print("\n---------------------------------")
print("\n*********************************\n")
                
hash_object2 = HashingDemo()
print("\nInserting Telephone numbers in hashtable...\n")
print("To solve collision Quadratic Probing is used...\n")
hash_object2.InsertQuadratic(1111111112)
hash_object2.InsertQuadratic(3333333331)
hash_object2.InsertQuadratic(4444444417)
hash_object2.InsertQuadratic(5555555590)
hash_object2.InsertQuadratic(6666666621)
hash_object2.InsertQuadratic(7777777788)
hash_object2.InsertQuadratic(8888888840)
hash_object2.InsertQuadratic(9999999977)
hash_object2.display()
print("\nPosition of 8888888840 : "+str(hash_object2.search(8888888840)))
print("\nPosition of 6666666621 : "+str(hash_object2.search(6666666621)))
print("\n---------------------------------")
print("\nTotal comparisons done for searching = "+str(hash_object2.comparisons))

print("\n---------------------------------")
print("\n*********************************\n")

            
