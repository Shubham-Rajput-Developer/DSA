'''Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client‘s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers.
'''
size = int(input("Enter Size of Hash Table : "))
hashTable = [-1]*size

def Linear(num):
    for i in range(size):
        idx = (num+i)%size
        if(hashTable[idx] == -1):
            hashTable[idx] = num
            print("Insert")
            return
    print("Table is Full..!!!!")
    
def Qudratic(num):
    for i in range(size):
        idx = (num+i*i)%size
        if(hashTable[idx] == -1):
            hashTable[idx] = num
            print("Insert")
            return
    print("Table is Full..!!!!")
  
def Search(num):
    for i in range(size):
        idx = (num+i)%size
        if(hashTable[idx]==num):
            print("Number found at : ",idx)
            print("Number of Comparision required : ",)
            return
    print("Element not found..!!!")
        
while(True):
    print("Enter your choise: ")
    print("1.Insert using Linear ")
    print("2.Insert using Qudratic")
    print("3.Search a telephone No. ")
    print("4.Exit")
    choise = int(input("Input-> "))
    if(choise==1):
        num = int(input("Enter Telephone No. : "));
        Linear(num)
    elif(choise==2):
        num = int(input("Enter Telephone No. : "))
        Qudratic(num)
    elif(choise==3):
        num = int(input("Enter Telephone No. to be Search : "))
        Search(num)
    else:
        exit(0)
    