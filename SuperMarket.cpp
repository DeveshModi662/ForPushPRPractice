#include<bits/stdc++.h> 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
# define bucket 13
#define INVENTORY \
{\
{111100000001,"1",100,20},{111100000002,"2",110,20},{111100000003,"3",120,20},{111100000004,"4",130,20},{111100000005,"5",140,20},{111100000006,"6",150,20},{111100000007,"7",160,20},{111100000008,"8",170,20},{111100000009,"9",180,20},{111100000010,"10",190,20},\
{111100000011,"11",200,20},{111100000012,"12",210,20},{111100000013,"13",220,20},{111100000014,"14",230,20},{111100000015,"15",240,20},{111100000016,"16",250,20},{111100000017,"17",260,20},{111100000018,"18",270,20},{111100000019,"19",280,20},{111100000020,"20",290,20},\
{111100000021,"21",300,20},{111100000022,"22",310,20},{111100000023,"23",320,20},{111100000024,"24",330,20},{111100000025,"25",340,20},{111100000026,"26",350,20},{111100000027,"27",360,20},{111100000028,"28",370,20},{111100000029,"29",380,20},{111100000030,"30",390,20},\
{111100000031,"31",400,20},{111100000032,"32",410,20},{111100000033,"33",420,20},{111100000034,"34",430,20},{111100000035,"35",440,20},{111100000036,"36",450,20},{111100000037,"37",460,20},{111100000038,"38",470,20},{111100000039,"39",480,20},{111100000040,"40",490,20},\
{111100000041,"41",500,20},{111100000042,"42",510,20},{111100000043,"43",520,20},{111100000044,"44",530,20},{111100000045,"45",540,20},{111100000046,"46",550,20},{111100000047,"47",560,20},{111100000048,"48",570,20},{111100000049,"49",580,20},{222200001111,"50",590,20},\
{222200001114,"51",600,20},{222200001117,"52",610,20},{222200001120,"53",620,20},{222200001123,"54",630,20},{222200001126,"55",640,20},{222200001129,"56",650,20},{222200001132,"57",660,20},{222200001135,"58",670,20},{222200001138,"59",680,20},{222200001141,"60",690,20},\
{222200001144,"61",700,20},{222200001147,"62",710,20},{222200001150,"63",720,20},{222200001153,"64",730,20},{222200001156,"65",740,20},{222200001159,"66",750,20},{222200001162,"67",760,20},{222200001165,"68",770,20},{222200001168,"69",780,20},{222200001171,"70",790,20},\
{222200001174,"71",800,20},{222200001177,"72",810,20},{222200001180,"73",820,20},{222200001183,"74",830,20},{222200001186,"75",840,20},{222200001189,"76",850,20},{222200001192,"77",860,20},{222200001195,"78",870,20},{222200001198,"79",880,20},{222200001201,"80",890,20},\
{222200001204,"81",900,20},{222200001207,"82",910,20},{222200001210,"83",920,20},{222200001213,"84",930,20},{222200001216,"85",940,20},{222200001219,"86",950,20},{222200001222,"87",960,20},{222200001225,"88",970,20},{222200001228,"89",980,20},{222200001231,"90",990,20},\
{222200001234,"91",1000,20},{222200001237,"92",1010,20},{222200001240,"93",1020,20},{222200001243,"94",1030,20},{222200001246,"95",1040,20},{222200001249,"96",1050,20},{222200001252,"97",1060,20},{222200001255,"98",1070,20},{222200001258,"99",1080,20},{222200001261,"100",1090,20},\
}
#define CUSTOMER \
{\
{9400000001,"1",0},{9400000002,"2",0},{9400000003,"3",0},{9400000004,"4",0},{9400000005,"5",0},{9400000006,"6",0},{9400000007,"7",0},{9400000008,"8",0},{9400000009,"9",0},{9400000010,"10",0},\
{9400000011,"11",0},{9400000012,"12",0},{9400000013,"13",0},{9400000014,"14",0},{9400000015,"15",0},{9400000016,"16",0},{9400000017,"17",0},{9400000018,"18",0},{9400000019,"19",0},{9400000020,"20",0},\
{9400000021,"21",0},{9400000022,"22",0},{9400000023,"23",0},{9400000024,"24",0},{9400000025,"25",0},{9400000026,"26",0},{9400000027,"27",0},{9400000028,"28",0},{9400000029,"29",0},{9400000030,"30",0},\
{9400000031,"31",0},{9400000032,"32",0},{9400000033,"33",0},{9400000034,"34",0},{9400000035,"35",0},{9400000036,"36",0},{9400000037,"37",0},{9400000038,"38",0},{9400000039,"39",0},{9400000040,"40",0},\
{9400000041,"41",0},{9400000042,"42",0},{9400000043,"43",0},{9400000044,"44",0},{9400000045,"45",0},{9400000046,"46",0},{9400000047,"47",0},{9400000048,"48",0},{9400000049,"49",0},{9400000050,"50",0},\
{9400000051,"51",0},{9400000052,"52",0},{9400000053,"53",0},{9400000054,"54",0},{9400000055,"55",0},{9400000056,"56",0},{9400000057,"57",0},{9400000058,"58",0},{9400000059,"59",0},{9400000060,"60",0},\
{9400000061,"61",0},{9400000062,"62",0},{9400000063,"63",0},{9400000064,"64",0},{9400000065,"65",0},{9400000066,"66",0},{9400000067,"67",0},{9400000068,"68",0},{9400000069,"69",0},{9400000070,"70",0},\
{9400000071,"71",0},{9400000072,"72",0},{9400000073,"73",0},{9400000074,"74",0},{9400000075,"75",0},{9400000076,"76",0},{9400000077,"77",0},{9400000078,"78",0},{9400000079,"79",0},{9400000080,"80",0},\
{9400000081,"81",0},{9400000082,"82",0},{9400000083,"83",0},{9400000084,"84",0},{9400000085,"85",0},{9400000086,"86",0},{9400000087,"87",0},{9400000088,"88",0},{9400000089,"89",0},{9400000090,"90",0},\
{9400000091,"91",0},{9400000092,"92",0},{9400000093,"93",0},{9400000094,"94",0},{9400000095,"95",0},{9400000096,"96",0},{9400000097,"97",0},{9400000098,"98",0},{9400000099,"99",0},{9400000100,"100",0},\
}
#define LETTERS 26
using namespace std;
int diff = 1 , RANDOM = 10;
int t = 0 ;
                // STRUCTURES
