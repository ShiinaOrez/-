import sqlite3

stu=sqlite3.connect('std_info.db')
s=stu.cursor()

print ("1-->add a column;2-->delete a column;3-->watch all column;quit-->-1;")
print ("\n")

while(1):
    a=input("please input the number:")
    a=int(a)
    if a==-1 :
        break
    if a==1 :
        id=input("the id:")
        name=input("the name:")
        age=input("the age:")
        address=input("the address:")
        s.execute("INSERT INTO STU (ID,NAME,AGE,ADDRESS) VALUES ("+str(id)+", "+str(name)+", "+str(age)+", "+str(address)+")");
        stu.commit()
        print ("insert successfully!\n")
    if a==2 :
        id=input("the id:")
        s.execute("DELETE FROM STU WHERE ID="+str(id)+";")
        stu.commit()
        print ("delete successfully!\n")
    if a==3 :
        ss=s.execute("SELECT id, name,age, address FROM STU")
        for row in ss:
            print ("ID = ", row[0])
            print ("NAME = ", row[1])
            print ("AGE = ", row[2])
            print ("ADDRESS = ", row[3])
            print ("\n")
        print ("that is all!\n")

stu.close()

