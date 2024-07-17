#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



// number of shops
#define no_of_shops 9


// Number of vertices including house(0)
#define V 10



// structure for the users products
typedef struct {
    char pname[100];
} cust_prod;


// Structure for customer details
typedef struct {
    char cname[100];
    int phone;
    char address[100];

    int no_of_prod;
    cust_prod cprod[100];
} customer;



// Structure for the shops products 
typedef struct {
    char pname[100];
    int expdate;
} product;

// Structure for shop details
typedef struct {
    char sname[100];
    int code;
    int no_of_prod;


    product sprod[100];
} shop;


typedef struct
{
    char hname[100];
    float ratings;
} hospital;


// declaration of user
customer c1;

// ddeclaration of shops
shop s[10];              //(actually 4 shops but for 1 indexing mode shop size is 10)


hospital h[5];

int hospital_matrix[5][5];

 //////////////////     ******************************** ///////////////////////////
int hvidyanagar[5][5]={
        {0,    2200,    0, 2500, 2200},
        {2200,    0, 2300,    0,    0},
        {2300,    0,    0, 1300,    0},
        {2500,    0, 1300,    0, 950},
        {2200,    0,    0, 950,    0}
 };
      

int hdeshpandenagar[5][5]= {
        {   0, 2300,    0,    0, 3200},
        {2300,    0, 950,    0, 1300},
        {   0, 950,    0, 2200,    0},
        {   0,    0, 2200,    0, 2300},
        {3200, 1300,    0, 2300,    0}
 };
       
       

int hhosur[5][5]= {
        {   0, 1400, 1100,   0,    0},
        {1400,    0, 2100,   0, 2200},
        {1100, 1400,    0, 1300,   0},
        {   0,    0, 1300,    0, 2300},
        {   0, 2200,    0, 2300,    0}
 };







int vidyanagar[10][10]={
                        {0, 827, 0, 0, 0,0,0,0,0,1200},
                        {827,0, 4400, 0, 0,0,0,0,0,0},
                        {0, 4400, 0, 1300,0,0,0,0,0,0},
                        {0, 0, 1300, 0, 3300,0,0,0,0,0},
                        {0, 0, 0, 3300, 0,350,0,600,1500,0},
                        {0,0,0,0,350,0,700,0,0,0},
                        {0,0,0,0,0,700,0,0,1800,0},
                        {0,0,0,0,600,0,0,0,0,2500},
                        {0,0,0,0,1500,0,1800,0,0,2900},
                        {1200,0,0,0,0,0,0,2500,2900,0}
                        };

int deshpandenagar[10][10]={
                        {0,1700,0,0,0,0,0,0,800,1000.0},
                        {1700,0,2000,0,0,0,0,0,0,0}, 
                        {0,2000,0,4400,0,0,0,0,0,0}, 
                        {0,0,4400,0,1300,0,0,0,0,0}, 
                        {0,0,0,1300,0,3300,0,0,0,0}, 
                        {0,0,0,0,3300,0,350,0,1500,600}, 
                        {0,0,0,0,0,350,0,700,0,0}, 
                        {0,0,0,0,0,0,700,0,1800,0}, 
                        {0,0,0,0,0,1500,0,1800,0,0}, 
                        {0,0,0,0,0,600,0,0,0,0}  
                                };


int hosur[10][10]={{0,2800,0,1600,1400,0,0,0,0,2400},
                   {2800,0,4400,0,0,0,0,0,0,0}, 
                   {0,4400,0,1300,0,0,0,0,0,0}, 
                   {0,0,1300,0,3300,0,0,0,0,0}, 
                   {1400,0,0,3300,0,350,0,600,1500,0}, 
                   {0,0,0,0,350,0,700,0,0,0}, 
                   {0,0,0,0,0,700,0,0,1800,0}, 
                   {0,0,0,0,600,0,0,0,0,2500}, 
                   {0,0,0,0,1500,0,1800,0,0,0}, 
                   {0,0,0,0,0,0,0,2500,2300,0}             };



/// general matrix


