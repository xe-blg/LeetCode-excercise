import java.util.Stack;

public class jianchakuohao {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for(char c : s.toCharArray()){
            // 有对应的另一半就直接消消乐
            if(c == ')' && !stack.isEmpty() && stack.peek() == '(')
                stack.pop();
            else if(c == '}' && !stack.isEmpty() && stack.peek() == '{')
                stack.pop();
            else if(c == ']' && !stack.isEmpty() && stack.peek() == '[')
                stack.pop();
            else
                stack.push(c);// 没有匹配的就放进去
        }

        return stack.isEmpty();
    }
}
