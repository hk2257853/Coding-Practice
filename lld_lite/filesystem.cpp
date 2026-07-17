#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

// One directory node in the N-ary tree
struct FileSystemNode {
    string name;
    FileSystemNode* parent;
    map<string, FileSystemNode*> children;  // sorted lex by default

    FileSystemNode(const string& n, FileSystemNode* p) : name(n), parent(p) {}
};

// Split "/foo/bar" -> ["foo", "bar"]
vector<string> splitPath(const string& path) {
    vector<string> tokens;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '/')) {
        if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
}

class InMemoryFileSystem {
private:
    FileSystemNode* root;
    FileSystemNode* cwd;

    /*
     * resolveSegments - core DFS traversal
     *
     * Walks tree segment by segment:
     *   "."  -> stay at current node
     *   ".." -> go to parent (clamp at root)
     *   "*"  -> try each child in sorted order, recurse on remaining segments.
     *           Return first (lex-smallest) success.
     *   else -> exact child lookup
     *
     * Returns destination node, or nullptr on failure.
     */
    FileSystemNode* resolveSegments(FileSystemNode* node,
                                    const vector<string>& segments,
                                    int idx) {
        // Base case: consumed all segments
        if (idx == (int)segments.size()) return node;

        const string& seg = segments[idx];

        if (seg == ".") {
            return resolveSegments(node, segments, idx + 1);
        }

        if (seg == "..") {
            FileSystemNode* up = (node->parent != nullptr) ? node->parent : node;
            return resolveSegments(up, segments, idx + 1);
        }

        if (seg == "*") {
            // Iterate children in lex order (map is sorted).
            // Return as soon as one path succeeds.
            for (auto& kv : node->children) {
                FileSystemNode* result = resolveSegments(kv.second, segments, idx + 1);
                if (result != nullptr) return result;
            }
            return nullptr;
        }

        // Exact match
        auto it = node->children.find(seg);
        if (it == node->children.end()) return nullptr;
        return resolveSegments(it->second, segments, idx + 1);
    }

public:
    InMemoryFileSystem() {
        root = new FileSystemNode("/", nullptr);
        cwd  = root;
    }

    /*
     * mkdir
     * Walk segments from root. Create missing nodes along the way.
     * Time: O(D * log C)
     */
    bool mkdir(const string& path) {
        if (path.empty()) return false;
        vector<string> segments = splitPath(path);
        if (segments.empty()) return false;

        FileSystemNode* curr = (path[0] == '/') ? root : cwd;

        for (const string& seg : segments) {
            if (seg == "." || seg == "..") continue;
            if (curr->children.find(seg) == curr->children.end()) {
                curr->children[seg] = new FileSystemNode(seg, curr);
            }
            curr = curr->children[seg];
        }
        return true;
    }

    /*
     * cd
     * Determine start node (absolute vs relative).
     * Delegate traversal to resolveSegments.
     * Time: O(D * log C) direct; O(V+E) with wildcards.
     */
    bool cd(const string& path) {
        if (path.empty()) return false;

        FileSystemNode* startNode = (path[0] == '/') ? root : cwd;
        vector<string> segments = splitPath(path);

        // Edge case: cd("/") with no segments -> go to root
        if (segments.empty()) {
            cwd = root;
            return true;
        }

        FileSystemNode* dest = resolveSegments(startNode, segments, 0);
        if (dest == nullptr) return false;

        cwd = dest;
        return true;
    }

    /*
     * pwd
     * Walk up via parent pointers, collect names, reverse.
     * Time: O(D)
     */
    string pwd() const {
        if (cwd == root) return "/";

        vector<string> parts;
        FileSystemNode* curr = cwd;
        while (curr != root) {
            parts.push_back(curr->name);
            curr = curr->parent;
        }

        string result;
        for (int i = (int)parts.size() - 1; i >= 0; i--) {
            result += "/" + parts[i];
        }
        return result;
    }
};

int main() {
    InMemoryFileSystem fs;

    cout << "=== Basic mkdir + pwd ===\n";
    fs.mkdir("/foo/bar");
    fs.mkdir("/foo/baz");
    fs.mkdir("/foo/zoo");
    fs.cd("/foo/bar");
    cout << fs.pwd() << "\n";    // /foo/bar

    cout << "\n=== Absolute cd ===\n";
    fs.cd("/foo/baz");
    cout << fs.pwd() << "\n";    // /foo/baz

    cout << "\n=== cd .. ===\n";
    fs.cd("..");
    cout << fs.pwd() << "\n";    // /foo
    fs.cd("..");
    cout << fs.pwd() << "\n";    // /
    fs.cd("..");                 // already at root, stay
    cout << fs.pwd() << "\n";    // /

    // /foo has children: bar, baz, zoo (sorted)
    // * resolves to bar (lex smallest)
    cout << "\n=== Wildcard * ===\n";
    fs.cd("/foo/*");
    cout << fs.pwd() << "\n";    // /foo/bar

    cout << "\n=== Wildcard in middle ===\n";
    fs.mkdir("/a/x/deep");
    fs.mkdir("/a/y/deep");
    fs.cd("/a/*/deep");
    cout << fs.pwd() << "\n";    // /a/x/deep (x < y)

    cout << "\n=== cd . ===\n";
    fs.cd("/foo/baz");
    fs.cd(".");
    cout << fs.pwd() << "\n";    // /foo/baz

    cout << "\n=== Mixed .. and * ===\n";
    fs.cd("/foo/baz");
    fs.cd("../*");               // go up to /foo, wildcard -> /foo/bar
    cout << fs.pwd() << "\n";    // /foo/bar

    cout << "\n=== cd to non-existent ===\n";
    bool ok = fs.cd("/foo/nonexistent");
    cout << (ok ? "moved" : "failed") << "\n";  // failed
    cout << fs.pwd() << "\n";                   // /foo/bar (unchanged)

    cout << "\n=== cd / ===\n";
    fs.cd("/");
    cout << fs.pwd() << "\n";    // /

    return 0;
}