struct person
{
    long id ;
    string name ;
    long points ;
    person *next ;
};
struct item
{
    long id ;
    string name ;
    int rate , quantity ;
    item *next ;
};
struct item1    //node for purchase cart
{
    long id ;
    string name ;
    int rate , quantity ;
    long amount ;
};
                //      I N V E N T O R Y       //
class inventory
{
    private :
    static item *item_list[bucket];
    
    public :
    inventory()
    {
        item items[100] = INVENTORY ;
        int i ;
        for(i = 0 ; i < 100 ; i++)
        {
            add_item(items[i].id, items[i].name, items[i].rate, items[i].quantity) ;
        }
    }
    
    protected :
    void add_item(long iid, string n, int r, int q)
    {
        int index = iid % bucket ;        
        item *itr , *prev , *new_item = new item ;
        itr = item_list[index] ;
        prev = NULL ;
        new_item->id = iid; new_item->name = n; new_item->rate = r; new_item->quantity = q;
        if(item_list[index] == NULL)
        {
            new_item->next = NULL ;
            item_list[index] = new_item ;            
        }
        else
        {
            while(itr != NULL && itr->id < iid)
            {
                prev = itr ;
                itr = itr->next ;
            }
            if(itr != NULL && itr->id == iid)
            {
                itr->name = n; itr->rate = r; itr->quantity = q;
            }
            else
            {
                new_item->next = itr ;
                if(prev == NULL)
                {   
                    item_list[index] = new_item ;
                }
                else
                {
                    prev->next = new_item ;
                }
            }   
        }     
    }
    void delete_item(long iid)
    {
        int index = iid % bucket ;
        item *itr , *prev ;
        itr = item_list[index] ;
        prev = NULL ;
        if(item_list[index])
        {
            while(itr != NULL && itr->id < iid)
            {
                prev = itr ;
                itr = itr->next ;
            }
            if(itr != NULL && itr->id == iid)
            {
                if(itr == item_list[index])
                {
                    item_list[index] = itr->next ;
                }
                else
                {
                    prev->next = itr->next ;
                }
                cout << "Item " << itr->name << " deleted" << endl ;
                delete itr ;
            }
            else
            {
                cout << "No such product" << endl ;
            }
        }
        else
        {
            cout << "No such product" << endl ;
        }
    }
    item get_product_info(long iid)
    {
        int index = iid % bucket ;
        item *itr = item_list[index] , *default_item = new item ;
        default_item->id = 0;default_item->name = "Can't find info !";default_item->rate = -1;default_item->quantity =0;
        while(itr != NULL && itr->id < iid)
        {
            itr = itr->next ;
        }
        if(itr != NULL && itr->id == iid)
        {
            return *itr ;
        }
        else
        {
            return *default_item ;
        }
    }
    void update_stock(long iid, int quantity_bought)
    {
        int index = iid % bucket ;
        item *itr = item_list[index] ;
        while(itr != NULL && itr->id != iid)
        {
            itr = itr->next ;
        }
        if(itr->id == iid)
        {
            itr->quantity = itr->quantity - quantity_bought ;
        }        
    }
    void update_item(long iid, string n, int r, int q)
    {    
        int index = iid % bucket ;        
        item *itr = item_list[index] ;
        while(itr != NULL && itr->id < iid)
        {
            itr = itr->next ;
        }
        if(itr->id == iid)
        {
            itr->name = n; itr->rate = r; itr->quantity = q;
        }
        else
        {
            add_item(iid, n, r, q); 
        }
    }
};
item* inventory::item_list[bucket];
                //      M A N A G E R       //
