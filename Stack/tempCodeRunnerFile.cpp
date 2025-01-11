int n=k.size();
        if(n/2==0){
            double ans=(double)k[n];
            return ans; 
        }
        if(n%2!=0){
            double ans=(double)k[n/2];
            return ans;    
        }
        else{
            double ans= (double)(k[n/2]+k[n/2-1])/2;
            return ans;    
        }