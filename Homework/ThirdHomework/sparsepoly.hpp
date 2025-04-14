#include <iostream>
#include <vector>

using namespace std;

class Term {
public:
    float coef;
    int expo;

    Term(float c = 0.0f, int e = 0) : coef(c), expo(e) {}
};

class SparsePoly {
    vector<Term> terms; 

public:
    //���׽� �Է��Լ�
    void read() {
        int n;
        cout << "���� ������ �Է��ϼ���: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            float c;
            int e;
            cout << i + 1 << "��° ���� ����� ������ �Է��ϼ��� (��: ��� ����): ";
            cin >> c >> e;
            terms.push_back(Term(c, e));
        }
    }

    // ���׽� ����Լ�
    void display(const string& title) const {
        cout << title;
        for (size_t i = 0; i < terms.size(); i++) {
            cout << terms[i].coef << "x^" << terms[i].expo;
            if (i < terms.size() - 1)
                cout << " + ";
        }
        cout << endl;
    }

    // ���׽� �����Լ�
    void add(const SparsePoly& a, const SparsePoly& b) {
        terms.clear(); 

        size_t i = 0, j = 0;

        while (i < a.terms.size() && j < b.terms.size()) {
            if (a.terms[i].expo == b.terms[j].expo) {
                float sum = a.terms[i].coef + b.terms[j].coef;
                if (sum != 0.0f)
                    terms.push_back(Term(sum, a.terms[i].expo));
                i++;
                j++;
            }
            else if (a.terms[i].expo > b.terms[j].expo) {
                terms.push_back(a.terms[i]);
                i++;
            }
            else {
                terms.push_back(b.terms[j]);
                j++;
            }
        }

        while (i < a.terms.size()) {
            terms.push_back(a.terms[i]);
            i++;
        }
        while (j < b.terms.size()) {
            terms.push_back(b.terms[j]);
            j++;
        }
    }
};
