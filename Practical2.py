'''
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)
'''
size = int(input("Enter size of hash Table : "))
hashTable = {}

def addList(size,dict):
    for i in range(size):
        dict[i] = []
    return dict

def Insert(size,key,val,dict):
    lst = []
    idx = key%size
    lst += [key,val]
    dict[idx].append(lst)
    return dict
def Search(key,dict):
    for i in dict:
        for j in dict[i]:
            if(j[0]==key):
                return j
    print("Not found !!!!")
def Delete(key,dict):
    for i in dict:
        for j in dict[i]:
            if(j[0]==key):
                dict[i].remove(j)
    return dict
    
dict = addList(size,hashTable)

while(True):
    print("Enter your choice : ")
    print("1.Insert ")
    print("2.Search ")
    print("3.Delete ")
    ch = int(input("--->"))
    
    if(ch==1):
        key = int(input("Enter key : "))
        val = input("Enter Value : ")
        print(Insert(size,key,val,dict))
    elif(ch==2):
        key = int(input("Enter key for Search : "))
        print(Search(key,dict))
    elif(ch==3):
        key = int(input("Enter key for that you want to delete : "))
        print(Delete(key,dict))
    else:
        exit(0)
     