# SuperMarket
Implementation of supermarket invoice sequence

The functionalities are :

Program handling the Super Market invoice sequence

Inventory = Product database with product name, code and quantity
    Used hashing with chaining(bucket = 13) because it is quick to search

Customer database = Name, Identification, Bill, Points
    Same as inventory
    
Manager = Manages the inventory and customers
    Can read, write, delete in inventory and customer database

Billing = Calculates the total payable, offers and discounts
    Cannot change customer and can only change quantity of items in inventory
