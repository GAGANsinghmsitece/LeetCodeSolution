#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
    //nlogn complexity as sorting in done in nlogn
    sort(nums.begin(),nums.end());
    int num=-1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            num=nums[i];
            break;
        }
    }
    return num;
}
int findDuplicate(vector<int>& arr) {
    //n complexity based on marking but only valid when 1<=arr[i]<=n
    for(int i=0;i<arr.size();i++){
        if(arr[abs(arr[i])]>=0){
            arr[abs(arr[i])]=-arr[abs(arr[i])];
        }else{
            return abs(arr[i]);
        }
    }
    return -1;
}
/*
Cyclic Detection or Floyd's Tortoise and Hare
In phase 1, hare = nums[nums[hare]] is twice as fast as tortoise = nums[tortoise]. Since the hare goes fast, it would be the first one who enters the cycle and starts to run around the cycle. At some point, the tortoise enters the cycle as well, and since it's moving slower the hare catches the tortoise up at some intersection point. Now phase 1 is over, and the tortoise has lost.
Note that the intersection point is not the cycle entrance in the general case.
To compute the intersection point, let's note that the hare has traversed twice as many nodes as the tortoise, i.e. 2d(tortoise)=d(hare), that means

2(F+a)=F+nC+a, where n is some integer.

Hence the coordinate of the intersection point is F+a=nC.

In phase 2, we give the tortoise a second chance by slowing down the hare, so that it now moves with the speed of tortoise: tortoise = nums[tortoise], hare = nums[hare]. The tortoise is back at the starting position, and the hare starts from the intersection point.

Let's show that this time they meet at the cycle entrance after F steps.

    The tortoise started from zero, so its position after F steps is F.

    The hare started at the intersection point F+a=nC, so its position after F steps is nC+F, that is the same point as F.

    So the tortoise and the (slowed down) hare will meet at the entrance of the cycle.

*/
int findDuplicate(vector<int>& nums) {
    //n complexity but only valid when 1<=arr[i]<=n
    int hare=nums[0];
    int tortoise=nums[0];
    do{
        tortoise=nums[tortoise];
        hare=nums[nums[hare]];
    }while(tortoise!=hare);
    tortoise=nums[0];
    while(tortoise!=hare){
        tortoise=nums[tortoise];
        hare=nums[hare];
    }
    return hare;
}