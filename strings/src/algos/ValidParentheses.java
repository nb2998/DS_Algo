package strings.src.algos;

public class ValidParentheses {
    public boolean isValid(String s) {
        if (s == null) {
            return false;
        }
        char[] stack = new char[s.length()];
        int count = 0;
        for(char c : s.toCharArray()) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    stack[count++] = c;
                    break;
                case ')':
                    if ((count == 0 || stack[--count] != '(')){
                        return false;
                    }
                    break;
                case '}':
                    if ((count == 0 || stack[--count] != '{')){
                        return false;
                    }
                    break;
                case ']':
                    if ((count == 0 || stack[--count] != '[')){
                        return false;
                    }
                    break;
                default: return false;
            }
        }
        return (count == 0);
    }

    public static void main(String[] args) {
        ValidParentheses validParentheses = new ValidParentheses();
        System.out.println(validParentheses.isValid("(((("));
        System.out.println(validParentheses.isValid("(((())))"));
        System.out.println(validParentheses.isValid("(((()))})"));
        System.out.println(validParentheses.isValid(""));
    }
}
