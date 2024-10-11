#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skillTrees) {
    int answer = 0;
    
    for (string skillTree : skillTrees) {
        string newSkillTree = "";
        for (char c : skillTree) {
            if (skill.find(c) != string::npos) newSkillTree += c;
        }
        
        // 선행 스킬 순서에 없는 스킬들로만 이루어진 경우
        if (newSkillTree == "") answer++;
        
        else if (skill.find(newSkillTree) == 0) answer++;
    }
    
    return answer;
}