void generate_adj_matix(int adj_matrix[][10])
{
    
    if(strcmp(c1.address,"BVB")==0||strcmp(c1.address,"bvb")==0 || strcmp(c1.address,"Vidya nagar")==0||strcmp(c1.address,"vidya nagar")==0||strcmp(c1.address,"vidyanagar")==0||strcmp(c1.address,"VIDYANAGAR")==0)
    {
        
      for(int i=0;i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
            adj_matrix[i][j]=vidyanagar[i][j];
            
        }
      }
    }
    else if(strcmp(c1.address,"Hosur")==0 || strcmp(c1.address,"hosur")==0||strcmp(c1.address,"HOSUR")==0)
    {
      for(int i=0;i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
            adj_matrix[i][j]=hosur[i][j];
          
        }
      }
    }
    else if(strcmp(c1.address,"Deshpandenagar")==0 || strcmp(c1.address,"Deshpande nagar")==0||strcmp(c1.address,"deshpande nagar")==0||strcmp(c1.address,"deshpandenagar")==0||strcmp(c1.address,"DESHPANDENAGAR")==0)
    {
      for(int i=0;i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
            adj_matrix[i][j]=deshpandenagar[i][j];
          
        }
      }
    }
    else
    {
        for(int i=0;i<10;i++)
      {
        for(int j=0;j<10;j++)
        {
            adj_matrix[i][j]=vidyanagar[i][j];
            
        }
      }
    }

}
void hgenerate_adj_matix(int hospital_matrix[5][5])
{
   
    if(strcmp(c1.address,"BVB")==0||strcmp(c1.address,"bvb")==0 || strcmp(c1.address,"Vidya nagar")==0||strcmp(c1.address,"vidya nagar")==0||strcmp(c1.address,"vidyanagar")==0||strcmp(c1.address,"VIDYANAGAR")==0)
    {
        
      for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
            hospital_matrix[i][j]=hvidyanagar[i][j];
            
        }
      }
    }
    else if(strcmp(c1.address,"Hosur")==0 || strcmp(c1.address,"hosur")==0||strcmp(c1.address,"HOSUR")==0)
    {
      for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
            hospital_matrix[i][j]=hhosur[i][j];
          
        }
      }
    }
    else if(strcmp(c1.address,"Deshpandenagar")==0 || strcmp(c1.address,"Deshpande nagar")==0||strcmp(c1.address,"deshpande nagar")==0||strcmp(c1.address,"deshpandenagar")==0||strcmp(c1.address,"DESHPANDENAGAR")==0)
    {
      for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
            hospital_matrix[i][j]=hdeshpandenagar[i][j];
          
        }
      }
    }
    else
    {
        for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
            hospital_matrix[i][j]=hvidyanagar[i][j];
            
        }
      }
    }

}


/// STL


/// STL of   m[string] -> 1,4,7


// typedef struct 
// {
//     char name[100];
    
//     int arr[100];
//     int size; 
// }map;




int search_product_in_one_particular_shop(customer c1, shop s[10],int key,int adj_matrix[][10]);
void display_map(int adj_matrix[10][10],int key);

void dijkstra(int create_adj_matrix[10][10],int src,int dest,int key);

int dijkstra_2(int adj_matrix[10][10], int source, int destination,int key);
void combination_of_shops(customer c1, shop s[10], int adj_matrix[10][10],int key);




// Display the connected graph of house and shops
void display_map(int adj_matrix[10][10],int key) {
 
 
  printf("Connected graph of house and shops \n\n");

    // Print column headers
    printf("      ");
    for (int i = 0; i < 10; i++) {
        printf("%-8d|", i);
    }
    printf("\n");

    // Print horizontal line
    printf("      ");
    for (int i = 0; i < 10; i++) {
        printf("--------|");
    }
    printf("\n");

    // Print matrix content with row numbers
    for (int i = 0; i < 10; i++) {
        printf("%-4d |", i);
        for (int j = 0; j < 10; j++) {
            printf("%-8d|", adj_matrix[i][j]);
        }
        printf("\n");

        // Print horizontal line between rows
        printf("      ");
        for (int k = 0; k < 10; k++) {
            printf("--------|");
        }
        printf("\n");
    }
}
void hdisplay_map(int hospital_matrix[][5],int key) {
 
 
  printf("Connected graph of house and Hospitals \n\n");

    // Print column headers
    printf("      ");
    for (int i = 0; i < 5; i++) {
        printf("%-8d|", i);
    }
    printf("\n");

    // Print horizontal line
    printf("      ");
    for (int i = 0; i < 5; i++) {
        printf("--------|");
    }
    printf("\n");

    // Print matrix content with row numbers
    for (int i = 0; i < 5; i++) {
        printf("%-4d |", i);
        for (int j = 0; j < 5; j++) {
            printf("%-8d|", hospital_matrix[i][j]);
        }
        printf("\n");

        // Print horizontal line between rows
        printf("      ");
        for (int k = 0; k < 5; k++) {
            printf("--------|");
        }
        printf("\n");
    }
}
typedef struct
{
     int dist;
     int index;
}pair1;



// Search all products in one particular shop 
int search_product_in_one_particular_shop(customer c1, shop s[10],int key,int adj_matrix[][10]) {

    pair1 v[no_of_shops];
    int v_index=0;

    int avail_shops_index[no_of_shops];
    int p=0;
    for (int j = 1; j <= no_of_shops; j++) {
        int count = 0;
        for (int i = 0; i < c1.no_of_prod; i++) {
            for (int k = 0; k < s[j].no_of_prod; k++) {
                if (strcmp(c1.cprod[i].pname, s[j].sprod[k].pname) == 0) {
                    count++;
                    break;
                }
            }
        }

        if (count == c1.no_of_prod) {
            avail_shops_index[p]=j;
            p++;
        }
    }

    if(p!=0)
   { 
    for(int i=0;i<p;i++)
    {
         v[v_index].dist=dijkstra_2(adj_matrix,0,avail_shops_index[i],key);
         v[v_index].index=avail_shops_index[i];
         v_index++;
    }

     printf("--------------------  ALL PRODUCTS ARE FOUND IN EITHER  ONE PARTICULAR SHOP  OR COMBINATION OF SHOPS  --------------------\n");
     printf("\n");

    printf("Option 1:\n");
    
   printf("All products found in shops : ");
    for(int i=0;i<v_index;i++)
    {
        if(i==v_index-1)
        {
              printf("%s.\n",s[v[i].index].sname);
        }
        else
         printf("%s,",s[v[i].index].sname);
    }
    
  


    // finding min distance

    int min=v[0].dist;
     int q=0;
    for(int i=0;i<v_index;i++)
    {
         if(v[i].dist<min)
         {
            min=v[i].dist;
            q=i;
         }
    }
    printf("But nearest among above is to visit : %s\n", s[v[q].index].sname);
    if(key==0)
    {
         printf("The Delivery Boy has to cover a distance of %0.2f Km\n",(dijkstra_2(adj_matrix,0,v[q].index,key))/1000.0);
    }
    else if(key==1)
    {
      printf("You have to cover a distance of %0.2f Km\n",(dijkstra_2(adj_matrix,0,v[q].index,key))/1000.0);
    }
    printf("\n");
   return v[q].index;

   }

    return -1;
}







