for(int j=(1<<n)-1;j>=0;j--)
    {
        for(int j=1;j<=m;j++)
        {
            if(Judge(j,j))
            {
                int target=Change(j,j);
                cout<<j<<" "<<j<<" "<<target<<endl;
                dp[target]=min(dp[target],dp[j]+t[j]);
            }
        }
    }