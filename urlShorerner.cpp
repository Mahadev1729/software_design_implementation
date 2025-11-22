#include <bits/stdc++.h>
using namespace std;

class URLShortener {
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    const string base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    long long id = 1;

    string encode(long long num) {
        string s = "";
        while (num > 0) {
            s += base62[num % 62];
            num /= 62;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string shortenURL(string longURL) {
        if (longToShort.count(longURL)) 
            return longToShort[longURL];

        string shortCode = encode(id++);
        string shortURL = "https://tiny.cc/" + shortCode;

        shortToLong[shortURL] = longURL;
        longToShort[longURL] = shortURL;

        return shortURL;
    }

    string expandURL(string shortURL) {
        if (!shortToLong.count(shortURL)) 
            return "Error: URL not found";

        return shortToLong[shortURL];
    }
};

int main() {
    URLShortener url;

    string longURL1 = "https://www.google.com/search?q=chatgpt";
    string shortURL1 = url.shortenURL(longURL1);
    cout << "Short: " << shortURL1 << endl;
    cout << "Original: " << url.expandURL(shortURL1) << endl;

    string longURL2 = "https://www.example.com/some/very/long/link/here";
    string shortURL2 = url.shortenURL(longURL2);
    cout << "Short: " << shortURL2 << endl;
    cout << "Original: " << url.expandURL(shortURL2) << endl;
}
