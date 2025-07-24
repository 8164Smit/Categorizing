#include <iostream>
using namespace std;

void selSort(int a[], int n)
{
    int i, j, min, t;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    cout << "Sorted: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int x[50], y[50];

    for (i = 0; i < n1; i++)
        x[i] = a[l + i];
    for (j = 0; j < n2; j++)
        y[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (x[i] < y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }
    while (i < n1)
        a[k++] = x[i++];
    while (j < n2)
        a[k++] = y[j++];
}

void mSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mSort(a, l, m);
        mSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void showArr(int a[], int n)
{
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void linSearch(int a[], int n, int x)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Found at " << i + 1 << endl;
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "Not found" << endl;
}

void binSearch(int a[], int n, int x)
{
    int s = 0, e = n - 1, m, f = 0;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (a[m] == x)
        {
            cout << "Found at " << m + 1 << endl;
            f = 1;
            break;
        }
        else if (a[m] < x)
            s = m + 1;
        else
            e = m - 1;
    }
    if (!f)
        cout << "Not found" << endl;
}

int main()
{
    int a[50], n, ch, x;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter items: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    do
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1. Selection" << endl;
        cout << "2. Merge" << endl;
        cout << "3. Linear" << endl;
        cout << "4. Binary" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> ch;

        if (ch == 1)
        {
            selSort(a, n);
        }
        else if (ch == 2)
        {
            mSort(a, 0, n - 1);
            showArr(a, n);
        }
        else if (ch == 3)
        {
            cout << "Find: ";
            cin >> x;
            linSearch(a, n, x);
        }
        else if (ch == 4)
        {
            mSort(a, 0, n - 1);
            cout << "Find: ";
            cin >> x;
            binSearch(a, n, x);
        }
        else if (ch == 5)
        {
            cout << "Exit" << endl;
        }
        else
        {
            cout << "Wrong option" << endl;
        }

    } while (ch != 5);

    return 0;
}
