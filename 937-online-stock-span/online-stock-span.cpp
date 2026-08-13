#include <stack>
#include <utility> // for std::pair

class StockSpanner {
public:
    // stack stores {price, span}
    std::stack<std::pair<int,int>> st;

    StockSpanner() {
        // nothing to initialize
    }
    
    int next(int price) {
        int span = 1;
        // Pop while previous prices are <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
