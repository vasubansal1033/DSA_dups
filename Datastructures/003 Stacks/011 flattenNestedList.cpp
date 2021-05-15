/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger> st;

    NestedIterator(vector<NestedInteger> &nestedList) {

        for(int i=nestedList.size()-1; i>=0; i--)
            st.push(nestedList[i]);

    }

    int next() {
        int i = st.top().getInteger(); st.pop();
        return i;
    }

    // ensures that the top of stack is an integer
    bool hasNext() {

        // incase of empty nestedLists
        while(!st.empty()){
        NestedInteger NI = st.top();
        if((NI.isInteger()))
            return true;

        st.pop();
        for(int i=NI.getList().size()-1; i>=0; i--)
            st.push(NI.getList()[i]);

        }

        return false;

    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
