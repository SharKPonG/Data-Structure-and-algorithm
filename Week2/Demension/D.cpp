#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rectangle {
public:
    double xLeft, xRight, yTop, yBottom;

    Rectangle(double x1, double y1, double x2, double y2) {
        xLeft = min(x1, x2);
        xRight = max(x1, x2);
        yBottom = min(y1, y2);
        yTop = max(y1, y2);
    }

    double calArea(const Rectangle& other) const {
        double x_area = max(0.0, min(xRight, other.xRight) - max(xLeft, other.xLeft));
        double y_area = max(0.0, min(yTop, other.yTop) - max(yBottom, other.yBottom));
        double area = x_area * y_area;
        if (area < 0.0) return 0.000000;
        else return area;
    }

    bool checkHorizontally(const Rectangle& other) const {
        return other.xLeft > xRight;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Rectangle> rectangles;

    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles.push_back(Rectangle(x1, y1, x2, y2));
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (rectangles[j].xLeft > rectangles[j + 1].xLeft) {
                swap(rectangles[j], rectangles[j + 1]);
            }
        }
    }

    double maxArea = 0.0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rectangles[i].checkHorizontally(rectangles[j])) break;
            double area = rectangles[i].calArea(rectangles[j]);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    printf("%.6lf\n", maxArea);

    return 0;
}
