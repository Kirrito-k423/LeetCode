#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void backTracking(int i, vector<int> & answer , vector<int> & cur_answer , unordered_map<string, int> & req_skills_meet, vector<string>& req_skills, vector<vector<string>>& people, 
        unordered_map<string, vector<int>> &req_skills_people) {
            int n = req_skills.size();
            while(i<n && req_skills_meet[req_skills[i]] > 0){
                i++;
            }
            if(i >= n){
                if(answer.size()>cur_answer.size()){
                    answer = cur_answer;
                }
                return;
            }
            //remain req to meet
            string toMeet = req_skills[i];
            for(auto addPeopleIndex : req_skills_people[toMeet]){
                //to add people
                cur_answer.push_back(addPeopleIndex);
                //change req_skills_meet
                for(auto addMeetString : people[addPeopleIndex]){
                    req_skills_meet[addMeetString]++;
                }
                backTracking(i+1, answer, cur_answer, req_skills_meet, req_skills, people, req_skills_people);
                for(auto addMeetString : people[addPeopleIndex]){
                    req_skills_meet[addMeetString]--;
                }
                cur_answer.pop_back();
            }
            return;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        //选择集合实现覆盖问题
        //使用回溯算法，从需求端开始，寻找能满足需求的人，计算每种组合的
        unordered_map<string, vector<int>> req_skills_people(req_skills.size());
        for (int i = 0; i < people.size(); i++) {
            for(auto & j : people[i]) {
                req_skills_people[j].push_back(i);
            }
        }
        unordered_map<string, int> req_skills_meet(req_skills.size());
        vector<int> answer(20) ;
        vector<int> cur_answer;
        backTracking(0, answer, cur_answer, req_skills_meet, req_skills, people, req_skills_people);
        return answer;
    }
};