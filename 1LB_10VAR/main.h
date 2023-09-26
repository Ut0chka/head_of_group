#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ofstream out("results.txt");
// ��������� ��� �������� ���������� � ���������
struct Candidate {
    string name;
    int votes;

    Candidate(string n) {
        name = n;
        votes = 0;
    }
};

// ������� ��� ���������� �����������
void listCandidates(vector<Candidate>& candidates) {
    cout << "����������� �� ����� ��������!" << endl;

    // ����� ������ ����������
    cout << "���������:" << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i].name << endl;
    }
}

void vote(vector<Candidate>& candidates)
{
    // ���� �����������
    while (true) {
        cout << "������� ����� ���������, �� �������� ������ ������������� (0 - ��������� �����������): ";
        int choice;
        cin >> choice;

        if (choice < 0 || choice > candidates.size()) {
            cout << "������������ �����!" << endl;
            continue;
        }
        else if (choice == 0) {
            break;
        }

        // ���������� ���������� ������� ���������
        candidates[choice - 1].votes++;
    }
}
void sortCandidates(vector<Candidate>& candidates)
{
    // ���������� ���������� �� �������� �������
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
        });

}

void resultsVote(vector<Candidate>& candidates, ofstream& out)
{
    // ����� ����������� �����������
    out << "���������� �����������: " << endl;
    for (int i = 0; i < candidates.size(); i++) {
        out << i + 1 << ". " << candidates[i].name << ": " << candidates[i].votes << " �������" << endl;
    }
    cout << "���������� ����������� ���������� �� ���� results.txt" << endl;
}