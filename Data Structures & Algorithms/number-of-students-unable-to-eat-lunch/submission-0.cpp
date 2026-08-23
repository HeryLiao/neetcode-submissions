class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> q;
        for(int i : students){
            q.push(i);
        }
        int u_c = 0;
        int s_i = 0;
        while(!q.empty() && u_c <q.size() ){
            int f_q = q.front();
            q.pop();
            if(f_q == sandwiches[s_i]){
                s_i++;
                u_c = 0;
            }
            else{
                q.push(f_q);
                u_c++;
            }
        }
        return q.size();
    }
};