#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::string notes = "GFEDCBAgfedcba";
    std::vector<std::string> song(n);
    std::unordered_map<char, int> index;
    for (char c : notes)
        index[c] = index.size();

    int total = n - 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> song[i];
        if (song[i].size() == 1)
            song[i] += '1';
        total += std::stoi(song[i].substr(1));
    }

    std::vector<std::string> staff(notes.size());
    for (int i = 0; i < notes.size(); ++i) {
        char c = (notes[i] == 'c' || i % 2 == 0) ? ' ' : '-';
        staff[i] = std::string(total, c);
    }

    for (int i = 0, p = 0; i < song.size(); ++i, ++p) {
        int count = std::stoi(song[i].substr(1));
        for (; count--; ++p)
            staff[index[song[i][0]]][p] = '*';
    }

    for (int i = 0; i < staff.size(); ++i)
        std::cout << notes[i] << ": " << staff[i] << '\n';
}
