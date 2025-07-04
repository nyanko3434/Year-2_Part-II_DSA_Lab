#include <iostream>
using namespace std;

struct PolyNode {
    int coeff, power;
    PolyNode* next;
};

class Polynomial {
    PolyNode* head;

public:
    Polynomial() : head(nullptr) {}

    void insertTerm(int coeff, int power) {
        if (coeff == 0) return;

        PolyNode* newNode = new PolyNode{coeff, power, nullptr};

        if (!head || head->power < power) {
            newNode->next = head;
            head = newNode;
            return;
        }

        PolyNode* temp = head;

        if (temp->power == power) {
            temp->coeff += coeff;
            delete newNode;
            return;
        }

        while (temp->next && temp->next->power > power)
            temp = temp->next;

        if (temp->next && temp->next->power == power) {
            temp->next->coeff += coeff;
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        PolyNode *a = p1.head, *b = p2.head;

        while (a && b) {
            if (a->power == b->power) {
                result.insertTerm(a->coeff + b->coeff, a->power);
                a = a->next;
                b = b->next;
            } else if (a->power > b->power) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else {
                result.insertTerm(b->coeff, b->power);
                b = b->next;
            }
        }

        while (a) {
            result.insertTerm(a->coeff, a->power);
            a = a->next;
        }

        while (b) {
            result.insertTerm(b->coeff, b->power);
            b = b->next;
        }

        return result;
    }

    void display() {
        PolyNode* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1, p2;

    p1.insertTerm(4, 4);
    p1.insertTerm(5, 2);
    p1.insertTerm(8, 0);

    p2.insertTerm(1, 3);
    p2.insertTerm(2, 2);
    p2.insertTerm(4, 0);

    cout << "Polynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = Polynomial::add(p1, p2);
    cout << "Sum: ";
    sum.display();

    return 0;
}
