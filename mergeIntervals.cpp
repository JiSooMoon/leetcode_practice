/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> answ;
        
        int i = 0;
//         sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
//         for(i=0; i < intervals.size(); i++){
//              if(intervals[i].end >= intervals[i+1].start && intervals[i].start <= intervals[i+1].start && intervals[i].end <= intervals[i+1].end) {
             
//                 answ.push_back(Interval(intervals[i].start, intervals[i+1].end));
//                  cout << "here\n";
//                 i++;
//             }else{
//                 answ.push_back(intervals[i]);
//             }
//         }
//         return answ;
        //sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        if(intervals.size() == 0 )return vector<Interval>{};
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        answ.push_back(intervals[0]);
        for(i = 1; i < intervals.size(); i++){
            if(answ.back().end < intervals[i].start){
                answ.push_back(intervals[i]);
            }else{
                answ.back().end = max(answ.back().end, intervals[i].end);
            }
        }
        return answ;
    }
};

/*
EX1) 
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

EX2)
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

/*
IDEA NOTE:

At the first: I thought I could simply compare the values from the first object's end value with the second object's first value. 
However, this requires me to go through only simple computations, so it cannot pass all the test cases 
ex) [[1,4], [2,3]] : can be wrong becasue it will eventually gives me output as itself

Then, I realized that the best way would be 
  1) Sort all the objects ascending order with the first elements. Time O(N log N) space (1)
  2) creare a new vector and save accordingly by comparing the new vector's back element with the new coming element's start value
  Otherwise, compute the max value and save into the back of the array
  3) Return the results
  
  Since I created a new vector, the space complexity will be O(N) with the time complexity of O(N log N)

*/
