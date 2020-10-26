#include <bits/stdc++.h>

template <typename T, int NDIMS>
struct tensor_view {
    static_assert(NDIMS >= 0, "need nonnegative ndims");

protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    T* data;

    tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T* data_) : shape(shape_), strides(strides_), data(data_) {}

public:
    tensor_view() : shape{0}, strides{0}, data(nullptr) {}

protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

public:
    T& operator[](std::array<int, NDIMS> idx) const {
        return data[flatten_index(idx)];
    }
    T& at(std::array<int, NDIMS> idx) const {
        return data[flatten_index_checked(idx)];
    }

    template <int D = NDIMS>
    std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> operator[](int idx) const {
        std::array<int, NDIMS - 1> nshape;
        std::copy(shape.begin() + 1, shape.end(), nshape.begin());
        std::array<int, NDIMS - 1> nstrides;
        std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
        T* ndata = data + (strides[0] * idx);
        return tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
    }
    template <int D = NDIMS>
    std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> at(int idx) const {
        assert(0 <= idx && idx < shape[0]);
        return operator[](idx);
    }

    template <int D = NDIMS>
    std::enable_if_t<(0 == D), T&> operator*() const {
        return *data;
    }

    template <typename U, int D>
    friend struct tensor_view;
    template <typename U, int D>
    friend struct tensor;
};

template <typename T, int NDIMS>
struct tensor {
protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    tensor(const tensor& o) : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        for (int i = 0; i < len; i++) {
            data[i] = o.data[i];
        }
    }

    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
    }
    tensor(tensor&& o) : tensor() {
        *this = std::move(o);
    }
    tensor& operator=(const tensor& o) {
        return *this = tensor(o);
    }
    ~tensor() { delete[] data; }

    using view_t = tensor_view<T, NDIMS>;
    view_t view() {
        return tensor_view<T, NDIMS>(shape, strides, data);
    }
    operator view_t() {
        return view();
    }

    using const_view_t = tensor_view<const T, NDIMS>;
    const_view_t view() const {
        return tensor_view<const T, NDIMS>(shape, strides, data);
    }
    operator const_view_t() const {
        return view();
    }

    T& operator[](std::array<int, NDIMS> idx) { return view()[idx]; }
    T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
    const T& operator[](std::array<int, NDIMS> idx) const { return view()[idx]; }
    const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }

    template <int D = NDIMS>
    std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> operator[](int idx) {
        return view()[idx];
    }
    template <int D = NDIMS>
    std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> at(int idx) {
        return view().at(idx);
    }

    template <int D = NDIMS>
    std::enable_if_t<(0 < D), tensor_view<const T, NDIMS - 1>> operator[](int idx) const {
        return view()[idx];
    }
    template <int D = NDIMS>
    std::enable_if_t<(0 < D), tensor_view<const T, NDIMS - 1>> at(int idx) const {
        return view().at(idx);
    }

    template <int D = NDIMS>
    std::enable_if_t<(0 == D), T&> operator*() {
        return *view();
    }
    template <int D = NDIMS>
    std::enable_if_t<(0 == D), const T&> operator*() const {
        return *view();
    }
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        int V, E, S, R;
        cin >> V >> E >> S >> R;
        vector<vector<int>> adj(V);
        for (int e = 0; e < E; e++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> sell(V);
        for (int i = 0; i < V; i++) {
            int c;
            cin >> c;
            sell[i].resize(c);
            for (int& s : sell[i]) {
                cin >> s;
                s--;
            }
        }

        // Which recipes use each type of stone
        vector<vector<int>> users(S);
        vector<int> num_inputs(R);
        vector<int> product(R);
        for (int r = 0; r < R; r++) {
            cin >> num_inputs[r];
            for (int k = 0; k < num_inputs[r]; k++) {
                int s;
                cin >> s;
                s--;
                users[s].push_back(r);
            }
            cin >> product[r];
            product[r]--;
        }

        const int64_t INF = 1e12;
        tensor<int64_t, 2> stone_dist({S, V}, INF);

        // sum of things that have reached you so far
        tensor<pair<int, int64_t>, 2> recipe_dist({R, V}, {0, 0});

        priority_queue<pair<int64_t, pair<int, int>>, vector<pair<int64_t, pair<int, int>>>, greater<>> pq;
        for (int i = 0; i < V; i++) {
            for (int s : sell[i]) {
                pq.push({stone_dist[{s, i}] = 0, {s, i}});
            }
        }

        while (!pq.empty()) {
            int64_t d = pq.top().first;
            int s = pq.top().second.first;
            int cur = pq.top().second.second;
            pq.pop();
            assert((d >= stone_dist[{s, cur}]));
            if (d != stone_dist[{s, cur}]) continue;

            // add it to any recipes
            for (int r : users[s]) {
                recipe_dist[{r, cur}].first++;
                recipe_dist[{r, cur}].second += d;
                if (recipe_dist[{r, cur}].first == num_inputs[r]) {
                    int64_t nd = recipe_dist[{r, cur}].second;
                    int t = product[r];
                    if (nd < stone_dist[{t, cur}]) {
                        pq.push({stone_dist[{t, cur}] = nd, {t, cur}});
                    }
                }
            }

            // move it along an edge
            for (int nxt : adj[cur]) {
                int64_t nd = d + 1;
                if (nd < stone_dist[{s, nxt}]) {
                    pq.push({stone_dist[{s, nxt}] = nd, {s, nxt}});
                }
            }
        }

        int64_t ans = INF;
        for (int i = 0; i < V; i++) {
            ans = min(ans, stone_dist[{0, i}]);
        }

        cout << "Case #" << case_num << ": ";
        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}
