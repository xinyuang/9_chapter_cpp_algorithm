// TinyUrl 
class Solution {
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string shortUrl = "";
		int n = rand() % INT_MAX;
		while (n)
		{
			shortUrl = base[n % N] + shortUrl;
			n = n / N;
		}
		map[shortUrl] = longUrl;
		return shortUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return map[shortUrl];
	}
private:
	unordered_map<string, string> map;
	string base = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int N = 62;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

class Solution {
	hash<string> t;
	unordered_map<string, string> tinyToLongUrl;
public:
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string key = to_string(t(longUrl));
		tinyToLongUrl[key] = longUrl;
		return key;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return tinyToLongUrl[shortUrl];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));