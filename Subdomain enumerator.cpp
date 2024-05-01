#include <bits/stdc++.h>
using namespace std;

int main() {
    string domain, wordlist_filename;
    cout << "Enter the domain name: ";
    cin >> domain; // test input: google.com
    cout << "Enter the filename of the subdomain wordlist: ";
    cin >> wordlist_filename;

    ifstream wordlist_file(wordlist_filename);
    if (!wordlist_file.is_open()) {
        cerr << "Error opening " << wordlist_filename << endl;
        return 1;
    }

    vector<string> subdomains;
    string subdomain;
    while (getline(wordlist_file, subdomain)) {subdomains.push_back(subdomain);}

    cout << "Fuzzing subdomains..." << endl;
    cout << "Valid subdomains for " << domain << "..." << endl;

    vector<string> valid_subdomains;
    for (const string& sub : subdomains) {
        string sub_domain = sub + "." + domain;
        string ping_command = "ping -c 1 " + sub_domain + " >/dev/null 2>&1";
        int result = system(ping_command.c_str());
        if (result == 0) {
            valid_subdomains.push_back(sub_domain);
        }
    }

    for (const string& valid_subdomain : valid_subdomains) {
        cout<< valid_subdomain << endl;
    }

    return 0;
}