/////////////    Dijkstra's Algorithm to find shortest path using Queue  ///////////////////////


typedef struct {
    int first;
    int second;
} pair;

struct Queue {
    pair* arr;
    int size;
    int f;
    int b;
};

// Function to create a new queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (pair*)malloc(size * sizeof(pair));
    q->size = size;
    q->f = -1;
    q->b = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->f == -1 && q->b == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->b == q->size - 1);
}

// Function to push an element into the queue
void push(struct Queue* q, int d, int v) {
    if (isFull(q)) {
        printf("Queue is Full\n");
    } else {
        if (isEmpty(q)) {
            q->f = 0;
        }
        q->b++;
        q->arr[q->b].first = d;
        q->arr[q->b].second = v;
    }
}

// Function to pop an element from the queue
void pop(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        if (q->f == q->b) {
            q->f = -1;
            q->b = -1;
        } else {
            q->f++;
        }
    }
}

// Function to get the front element of the queue
pair front(struct Queue* q) {
    return q->arr[q->f];
}


// Dijkstra 1 to implement shortest path between house and one particular shop

void dijkstra(int adj_matrix[10][10],int src,int dest,int key) {
    struct Queue* q = createQueue(100);

    push(q, 0, src);

    int dist[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    while (!isEmpty(q)) {
        pair temp = front(q);
        pop(q);

        for (int j = 0; j < V; j++) {
            if (adj_matrix[temp.second][j] != 0) {
                int d = temp.first + adj_matrix[temp.second][j];

                if (d < dist[j]) {
                    dist[j] = d;

                    push(q, d, j);
                }
            }
        }
    }

       printf("The shortest path between %d (source)  and %d (destination) is : %0.2f Km\n",src,dest,(dist[dest])/1000.0);
    

    // Don't forget to free the memory used by the queue
    free(q->arr);
    free(q);
}


//////////////////////////////////////////////////////////
void left_out_products(int key);

void left_out_products(int key)
{
      product all_shops_products[100];
  

      int p=0;
      for(int i=1;i<=no_of_shops;i++)
      {
         for(int j=0;j<s[i].no_of_prod;j++)
         {
              strcpy(all_shops_products[p].pname, (s[i].sprod[j].pname) );
              p++;
         }
      }

  
     if(key==3)
     {printf("All the products availabe in this town are\n");
      printf("------------------------------------------\n         -> ");
     
     for(int i=0;i<p;i++)
     {
         printf("%s\n         -> ",all_shops_products[i].pname);

         if(i==p-1)
         {
             printf("%s\n",all_shops_products[i].pname);

         }
     }
    printf("----------------------------------------------------------------------------------------------------------------\n");
     }
     else

    { int found=0;

     product not_available_products[c1.no_of_prod];

     int not_avail_index=0;

     for(int i=0;i<c1.no_of_prod;i++)
     {
        found=0;

        for(int j=0;j<p;j++)
        {
             if(strcmp(c1.cprod[i].pname,all_shops_products[j].pname)==0)
             {
                 found=1;
                 break;
             }
        }
        if(found==0)
        {
            strcpy(not_available_products[not_avail_index].pname, c1.cprod[i].pname);

            not_avail_index ++;
        }
     }

     if(not_avail_index!=0)
  {     printf("\nProducts which are not found in this town are\n");
     for(int i=0;i<not_avail_index;i++)
     {
          printf("-> %s\n",not_available_products[i].pname);
     }
  }
    }
}


//////////      Findining shortest distance covering the combination of shops  /////////////////////
      typedef struct {
    int first;
    int second;
} pairx;
void sort(pairx distance_between_shops[],int p);
int remove_duplicates(int found_shops[],int foundCount);
void combination_of_shops(customer c1, shop s[10], int adj_matrix[10][10],int key) {
   

   typedef struct 
{
    char name[100];
    
    int arr[100];
    int size; 
}map;
    int found = 0;
   


    map m[100];
    int mapindex=0;

    int arr_index=0;

  for (int i = 0; i < c1.no_of_prod; i++)
{

        strcpy(m[mapindex].name,c1.cprod[i].pname);
    for (int j = 1; j <= no_of_shops; j++)
     {
        found = 0;
        
            for (int k = 0; k < s[j].no_of_prod; k++) {
                if (strcmp(c1.cprod[i].pname, s[j].sprod[k].pname) == 0) {
                    found = 1;
                    break;
                }
            }

            if(found==1)
            {
                 m[mapindex].arr[arr_index]=j;
                 arr_index++;
                 
            }
           
    }
    
 
           m[mapindex].size=arr_index-1;
            mapindex++;

            
            arr_index=0;
            
    }
   printf("----------------------------------------\n");
   printf("Product              |  Available Shops\n");
   printf("----------------------------------------\n");

    for (int i = 0; i < mapindex; i++) {
        printf("%-20s |", m[i].name);
        for (int j = 0; j <= m[i].size; j++) {
            printf(" %s ",s[m[i].arr[j]].sname);
        }
        printf("\n");
    }
  printf("\n");

  int distance[100];
      int distance_index=0;


       int found_shops[no_of_shops];



        int foundCount = 0;




       ///////////

     for(int i=0;i<mapindex;i++)
     {

        distance_index=0;
         for(int j=0;j<=m[i].size;j++)
         {
                 distance[distance_index]=dijkstra_2(adj_matrix,0,m[i].arr[j],key);
                 distance_index++;              
         }


         int min=distance[0];
         int min_distance_index=0;


         for(int k=0;k<distance_index;k++)
         {
              if(distance[k]<min)
              {
                 min=distance[k];
                 min_distance_index=k;
              }
         }
    
        
         for(int g=0;g<distance_index;g++)
         {
              if(min_distance_index == g  )
              {
                  found_shops[foundCount]=m[i].arr[g];
                  
                  foundCount++;
              }
         }
        
     }

     foundCount=remove_duplicates(found_shops,foundCount);

    


     int visited[foundCount];

     for(int i=0;i<foundCount;i++)
     { 
        visited[i]=0;
     }
     


     pairx distance_between_shops[100];


     int source=0;

     int Distance=0;

     int p=0;

 
 printf("Path for the combination of shops from House :\n");
 
  
   for(int k=1;k<=foundCount;k++)
{
     p=0;
     for(int i=0;i<foundCount;i++)
     {
        if(visited[found_shops[i]]!=1)
         { 
            distance_between_shops[p].first=dijkstra_2(adj_matrix,source,found_shops[i],key);

            distance_between_shops[p].second=found_shops[i];
            p++;
         }
     }

     sort(distance_between_shops,p); 

     

     printf("%d to  %s  is %d m\n",source,s [(distance_between_shops[0].second)].sname ,distance_between_shops[0].first);
 
     Distance=Distance + distance_between_shops[0].first;
     visited[distance_between_shops[0].second]=1;

     source=distance_between_shops[0].second;


     for(int i=0;i<20;i++)
     {
         
     }
}


printf("Shortest Distance to cover these shops is %0.2f Km\n",(float)(Distance/1000.0));
if(key==1)
{
    printf("\n");
   
    printf("\033[1;34m*********************************************************\033[0m\n");
   
    printf("\033[1;34m \033[1;36m\033[1;34mThe Shortest Distance   \033[0m\n");
   
    printf("\033[1;34m                                                       \033[0m\n");
   
    printf("\033[1;34m  \033[1;36m\033[1;34mto cover these shops is %0.2f Km  \033[0m    \n",Distance/1000.0);
   
    printf("\033[1;34m                                                       \033[0m\n");
    
    printf("\033[1;34m*********************************************************\033[0m\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

}
    

else if(key==0)
{
//printf("So delivery boy has to cover a distance of %0.2f Km\n",(float)(Distance/1000.0));
printf("\n");
          
    printf("\033[1;34m*********************************************************\033[0m\n");
      
    printf("\033[1;34m \033[1;36m\033[1;34mThe Delivery Boy has  to cover   \033[0m\n");
     
    printf("\033[1;34m                                                       \033[0m\n");
    
    printf("\033[1;34m  \033[1;36m\033[1;34m a distance of %0.2f Km  \033[0m    \n",Distance/1000.0);
      
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m*********************************************************\033[0m\n\n");
     printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

}
//  map * mptr;
//   mptr = &m;
//  for (int i = 0; i < sizeof(mptr->name); i++) {
//         mptr->name[i] = '\0';
//     }

//     // Set each element in the arr array to zero
//     for (int i = 0; i < sizeof(mptr->arr) / sizeof(mptr->arr[0]); i++) {
//         mptr->arr[i] = 0;
//     }

//     // Set the size to zero
//     mptr->size = 0;


     pairx *ptr= distance_between_shops;

 for (size_t i = 0; i < 100; i++) {
         memset(&ptr[i], 0, sizeof(pairx));
     }
}


int dijkstra_2(int adj_matrix[10][10],int src,int dest,int key) {
    struct Queue* q = createQueue(100);

    push(q, 0, src);

    int dist[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    while (!isEmpty(q)) {
        pair temp = front(q);
        pop(q);

        for (int j = 0; j < V; j++) {
            if (adj_matrix[temp.second][j] != 0) {
                int d = temp.first + adj_matrix[temp.second][j];

                if (d < dist[j]) {
                    dist[j] = d;

                    push(q, d, j);
                }
            }
        }
    }

      
    

    // Don't forget to free the memory used by the queue
    free(q->arr);
    free(q);

     return dist[dest];
}

void sort(pairx distance_between_shops[],int p)
{
     int z1;
     int z2;
      for(int i=0;i<p;i++)
      {
          for(int j=0;j<p;j++)
          {
             if(distance_between_shops[i].first <distance_between_shops[j].first)
             {
                z1=distance_between_shops[i].first;
                  distance_between_shops[i].first=distance_between_shops[j].first;
                  distance_between_shops[j].first=z1;

                    z2=distance_between_shops[i].second;
                  distance_between_shops[i].second=distance_between_shops[j].second;
                  distance_between_shops[j].second=z2;

             }
          }
      }
}


int remove_duplicates(int found_shops[],int foundCount)
{
      int z;
    for(int i=0;i<foundCount;i++)
    {
         for(int j=0;j<foundCount;j++)
         {
             if(found_shops[i]== found_shops[j] && i!=j)
             {
                   for(int k=j;k<foundCount-1;k++)
                   {
                       found_shops[k]=found_shops[k+1];
                   }
                   foundCount--;
                   j--;
             }
         }
    }

    return foundCount;

}

/// to check apart from one particular shop

int combination_apart_from_part_shop(int shop_index,int key,int adj_matrix[][10])
{
    int found=0;

    int found_shops[100];
    int foundCount=0;
      for(int i=0;i<c1.no_of_prod;i++)
      {
         for(int j=1;j<=no_of_shops;j++)
         {
            found=0;
             for(int k=0;k<s[j].no_of_prod;k++)
             {
                  if(strcmp(c1.cprod[i].pname,s[j].sprod[k].pname)==0)
                  {
                     found=1;
                     break;
                  }
             }
             if(found==1)
             {found_shops[foundCount]=j;
             foundCount++;
             }
         }
      }

      foundCount=remove_duplicates(found_shops,foundCount);
      ///////////////////

      for(int i=0;i<foundCount;i++)
      {
          if(found_shops[i]==shop_index)
          {
              for(int j=i;j<foundCount-1;j++)
              {
                 found_shops[j]=found_shops[j+1];
              }
              foundCount--;
              i--;
          }
      }

   if(foundCount>1)
 {int visited[foundCount];

     for(int i=0;i<foundCount;i++)
     { 
        visited[i]=0;
     }

     pairx distance_between_shops[100];


     int source=0;

     int Distance=0;

     int p=0;
 printf("\nOption 2 :\n");
 if(key==1)
 {printf("Path for the combination of shops from House :\n");
  


   for(int k=1;k<=foundCount;k++)
{
     p=0;



     for(int i=0;i<foundCount;i++)
     {
        if(visited[found_shops[i]]!=1)
         { 
            distance_between_shops[p].first=dijkstra_2(adj_matrix,source,found_shops[i],key);

            distance_between_shops[p].second=found_shops[i];
            p++;
         }
     }

     sort(distance_between_shops,p); 
     
     printf("%d to  %s  is %d m\n",source,s [(distance_between_shops[0].second)].sname ,distance_between_shops[0].first);
 
     Distance=Distance + distance_between_shops[0].first;
     visited[distance_between_shops[0].second]=1;

     source=distance_between_shops[0].second;


     
}
printf("You have to cover a distance of %0.2f Km\n",Distance/1000.0);
 }
 else if(key==0)
{printf("Path for the combination of shops to House :\n");

   for(int k=1;k<=foundCount;k++)
{
     p=0;



     for(int i=0;i<foundCount;i++)
     {
        if(visited[found_shops[i]]!=1)
         { 
            distance_between_shops[p].first=dijkstra_2(adj_matrix,source,found_shops[i],key);

            distance_between_shops[p].second=found_shops[i];
            p++;
         }
     }

     sort(distance_between_shops,p); 
     
     printf("%d to  %s  is %d m\n",source,s [(distance_between_shops[0].second)].sname ,distance_between_shops[0].first);
 
     Distance=Distance + distance_between_shops[0].first;
     visited[distance_between_shops[0].second]=1;

     source=distance_between_shops[0].second;

    
}
 printf("So the Delivery Boy has to cover a distance of %0.2f Km\n",Distance/1000.0);
}
 pairx *ptr= distance_between_shops;

 for (size_t i = 0; i < 100; i++) {
         memset(&ptr[i], 0, sizeof(pairx));
     }

  return Distance;

 }

 else
   {
     
      return INT_MAX;
   }


}

int dijkstra_hospital(int hospital_matrix[][5],int src,int key) {
    struct Queue* q = createQueue(100);

    push(q, 0, src);

    int dist[V];

    for (int i = 0; i < 5; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    while (!isEmpty(q)) {
        pair temp = front(q);
        pop(q);

        for (int j = 0; j < 5; j++) {
            if (hospital_matrix[temp.second][j] != 0) {
                int d = temp.first + hospital_matrix[temp.second][j];

                if (d < dist[j]) {
                    dist[j] = d;

                    push(q, d, j);
                }
            }
        }
    }
    int min=dist[1];
    int p=1;

    for(int i=1;i<5;i++)
    {
        
        if(dist[i] < min)
        {
            min=dist[i];
             p=i;
        }    
    }
    


   //printf("The Nearest Hospital from your location is %s at a distance of %0.2f Km\n",h[p].hname,min/1000.0);
   
      printf("\n");
    printf("\033[1;34m*********************************************************\033[0m\n");
    printf("\033[1;34m  \033[1;36mThe Nearest Hospital from your location is %s\033[1;34m   \n",h[p].hname);
    printf("\033[1;34m                                                       \033[0m\n");
    printf("\033[1;34m  \033[1;36mAt a distance of %0.2f Km\033[1;34m                             \033[0m\n",min/1000.0);
    printf("\033[1;34m                                                       \033[0m\n");
    printf("\033[1;34m*********************************************************\033[0m\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");


}



void print_shops()
{
      printf("Available shops\n");

   // Print the details of the shops
    for (int i = 1; i <= no_of_shops; i++) {
        printf("Name : %s\tCode : %d\t\tAvailable products: ", s[i].sname, s[i].code);
        for (int j = 0; j < s[i].no_of_prod; j++) {
            printf("%s  ", s[i].sprod[j].pname);
        }
        printf("\n");
    }

    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");

}

void order_products(int key,int adj_matrix[][10])
{
    print_shops();
     printf("                                     Number of products requiered: ");
    scanf("%d", &c1.no_of_prod);
    getchar();  // consume the newline character left in the buffer
    printf("\n");
    printf("Enter the products name required\n");
    for (int i = 0; i < c1.no_of_prod; i++) {
        fgets(c1.cprod[i].pname, sizeof(c1.cprod[i].pname), stdin);
        c1.cprod[i].pname[strcspn(c1.cprod[i].pname, "\n")] = '\0';  // remove the newline character
    }
    
    // print customer required products
    printf("\n      Customers Required Products    \n");
    printf("---------------------------------------\n");
    for (int i = 0; i < c1.no_of_prod; i++)
     {
   
    
    printf("  -> %s\n", c1.cprod[i].pname);
     }
    printf("---------------------------------------\n");
 

    printf("\n");
    display_map(adj_matrix,key);
    printf("\n");
    int shop_index;
    //  Returns the shop's index if all products are available in that particular shop

    shop_index = search_product_in_one_particular_shop(c1, s,key,adj_matrix);
    

    if (shop_index != -1) {
     
      int one_dist=dijkstra_2(adj_matrix, 0,shop_index,key);

 
     
       int comb_dist=combination_apart_from_part_shop(shop_index,key,adj_matrix);
     
      printf("\n");

      printf("-----------------------------------------------------\n");
      printf("\n");
       if(one_dist < comb_dist)
       {
           printf("Option 1 gives the shortest distance\n");
          
            printf("The shorest distance from %s to House is : %0.2f Km\n",s[shop_index].sname,one_dist/1000.0);
           
           // printf("| The delivery Boy has  to cover a distance of  %0.2f Km |\n",one_dist/1000.0);
            printf("\n");
              
    printf("\033[1;34m*********************************************************\033[0m\n");
       
    printf("\033[1;34m \033[1;36m\033[1;34mThe Delivery Boy has  to cover   \033[0m\n");
      
    printf("\033[1;34m                                                       \033[0m\n");
      
    printf("\033[1;34m  \033[1;36m\033[1;34m a distance of %0.2f Km  \033[0m    \n",one_dist/1000.0);
       
    printf("\033[1;34m                                                       \033[0m\n");
      
    printf("\033[1;34m*********************************************************\033[0m\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
           
       }
       else
       {
        printf("Option 2 gives the shortest distance\n");
           
            //printf("| The delivery Boy has  to cover a distance of  %0.2f Km |\n",comb_dist/1000.0);
           printf("\n");
          
    printf("\033[1;34m*********************************************************\033[0m\n");
     
    printf("\033[1;34m \033[1;36m\033[1;34mThe Delivery Boy has  to cover   \033[0m\n");
       
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m  \033[1;36m\033[1;34m a distance of %0.2f Km  \033[0m    \n",comb_dist/1000.0);
    
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m*********************************************************\033[0m\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");

       }
       


    } else {

        printf("Not found in one particular shop\n");

        left_out_products(key);
        printf("\n");

        combination_of_shops(c1, s, adj_matrix,key);   
    }

}

void Check_available_shops(int key,int adj_matrix[][10])
{
    print_shops();
    printf("Number of products requiered\n");
    scanf("%d", &c1.no_of_prod);
    getchar();  // consume the newline character left in the buffer
    printf("Enter the products name required\n");
    for (int i = 0; i < c1.no_of_prod; i++) {
        fgets(c1.cprod[i].pname, sizeof(c1.cprod[i].pname), stdin);
        c1.cprod[i].pname[strcspn(c1.cprod[i].pname, "\n")] = '\0';  // remove the newline character
    }
    
    // print customer required products
    printf("\n      Customers Required Products    \n");
    printf("---------------------------------------\n");
    for (int i = 0; i < c1.no_of_prod; i++)
     {
   
    
    printf("  -> %s\n", c1.cprod[i].pname);
     }
    printf("---------------------------------------\n");
 

    printf("\n");
    display_map(adj_matrix,key);
    printf("\n");
    int shop_index;
    //  Returns the shop's index if all products are available in that particular shop

    shop_index = search_product_in_one_particular_shop(c1, s,key,adj_matrix);
    

    if (shop_index != -1) {
     
      int one_dist=dijkstra_2(adj_matrix, 0,shop_index,key);

 
     
       int comb_dist=combination_apart_from_part_shop(shop_index,key,adj_matrix);
     
      printf("\n");

      printf("-----------------------------------------------------\n");
         printf("\n");
       if(one_dist < comb_dist)
       {
           printf("Option 1 gives the shortest distance\n");
          
            printf("The shorest distance to reach %s is : %0.2f Km\n",s[shop_index].sname,one_dist/1000.0);

              printf("\n");
          
    printf("\033[1;34m*********************************************************\033[0m\n");
     
    printf("\033[1;34m \033[1;36m\033[1;34mThe Shortest Distance to   \033[0m\n");
       
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m  \033[1;36m\033[1;34mreach %s    is   %0.2f Km  \033[0m    \n",s[shop_index].sname,one_dist/1000.0);
    
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m*********************************************************\033[0m\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    

       }
       else
       {
        printf("Option 2 gives the shortest distance\n");
        printf("Shortest Distance to cover these shops is %0.2f Km \n",comb_dist/1000.0);

         printf("\n");
          
    printf("\033[1;34m*********************************************************\033[0m\n");
     
    printf("\033[1;34m \033[1;36m\033[1;34mThe Shortest Distance to   \033[0m\n");
       
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m  \033[1;36m\033[1;34mto cover these shops is   %0.2f Km  \033[0m    \n",one_dist/1000.0);
    
    printf("\033[1;34m                                                       \033[0m\n");
       
    printf("\033[1;34m*********************************************************\033[0m\n\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
        

       }
       


    } else {

        printf("Not found in one particular shop\n");

        left_out_products(key);
        printf("\n");

        combination_of_shops(c1, s, adj_matrix,key);   
    }

      
}

void print_house_to_shop()
{

    printf("  _________\n");
    printf(" /  HOUSE  \\\n");
    printf("/-----------\\                             ___+___\n");
    printf("|    ___    |                            /_______\\\n");
    printf("|   |   |   | -------------------------> |  SHOP |\n");
    printf("|___|___|___|                            |_______|\n");
    printf("\n");
    printf("\n");

}

void print_shop_to_house()
{

    printf("  _________                                       \n");
    printf(" /  HOUSE  \\                                     \n");
    printf("/-----------\\                             ___+___\n");
    printf("|    ___    |                            /_______\\\n");
    printf("|   |   |   | <------------------------- |  SHOP |\n");
    printf("|___|___|___|                            |_______|\n");
    printf("\n");
    printf("\n");

}

void print_house_to_hospital()
{
    printf("  _________\n");
    printf(" /  HOUSE  \\\n");
    printf("/-----------\\                             ____+_____\n");
    printf("|    ___    |                            /__________\\\n");
    printf("|   |   |   | -------------------------> | Hospital |\n");
    printf("|___|___|___|                            |__________|\n");
    printf("\n");
    printf("\n");
}

struct queue {
    int *arr;
    int size;
    int f;
    int b;
};

// Function to create a new queue
struct queue* createqueue(int size) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->size = size;
    q->f = -1;
    q->b = -1;
    return q;
}

// Function to check if the queue is empty
int qisEmpty(struct queue* q) {
    return (q->f == -1 && q->b == -1);
}

// Function to check if the queue is full
int qisFull(struct queue* q) {
    return (q->b == q->size - 1);
}

// Function to push an element into the queue
void qpush(struct queue* q, int d) {
    if (qisFull(q)) {
        printf("Queue is Full\n");
    } else {
        if (qisEmpty(q)) {
            q->f = 0;
        }
        q->b++;
        q->arr[q->b] = d;
    }
}

// Function to pop an element from the queue
void qpop(struct queue* q) {
    if (qisEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        if (q->f == q->b) {
            q->f = -1;
            q->b = -1;
        } else {
            q->f++;
        }
    }
}

// Function to get the front element of the queue
int qfront(struct queue* q) {
    return q->arr[q->f];
}

void bfs(int adj_matrix[][10], int n, int src) {
    struct queue* q = createqueue(100);

    int visited[n];
    qpush(q, src);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
     int count=0;
    visited[src] = 1;
 
    printf("BFS traversal of shops(Nodes) is \n");

    printf("House , ");
    while (qisEmpty(q) != 1) {
        int temp = qfront(q);
        count++;
        if(temp!=0 && count!=10)
        {printf("%s , ",s[temp].sname);}
        else if(count==10)
        {
          printf("%s .\n",s[temp].sname);
        }
        qpop(q);

        for (int i = 0; i < n; i++) {
            if (visited[i]!=1 && adj_matrix[temp][i] != 0) {
                qpush(q, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    printf("\n");

   //  Initialize all the shops available products
  
    strcpy(s[1].sname, "S1");
           s[1].code = 1;
           s[1].no_of_prod = 3;
    strcpy(s[1].sprod[0].pname, "zandubalm");
    strcpy(s[1].sprod[1].pname, "dolo");
    strcpy(s[1].sprod[2].pname, "tonic");


    strcpy(s[2].sname, "S2");
           s[2].code = 2;
           s[2].no_of_prod = 4;
    strcpy(s[2].sprod[0].pname, "saridon");
    strcpy(s[2].sprod[1].pname, "zandubalm");
    strcpy(s[2].sprod[2].pname, "spray");
    strcpy(s[2].sprod[3].pname, "bandage");

    strcpy(s[3].sname, "S3");
           s[3].code = 3;
           s[3].no_of_prod = 3;
    strcpy(s[3].sprod[0].pname, "inhealer");
    strcpy(s[3].sprod[1].pname, "dolo");
    strcpy(s[3].sprod[2].pname, "tonic");

    strcpy(s[4].sname, "S4");
           s[4].code = 4;
           s[4].no_of_prod = 3;
    strcpy(s[4].sprod[0].pname, "vicks");
    strcpy(s[4].sprod[1].pname, "boost");
   strcpy(s[4].sprod[2].pname, "bandage");

    strcpy(s[5].sname, "S5");
           s[5].code = 5;
           s[5].no_of_prod = 3;
    strcpy(s[5].sprod[0].pname, "spray");
    strcpy(s[5].sprod[1].pname, "horlicks");
    strcpy(s[5].sprod[2].pname, "bandage");

    strcpy(s[6].sname, "S6");
           s[6].code = 6;
           s[6].no_of_prod = 1;
    strcpy(s[6].sprod[0].pname, "thermometer");


    strcpy(s[7].sname, "S7");
           s[7].code = 7;
           s[7].no_of_prod = 4;
    strcpy(s[7].sprod[0].pname, "vicks");
    strcpy(s[7].sprod[1].pname, "horlicks");
    strcpy(s[7].sprod[2].pname, "bandage");
    strcpy(s[7].sprod[3].pname, "cotton");

    strcpy(s[8].sname, "S8");
           s[8].code = 8;
           s[8].no_of_prod = 3;
    strcpy(s[8].sprod[0].pname, "tonic");
    strcpy(s[8].sprod[1].pname, "thermometer");
    strcpy(s[8].sprod[2].pname, "cotton");

    strcpy(s[9].sname, "S9");
           s[9].code = 9;
           s[9].no_of_prod = 3;
    strcpy(s[9].sprod[0].pname, "bornvita");
    strcpy(s[9].sprod[1].pname, "horlicks");
    strcpy(s[9].sprod[2].pname, "complant");
   


   
     //  Initialize all the shops available products
  
    strcpy(h[1].hname, "H1");
    strcpy(h[2].hname, "H2");
    strcpy(h[3].hname, "H3");
    strcpy(h[4].hname, "H4");





    //// write a function such a way that once the expiry date is reached then delete that particular product///////////////////
    
    /////////////////      ??????????????????????????????? ////////////////////////////


     int adj_matrix[10][10];
  ///   Take the input of customer details
  
    printf("--------------------------------------    ENTER THE CUSTOMER DETAILS    --------------------------------------\n");
    printf("\n");
    printf("                                      NAME  : ");
    fgets(c1.cname, sizeof(c1.cname), stdin);
    c1.cname[strcspn(c1.cname, "\n")] = '\0';  // remove the newline character
    printf("\n");
    printf("                                      PHONE : ");
    scanf("%d", &c1.phone);
    getchar();
    printf("\n");
    printf("                                      ADDRESS : ");
    gets(c1.address);
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    
     generate_adj_matix(adj_matrix);


       
     
       
     // above will be useful to check nearby hospitals



    /////////////// order or check available shops//////////////////
  
 
     

   // Display the connected graph
 


   //////////////////// 



     int choice; // Variable to select a funtion from a list.
    int loopkey = 1; //Variable to exit the loop
    

    while(loopkey)
    {
        printf("                                      FUNCTIONS : \n");

        printf("                                      1 -- Order the products\n");
        printf("                                      2 -- Look for the available nearby shops\n");
        printf("                                      3 -- Look for nearby hospitals \n");
        printf("                                      4 -- List all the products available in this town\n");
        printf("                                      5 -- BFS traversal of shops(Nodes)\n");
        printf("                                      6 -- Log Out\n");
        printf("                                      7 -- Exit Program\n");
        printf("\n");
        
        printf("                                      Enter your choice : ");
        scanf("%d", &choice);
        getchar();
        printf("\n");

        switch(choice)
        {
            case 1:   print_shop_to_house(); 
                      order_products(0,adj_matrix);
                       break;

            case 2:  
            print_house_to_shop();    
                   Check_available_shops(1,adj_matrix);   
                        break;

            case 3:print_house_to_hospital();   
                    hgenerate_adj_matix(hospital_matrix);
                   hdisplay_map(hospital_matrix,2); 
                   dijkstra_hospital(hospital_matrix,0,2);
                    
                    break;
            case 4: left_out_products(3);
                        
                    break;
            case 5:  printf("Breadth-First Search (BFS) Traversal starting from Vidyanagar:\n");
printf("--------------------------------------------------------------\n");
bfs(vidyanagar, V, 0);

printf("Breadth-First Search (BFS) Traversal starting from Deshpandenagar:\n");
printf("--------------------------------------------------------------------\n");
bfs(deshpandenagar, V, 0);

printf("Breadth-First Search (BFS) Traversal starting from Hosur:\n");
printf("---------------------------------------------------------\n");
bfs(hosur, V, 0);
                       break;
                        
            case 6:       
    printf("--------------------------------------    ENTER THE CUSTOMER DETAILS    --------------------------------------\n");
    printf("\n");
    printf("                                      NAME  : ");
    fgets(c1.cname, sizeof(c1.cname), stdin);
    c1.cname[strcspn(c1.cname, "\n")] = '\0';  // remove the newline character
    printf("\n");
    printf("                                      PHONE : ");
    scanf("%d", &c1.phone);
    getchar();
    printf("\n");
    printf("                                      ADDRESS : ");
    gets(c1.address);
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    
     generate_adj_matix(adj_matrix);
                       
                           break;                                     
            case 7: printf("************************************************   PROGRAM ENDED   ********************************************\n");
                    printf("\n");
                    printf("\n");
                    loopkey=0; 
                    break;
            default:printf("INVALID CHOICE\n");
        } 
    }  

    
    return 0;
}