class manager : protected inventory
{
    private :
    long id ;
    string name ;
    
    public :
    manager(long iid, string n)
    {
        id = iid ;
        name = n ;
    }
    void add_item(long iid, string n, int r, int q)
    {
        inventory::add_item(iid, n, r, q) ;
    }
    void delete_item(long iid)
    {
        inventory::delete_item(iid) ;
    }
    void update_item(long iid, string n, int r, int q)
    {
        inventory::update_item(iid, n, r, q) ;
    }
    void update_stock(long iid, int quantity_bought)
    {
        inventory::update_stock(iid, quantity_bought) ;
    }
    item get_product_info(long iid)
    {
        item i = inventory::get_product_info(iid) ;
        return i ;
    }
};
                //      C U S T O M E R        //
class customer 
{
    private :
    static person *customer_list[bucket];
    
    public :
    customer()
    {
        person customers[100] = CUSTOMER ;
        int i ;
        for(i = 0 ; i < 100 ; i++)
        {
            add_customer(customers[i].id, customers[i].name, customers[i].points) ;
        }
    }
    
    protected :
    void add_customer(long iid, string n, long p)
    {
        int index = iid % bucket ;        
        person *itr , *prev , *new_customer = new person ;
        itr = customer_list[index] ;
        prev = NULL ;
        new_customer->id = iid; new_customer->name = n; new_customer->points = p;
        if(customer_list[index] == NULL)
        {
            new_customer->next = NULL ;
            customer_list[index] = new_customer ;            
        }
        else
        {
            while(itr != NULL && itr->id < iid)
            {
                prev = itr ;
                itr = itr->next ;
            }
            if(itr != NULL && itr->id == iid)
            {
                itr->id = iid; itr->name = n; itr->points = itr->points + p;
            }
            else
            {
                new_customer->next = itr ;
                if(prev == NULL)
                {   
                    customer_list[index] = new_customer ;
                }
                else
                {
                    prev->next = new_customer ;
                }
            }   
        }     
    }
    void update_points(long iid, long add_pts)
    {
        int index = iid % bucket ;
        person *itr = customer_list[index] ;
        while(itr != NULL && itr->id < iid)
        {
            itr = itr->next ;
        }
        if(itr != NULL && itr->id == iid)
        {
            itr->points = itr->points + add_pts ;
        }
    }
    int search_customer(long iid)
    {
        person *itr = customer_list[iid%bucket] ;
        while(itr != NULL && itr->id < iid)
        {
            itr = itr->next ;
        }
        if(itr != NULL && itr->id == iid)
        {
            return 1 ;
        }
        return 0 ;
    }
};
person* customer::customer_list[bucket];
                //      B I L L I N G      //
class billing : protected inventory, protected customer
{
    private :
    long customer_id , total_amount ;
    string transaction_id ;
    list<item1> bill_list ;
    
