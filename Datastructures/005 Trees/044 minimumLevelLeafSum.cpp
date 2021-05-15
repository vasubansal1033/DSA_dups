int minLeafSum(Node* root){
	// Code here
	if(!root) return 0;

	int sum = 0;
	queue<Node* > q;
	q.push(root);

	while(!q.empty()){

	    int sz = q.size();
	    for(int i=0; i<sz; i++){

	        Node* front = q.front(); q.pop();
	        if(!front->left && !front->right) sum+=front->data;

	        if(front->left) q.push(front->left);
	        if(front->right) q.push(front->right);

	    }

	    if(sum>0) break;

	}

	return sum;

}
