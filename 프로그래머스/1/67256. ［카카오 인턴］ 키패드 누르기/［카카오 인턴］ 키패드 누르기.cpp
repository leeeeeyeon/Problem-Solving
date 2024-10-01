#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> leftHand = {3, 0}; // 왼손의 위치
    pair<int, int> rightHand = {3, 2}; // 오른손의 위치
    
    for (int number : numbers) {        
        if (number % 3 == 1) { // 1, 4, 7은 왼손
            // 왼손 좌표를 옮기고
            leftHand = {number/3, 0};
            
            // answer에 사용한 손가락 추가
            answer += 'L';
        }
        else if (number != 0 && number % 3 == 0) { // 3, 6, 9는 오른손
            // 오른손 좌표를 옮기고
            rightHand = {number/3 - 1, 2};
            
            // answer에 사용한 손가락 추가
            answer += 'R';
        }
        else { // 2, 5, 8, 0은 더 가까운 손, 같다면 잡이에 맞는 손
            // |x2-x1| + |y2-y1|으로 거리 비교
            pair<int, int> numberPoint;
            if (number == 0) numberPoint = {3, 1};
            else numberPoint = {number/3, 1};
            
            int leftDist = abs(leftHand.first - numberPoint.first) + abs(leftHand.second - numberPoint.second);
            int rightDist = abs(rightHand.first - numberPoint.first) + abs(rightHand.second - numberPoint.second);
            
            if (leftDist == rightDist) {
                if (hand == "left") {
                    leftHand = numberPoint;
                    answer += 'L';
                } else { // hand == "right"
                    rightHand = numberPoint;
                    answer += 'R';
                }
            } else if (leftDist > rightDist) {
                rightHand = numberPoint;
                answer += 'R';
            } else { // leftDist < rightDist
                leftHand = numberPoint;
                answer += 'L';
            }
        }
    }
    
    return answer;
}