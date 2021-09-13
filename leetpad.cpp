#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> count(amount+1, -1);
    int curMin = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (auto & c : coins)
        {
            if (i - c < 0)
            {
                cout <<"breaked " << i << " " << c << endl;
                break;
            }
            else 
            {
                if (count[i - c] != -1 || i-c == 0)
                {
                    if (count[i] == -1)
                    {
                        count[i] = 1 + ((i - c) == 0 ? 0 : count[i-c]);
                    }
                    else
                    {
                        count[i] = min(count[i], 1+((i - c) == 0 ? 0 : count[i-c]));
                    }
                }
            }
        }
    }
    for (auto c : count)
    {
        cout << c << endl;
    }
    return count[amount];
    
}

vector<int> has_sum(vector<int> numbers, int amount)
{
    unordered_map<int,int> nmap;

    for (int i = 0; i < numbers.size(); i++)
    {

        if (nmap.find(amount-numbers[i]) != nmap.end())
        {
            return {i, nmap[amount-numbers[i]]};
        }
        nmap[numbers[i]] = i;
    }
    return {};
}

struct Interval
{
    int start;
    int end;
};

int minMeetingRooms(vector<vector<int>> &intervals) {
		vector<int> startTimes, endTimes;
		for (auto& inter : intervals)
        {
            startTimes.push_back(inter[0]);
            endTimes.push_back(inter[1]);
        }
		sort(startTimes.begin(), startTimes.end());
		sort(endTimes.begin(), endTimes.end());
		int i = 0, j = 0, rooms = 0;
		while(i < intervals.size()) {
				if(startTimes[i] < endTimes[j]) {
						rooms++;
				} else {
						j++;
				}
                i++;
		}
		return rooms;
}


bool dfs(vector<vector<int>> & conns, unordered_map<int,int> &labels, int n, int label)
{
    if (labels.count(n) == 0)
    {
        labels[n] = label;
    }
    else
    {
        if (labels[n] != label)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    for (const auto& con : conns[n])
    {
        if (dfs(conns, labels, con, 1-label) == false)
        {
            return false;
        }
    }
    
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {

    unordered_map<int,int> label;
    int maxx = 0;
    
    for (int i = 0; i < graph.size(); i++)
    {
        int curlabel = label.count(i) == 0 ? 0 : label[i];
        if (dfs(graph,label, i, curlabel) == false)
        {
            return false;
        }
    }
    return true;
}
bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n , vector<int>());
    for (auto & dislike : dislikes)
    {
        graph[dislike[0]].push_back(dislike[1]);
        graph[dislike[1]].push_back(dislike[0]);
    }
    return isBipartite(graph);                
}


template <class T>
void printVector(vector<T> arr)
{
    for (auto& item: arr)
    {
        cout << item << " ";
    }
    cout << endl;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
        printVector(res);
    }
    return res.size();
}
int main()
{
    vector<int> test = {10,9,2,5,3,7,8,101,4,18};
    lengthOfLIS(test);
    return 0;
}