    public :
    billing(long cid)
    {
        transaction_id = "" ;
        customer_id = cid ;
        total_amount = 0 ;
        
        int result = customer::search_customer(cid) ;
        if(!result)
        {
            string n = assign_random_id() ;
            customer::add_customer(cid, n, 0) ;
        }
        transaction_id = assign_random_id() ;
    }
    string assign_random_id()
    {
        int cnt ;
        char c = 65 ;
        string n = "" ;
        t = (t+1)%LETTERS ;
        c = c + t - 1 ;
        if(c == 90)
        {
            diff++ ;
            c = 65 ;        
        }
        for(cnt = 0 ; cnt < RANDOM ; cnt++)
        {
            n = n + c ;
            c = c + diff ;
            diff = (2*(c) - 65)%LETTERS ;              
            if(c > 90)
            {
                c = 65 + t ;
                t++ ;
            }
        }
        return n ; 
    }
    void update_stock(long iid, int quantity_bought)
    {
        inventory::update_stock(iid, quantity_bought) ;
    }
    void buy_item(long iid, int q)
    {
        item i = get_product_info(iid) ;
        item1 cart ;
        if(i.quantity == 0)
        {
            cout << "Sorry,item is out of stock or does not exist" << endl ;
        }
        else
        {   cart.rate = i.rate; cart.id = iid; cart.name = i.name;
            if(i.quantity < q)
            {
                cart.quantity = i.quantity;
            }
            else
            {
                cart.quantity = q ;
            }
            cart.amount = (cart.rate) * (cart.quantity) ;
            bill_list.push_back(cart) ;
            update_stock(iid, cart.quantity) ;
        }
    }
    void display_bill()
    {
        list <item1> :: iterator i; 
        for (i = bill_list.begin(); i != bill_list.end(); i++) 
        { 
            cout << i->id << "\t" << i->name <<"\t" << i->rate << "\t" << i->quantity << "\t   " << i->amount << endl ;
            total_amount = total_amount + i->amount ;
        } 
    }
    void make_payment()
    {
        cout << "\n=========================== B  I  L  L ===========================" << endl ;
        cout << "Transaction id : " << transaction_id << endl << "Customer id : " << customer_id << endl ;
        cout << "Product Id\t" << "Name\t" << "Rate\t" << "Quantity   " << "Amount" << endl ;
        display_bill() ;
        cout << "\t\t\t\tTotal :    " << total_amount << endl ;
        update_points(customer_id, total_amount) ;
        total_amount = 0 ;
    }
    item get_product_info(long iid)
    {
        item i = inventory::get_product_info(iid) ;
        return i ;
    }
    void cancel_item(long iid, int qty)
    {
        list <item1> :: iterator i; 
        for (i = bill_list.begin(); i != bill_list.end(); i++) 
        { 
            if (i->id == iid)
            {
                if(i->quantity > qty){i->quantity = i->quantity - qty; i->amount = i->amount-(qty)*(i->rate);}
                else                 {i->quantity = 0; i->amount = 0;}
            }
        } 
        if(i->id != iid)
        {
            cout << "Item not in the cart." << endl ;
        }        
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    inventory menu ;            // - - - - INVENTORY OBJECT
    customer clients ;          // - - - - CUSTOMER OBJECT
    int i , no_of_items ;
    
    // cin >> no_of_items ;
    no_of_items = 3 ;
    
    int quantity[no_of_items] ;
    long id[no_of_items] , customer_id1 ;
    
    cin >> customer_id1 ;
    billing client1(customer_id1) ;         // - - - - BILLING OBJECT
    manager mba(201901173,"Devesh Modi") ;  // - - - - MANAGER OBJECT
    
    item item_for_info ;
    
    cout << "Printing product info :\n";
    for(i = 0 ; i < no_of_items ; i++ )
    {
        cin >> id[i] >> quantity[i] ;
        client1.buy_item(id[i], quantity[i]);
        item_for_info = mba.get_product_info(id[i]);    // - - - - PRODUCT INFO CALL BY MANAGER OBJECT
        cout<<item_for_info.id<<", "<<item_for_info.name<<", "<<item_for_info.rate<<", "<<item_for_info.quantity<<endl ;
    }
    
    cout << "\n";
    client1.make_payment() ;
    
    return 0;
}