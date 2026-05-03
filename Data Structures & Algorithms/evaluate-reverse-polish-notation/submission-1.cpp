class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1){
            return stoi(tokens[0]);
        }
        stack<int> S;
        
        int i=1;
        S.push(stoi(tokens[0]));
        while(!S.empty()){
            string temp = tokens[i++];
            if(temp == "+" || temp == "-" || temp == "/" || temp == "*"){
                int second = (S.top());
                S.pop();
                int first= (S.top());
                S.pop();
                int t;
                if(temp=="+"){
                    t = first + second;
                }
                if(temp=="-"){
                    t = first - second;
                }
                if(temp=="/"){
                    t = first / second;
                }
                if(temp=="*"){
                    t = first * second;
                }
                cout<<"Pushing"<<" "<<t<<endl;
                S.push(t);
            }
            else{
                cout<<"DIGIT"<<" "<<temp<<endl;
                S.push(stoi(temp));
            }
            if(i == tokens.size()){
                return S.top();
            }
        }
    }
};
