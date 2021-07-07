// https://practice.geeksforgeeks.org/viewSol.php?subId=d2ab79eb68870c0ac9037640b2e88391&pid=701755&user=kirtanprajapati




class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	 {
	    int x1 =  KnightPos[0];
	    int y1 =  KnightPos[1];
	    int x2 =  TargetPos[0];
	    int y2 =  TargetPos[1];
	    
	    int a[1001][1001];
	    if(x1 == x2 && y1 == y2){
	        return 0;
	    }
	    
	    memset(a,0,sizeof(a));
	    
	    queue<pair<int,int> >q;
	    q.push(make_pair(x1-1,y1-1));
	    
	    while(!q.empty()){
	        auto curr = q.front();
	        int i = curr.first;
	        int j = curr.second;
	        q.pop();
	        
	        if((i+1)>=0 && (i+1)<n and (j+2)>=0 and (j+2)<n and a[i+1][j+2] == 0){
	            a[i+1][j+2] = a[i][j]+1;
	            q.push(make_pair(i+1,j+2));
	        }
	        
	        if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and a[i+2][j+1] == 0){
	            a[i+2][j+1] = a[i][j] + 1;
	            q.push(make_pair(i+2 , j+1));
	        } 
	        
	        if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and a[i-1][j+2] == 0){
	            a[i-1][j+2] = a[i][j] + 1;
	            q.push(make_pair(i-1,j+2));
	        }
	        
	        if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and a[i-2][j+1] == 0){
	            a[i-2][j+1] = a[i][j] + 1;
	            q.push(make_pair(i-2,j+1));
	        }
	        
	        if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and a[i-1][j-2] == 0){
	            a[i-1][j-2] = a[i][j] + 1;
	            q.push(make_pair(i-1,j-2));
	        }
	        
	        if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and a[i+1][j-2] == 0){
	            a[i+1][j-2] = a[i][j] + 1;
	            q.push(make_pair(i+1,j-2));
	        }
	        
	        if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and a[i-2][j-1] == 0){
	            a[i-2][j-1] = a[i][j] + 1;
	            q.push(make_pair(i-2,j-1));
	        }
	        
	        if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and a[i+2][j-1] == 0){
	            a[i+2][j-1] = a[i][j] + 1;
	            q.push(make_pair(i+2,j-1));
	        }
	        
	    } 
	    return a[x2-1][y2-1];
	
	}
};
