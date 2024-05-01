'''
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)
'''
size = int(input("Enter size of HashTable : "))
hashTable = {}

def addList(size,dict):
    for i in range(size):
        hashTable[i] = []
    return dict

def Insert(size,key,value,dict):
    lst = []
    idx = value%size
    lst +=[key,value]
    dict[idx].append(lst)
    return dict
    
def Delete(dict,key):
    for i in dict:
        for j in dict[i]:
            if(j[0]==key):
                dict[i].remove(j)
    return dict
 
def Search(dict,key):
    for i in dict:
        for j in dict[i]:
            if(j[0]==key):
                return j
    print("Not Found!")
    
dict = addList(size,hashTable)

while(True):
    print("Enter your choice : ")
    print("1.Inserting Data ")
    print("2.Deleting Data ")
    print("3.Search Data")
    choice = int(input("Input->"))
    
    if(choice==1):
        key = int(input("Enter Key : "))
        value = int(input("Enter Value : "))
        print(Insert(size,key,value,dict))
    elif(choice==2):
        key = int(input("Enter Key to be Deleted : "))
        print(Delete(dict,size))
    elif(choice==3):
        key = int(input("Enter key to be Search : "))
        print(Search(dict,key))
    else:
        exit(0)