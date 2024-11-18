#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0; // 지폐를 접은 횟수
    
    int billMin = *min_element(bill.begin(), bill.end());
    int billMax = *max_element(bill.begin(), bill.end());

    int walletMin = *min_element(wallet.begin(), wallet.end());
    int walletMax = *max_element(wallet.begin(), wallet.end());
    
    while (billMin > walletMin || billMax > walletMax) {                
        if (bill[0] > bill[1]) bill[0] /= 2;
        else bill[1] /= 2;
        
        answer++;
        
        billMin = *min_element(bill.begin(), bill.end());
        billMax = *max_element(bill.begin(), bill.end());
        
        walletMin = *min_element(wallet.begin(), wallet.end());
        walletMax = *max_element(wallet.begin(), wallet.end());
    }
    
    return answer;
}