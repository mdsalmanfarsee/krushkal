#include<bits/stdc++.h>
using namespace std;
struct item{
	int st;
	int end;
	int weight;
    
};

void sort(vector<item>&edges)
{
    //bubble sort
    for(int i=edges.size()-1; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            int a=edges[j].weight;
            int b=edges[j+1].weight;
            if(a>b) swap(edges[j],edges[j+1]);
        }
    }
}
	
void makeset(vector<int>&parent,vector<int>&rank)
	{
	    for(int i=0; i<rank.size(); i++)
	    {
	        parent[i]=i;
	        rank[i]=0;
	    }
	}
	
	int findpar(int node,vector<int>&parent)
	{
	    if(parent[node]==node) return node;
	    return parent[node]=findpar(parent[node],parent);//path compression
	}
	
	void unionset(vector<int>&parent,vector<int>&rank,int u,int v)
	{
	    int par_u=findpar(u,parent);
	    int par_v=findpar(v,parent);
	    if(rank[par_u]>rank[par_v])
	    {
	        parent[v]=par_u;
	    }
	    else if(rank[par_v]>rank[par_u])
	    {
	        parent[u]=par_v;
	    }
	    else
	    {
	        parent[v]=par_u;
	        rank[par_u]++;
	    }
	}
	
	
int main() {
    vector<item>edges={{0,1,5},{1,2,3},{0,2,1}};
        
        sort(edges);
        vector<int>parent(3);
        vector<int>rank(3);
        makeset(parent,rank);
        string path="";
        int sum=0;
        //int count=0;
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i].st;
            int v=edges[i].end;
            int w=edges[i].weight;
            int par_u=findpar(u,parent);
            int par_v=findpar(v,parent);
            if(par_u != par_v)
            {
                sum+=w;
                path+=to_string(u)+to_string(v);
                unionset(parent,rank,u,v);
            }
        }
        cout<<"total cost is : "<< sum<<"\n and path is: "<<path<<endl;

}
