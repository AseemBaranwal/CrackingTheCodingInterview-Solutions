/*
 * Problem 3.2 : How would you design a stack which, in addition to push and pop, has a function min
 * which returns the minimum element? Push, pop and min should all operate in O(1) time.
 * 
 * Approach : Use a separate stack to take care of the min values. The
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 * 
 * Problem Link : https://practice.geeksforgeeks.org/problems/special-stack/1#
 * 
 */
stack<int> mn;
void push(stack<int>& s, int a){ 
    s.push(a);
    if(mn.size() == 0 or mn.top() >= a)
        mn.push(a);
}

bool isFull(stack<int>& s,int n){ 
	return s.size() == n;
}

bool isEmpty(stack<int>& s){ 
	return s.size() == 0;
}

int pop(stack<int>& s){ 
	if(!isEmpty(s)){
	    if(mn.top() == s.top()){
	        mn.pop();
	    }
	    int x = s.top(); s.pop();
	    return x;
	}
	return -1;
}

int getMin(stack<int>& s){ 
	if(!isEmpty(s))
	    return mn.top();
	return -1;
}