# Project_Order_Manager

Application which executes orders placed by a user. The orders can be placed on the buy or the sell side. 
Additionally, the application also supports cancellation of and printing of the orders placed earlier. 

The application comes with a built in small compiler which parses each individual order and throws exception
when the order is invalid. The orders are matched on the buy and sell side based on Price-Time priority. As 
soon as a matching order is found on the buy or sell side for a received order on the sell or buy side, the
trade is executed by the executor and orders within the datasets are updated.

## Software Architecture Highlights:

### Use Cases  

![alt text](https://github.com/GDhir/Project_Order_Manager/blob/master/IMG_Folder/uml_diagram.png)

### Class Hierarchy

![alt text](https://github.com/GDhir/Project_Order_Manager/blob/master/IMG_Folder/class_diagrams.png)
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
![alt text](https://github.com/GDhir/Project_Order_Manager/blob/master/IMG_Folder/factory_diagrams.png)
<br/>
<br/>
### Sample User Session <br/>
    INPUT                                   
    ======================================= 
    "O 10000 IBM B 10 100.00000"            
    "O 10001 IBM B 10 99.00000"             
    "O 10002 IBM S 5 101.00000"             
    "O 10003 IBM S 5 100.00000"             
    "O 10004 IBM S 5 100.00000"             
    "X 10002"                               
    "O 10005 IBM B 10 99.00000"             
    "O 10006 IBM B 10 100.00000"            
    "O 10007 IBM S 10 101.00000"            
    "O 10008 IBM S 10 102.00000"            
    "O 10008 IBM S 10 102.00000"            
                                            
    "O 10009 IBM S 10 102.00000"            
    "P"                                     
    "O 10010 IBM B 13 102.00000"  
    
Output: <br/>
F 10003 IBM 5 100.00000 <br/>
F 10000 IBM 5 100.00000 <br/>
F 10004 IBM 5 100.00000 <br/>
F 10000 IBM 5 100.00000 <br/>
X 10002 <br/>
E 10008 Duplicate order id <br/>
P 10009 IBM S 10 102.00000 <br/>
P 10008 IBM S 10 102.00000 <br/>
P 10007 IBM S 10 101.00000 <br/>
P 10006 IBM B 10 100.00000 <br/>
P 10001 IBM B 10 99.00000 <br/>
P 10005 IBM B 10 99.00000 <br/>
F 10010 IBM 10 101.00000 <br/>
F 10007 IBM 10 101.00000 <br/>
F 10010 IBM 3 102.00000 <br/>
F 10008 IBM 3 102.00000 <br/>
