/*
Name: Mujeeb ur rahman khan
Roll No:27035
Class : SE IT B
DSA Assignment 7 */
#include<iostream>
using namespace std;

const int V=8;

int MinimumKey(int key[], bool visited[])  
{ 
    int min = 999, min_index;  // Infinite value

    for (int v = 0; v < V; v++) { 
        if (visited[v] == false && key[v] < min) { 
        
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  


int printMST(int parent[], int cost[V][V])  
{  
    string dept [8] = {"CS","IT","ENTC","Elec.","Mech.","AIDS","AIML","Civil"};
    int minCost=0;
	cout<<"Department\t----->   Distance\n"; 
	cout<<"====================================="<<endl;
    for (int i = 1; i< V; i++) 
    {
		cout<<"A--B : "<<dept[parent[i]]<<" --> "<<dept[i]<<" \t Dist ="<<cost[i][parent[i]]<<" m"<<" \n";  
		minCost+=cost[i][parent[i]];
    }
    cout<<"====================================="<<endl;
	cout<<"Distance of Mininimum Spanning Tree is : "<<minCost<<" m";
	
	return minCost;
}  


void findMST(int cost[V][V])  
{  
    int parent[V], key[V];
    bool visited[V];

    for (int i = 0; i< V; i++) 
    { 
        key[i] = 999;   
        visited[i] = false;
        parent[i]=-1;
    }    

    key[0] = 0;  
    parent[0] = -1; 

    for (int x = 0; x < V - 1; x++) 
    {  
       
        int u = MinimumKey(key, visited);  

        visited[u] = true;  

        
        for (int v = 0; v < V; v++)  
        {
             
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {  
                parent[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    }

    
	printMST(parent, cost);  
}  


int main()  
{  
    cout<<"\n*************************************"<<endl;
	cout<<"\tPrim's Algorithm";
	cout<<"\n*************************************"<<endl;
    
    int graph[V][V] = { {0,90,60,0,0,0,0,50},
                        {90,0,60,300,90,0,40,0},
	                    {60,60,0,100,80,0,40,40},
	                    {0,300,100,0,200,300,0,0},
	                    {0,90,80,200,0,70,38,81},
	                    {0,0,0,300,70,0,0,90}, 
                        {0,45,86,101,0,0,0,0},
                        {40,60,30,0,0,51,0,0} };
	findMST(graph);  

    return 0;  
}  
