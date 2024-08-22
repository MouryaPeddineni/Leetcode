class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> adj[numCourses];
        vector<int> topo;
        vector<int> indegree(numCourses, 0);

        for(int i=0;i<n;i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++) {
            for(int adjNode:adj[i]) {
                indegree[adjNode]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int adjNode:adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        
        if(topo.size() == numCourses) return true;
        return false;
    }
};