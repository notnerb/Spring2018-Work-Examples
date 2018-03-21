#include <stdio.h>
#include <iostream>     
#include <algorithm> 
#include <utility>

int MaxA(std::vector<std::pair<int, int>> s, int n)
{
    int i, j;
    int max = 1;
    i = 0;
    for (j = 1; j < n; j++)
    {
      if (s[j].first >= s[i].second)
      {
          max++;
          i = j;
      }
    }
    return max;
}

int main()
{
	int testcases, n, s, f;
	std::cin>>testcases;
	int* answers = new int[testcases];
	for(int i = 0; i < testcases; i++)
	{
		std::cin>>n;
		std::vector<std::pair<int, int>> times(n);
		for(int x = 0; x<n; x++){
			std::cin>>s;
			std::cin>>f;
			times[x].first = s;
			times[x].second = f;
		}
		std::sort(times.begin(), times.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {return left.second < right.second;});		
       for(int i = 0; i<n; i++){
			//std::cout<<" "<<times[i].second;
			//std::cout<<" "<<times[i].first;
		}
		answers[i]=MaxA(times, n);
	}
	for(int i = 0; i < testcases; i++)
	{
		std::cout<<"\n"<<answers[i];
	}
}
