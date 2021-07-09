public class Solution {
    public int EvalRPN(string[] tokens) {
        Stack<int> tokenStack = new Stack<int>();
        foreach (string token in tokens) {
            switch (token)
            {
                case "+":
                {
                    int token2 = tokenStack.Pop(), token1 = tokenStack.Pop();
                    tokenStack.Push(token1 + token2);
                    break;
                }
                case "-":
                {
                    int token2 = tokenStack.Pop(), token1 = tokenStack.Pop();
                    tokenStack.Push(token1 - token2);
                    break;
                }
                case "*":
                {
                    int token2 = tokenStack.Pop(), token1 = tokenStack.Pop();
                    tokenStack.Push(token1 * token2);
                    break;
                }
                case "/":
                {
                    int token2 = tokenStack.Pop(), token1 = tokenStack.Pop();
                    tokenStack.Push(token1 / token2);
                    break;
                }
                default:
                    tokenStack.Push(int.Parse(token));
                    break;
            };
        }
        return tokenStack.Pop();
    }
}