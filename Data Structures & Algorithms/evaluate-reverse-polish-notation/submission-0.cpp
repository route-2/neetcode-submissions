class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int n = tokens.size();

        int i = 0;
        while(i<n){
            int result = 0;
            if(tokens[i]=="+"){
               int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                result = num1 + num2;
                numbers.push(result);
            }else if(tokens[i]=="-"){
               int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                result = num1 - num2;
                numbers.push(result);
            }else if(tokens[i]=="*"){
               int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                result = num1 * num2;
                numbers.push(result);
            }else if(tokens[i]=="/"){
               int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                result = num1 / num2;
                numbers.push(result);
            } else {
                 numbers.push(stoi(tokens[i]));
            }
            i++;
        }
        return numbers.top();

        
    }
};
