#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <assert.h>
using namespace std;

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

struct Mountain{
	/*定义一个山峰结构，left表示左山脚，right表示右山脚，value表示山峰高度*/
    int left;
    int right;
    int value;
    Mountain(int l, int r, int v){
		left = l;
		right = r;
		value = v;
	}
};

Mountain getIntValue(char* mountain_string){
	/*把字符串格式的山峰数据转换成Mountain结构类型*/
	if(mountain_string == NULL)
		return Mountain(0,0,0);
    int l,r,v;

    sscanf(mountain_string,"%d,%d,%d",&l,&r,&v);
    
    return Mountain(l,r,v);
}

int getWalkNum(vector<Mountain>& mountains){
	/*计算每一组从A出发到到B需要Walk的值*/
    int mountainNum = mountains.size();
    
    if(mountainNum == 0)
		return 0;
	
	//得到最右边的山峰的右山脚	
    int max_right = 0;
    for(int i=0; i<mountainNum; i++)
        max_right = max(mountains[i].right, max_right);
        
    vector<int> height(max_right*2 + 2, 0);	//这里max_right乘2是为了处理两做山峰相邻的情况，使得山峰不再相邻，举例：
											//原来的山峰 M1（0，1，1）与N1（2，3，2）是相邻的，按我们的算法会导致没下M1直接上N1的错误
											//但乘2就变成M2（0，2，1）与N2（4，6，2）不相邻，这样就会先下M2再上N2，得到正确结果
    for(int i=0; i<mountainNum; i++){
        int l = 2 * mountains[i].left;
        int r = 2 * mountains[i].right;
        for(int j=l; j<=r; j++)
            height[j] = max(height[j], mountains[i].value);
    }
    
    int sum = 0;
    sum += height[0];
    for(int i=1; i< max_right*2 + 2; i++){
        sum += abs(height[i]-height[i-1]);
    }
    sum += max_right;
    return sum;	
}

int resolve(const char* input){
	if(input == NULL)
		return 0;
	
    stringstream stream(input);
    int mountainNum;
    stream>>mountainNum;
    
    vector<Mountain> mountains;
    char mountain_string[100];
    while(mountainNum > 0){
        stream>>mountain_string;
        mountains.push_back(getIntValue(mountain_string));
        --mountainNum;
    }
    return getWalkNum(mountains);	
}

int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        "",//I add a empty input test
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20, 0};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
