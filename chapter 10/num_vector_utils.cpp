#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string render_num_vector(const vector<int>& vec) {
    string s ="";
    if(vec.size()==0){
        return s;
    }
    for (int i=0; i<vec.size(); i++) {
        s += to_string(vec[i]) + " ";
    }
    s.erase(s.length()-1,1);
    return s;
}
int num_vector_sum(const vector<int>& vec){
    int sum = 0;
    if(vec.size()==0){
        return sum;
    }
    for(int i =0; i<vec.size(); i++){
        sum += vec[i];
    }
    return sum;
}
int num_vector_product(const vector<int>& vec){
    int product = 1;
    if(vec.size()==0){
        return product;
    }
    for(int i =0; i<vec.size(); i++){
        product *= vec[i];
    }
    return product;
}
vector<int> only_evens(const vector<int>& vec){
    vector<int> even;
    for (int i =0; i<vec.size(); i++){
        if(vec[i]%2==0){
            even.push_back(vec[i]);
        }
     }
    return even;
     
}
vector<int> only_odds(const vector<int>& vec){
    vector<int> odd;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]%2!=0){
            odd.push_back(vec[i]);
        }
    }
    return odd;
}
vector<int> nums_between(const vector<int>& vec, int low, int high){
    vector<int> between;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]>=low && vec[i]<=high){
            between.push_back(vec[i]);
        }
    }
    return between;
}
double mean(const vector<int>& vec){
    double m = 0;
    for(int i=0; i<vec.size(); i++){
        m+= vec[i];
    }
    m /= vec.size();
    return m;
}
int median(const vector<int>& vec){
    vector<int> sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end());
    int n = sortedVec.size();
    if(n==0){
        return 0;
    }
    if (n % 2 == 1) {
        return sortedVec[n / 2];
    } else {
        return (sortedVec[n / 2 - 1] + sortedVec[n / 2]) / 2;
    }
}
vector<int> mode(const vector<int>& vec){
    vector<int> sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end());
    int currentFrequency = 1;
    int maxFrequency = 0;
    vector<int> modes;
    for (size_t i = 1; i < sortedVec.size(); ++i) {
        if (sortedVec[i] == sortedVec[i - 1]) {
            currentFrequency++;
        } else{ 
            if (currentFrequency > maxFrequency) {
               modes.clear(); 
                modes.push_back(sortedVec[i - 1]); 
                maxFrequency = currentFrequency;
            } else if (currentFrequency == maxFrequency) {
                modes.push_back(sortedVec[i - 1]); 
            }           
            currentFrequency = 1;
        }
    }

    if (currentFrequency > maxFrequency) {
        modes.clear();
        modes.push_back(sortedVec.back());
    } else if (currentFrequency == maxFrequency) {
        modes.push_back(sortedVec.back());
    }

    return modes;
}
