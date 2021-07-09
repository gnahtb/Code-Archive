public class Solution {
    public IList<IList<string>> SuggestedProducts(string[] products, string searchWord) {
        List<string> productList = products.ToList();
        productList.Sort();
        IList<IList<string>> res = new List<IList<string>>();
        for (int i = 0; i < searchWord.Length; ++i) {
            res.Add(new List<string>());
            List<string> removingQueue = new List<string>();
            foreach (string st in productList)
                if (st.Length <= i || st[i] != searchWord[i])
                    removingQueue.Add(st);
            foreach (string st in removingQueue)
                productList.Remove(st);
            for (int j = 0; j < Math.Min(3, productList.Count); ++j)
                res[i].Add(productList[j]);
        }
        return res;
    }
}