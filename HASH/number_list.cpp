#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (i != 0)
        {
            if (phone_book[i - 1] == phone_book[i].substr(0, phone_book[i - 1].size()))
                answer = false;
        }
        if (!answer)
            break;
    }
    return answer;
}