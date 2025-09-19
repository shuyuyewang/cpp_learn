class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 邻接表：graph[u] = { {v, w}, ... }存放 (v, w)，表示 u → v 有一条权重 w 的边
        vector<vector<pair<int,int>>> graph(n + 1);//从1开始计数，丢掉 0
        for (auto &e : times) {//遍历边放到graph里面
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
        }

        const int INF = INT_MAX / 2;//实际上取个很大的值就行，当作∞
        vector<int> dist(n + 1, INF);//用来存所有点到起点的最短距离
        dist[k] = 0;//初始化起点到自己的距离为0
        vector<char> in_closed(n + 1, 0);// close_list：是否已收录（确定最短）

        // open_list：小根堆（g最小优先）；元素 = {当前距离, 节点}
        using P = pair<int,int>;
        priority_queue<P, vector<P>, greater<P>> open_list;//保证堆顶始终是最小的
        open_list.push({0, k});//入堆

        //while(1)：直到 open_list 为空
        while (!open_list.empty()) {
            // 取 open_list 中 g(n) 最小的节点
            auto [d, u] = open_list.top();
            open_list.pop();

            // 如果这个堆元素是我们已经有更短的dist[u]，或已收录，跳过
            if (d != dist[u] || in_closed[u]) continue;

            // 收录到 close_list
            in_closed[u] = 1;

            // 遍历当前节点未在 close_list 的邻接节点
            for (auto [v, w] : graph[u]) {
                if (in_closed[v]) continue; // 已收录的不再更新
                // 如果 v 在 open_list 中（隐含于 dist[v] != INF），尝试更新更小的 g
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    open_list.push({dist[v], v}); // 放进 open_list
                }
            }
        }

        // open_list 为空后，检查是否所有节点可达；答案是 dist 的最大值
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1; // 有不可达节点
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};