 
 #include <bits/stdc++.h>

int main()
    {
        int num, i;
        std::scanf( "%d", &num);
        while(num!=0){
		long int happy[num];
           for(i=0;i<num; i++){
               std::scanf("%ld", &happy[i]);
			}
           long long int werk = 0;
           for(i=1; i<num;i++){
                happy[i]+=happy[i-1];
                werk+=fabs(happy[i-1]);
           }
			 std::printf("\n");
            std::printf("%lld\n", werk);
           std::scanf("%d", &num);
     }
       return 0;
 }
