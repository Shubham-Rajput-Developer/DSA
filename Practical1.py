'''Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.
'''
size = int(input("Enter size of Hash Table : "))
hashTable=[-1]*size

def Linear(num):
    for i in range(size):
        idx = (num+i)%size
        if(hashTable[idx]==-1):
            hashTable[idx]=num
            print("Insert")
            return
    print("Table is Full!!!")
    
def Qudratic(num):
    for i in range(size):
        idx = (num+i*i)%size
        if(hashTable[idx]==-1):
            hashTable[idx]=num
            print("Insert")
            return
    print("Table is Full!!!!")

def Search(num):
    count = 0
    for i in range(size):
        idx = (num+i)%size
        count = count+1
        if(hashTable[idx]==num):
            print("Number found at : ",idx)
            print("Number of Comparision required is : ",count)
    print("Element not found!!!")
            
        
while(True):
    print("Enter Your choice : ")
    print("1.Insert using Linear techniques")
    print("2.Insert using Qudratic techniques")
    print("3.Search a telephone no. ")
    print("4.Exit")
    ch = int(input("---->"))
    if(ch == 1):
        num = int(input("Enter telephone No. : "))
        Linear(num)
    elif(ch == 2):
        num = int(input("Enter telephone No. : "))
        Qudratic(num)
    elif(ch==3):
        num = int(input("Enter no. do you want to search : "))
        Search(num)
    else:
        exit(0)
